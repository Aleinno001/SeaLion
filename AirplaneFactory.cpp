//
// Created by alessandro on 04/07/21.
//

#include "AirplaneFactory.h"
#include "Bomber.h"
#include "TorpedoBomber.h"
#include "Fighter.h"

std::unique_ptr<Vehicle> AirplaneFactory::createBomber(int posX, int posY,WarShip &subject) {

    std::unique_ptr<Bomber> bomber(new Bomber(posX,posY,3,60,500,26,35,true,150,900,"Bomber",subject));
    return std::move(bomber);

}

std::unique_ptr<Vehicle> AirplaneFactory::createTorpedoBomber(int posX, int posY,WarShip &subject) {

    std::unique_ptr<TorpedoBomber> torpedoBomber(new TorpedoBomber(posX,posY,4,70,400,35,35,true,20,1500,"TorpedoBomber",subject));
    return std::move(torpedoBomber);
}

std::unique_ptr<Vehicle> AirplaneFactory::createFighter(int posX, int posY,WarShip &subject) {

    std::unique_ptr<Fighter> fighter(new Fighter(posX,posY,5,80,300,27,15,true,"Fighter",subject));
    return std::move(fighter);

}
