//
// Created by pala on 9/4/21.
//

#include "BarInterface.h"
#include "CurrentDir.h"
#include "Collision.h"

BarInterface::BarInterface(){
    setUpSprite("lifeBar");
}

bool BarInterface::setUpSprite(std::string textureName) {
    std::string currentDir = CurrentDir::GetCurrentWorkingDir();
    std::string unitTestingPath = "UnitTesting";
    std::size_t found = currentDir.find(unitTestingPath);
    if (found != std::string::npos) {
        currentDir.erase(found);
        currentDir.pop_back();
    }
    textureName = currentDir + "/../Res/Tiles/" + textureName + ".png";
    if (!Collision::CreateTextureAndBitmask(textureLife,textureName)) {
        throw std::runtime_error("Path to tile filename invalid!!");
    }
    textureLife.setSmooth(true);
    life.setTexture(textureLife);
    life.setTextureRect(sf::IntRect(0, 0, 10, 20));
    return true;
}

const sf::Sprite &BarInterface::getSprite() const {
    return life;
}
