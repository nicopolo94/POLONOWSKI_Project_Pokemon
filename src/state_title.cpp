//
// Created by npolo on 05/10/2026.
//

#include "state_title.h"
#include "game_engine.h"
#include "state_exploration.h"
#include <iostream>

state_title::state_title(game_engine* engine) : game_state(engine) {
    // Tente de charger la police système par défaut de Linux/WSL
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        std::cerr << "Attention : Police d'ecriture non trouvee.\n";
    }

    text_title.setFont(font);
    text_title.setString("PROJET POKEMON");
    text_title.setCharacterSize(50);
    text_title.setFillColor(sf::Color::Yellow);
    
    text_title.setPosition(180.f, 200.f);

    text_prompt.setFont(font);
    text_prompt.setString("Appuyez sur ESPACE ou CLIQUEZ pour commencer");
    text_prompt.setCharacterSize(24);
    text_prompt.setFillColor(sf::Color::White);
    text_prompt.setPosition(100.f, 400.f);
}

void state_title::handle_event(const sf::Event& event) {
    // Si on clique ou qu'on appuie sur une touche, on passe à l'exploration
    if (event.type == sf::Event::KeyPressed ||
       (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)) {

        engine->change_state(std::make_unique<state_exploration>(engine));
       }
}

void state_title::update() {
    // Rien à mettre à jour sur l'écran titre
}

void state_title::draw(sf::RenderWindow& window) {
    window.clear(sf::Color(50, 50, 150));
    window.draw(text_title);
    window.draw(text_prompt);
}