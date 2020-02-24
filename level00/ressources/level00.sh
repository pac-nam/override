#!/usr/bin/env bash

. /tmp/init.sh

echo 5276 > /tmp/level00

cat /tmp/level00 - | ./level00
