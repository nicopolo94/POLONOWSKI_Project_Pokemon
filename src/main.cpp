#include "pokedex.h"
#include "game_engine.h"
#include "state_title.h"
#include <iostream>

#ifndef DATA_DIR
#define DATA_DIR "./data"
#endif

int main() {
    try {
        // Initialise le Pokedex
        const std::string csv_path = std::string(DATA_DIR) + "/pokedex.csv";
        const pokedex& dex = pokedex::get_instance(csv_path);

        // Crée le contexte global (la machine à états)
        game_engine engine;

        // On donne quelques Pokémon de base au joueur
        for (std::size_t i = 1; i <= 25; ++i) {
            try { engine.party.add_pokemon(dex.copy_pokemon(i)); }
            catch (...) {}
        }

        // On démarre la machine avec l'écran d'accueil
        engine.change_state(std::make_unique<state_title>(&engine));

        // Lance la boucle infinie du jeu (tourne jusqu'à la fermeture)
        engine.run();

    } catch (const std::exception& e) {
        std::cerr << "Erreur fatale : " << e.what() << '\n';
        return 1;
    }

    return 0;
}