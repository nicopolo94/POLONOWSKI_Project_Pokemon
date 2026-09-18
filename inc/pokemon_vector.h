//
// Created by npolo on 14/09/2026.
//

// The abstract class pokemon_vector allow to create other class who need a list of pokemon.

#ifndef TP_POKEMON_VECTOR_H
#define TP_POKEMON_VECTOR_H

#include "pokemon.h"

#include <cstddef>
#include <memory>
#include <optional>
#include <vector>

// Each collection owns its pokemon through unique_ptr: moving a pokemon from the party to the
// attack team is a transfer of ownership, so it can never be in two lists or be deleted twice.
//
// Methods that give access to the pokemon are protected: the Pokedex must stay read-only, so each
// derived class decides which of them to make public.
class pokemon_vector {
protected:
    std::vector<std::unique_ptr<pokemon>> list_of_pokemon;

    void add_pokemon(std::unique_ptr<pokemon> p);
    void insert_pokemon(std::size_t position, std::unique_ptr<pokemon> p);
    [[nodiscard]] std::unique_ptr<pokemon> extract_pokemon(std::size_t index);
    [[nodiscard]] pokemon& get_by_index(std::size_t index);
    [[nodiscard]] const pokemon& get_by_index(std::size_t index) const;

public:
    pokemon_vector() = default;
    pokemon_vector(const pokemon_vector&) = delete;
    pokemon_vector& operator=(const pokemon_vector&) = delete;
    // Pure virtual destructor: makes the class abstract without inventing an artificial method.
    virtual ~pokemon_vector() = 0;

    [[nodiscard]] std::size_t size() const;
    [[nodiscard]] bool empty() const;
    [[nodiscard]] std::optional<std::size_t> find_pokemon(const string& pokemon_name) const;
    void remove_all_pokemon();
    void display() const;
};

#endif //TP_POKEMON_VECTOR_H

