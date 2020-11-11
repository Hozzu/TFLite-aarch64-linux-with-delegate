#! /bin/bash

mount -o remount,rw /

sed -i '/# Start for pkshin/,/#End for pkshin/d' /etc/profile

printf "# Start for pkshin\nPATH=\$PATH:/home/pkshin/bin\n# End for pkshin\n" >> /etc/profile
