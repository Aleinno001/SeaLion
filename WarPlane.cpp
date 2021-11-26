//
// Created by alessandro on 12/10/21.
//
#include "WarPlane.h"
bool WarPlane::setUpSprite(const std::string &textureName){
    std::string currentDir = ToolBox::GetCurrentWorkingDir();
    std::string unitTestingPath = "UnitTesting";
    std::size_t found = currentDir.find(unitTestingPath);
if (found != std::string::npos) {
    currentDir.erase(found);
    currentDir.pop_back();
}
std::string textPath;
textPath = currentDir + "/../Res/"+nationality+"/WarPlanes/" + textureName + ".png";
if (!Collision::CreateTextureAndBitmask(texture, textPath)) {
    throw std::runtime_error("Path to tile filename invalid!!");
}
texture.setSmooth(true);
sprite.setTexture(texture);
sprite.setTextureRect(sf::IntRect(0, 0, width, length));
return true;
}
