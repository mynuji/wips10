#!/bin/sh

if [ $# = 0 ]
then
	echo "무선랜 device정보가 누락되었습니다"
	return
fi

#sudo ifconfig $1 down
sudo iwconfig $1 mode monitor 
#sudo ifconfig $1 up


#sudo airmon-ng start $1 > /dev/null

#echo "ifconfig $1 down, monitor mode, up"

