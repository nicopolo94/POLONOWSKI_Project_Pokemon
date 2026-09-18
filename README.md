### Nicolas Polonowski ###
# Projet Pokémon #

___

Le but de ce projet est de concevoir un jeu Pokémon simple.

### Lancement du projet ###

Pour compiler et lancer le projet :
```shell
$ cmake -B build
$ cmake --build build
$ build/TP
```

Le chemin du dossier `data` est transmis au code par CMake (`DATA_DIR`) sous forme de chemin absolu. Le programme trouve donc `pokedex.csv` quel que soit le dossier depuis lequel il est lancé.

### Structure du projet ###

~~~
TP
|- data
|   |- pokemon -> images des pokemons
|   |- pokedex.csv -> liste des pokemons
|- inc
|   |- pokemon.h
|   |- pokemon_vector.h
|   |- pokedex.h
|   |- pokemon_party.h
|   |- pokemon_attack.h
|- src
|   |- main.cpp
|   |- pokemon.cpp -> définition d'un pokemon
|   |- pokemon_vector.cpp -> classe abstraite d'une liste de pokemons
|   |- pokedex.cpp -> singleton contenant tous les pokemons, créé à partir de pokedex.csv
|   |- pokemon_party.cpp -> l'ensemble des pokemons du joueur
|   |- pokemon_attack.cpp -> l'équipe de combat, 6 pokemons au maximum
|- CMakeLists.txt
~~~

### Les classes ###

`pokemon` représente un individu. Il possède un ID unique, attribué à chaque création (copies comprises), et son numéro de Pokédex, commun à tous les pokemons de la même espèce. Copier un pokemon crée donc un nouvel individu, avec un nouvel ID et tous ses points de vie.

`pokemon_vector` est la classe abstraite commune à toutes les listes de pokemons. Chaque liste possède ses pokemons (via `std::unique_ptr`) : un pokemon n'est jamais dans deux listes à la fois, et la mémoire est libérée automatiquement. Les méthodes d'accès sont protégées, et chaque classe fille choisit celles qu'elle rend publiques.

`pokedex` est un singleton qui lit `pokedex.csv` à sa première utilisation. Ses pokemons ne peuvent être ni modifiés ni retirés : on obtient un pokemon uniquement en demandant une copie avec `copy_pokemon`, par nom ou par index.

`pokemon_party` contient tous les pokemons du joueur, sans limite de taille. On peut y ajouter un pokemon (à la fin ou à une position choisie), y accéder et l'en retirer.

`pokemon_attack` est l'équipe envoyée au combat, limitée à 6 pokemons. Les pokemons sont déplacés depuis la party, un par un ou par sélection de plusieurs index, puis rendus à la party, à la fin ou à la position choisie par le joueur. Une sélection invalide (index inexistant, doublon, équipe trop grande) est refusée avant tout déplacement, donc la party et l'équipe restent intactes.

### Règle d'attaque ###

Un pokemon inflige `attaque - défense adverse` points de dégâts. Si ce nombre est nul ou négatif, l'attaque n'a aucun effet. Un pokemon dont les points de vie tombent à 0 est K.O., et une équipe est vaincue quand tous ses pokemons sont K.O.
