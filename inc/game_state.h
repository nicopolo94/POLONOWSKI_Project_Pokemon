//
// Created by npolo on 05/10/2026.
//

#ifndef TP_GAME_STATE_H
#define TP_GAME_STATE_H

#include <SFML/Graphics.hpp>

class game_engine;

class game_state {
protected:
    // Pointeur vers le moteur de jeu pour pouvoir accéder à la Party ou changer d'état
    game_engine* engine;

public:
    explicit game_state(game_engine* engine) : engine(engine) {}
    virtual ~game_state() = default;

    virtual void handle_event(const sf::Event& event) = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif //TP_GAME_STATE_H
