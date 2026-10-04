//
// Created by npolo on 05/10/2026.
//

#ifndef TP_STATE_COMBAT_H
#define TP_STATE_COMBAT_H

#include "game_state.h"
#include <SFML/Graphics.hpp>

class state_combat : public game_state {
private:
    sf::Font font;
    sf::Text text_info;

public:
    explicit state_combat(game_engine* engine);
    void handle_event(const sf::Event& event) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;
};

#endif