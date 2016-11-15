#! /bin/bash

# a simple script that is supposed to be run from launchd
# see /Users/msantl/Library/LaunchAgents/com.sync.music.plist

DEVICE_ID="090c:1000"

DESTINATION="/Volumes/LEGOBLOCK/"
SOURCE="/Users/msantl/Music/"

# make sure the device mounted
RETRY=3
while [ $RETRY -gt 0 ]; do
  if [[ -d $DESTINATION ]]; then
    break
  fi
  let RETRY=$RETRY-1
  /bin/sleep 1
done

if [[ $RETRY -eq 0 ]]; then
  exit 1
fi

# do the actual sync
RETRY=3
while [ $RETRY -gt 0 ]; do
  /usr/bin/rsync -a -t -q --delete --modify-window=1 --no-perms --omit-dir-times $SOURCE $DESTINATION
  if [[ $? -eq 0 ]]; then
    exit 0
  fi
  let RETRY=$RETRY-1
  /bin/sleep 1
done

exit 1
