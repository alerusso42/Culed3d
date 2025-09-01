#!/bin/bash

CURR="$(pwd)"
LOG="$CURR/log"
rm "$LOG"
test_cub ()
{
	MAP=$1
	make script >> "$LOG" 2>&1
	echo -e "\n\n" >> $LOG
}

echo "" > $LOG
cd cub3D
TEST_N=$(ls maps/ | wc -l)
mand=(maps/*.cub)
i=0
while (($i < $TEST_N)); do
	test_cub "${mand[$i]}"
	((i++))
done