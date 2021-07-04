//
// Created by pala on 7/4/21.
//

#include "GameTile.h"

bool GameTile::setUpSprite(std::string) {
    return false;
}

GameTile::GameTile(std::string textureName, float x, float y, bool collision, bool exit) : pos(sf::Vector2f(x, y)) {

    sprite.setPosition(pos);
    isPassable = collision;


}
