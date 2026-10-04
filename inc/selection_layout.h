//
// Created by npolo on 25/09/2026.
//

#ifndef TP_SELECTION_LAYOUT_H
#define TP_SELECTION_LAYOUT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstddef>

struct slot_layout {
    sf::FloatRect bounds;
    std::size_t index{};
};

class selection_layout {
public:
    std::vector<slot_layout> party_slots;
    std::vector<slot_layout> attack_slots;

    void update(std::size_t party_size, const sf::Vector2f& window_size);

    // Renvoie l'index de la case cliquée ou -1 si clic dans le vide
    [[nodiscard]] int get_party_slot_at(const sf::Vector2f& pos) const;
    [[nodiscard]] int get_attack_slot_at(const sf::Vector2f& pos) const;
};

#endif //TP_SELECTION_LAYOUT_H