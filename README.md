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

### Struture du projet ###

~~~
TP
|- data
|   |- pokemon          -> images des pokemons
|   |- pokedex.csv      -> liste des pokemons
|- inc
|   |- pokemon.h
|   |- pokemon_vector.h
|   |- pokedex.h
|- src
|   |- main.cpp
|   |- pokemon.cpp      -> définition des pokemons
|   |- pokemon_vector.h -> classe abstraite d'une liste de pokemons
|   |- pokedex.h        -> liste principale des pokemons,
|                          créée à partir de pokedex.csv
|- CMakeLists.txt
~~~
