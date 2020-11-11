#! /bin/bash

mount -o remount,rw /

./del_config.sh

rm -rf /home/pkshin

printf "uninstall finished\n"
