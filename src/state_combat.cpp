//
// Created by npolo on 05/10/2026.
//

#include "state_combat.h"
#include "game_engine.h"
#include "state_exploration.h"
#include "state_game_over.h"

state_combat::state_combat(game_engine* engine) : game_state(engine) {
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {}

    text_info.setFont(font);
    text_info.setString("UN POKEMON SAUVAGE APPARAIT !\n\n"
                        "[V] -> Simuler une Victoire (Retour a l'exploration)\n"
                        "[D] -> Simuler une Defaite de toute l'equipe (Game Over)\n");
    text_info.setCharacterSize(24);
    text_info.setFillColor(sf::Color::White);
    text_info.setPosition(50.f, 250.f);
}

void state_combat::handle_event(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::V) {
            engine->change_state(std::make_unique<state_exploration>(engine));
        } else if (event.key.code == sf::Keyboard::D) {
            engine->change_state(std::make_unique<state_game_over>(engine));
        }
    }
}
void state_combat::update() {}
void state_combat::draw(sf::RenderWindow& window) {
    window.clear(sf::Color(150, 50, 50));
    window.draw(text_info);
}