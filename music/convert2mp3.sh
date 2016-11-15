#! /bin/bash

USAGE="convert2mp3.sh source/"

if [[ $# -ne 1 ]]; then
  echo $USAGE;
  exit 1
fi

SAVEIFS=$IFS
IFS=$(echo -en "\n\b")
PWD=$1

for file in $(ls $PWD | grep -v mp3)
do
  echo -n "converting $PWD/$file ..."
  ffmpeg -i "$PWD/$file" -q:a 0 -map a "$PWD/${file%.*}.mp3" &> /dev/null
  if [[ $? -eq 0 ]]; then
    rm -f "$PWD/$file"
    echo " OK"
  else
    echo " FAIL"
  fi
done

IFS=$SAVEIFS
