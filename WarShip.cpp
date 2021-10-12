//
// Created by alessandro on 12/10/21.
//
#include "WarShip.h"
bool WarShip::setUpSprite(const std::string &textureName) {
std::string currentDir = ToolBox::GetCurrentWorkingDir();
std::string unitTestingPath = "UnitTesting";
std::size_t found = currentDir.find(unitTestingPath);
if (found != std::string::npos) {
currentDir.erase(found);
currentDir.pop_back();
}
std::string textPath;
std::string model;
switch (shipType) {
case ShipType::AircraftCarrier:
{model="AircraftCarrier";}
break;
case ShipType::Destroyer:
{model="Destroyer";}
break;
case ShipType::Battleship:
{model="Battleship";}
break;
case ShipType::Submarine:
{model="Submarines";}
break;
case ShipType::Cruiser:
{model="Cruiser";}
break;
}
textPath = currentDir + "/../Res/"+nationality+"/"+model+"/" + textureName + ".png";
if (!Collision::CreateTextureAndBitmask(texture, textPath)) {
throw std::runtime_error("Path to tile filename invalid!!");
}
texture.setSmooth(true);
sprite.setTexture(texture);
sprite.setTextureRect(sf::IntRect(0, 0, width, length));
return true;
}
