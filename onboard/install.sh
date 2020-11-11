#! /bin/bash

mount -o remount,rw /

cp -r ./home/pkshin /home/
cp -r ./lib /usr/
./set_config.sh
printf "install finished\nplease restart the shell to use the toolchain\n"
