//
// Created by pala on 9/4/21.
//

#include "LifeBar.h"
#include "Collision.h"


bool LifeBar::setUpSprite(std::string textureName) {
    std::string currentDir = CurrentDir::GetCurrentWorkingDir();
    std::string unitTestingPath = "UnitTesting";
    std::size_t found = currentDir.find(unitTestingPath);
    if (found != std::string::npos) {
        currentDir.erase(found);
        currentDir.pop_back();
    }
    textureName = currentDir + "/../Res/Tiles/" + textureName;
    if (!Collision::CreateTextureAndBitmask(textureLife,textureName)) {
        throw std::runtime_error("Path to tile filename invalid!!");
    }
    textureLife.setSmooth(true);
    life.setTexture(textureLife);
    life.setTextureRect(sf::IntRect(0, 0, 10, 20));
    return true;
}


LifeBar::LifeBar(WarShip &subject) {

}
