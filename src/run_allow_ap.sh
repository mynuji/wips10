#!/bin/sh

wget http://192.168.0.4:8888/allow --post-data="mac=$1" -O $2 -o wget.txt
