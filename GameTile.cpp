//
// Created by pala on 7/4/21.
//

#include "GameTile.h"

bool GameTile::setUpSprite(std::string textureName) {
    if (!texture.loadFromFile(textureName)) {
        throw std::runtime_error("Path to tile filename invalid!!");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
    return true;
}

GameTile::GameTile(std::string textureName, int x, int y, bool collision, bool exit, TileType tp) {
    setUpSprite(textureName);
    pos = sf::Vector2f(x, y);
    sprite.setPosition(pos);
    isPassable = collision;
    isExit = exit;
    tileType = tp;

}

