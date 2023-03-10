#!/bin/sh

if [ $# = 0 ]
then
	echo "무선랜 device정보가 누락되었습니다"
	return
fi
 

#if [ $2 = "90:9f:33:d3:89:1a" ]
#if [ $2 = "90:9f:33:d3:89:18" ]
#then
#
	echo "./run_change_channel.sh $4 $3"
	sh ./run_change_channel.sh $4 $3 

	echo "aireplay-ng --deauth $1 -a $2 $4"
#	aireplay-ng --deauth $1 -a $2 $4 
#fi
