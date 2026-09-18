//
// Created by npolo on 18/09/2026.
//

#include "pokemon_party.h"

#include <stdexcept>

std::unique_ptr<pokemon> pokemon_party::extract_pokemon(const string& pokemon_name) {
    const std::optional<std::size_t> index = find_pokemon(pokemon_name);
    if (!index) {
        throw std::invalid_argument("No " + pokemon_name + " in the party");
    }
    return extract_pokemon(*index);
}