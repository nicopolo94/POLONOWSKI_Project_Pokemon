//
// Created by npolo on 25/09/2026.
//

#include "texture_cache.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>

#ifndef DATA_DIR
#define DATA_DIR "./data"
#endif

texture_cache::texture_cache() {
    // Crée un carré magenta comme texture de secours (si l'image manque)
    sf::Image img;
    img.create(64, 64, sf::Color::Magenta);
    fallback.loadFromImage(img);
}

const sf::Texture& texture_cache::get(const int number) {
    const std::string key = std::to_string(number);
    if (cache.contains(key)) {
        return cache[key];
    }

    sf::Texture tex;
    std::vector<std::string> paths;

    paths.push_back(std::string(DATA_DIR) + "/pokemon/" + std::to_string(number) + ".png");

    for (const auto& p : paths) {
        if (tex.loadFromFile(p)) {
            cache[key] = tex;
            return cache[key];
        }
    }

    // Si aucune image n'est trouvée, renvoie la texture de secours
    cache[key] = fallback;
    return cache[key];
}