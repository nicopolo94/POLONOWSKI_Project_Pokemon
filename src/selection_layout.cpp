//
// Created by npolo on 25/09/2026.
//

#include "selection_layout.h"

void selection_layout::update(const std::size_t party_size, const sf::Vector2f& window_size) {
    party_slots.clear();
    attack_slots.clear();

    constexpr float slot_w = 64.f;
    constexpr float slot_h = 64.f;
    constexpr float padding = 15.f;

    // Calcul de la grille de la "Party" (en haut)
    int cols = static_cast<int>((window_size.x - padding) / (slot_w + padding));
    if (cols < 1) cols = 1;

    // On affiche une case supplémentaire (+1) pour autoriser l'insertion tout à la fin
    for (std::size_t i = 0; i <= party_size; ++i) {
        float x = padding + (i % cols) * (slot_w + padding);
        float y = padding + (i / cols) * (slot_h + padding);
        party_slots.push_back({.bounds = sf::FloatRect(x, y, slot_w, slot_h), .index = i});
    }

    // Calcul de la disposition de "l'Attack Team" (en bas)
    float attack_start_x = (window_size.x - (6 * slot_w + 5 * padding)) / 2.f;
    float attack_y = window_size.y - slot_h - 30.f;

    for (std::size_t i = 0; i < 6; ++i) {
        float x = attack_start_x + i * (slot_w + padding);
        attack_slots.push_back({.bounds = sf::FloatRect(x, attack_y, slot_w, slot_h), .index = i});
    }
}

int selection_layout::get_party_slot_at(const sf::Vector2f& pos) const {
    for (const auto&[bounds, index] : party_slots) {
        if (bounds.contains(pos)) return static_cast<int>(index);
    }
    return -1;
}

int selection_layout::get_attack_slot_at(const sf::Vector2f& pos) const {
    for (const auto&[bounds, index] : attack_slots) {
        if (bounds.contains(pos)) return static_cast<int>(index);
    }
    return -1;
}