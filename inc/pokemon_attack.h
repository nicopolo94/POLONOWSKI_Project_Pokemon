//
// Created by npolo on 18/09/2026.
//

/*
 * The pokemon_attack is the team sent into battle: an extract of the pokemon_party,
 * limited to MAX_SIZE (6) pokemon.
 * Pokemon are never copied between the party and the attack team, they are moved:
 * a pokemon is always either in the party or in the attack team, never in both.
 *
 * The team is built from the party (one pokemon at a time or a whole selection at once),
 * and its pokemon can be given back to the party, at the end or at a chosen position.
 *
 * Pokemon_attack inherits from pokemon_vector.
 */

#ifndef TP_POKEMON_ATTACK_H
#define TP_POKEMON_ATTACK_H

#include "pokemon_vector.h"
#include "pokemon_party.h"

#include <cstddef>
#include <vector>

class pokemon_attack : public pokemon_vector {
public:
    static constexpr std::size_t MAX_SIZE = 6;

    using pokemon_vector::get_by_index;

    [[nodiscard]] bool is_full() const;

    void take_from_party(pokemon_party& party, std::size_t party_index);
    void take_from_party(pokemon_party& party, const std::vector<std::size_t>& party_indexes);

    void return_to_party(pokemon_party& party, std::size_t attack_index);
    void return_to_party(pokemon_party& party, std::size_t attack_index, std::size_t party_position);
    void return_all_to_party(pokemon_party& party);

    [[nodiscard]] bool is_knocked_out() const;
};

#endif //TP_POKEMON_ATTACK_H
