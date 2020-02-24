#!/usr/bin/env bash

. /tmp/init.sh

python -c 'print "%lx" * 33' > /tmp/level02

res=$(cat /tmp/level02 | ./level02)

flag=$(echo $res | cut -d ' ' -f 25)

echo "import sys

arg = sys.argv[1].decode(\"hex\")
for i in range (-1, len(arg), 8):
    if i != -1:
        sys.stdout.write(arg[i+8:i:-1])
    else:
        sys.stdout.write(arg[7:0:-1] + arg[0])
sys.stdout.write(\"\n\")
sys.stdout.flush()" > /tmp/reverse.py 

echo -e "/tmp/reverse.py \"${flag:89:80}\"\n"

echo -ne "\n\nLevel03 password: "
python /tmp/reverse.py "${flag:89:80}"
