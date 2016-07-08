#!/bin/bash
# needs debian-jessie with libasound2-dev libudev-dev

start=$SECONDS
src=$(pwd)
target=$src/bin
set -e
if [ ! -d $target ]; then
  mkdir $target
fi
cd $target
cmake -D"CMAKE_BUILD_TYPE=Release" -D"PI=1" -G"Unix Makefiles" $src
make -j 8
#make 
ls -l .

elapsed=$(($SECONDS-$start))
echo "Task Complete elapsed="$(($elapsed/60))":"$(($elapsed%60))
