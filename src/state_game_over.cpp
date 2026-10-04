//
// Created by npolo on 05/10/2026.
//

#include "state_game_over.h"
#include "game_engine.h"
#include "state_title.h"

state_game_over::state_game_over(game_engine* engine) : game_state(engine) {
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {}

    text_go.setFont(font);
    text_go.setString("GAME OVER\n\nAppuyez sur ESPACE pour revenir a l'ecran titre");
    text_go.setCharacterSize(30);
    text_go.setFillColor(sf::Color::White);
    text_go.setPosition(100.f, 250.f);
}

void state_game_over::handle_event(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
        // Redémarre le jeu à l'accueil
        engine->change_state(std::make_unique<state_title>(engine));
    }
}
void state_game_over::update() {}
void state_game_over::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    window.draw(text_go);
}