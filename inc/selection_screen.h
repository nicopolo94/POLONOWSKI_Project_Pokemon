//
// Created by npolo on 25/09/2026.
//

#ifndef TP_SELECTION_SCREEN_H
#define TP_SELECTION_SCREEN_H

#include "pokemon_party.h"
#include "pokemon_attack.h"
#include "texture_cache.h"
#include "selection_layout.h"

class selection_screen {
private:
    pokemon_party& party;
    pokemon_attack& attack;
    texture_cache cache;
    selection_layout layout;

    int placing_attack_index; // Vaut -1 si on ne déplace pas de Pokémon actuellement

public:
    selection_screen(pokemon_party& p, pokemon_attack& a);
    void run(); // Démarre la boucle principale SFML
};

#endif //TP_SELECTION_SCREEN_H