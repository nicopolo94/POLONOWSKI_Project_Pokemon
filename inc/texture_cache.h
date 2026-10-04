//
// Created by npolo on 25/09/2026.
//

#ifndef TP_TEXTURE_CACHE_H
#define TP_TEXTURE_CACHE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class texture_cache {
private:
    std::unordered_map<std::string, sf::Texture> cache;
    sf::Texture fallback; // Texture par défaut si l'image est introuvable

public:
    texture_cache();

    // Tente de charger la texture d'un Pokémon selon son numéro
    const sf::Texture& get(int number);
};

#endif //TP_TEXTURE_CACHE_H