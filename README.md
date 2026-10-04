### Nicolas Polonowski ###
# Projet Pokémon #

___

Le but de ce projet est de concevoir un jeu Pokémon simple en C++, doté d'une interface graphique interactive.

### Lancement du projet (Linux / WSL)

Le projet utilise **SFML 2**. Sous un environnement Linux ou WSL (Windows Subsystem for Linux), vous devez d'abord installer la bibliothèque graphique :
```shell
$ sudo apt-get update
$ sudo apt-get install libsfml-dev
```

Pour compiler et lancer le projet :
```shell
$ cmake -B build
$ cmake --build build
$ ./build/TP
```

*Note : Le chemin du dossier `data` est transmis automatiquement au code par CMake (`DATA_DIR`). Le programme trouvera les images et le `pokedex.csv` quel que soit le dossier de lancement.*

### Architecture

#### 1. Moteur de Jeu (Design Pattern : STATE)
Le jeu utilise le patron de conception **State** pour gérer les différents écrans de manière propre :
- `game_engine` : Le chef d'orchestre (Contexte). Il gère la fenêtre SFML, la mémoire cache des textures, et possède les listes de Pokémon du joueur.
- `game_state` : L'interface abstraite que chaque écran doit respecter.
- **Les États actuels** : `state_title` (Écran d'accueil), `state_exploration` (Écran principal), `state_team_selection` (Écran de choix d'équipe), `state_combat` (Écran de combat) et `state_game_over` (Écran de game over)

#### 2. Interface Graphique (SFML)
- `texture_cache` : Charge les images dynamiquement et les garde en mémoire pour éviter les ralentissements.
- `selection_layout` & `selection_screen` : Gèrent la grille cliquable pour transférer les Pokémon de la réserve (`pokemon_party`) vers l'équipe d'attaque (`pokemon_attack`).

#### 3. Logique Métier (Classes de base)
- `pokemon` : Représente un individu (ID unique, stats, points de vie).
- `pokemon_vector` : Classe abstraite commune à toutes les listes de Pokémon (gestion sécurisée de la mémoire via `std::unique_ptr`).
- `pokedex` : Singleton lisant `pokedex.csv` (usine à Pokémon en lecture seule).
- `pokemon_party` : La réserve illimitée du joueur.
- `pokemon_attack` : L'équipe envoyée au combat (6 Pokémon maximum).

### Règle d'attaque

Un pokemon inflige `attaque - défense adverse` points de dégâts. Si ce nombre est nul ou négatif, l'attaque n'a aucun effet. Un pokemon dont les points de vie tombent à 0 est K.O., et une équipe est vaincue quand tous ses pokemons sont K.O.