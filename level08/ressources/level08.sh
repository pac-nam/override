#!/usr/bin/env bash

export HOME=`pwd`

cd /tmp
mkdir -p home/users/level09 backups
~level08/level08 ../home/users/level09/.pass
cat home/users/level09/.pass
