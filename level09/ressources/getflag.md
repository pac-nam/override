## GET Flag

L'erreur du programme est de copier 41 caractères dans un buffer de 40
et d'utiliser le nombre qui suit comme troisième paramètre de strncpy.
Il est donc possible d'effectuer un buffer overflow afin de remplacer l'EIP par l'adresse de la fonction secret_backdoor.
La fonction secret_backdoor va passer à system l'entré utilisateur.

### Flag

```
end
j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE
```
