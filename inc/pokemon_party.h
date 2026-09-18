//
// Created by npolo on 18/09/2026.
//

#ifndef TP_POKEMON_PARTY_H
#define TP_POKEMON_PARTY_H

#include "pokemon_vector.h"

class pokemon_party : public pokemon_vector {
public:
    using pokemon_vector::add_pokemon;
    using pokemon_vector::extract_pokemon;
    using pokemon_vector::insert_pokemon;
    using pokemon_vector::get_by_index;

    [[nodiscard]] std::unique_ptr<pokemon> extract_pokemon(const string& pokemon_name);
};

#endif //TP_POKEMON_PARTY_H
