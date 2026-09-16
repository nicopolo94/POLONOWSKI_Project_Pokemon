//
// Created by npolo on 14/09/2026.
//

#include "../inc/pokemon_vector.h"
#include "../inc/pokemon.h"

#include <vector>
using std::vector;

void pokemon_vector::add_pokemon(pokemon *p) {
    list_of_pokemon.push_back(p);
}

void pokemon_vector::remove_all_pokemon() {
    list_of_pokemon.clear();
}

void pokemon_vector::display() const {
    for (const pokemon* p : list_of_pokemon) {
        p->displayName();
    }
}
