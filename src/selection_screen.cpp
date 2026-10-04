//
// Created by npolo on 25/09/2026.
//

#include "selection_screen.h"
#include <iostream>
#include <algorithm>
#include <SFML/Window.hpp>

selection_screen::selection_screen(pokemon_party& p, pokemon_attack& a)
    : party(p), attack(a), placing_attack_index(-1) {}

void selection_screen::run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pokemon Selector");

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f m_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                int clicked_party = layout.get_party_slot_at(m_pos);
                int clicked_attack = layout.get_attack_slot_at(m_pos);

                if (placing_attack_index != -1) {
                    // MODE PLACEMENT : le joueur replace un Pokemon vers la party
                    if (clicked_party != -1) {
                        std::size_t insert_pos = std::min(static_cast<std::size_t>(clicked_party), party.size());
                        attack.return_to_party(party, placing_attack_index, insert_pos);
                        placing_attack_index = -1;
                    } else if (clicked_attack == placing_attack_index) {
                        // Annuler la sélection si on clique dessus
                        placing_attack_index = -1;
                    }
                } else {
                    // MODE NORMAL : le joueur clique sur un Pokemon
                    if (clicked_party != -1 && clicked_party < static_cast<int>(party.size())) {
                        if (!attack.is_full()) {
                            attack.take_from_party(party, clicked_party); // Sélectionne vers l'équipe Attack
                        }
                    } else if (clicked_attack != -1 && clicked_attack < static_cast<int>(attack.size())) {
                        placing_attack_index = clicked_attack; // Initialise le mode de remplacement
                    }
                }
            }
        }

        // Met à jour la disposition selon le nombre actuel de Pokémon dans la party
        layout.update(party.size(), sf::Vector2f(window.getSize().x, window.getSize().y));
        window.clear(sf::Color(240, 240, 240));

        // Récupère la position de la souris pour les effets de survol
        sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        int hovered_party = layout.get_party_slot_at(mouse_pos);
        int hovered_attack = layout.get_attack_slot_at(mouse_pos);

        // --- DESSIN DU GROUPE PARTY ---
        for (std::size_t i = 0; i <= party.size(); ++i) {
            if (i >= layout.party_slots.size()) break;

            sf::RectangleShape rect(sf::Vector2f(layout.party_slots[i].bounds.width, layout.party_slots[i].bounds.height));
            rect.setPosition(layout.party_slots[i].bounds.left, layout.party_slots[i].bounds.top);

            // Apparence générale de la case
            if (i == party.size()) {
                rect.setFillColor(sf::Color(220, 220, 220)); // Case d'insertion vide (à la fin)
            } else {
                rect.setFillColor(sf::Color(180, 180, 180));
            }
            rect.setOutlineColor(sf::Color(100, 100, 100));
            rect.setOutlineThickness(2.f);

            // Effets de survol / d'insertion
            if (placing_attack_index != -1) {
                if (static_cast<int>(i) == hovered_party) {
                    rect.setOutlineColor(sf::Color(255, 200, 0)); // Jaune
                    rect.setOutlineThickness(4.f);
                }
            } else if (static_cast<int>(i) == hovered_party && i < party.size()) {
                rect.setOutlineColor(sf::Color(0, 200, 255)); // Cyan
                rect.setOutlineThickness(4.f);
            }

            window.draw(rect);

            // Dessin du Sprite du Pokemon
            if (i < party.size()) {
                const pokemon& p = party.get_by_index(i);
                sf::Sprite sprite;
                const sf::Texture& tex = cache.get(p.getNumber());
                sprite.setTexture(tex);

                sf::FloatRect b = sprite.getLocalBounds();
                if(b.width > 0 && b.height > 0) {
                    sprite.setScale(rect.getSize().x / b.width, rect.getSize().y / b.height);
                }
                sprite.setPosition(rect.getPosition());
                window.draw(sprite);
            }
        }

        // --- DESSIN DU SÉPARATEUR ---
        sf::RectangleShape sep(sf::Vector2f(window.getSize().x, 4.f));
        sep.setPosition(0.f, layout.attack_slots[0].bounds.top - 20.f);
        sep.setFillColor(sf::Color(50, 50, 50));
        window.draw(sep);

        // --- DESSIN DE L'ÉQUIPE D'ATTAQUE (ATTACK TEAM) ---
        for (std::size_t i = 0; i < pokemon_attack::MAX_SIZE; ++i) {
            if (i >= layout.attack_slots.size()) break;

            sf::RectangleShape rect(sf::Vector2f(layout.attack_slots[i].bounds.width, layout.attack_slots[i].bounds.height));
            rect.setPosition(layout.attack_slots[i].bounds.left, layout.attack_slots[i].bounds.top);

            if (placing_attack_index == (int)i) {
                rect.setFillColor(sf::Color(255, 255, 150)); // Sélectionné en jaune vif
                rect.setOutlineColor(sf::Color(255, 200, 0));
                rect.setOutlineThickness(4.f);
            } else {
                rect.setFillColor(sf::Color(220, 150, 150));
                rect.setOutlineColor(sf::Color(100, 50, 50));
                rect.setOutlineThickness(2.f);

                if (placing_attack_index == -1 && static_cast<int>(i) == hovered_attack && i < attack.size()) {
                    rect.setOutlineColor(sf::Color(0, 200, 255));
                    rect.setOutlineThickness(4.f);
                }
            }

            window.draw(rect);

            if (i < attack.size()) {
                const pokemon& p = attack.get_by_index(i);
                sf::Sprite sprite;
                const sf::Texture& tex = cache.get(p.getNumber());
                sprite.setTexture(tex);

                sf::FloatRect b = sprite.getLocalBounds();
                if(b.width > 0 && b.height > 0) {
                    sprite.setScale(rect.getSize().x / b.width, rect.getSize().y / b.height);
                }
                sprite.setPosition(rect.getPosition());
                window.draw(sprite);
            }
        }

        window.display();
    }
}