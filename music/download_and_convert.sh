#! /bin/bash

USAGE="download_and_convert.sh youtube_uri name"

if [[ $# -ne 2 ]]; then
  echo $USAGE;
  exit 1
fi

URI=$1
NAME=$2
BASE="/Users/msantl/Music"
OUTPUT="$BASE/$NAME/%(title)s.%(ext)s"

echo -n "Creating $NAME ..."
mkdir -p "$BASE/$NAME"

if [[ $? -eq 0 ]]; then
  echo " done"
else
  echo " FAIL"
  exit 1
fi

echo -n "Downloading ..."
youtube-dl -c \
  --ignore-errors \
  --no-warnings \
  --extract-audio \
  --audio-format "mp3" \
  --output "$OUTPUT" $URI

# echo "Converting to mp3 ..."
# /Users/msantl/scripts/convert2mp3.sh "$BASE/$NAME"
