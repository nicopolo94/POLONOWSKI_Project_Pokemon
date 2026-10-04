//
// Created by npolo on 05/10/2026.
//

#ifndef TP_STATE_TEAM_SELECTION_H
#define TP_STATE_TEAM_SELECTION_H

#include "game_state.h"
#include "selection_layout.h"
#include <SFML/Graphics.hpp>

class state_team_selection : public game_state {
private:
    selection_layout layout;
    int placing_attack_index;
    sf::Font font;
    sf::Text text_escape;

public:
    explicit state_team_selection(game_engine* engine);
    void handle_event(const sf::Event& event) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;
};

#endif //TP_STATE_TEAM_SELECTION_H