# Relecture de code


## Lancement du projet
Lors de la compilation initiale, j'ai obtenu une erreur car SFML n'est pas configuré dans le projet et n'est pas déclaré dans `CMakeLists.txt`. En commentant l'include `SFML/Graphics.hpp`, la compilation a réussi.


Le README est simple et efficace : il donne bien les instructions à suivre pour lancer le projet et il consacre une partie à la structure globale du projet pour visualiser l'organisation des fichiers. Peut-être qu'une petite description des différentes classes et de leur rôle permettrait d'avoir un peu plus d'informations.
Quelques petites erreurs de frappe se sont glissées dans la *Structure* du projet : l'arborescence montre certains headers dans `src` alors qu'il s'agit certainement de `.cpp`. 


## Structure
Le projet est bien structuré, les ressources sont réunies dans un dossier réservé `data` et les fichiers sont correctement répartis entre `src` et `inc`. Chaque classe a bien un fichier `.cpp` et un fichier `.h`.


## Inc
Ceci est une remarque et n'empêche en rien au projet de fonctionner, mais les headers ont une extension `.h` au lieu de `.hpp`.

<br>

## `main.cpp`
- Les includes de `pokemon.h` et `pokemon_vector.h` ne sont pas utilisés directement dans ce fichier, seul `pokedex.h` semble nécessaire.

<br>

## `Pokemon`

### `pokemon.cpp`
- Les commentaires indiquent le but des méthodes principales, mais parfois, ils répètent le nom de la méthode sans expliquer un point important en particulier.
- Les noms des variables mélangent parfois plusieurs conventions (ex : hitPointsMax et sp_attack).
- Le constructeur de copie réinitialise les points de vie au maximum, il ne copie pas les points de vie actuels. Cela peut poser des problèmes selon l'utilisation.
- L'identifiant `nextId` est `public` et peut donc être modifié depuis l'extérieur, ce qui peut entraîner des problèmes d'unicité des identifiants. La variable pourrait être déclarée `private` pour une meilleure encapsulation.
- Certaines méthodes mélangent actions et sorties console. Pour un code plus propre, limiter une méthode à une action. 


### `pokemon.h`
Le commentaire général permet d'avoir une description des principales caractéristiques d'un Pokémon. Peut-être que ces descriptions pourraient aussi être mises dans le README afin d'éviter d'avoir à ouvrir tous les fichiers de classes pour comprendre leur rôle. 

<br>

## `pokemon_vector`

### `pokemon_vector.cpp`
- `#include <vector>` et `using std::vector;` ne sont pas utilisés dans ce fichier.
- `remove_all_pokemon` vide le vecteur, mais ne libère pas les objets pointés, ce qui peut entraîner des fuites de mémoire selon l'utilisation. 

### `pokemon_vector.h`
- D'après le sujet, la classe devrait être abstraite, mais elle ne contient aucune méthode virtuelle pure. Par exemple, les méthodes pour récupérer un Pokémon à partir de son identifiant ou de son nom peuvent être virtuelles pures. 
- `list_of_pokemon` est `public`. Il est donc possible d'ajouter, de supprimer ou de modifier des éléments de l'extérieur. Il serait peut-être préférable de la mettre en `protected` ou `private`.

<br>

## `pokedex`

### `pokedex.cpp`
- Pour rendre le code très propre, on pourrait commencer par vérifier que la première ligne du CSV correspond bien à l'en-tête.
- Les Pokémon sont créés avec `new`, mais ne sont jamais détruits. Cela peut entraîner des fuites mémoire. Pour éviter ça, on peut utiliser des smart pointers. 


### `pokedex.h`
Le constructeur est bien protégé pour empêcher la création d'instances depuis l'extérieur. 

- `copy_pokemon` est déclarée mais n'est pas définie. 


<br>

## Fonctionnalité supplémentaire proposée
Une fonctionnalité supplémentaire pourrait être l'ajout de potions de soin. Lorsqu'un Pokémon est blessé après un combat, l'utilisateur pourrait utiliser des soins pour restaurer une partie ou la totalité des points de vie, sans pouvoir dépasser la valeur maximale. 

Cette fonctionnalité s'appuierait sur l'attribut `hitPoints` et `hitPointsMax`. Il faudrait ajouter une méthode de soin distincte. Elle s'ajouterait aussi à l'intégration des combats dans la suite du projet et permettrait d'avoir une mécanique de gestion de l'état des Pokémon. 

Pour ajouter une contrainte supplémentaire, le nombre de potions disponibles pourrait être limité et l'utilisateur serait obligé de choisir le bon moment pour les utiliser, et à quels Pokémon les donner. 