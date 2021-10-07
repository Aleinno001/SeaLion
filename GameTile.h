//
// Created by alessandro on 7/4/21.
//

#ifndef SEALION_GAMETILE_H
#define SEALION_GAMETILE_H

#include <SFML/Graphics.hpp>

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameTile.h"
#include <string>
#include <memory>
#include <list>
#include "Dice.h"
#include <iostream>
#include "ToolBox.h"

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
    GameTile() = default;
    GameTile(std::string textureName, int x, int y, bool collision, bool exit, TileType tp);
    bool setUpSprite(std::string textureName);
    void setIsPassable(bool isPassable);
    void setPos(const sf::Vector2f &pos);
    void setTexture(const sf::Texture &texture);
    void setTileType(TileType tileType);
    const sf::Vector2f &getPos() const;
    const sf::Sprite &getSprite() const;
    TileType getTileType() const;
    GameTile * getInstance();
    ~GameTile() = default;
};


#endif //SEALION_GAMETILE_H
