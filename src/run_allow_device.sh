#!/bin/sh

wget http://192.168.0.4:8888/allowdevice --post-data="mac=$1" -O $2 
