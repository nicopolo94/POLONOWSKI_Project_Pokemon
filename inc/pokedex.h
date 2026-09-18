//
// Created by npolo on 14/09/2026.
//

/*
 * The pokedex is an instance for listing all the existing Pokemon (from pokedex.csv).
 * All pokemon are first copied from the pokedex.
 *
 * Pokedex inherit from pokemon_vector.
*/

#ifndef TP_POKEDEX_H
#define TP_POKEDEX_H

#include "pokemon_vector.h"

#include <cstddef>
#include <memory>
#include <string>

class pokedex : public pokemon_vector {
private:
    explicit pokedex(const string& file_name);

public:
    pokedex(const pokedex&) = delete;
    pokedex& operator=(const pokedex&) = delete;

    // The file name is only used on the first call, when the Pokedex is built.
    static pokedex& get_instance(const string& file_name);

    [[nodiscard]] std::unique_ptr<pokemon> copy_pokemon(const string& pokemon_name) const;
    [[nodiscard]] std::unique_ptr<pokemon> copy_pokemon(std::size_t index) const;
};

#endif //TP_POKEDEX_H

