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
#include "pokemon.h"

#include <string>
using std::string;

class pokedex : public pokemon_vector {
private:
    static pokedex* pokedex_instance;
protected:
    explicit pokedex(const string& file_name);
public:
    static pokedex* get_instance(const string& file_name);
    pokemon* copy_pokemon(const string& pokemon_name);
};

#endif //TP_POKEDEX_H
