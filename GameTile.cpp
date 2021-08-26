//
// Created by alessandro on 7/4/21.
//

#include "GameTile.h"


bool GameTile::setUpSprite(std::string textureName) {
    std::string currentDir = CurrentDir::GetCurrentWorkingDir();
    std::string unitTestingPath = "UnitTesting";
    std::size_t found = currentDir.find(unitTestingPath);
    if (found != std::string::npos) {
        currentDir.erase(found);
        currentDir.pop_back();
    }
    textureName = currentDir + "/../Res/Tiles/" + textureName;
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

void GameTile::setIsPassable(bool isPassable) {
    GameTile::isPassable = isPassable;
}

void GameTile::setIsExit(bool isExit) {
    GameTile::isExit = isExit;
}

void GameTile::setPos(const sf::Vector2f &pos) {
    GameTile::pos = pos;
}

void GameTile::setTexture(const sf::Texture &texture) {
    GameTile::texture = texture;
}

void GameTile::setSprite(const sf::Sprite &sprite) {
    GameTile::sprite = sprite;
}

void GameTile::setTileType(TileType tileType) {
    GameTile::tileType = tileType;
}

const sf::Vector2f &GameTile::getPos() const {
    return pos;
}

const sf::Texture &GameTile::getTexture() const {
    return texture;
}

const sf::Sprite &GameTile::getSprite() const {
    return sprite;
}

TileType GameTile::getTileType() const {
    return tileType;
}

bool GameTile::getIsPassable() const {
    return isPassable;
}

