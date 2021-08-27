//
// Created by alessandro on 04/07/21.
//

#include "AirplaneFactory.h"
#include "Bomber.h"

std::unique_ptr<Vehicle> AirplaneFactory::createBomber(int posX, int posY,WarPlanes &subject) {

    std::unique_ptr<Bomber> bomber(new Bomber());
    return std::move(bomber);
}

std::unique_ptr<Vehicle> AirplaneFactory::createTorpedoBomber(int posX, int posY,WarPlanes &subject) {

    return ;
}

std::unique_ptr<Vehicle> AirplaneFactory::createFighter(int posX, int posY,WarPlanes &subject) {

    return ;
}
