//
// Created by pala on 7/4/21.
//

#ifndef SEALION_GAMETILE_H
#define SEALION_GAMETILE_H

#include <SFML/Graphics.hpp>

enum class TileType {
    Sea,
    Wave,
    Fog,
    Dirt,
    Whirlpool
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

    void setIsPassable(bool isPassable);

    void setIsExit(bool isExit);

    void setPos(const sf::Vector2f &pos);

    void setTexture(const sf::Texture &texture);

    void setSprite(const sf::Sprite &sprite);

    void setTileType(TileType tileType);
};


#endif //SEALION_GAMETILE_H
