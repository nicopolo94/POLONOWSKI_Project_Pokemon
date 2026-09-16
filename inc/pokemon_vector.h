//
// Created by npolo on 14/09/2026.
//

// The abstract class pokemon_vector allow to create other class who need a list of pokemon.

#ifndef TP_POKEMON_VECTOR_H
#define TP_POKEMON_VECTOR_H

#include <vector>
using std::vector;

#include "pokemon.h"

class pokemon_vector {
public:
    virtual ~pokemon_vector() = default;

    vector<pokemon*> list_of_pokemon;

    void add_pokemon(pokemon *p);
    void remove_all_pokemon();

    void display() const;
};


#endif //TP_POKEMON_VECTOR_H
