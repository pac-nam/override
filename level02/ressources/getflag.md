## GET Flag

Le programme lit le mot de passe et le stoque dans un buffer puis le compare avec l'entrée de l'utilisateur.
Il lance un shell si les deux correspondent, sinon il imprime le nom entré par l'utilisateur suivit de " does not have access!".

La faille réside dans le fait que le nom entré par l'utilisateur est passé en tant que format à printf.
Il est donc possible d'imprimer la stack, puis en connaissant l'architecture de retrouver le mot de passe.

### Flag

```
level03
Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
```
