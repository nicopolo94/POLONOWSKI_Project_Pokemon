//
// Created by npolo on 05/10/2026.
//

#include "state_exploration.h"
#include "game_engine.h"

state_exploration::state_exploration(game_engine* engine) : game_state(engine) {
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {}

    text_info.setFont(font);
    text_info.setString("Mode Exploration (Le monde sauvage)\n\n"
                        "-> Appuyez sur 'T' pour gerer votre equipe\n"
                        "-> Appuyez sur 'E' pour chercher un combat\n");
    text_info.setCharacterSize(24);
    text_info.setFillColor(sf::Color::White);
    text_info.setPosition(50.f, 250.f);
}

void state_exploration::handle_event(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::T) {
            // TODO (Prochain commit) : Aller vers l'écran de sélection de la partie 1.3
        } else if (event.key.code == sf::Keyboard::E) {
            // TODO (Prochain commit) : Aller vers un combat
        }
    }
}

void state_exploration::update() {}

void state_exploration::draw(sf::RenderWindow& window) {
    window.clear(sf::Color(34, 139, 34));
    window.draw(text_info);
}