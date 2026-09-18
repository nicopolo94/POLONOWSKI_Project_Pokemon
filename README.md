### Nicolas Polonowski ###
# Projet Pokémon #

___

Le but de ce projet est de concevoir un jeu Pokémon simple.

### Lancement du projet ###

Pour compiler et lancer le projet, depuis la racine du dépôt (le chemin `data/pokedex.csv` est relatif au dossier courant) :
```shell
$ cmake -B build
$ cmake --build build
$ build/TP
```

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
|- src
|   |- main.cpp
|   |- pokemon.cpp -> définition d'un pokemon
|   |- pokemon_vector.cpp -> classe abstraite d'une liste de pokemons
|   |- pokedex.cpp -> singleton contenant tous les pokemons, créé à partir de pokedex.csv
|   |- pokemon_party.cpp -> l'ensemble des pokemons du joueur
|- CMakeLists.txt
~~~

### Règle d'attaque ###

Un pokemon inflige `attaque - défense adverse` points de dégâts. Si ce nombre est nul ou négatif, l'attaque n'a aucun effet.
