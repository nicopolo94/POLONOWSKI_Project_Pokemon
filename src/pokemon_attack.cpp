//
// Created by npolo on 18/09/2026.
//

#include "pokemon_attack.h"

#include <algorithm>
#include <memory>
#include <stdexcept>
#include <string>

bool pokemon_attack::is_full() const {
    return size() >= MAX_SIZE;
}

void pokemon_attack::take_from_party(pokemon_party& party, const std::size_t party_index) {
    // Checked before extracting: if the team were full after the extraction,
    // the pokemon would already be out of the party and would be lost.
    if (is_full()) {
        throw std::length_error("The attack team already has " + std::to_string(MAX_SIZE) + " pokemon");
    }
    add_pokemon(party.extract_pokemon(party_index));
}

void pokemon_attack::take_from_party(pokemon_party& party, const std::vector<std::size_t>& party_indexes) {
    // Every index is checked before anything moves, so an invalid selection leaves
    // both the party and the team untouched.
    if (size() + party_indexes.size() > MAX_SIZE) {
        throw std::length_error("The attack team can't have more than " + std::to_string(MAX_SIZE) + " pokemon");
    }
    for (std::size_t i = 0; i < party_indexes.size(); ++i) {
        if (party_indexes[i] >= party.size()) {
            throw std::out_of_range("No pokemon at index " + std::to_string(party_indexes[i]) + " in the party");
        }
        if (std::find(party_indexes.begin(), party_indexes.begin() + static_cast<std::ptrdiff_t>(i), party_indexes[i])
            != party_indexes.begin() + static_cast<std::ptrdiff_t>(i)) {
            throw std::invalid_argument("Index " + std::to_string(party_indexes[i]) + " selected twice");
        }
    }

    // Extracting shifts the following indexes of the party, so the pokemon are extracted from the
    // highest index to the lowest, then added to the team in the order chosen by the player.
    std::vector<std::size_t> extraction_order(party_indexes.size());
    for (std::size_t i = 0; i < extraction_order.size(); ++i) {
        extraction_order[i] = i;
    }
    std::sort(extraction_order.begin(), extraction_order.end(),
              [&party_indexes](const std::size_t a, const std::size_t b) {
                  return party_indexes[a] > party_indexes[b];
              });

    std::vector<std::unique_ptr<pokemon>> selected(party_indexes.size());
    for (const std::size_t i : extraction_order) {
        selected[i] = party.extract_pokemon(party_indexes[i]);
    }
    for (std::unique_ptr<pokemon>& p : selected) {
        add_pokemon(std::move(p));
    }
}

void pokemon_attack::return_to_party(pokemon_party& party, const std::size_t attack_index) {
    return_to_party(party, attack_index, party.size());
}

void pokemon_attack::return_to_party(pokemon_party& party, const std::size_t attack_index,
                                     const std::size_t party_position) {
    if (attack_index >= size()) {
        throw std::out_of_range("No pokemon at index " + std::to_string(attack_index) + " in the attack team");
    }
    if (party_position > party.size()) {
        throw std::out_of_range("Invalid position in the party : " + std::to_string(party_position));
    }
    party.insert_pokemon(party_position, extract_pokemon(attack_index));
}

void pokemon_attack::return_all_to_party(pokemon_party& party) {
    while (!empty()) {
        party.add_pokemon(extract_pokemon(0));
    }
}

bool pokemon_attack::is_knocked_out() const {
    for (std::size_t i = 0; i < size(); ++i) {
        if (!get_by_index(i).isKnockedOut()) {
            return false;
        }
    }
    return true;
}
