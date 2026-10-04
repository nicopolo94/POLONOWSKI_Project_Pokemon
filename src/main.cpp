#include "pokedex.h"
#include "pokemon_party.h"
#include "pokemon_attack.h"
#include "selection_screen.h"
#include <iostream>

#ifndef DATA_DIR
#define DATA_DIR "./data"
#endif

int main() {
    try {
        // 1. Initialise le Pokedex
        const std::string csv_path = std::string(DATA_DIR) + "/pokedex.csv";
        const pokedex& dex = pokedex::get_instance(csv_path);

        // 2. Initialise la party (La réserve de Pokémon du joueur)
        pokemon_party party;

        // On copie par exemple les 25 premiers Pokémon existants dans la party
        for (std::size_t i = 1; i <= 25; ++i) {
            try {
                party.add_pokemon(dex.copy_pokemon(i));
            } catch (...) {
                // Ignore silencieusement si un index n'a pas pu être instancié
            }
        }

        // 3. Initialise l'équipe d'attaque
        pokemon_attack attack;

        // 4. Lance l'interface graphique SFML de sélection
        selection_screen screen(party, attack);
        screen.run();

    } catch (const std::exception& e) {
        std::cerr << "Erreur fatale : " << e.what() << '\n';
        return 1;
    }

    return 0;
}