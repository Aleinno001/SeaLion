//
// Created by pala on 7/4/21.
//

#include "GameTile.h"

bool GameTile::setUpSprite(std::string textureName) {
    if (!texture.loadFromFile(textureName)) {
        return false; //TODO usare poi l'eccezioni per gestire la lettura da file
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    return true;
}

GameTile::GameTile(std::string textureName, float x, float y, bool collision, bool exit) {
    if (!setUpSprite(textureName)) {
        return; //TODO da gestire meglio con le eccezioni
    }
    pos = sf::Vector2f(x, y);
    sprite.setPosition(pos);
    isPassable = collision;
    isExit = exit;


}
