//
// Created by alessandro on 04/07/21.
//

#include "AirplaneFactory.h"

std::unique_ptr<ConcreteWarPlane> AirplaneFactory::createBomber(int posX, int posY,std::string nat,WarShip &subject) {
    std::unique_ptr<ConcreteWarPlane> bomber(new ConcreteWarPlane(posX,posY,3,60,500,26,35,true,nat,150,900,subject,"Bomber"));
    return std::move(bomber);
}
std::unique_ptr<ConcreteWarPlane> AirplaneFactory::createTorpedoBomber(int posX, int posY,std::string nat,WarShip &subject) {
    std::unique_ptr<ConcreteWarPlane> torpedoBomber(new ConcreteWarPlane(posX,posY,4,70,400,35,35,true,nat,20,1500,subject,"TorpedoBomber"));
    return std::move(torpedoBomber);
}
std::unique_ptr<ConcreteWarPlane> AirplaneFactory::createFighter(int posX, int posY,std::string nat,WarShip &subject) {
    std::unique_ptr<ConcreteWarPlane> fighter(new ConcreteWarPlane(posX,posY,5,80,300,27,15,true,nat,10000,1,subject,"Fighter"));
    return std::move(fighter);
}
