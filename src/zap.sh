#!/bin/sh

kill -9 `ps -ef | grep $1 | awk '{print \$2}'`

