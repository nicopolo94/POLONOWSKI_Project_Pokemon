//
// Created by npolo on 05/10/2026.
//

#include "game_engine.h"

game_engine::game_engine(): running(true), window(sf::VideoMode(800, 600), "Pokemon Game") {}

void game_engine::change_state(std::unique_ptr<game_state> state) {
    next_state = std::move(state);
}

void game_engine::quit() {
    running = false;
    window.close();
}

void game_engine::run() {
    while (window.isOpen() && running) {
        // Applique la transition d'état si elle a été demandée
        if (next_state) {
            current_state = std::move(next_state);
        }

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                quit();
            }

            // Délègue la gestion de l'événement à l'état actif
            if (current_state) {
                current_state->handle_event(event);
            }
        }

        // Mise à jour de la logique
        if (current_state) {
            current_state->update();
        }

        // Dessin
        window.clear(sf::Color::Black);
        if (current_state) {
            current_state->draw(window);
        }
        window.display();
    }
}