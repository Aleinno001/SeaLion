//
// Created by pala on 7/4/21.
//

#ifndef SEALION_GAMETILE_H
#define SEALION_GAMETILE_H

#include <SFML/Graphics.hpp>

enum class TileType {
    Sea,
    Wave,
    Fog
};

class GameTile {
public:
    bool isPassable;
    bool isExit;
    sf::Vector2f pos;
    sf::Texture texture;
    sf::Sprite sprite;
    TileType tileType;
public:

    GameTile(std::string textureName, int x, int y, bool collision, bool exit, TileType tp);

    bool setUpSprite(std::string textureName);
};


#endif //SEALION_GAMETILE_H
