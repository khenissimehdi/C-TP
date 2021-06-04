# Rapport de relecture de code

Production soumise à la relecture : **TP14**
Projet/code produit par **Mehdi KHENISSI**
Relecture opérée par **Fabian REITER** le 29 avril 2021

## Concision et propreté des rendus

L'auteur a laissé des éléments inutiles ou des fichiers mal identifiés dans ses contenus.

La fonction `ls_rec` est définie dans `main.c` mais jamais utilisée.

## Installation et compilation des sources transmises

Un makefile permet la compilation de toutes les sources sans grave warning et avec, a minima, le flag -Wall.

Attention `exo1.c` utilise `exo1.h`, mais cette dépendance n'est pas renseignée dans le makefile.

## Fonctionnalités implantées dans les rendus

Une des fonctionnalité n'est pas implantée correctement.

Il y a une erreur dans la fonction `ordered_insertion` qui fait que les fichiers ne sont pas triés par taille. La conséquence est que les 10 fichiers affichés par le programme ne sont pas nécessairement les plus grands. Aussi, le programme n'ignore pas le répertoire `.` qui est donc aussi affiché.

## Utilisations et sécurité des programmes produits

Un cas d'utilisation normal fait échouer un programme (erreur, segfault, etc...).

Quand on appelle le programme sans arguments, il ne fait rien de visible, alors qu'il devrait afficher un message d'erreur expliquant son utilisation. Ce message n'est pas affiché parce que le `main` teste `if (argc < 1)` au lieu de `if (argc < 2)`.

## Nommage des éléments dans les productions rendues

Les éléments des productions sont correctement nommés.

## Efficacité et performance des productions rendues

Un programme utilise un mauvais algorithme ou procède à des calculs ou des tests inutiles.

La fonction `engine` alloue de la mémoire pour copier une chaîne de caractères, puis passe cette copie à `ordered_insertion` qui alloue aussi de la mémoire et crée une deuxième copie. L'allocation dans `engine` est donc complètement inutile.

## Commentaires dans les sources des productions rendues

Un passage trop rusé ou surprenant manque de commentaires ou encore un commentaire est présent mais non-éclairant .

Le programme ne contient aucun commentaire.

## Derniers commentaires :

Globalement, le code est lisible, mais il manque encore un peu de rigueur dans le formatage qui n'est pas toujours très cohérent. Par exemple, le nombre d'espace utilisées pour indenter, le nombre de lignes vides utilisées pour séparer des éléments, etc., varient.
Pour un compilateur, ça ne fait aucune différence, mais pour un lecteur humain, les incohérences diminuent la facilité de lecture et la confiance en la qualité du code (si le formatage n'est pas hyper soigné, on se demande si la logique du code peut l'être). Je te conseille donc de trouver un style qui te plaît et de l'appliquer rigoureusement.
