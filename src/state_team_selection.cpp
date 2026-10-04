//
// Created by npolo on 05/10/2026.
//

#include "state_team_selection.h"
#include "game_engine.h"
#include "state_exploration.h"
#include <algorithm>

state_team_selection::state_team_selection(game_engine* engine)
    : game_state(engine), placing_attack_index(-1)
{
    if (font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        text_escape.setFont(font);
        text_escape.setString("Appuyez sur ECHAP pour retourner a l'exploration");
        text_escape.setCharacterSize(18);
        text_escape.setFillColor(sf::Color::Black);
        text_escape.setPosition(10.f, 10.f);
    }
}

void state_team_selection::handle_event(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        engine->change_state(std::make_unique<state_exploration>(engine));
        return;
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        const sf::Vector2f m_pos = engine->window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
        const int clicked_party = layout.get_party_slot_at(m_pos);
        const int clicked_attack = layout.get_attack_slot_at(m_pos);

        if (placing_attack_index != -1) {
            if (clicked_party != -1) {
                const std::size_t insert_pos = std::min(static_cast<std::size_t>(clicked_party), engine->party.size());
                engine->attack_team.return_to_party(engine->party, placing_attack_index, insert_pos);
                placing_attack_index = -1;
            } else if (clicked_attack == placing_attack_index) {
                placing_attack_index = -1; // Annule
            }
        } else {
            if (clicked_party != -1 && clicked_party < static_cast<int>(engine->party.size())) {
                if (!engine->attack_team.is_full()) {
                    engine->attack_team.take_from_party(engine->party, clicked_party);
                }
            } else if (clicked_attack != -1 && clicked_attack < static_cast<int>(engine->attack_team.size())) {
                placing_attack_index = clicked_attack;
            }
        }
    }
}

void state_team_selection::update() {
    layout.update(engine->party.size(), sf::Vector2f(engine->window.getSize().x, engine->window.getSize().y));
}

void state_team_selection::draw(sf::RenderWindow& window) {
    window.clear(sf::Color(240, 240, 240));
    window.draw(text_escape);

    sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    int hovered_party = layout.get_party_slot_at(mouse_pos);
    int hovered_attack = layout.get_attack_slot_at(mouse_pos);

    // DESSIN PARTY
    for (std::size_t i = 0; i <= engine->party.size(); ++i) {
        if (i >= layout.party_slots.size()) break;

        sf::RectangleShape rect(sf::Vector2f(layout.party_slots[i].bounds.width, layout.party_slots[i].bounds.height));
        rect.setPosition(layout.party_slots[i].bounds.left, layout.party_slots[i].bounds.top);

        if (i == engine->party.size()) rect.setFillColor(sf::Color(220, 220, 220));
        else rect.setFillColor(sf::Color(180, 180, 180));
        rect.setOutlineColor(sf::Color(100, 100, 100));
        rect.setOutlineThickness(2.f);

        if (placing_attack_index != -1 && static_cast<int>(i) == hovered_party) {
            rect.setOutlineColor(sf::Color(255, 200, 0)); rect.setOutlineThickness(4.f);
        } else if (placing_attack_index == -1 && static_cast<int>(i) == hovered_party && i < engine->party.size()) {
            rect.setOutlineColor(sf::Color(0, 200, 255)); rect.setOutlineThickness(4.f);
        }
        window.draw(rect);

        if (i < engine->party.size()) {
            const pokemon& p = engine->party.get_by_index(i);
            sf::Sprite sprite;
            sprite.setTexture(engine->cache.get(p.getNumber()));
            sf::FloatRect b = sprite.getLocalBounds();
            if(b.width > 0 && b.height > 0) sprite.setScale(rect.getSize().x / b.width, rect.getSize().y / b.height);
            sprite.setPosition(rect.getPosition());
            window.draw(sprite);
        }
    }

    // SÉPARATION
    sf::RectangleShape sep(sf::Vector2f(window.getSize().x, 4.f));
    sep.setPosition(0.f, layout.attack_slots[0].bounds.top - 20.f);
    sep.setFillColor(sf::Color(50, 50, 50));
    window.draw(sep);

    // DESSIN ATTAQUE
    for (std::size_t i = 0; i < pokemon_attack::MAX_SIZE; ++i) {
        if (i >= layout.attack_slots.size()) break;

        sf::RectangleShape rect(sf::Vector2f(layout.attack_slots[i].bounds.width, layout.attack_slots[i].bounds.height));
        rect.setPosition(layout.attack_slots[i].bounds.left, layout.attack_slots[i].bounds.top);

        if (placing_attack_index == static_cast<int>(i)) {
            rect.setFillColor(sf::Color(255, 255, 150));
            rect.setOutlineColor(sf::Color(255, 200, 0)); rect.setOutlineThickness(4.f);
        } else {
            rect.setFillColor(sf::Color(220, 150, 150));
            rect.setOutlineColor(sf::Color(100, 50, 50)); rect.setOutlineThickness(2.f);
            if (placing_attack_index == -1 && static_cast<int>(i) == hovered_attack && i < engine->attack_team.size()) {
                rect.setOutlineColor(sf::Color(0, 200, 255)); rect.setOutlineThickness(4.f);
            }
        }
        window.draw(rect);

        if (i < engine->attack_team.size()) {
            const pokemon& p = engine->attack_team.get_by_index(i);
            sf::Sprite sprite;
            sprite.setTexture(engine->cache.get(p.getNumber()));
            if(sf::FloatRect b = sprite.getLocalBounds(); b.width > 0 && b.height > 0) sprite.setScale(rect.getSize().x / b.width, rect.getSize().y / b.height);
            sprite.setPosition(rect.getPosition());
            window.draw(sprite);
        }
    }
}