//
// Created by npolo on 05/10/2026.
//

#ifndef TP_GAME_ENGINE_H
#define TP_GAME_ENGINE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "game_state.h"
#include "pokemon_party.h"
#include "pokemon_attack.h"
#include "texture_cache.h"

class game_engine {
private:
    std::unique_ptr<game_state> current_state;
    std::unique_ptr<game_state> next_state; // Stocke le prochain état pour une transition propre
    bool running;

public:
    sf::RenderWindow window;
    pokemon_party party;
    pokemon_attack attack_team;
    texture_cache cache; // Cache global pour ne charger les images qu'une fois

    game_engine();

    // Demande au moteur de passer à un nouvel état (ex: de l'accueil au combat)
    void change_state(std::unique_ptr<game_state> state);
    void run();
    void quit();
};

#endif //TP_GAME_ENGINE_H
