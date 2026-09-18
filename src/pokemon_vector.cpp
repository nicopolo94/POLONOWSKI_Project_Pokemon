//
// Created by npolo on 14/09/2026.
//

#include "pokemon_vector.h"

#include <stdexcept>

pokemon_vector::~pokemon_vector() = default;

void pokemon_vector::add_pokemon(std::unique_ptr<pokemon> p) {
    if (!p) {
        throw std::invalid_argument("Cannot add a null pokemon");
    }
    list_of_pokemon.push_back(std::move(p));
}

void pokemon_vector::insert_pokemon(const std::size_t position, std::unique_ptr<pokemon> p) {
    if (!p) {
        throw std::invalid_argument("Cannot add a null pokemon");
    }
    if (position > list_of_pokemon.size()) {
        throw std::out_of_range("Invalid position : " + std::to_string(position));
    }
    list_of_pokemon.insert(list_of_pokemon.begin() + static_cast<std::ptrdiff_t>(position), std::move(p));
}

std::unique_ptr<pokemon> pokemon_vector::extract_pokemon(const std::size_t index) {
    std::unique_ptr<pokemon> extracted = std::move(list_of_pokemon.at(index));
    list_of_pokemon.erase(list_of_pokemon.begin() + static_cast<std::ptrdiff_t>(index));
    return extracted;
}

pokemon& pokemon_vector::get_by_index(const std::size_t index) {
    return *list_of_pokemon.at(index);
}

const pokemon& pokemon_vector::get_by_index(const std::size_t index) const {
    return *list_of_pokemon.at(index);
}

std::size_t pokemon_vector::size() const {
    return list_of_pokemon.size();
}

bool pokemon_vector::empty() const {
    return list_of_pokemon.empty();
}

std::optional<std::size_t> pokemon_vector::find_pokemon(const string& pokemon_name) const {
    for (std::size_t i = 0; i < list_of_pokemon.size(); ++i) {
        if (list_of_pokemon[i]->getName() == pokemon_name) {
            return i;
        }
    }
    return std::nullopt;
}

void pokemon_vector::remove_all_pokemon() {
    list_of_pokemon.clear();
}

void pokemon_vector::display() const {
    for (const auto& p : list_of_pokemon) {
        p->displayName();
    }
}
