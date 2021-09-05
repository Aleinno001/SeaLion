//
// Created by alessandro on 04/09/21.
//

#include "Explosion.h"


Explosion::Explosion(sf::Vector2f pos) {
    setUpSprite();
    resetOrigin();
    sprite.setPosition(pos);
}

bool Explosion::setUpSprite() {
    std::string currentDir = CurrentDir::GetCurrentWorkingDir();
    std::string unitTestingPath = "UnitTesting";
    std::size_t found = currentDir.find(unitTestingPath);
    if (found != std::string::npos) {
        currentDir.erase(found);
        currentDir.pop_back();
    }
    std::string textPath;
    textPath = currentDir + "/../Res/Animations/" + "explosion.png";
    if (!texture.loadFromFile(textPath)) {
        throw std::runtime_error("Path to tile filename invalid!!");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 7, 7));
    return true;
}

void Explosion::resetOrigin() {
    sprite.setOrigin(4, 4);
}

void Explosion::setFrame(int numFrame, sf::Vector2f pos) {
    sprite.setTextureRect(sf::IntRect(7 * numFrame, 0, 7 + 7 * numFrame, 7));
    sprite.setPosition(pos);
}

const sf::Sprite &Explosion::getSprite() const {
    return sprite;
}


