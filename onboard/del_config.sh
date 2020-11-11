#! /bin/bash

mount -o remount,rw /

sed -i '/# Start for pkshin/,/#End for pkshin/d' /etc/profile
