//
// Created by npolo on 05/10/2026.
//

#ifndef TP_STATE_EXPLORATION_H
#define TP_STATE_EXPLORATION_H

#include "game_state.h"
#include <SFML/Graphics.hpp>

class state_exploration : public game_state {
private:
    sf::Font font;
    sf::Text text_info;

public:
    explicit state_exploration(game_engine* engine);
    void handle_event(const sf::Event& event) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;
};

#endif //TP_STATE_EXPLORATION_H