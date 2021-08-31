//
// Created by alessandro on 04/07/21.
//

#include "AirplaneFactory.h"
#include "Bomber.h"
#include "TorpedoBomber.h"
#include "Fighter.h"

std::unique_ptr<Vehicle> AirplaneFactory::createBomber(int posX, int posY,WarShip &subject) {

    std::unique_ptr<Bomber> bomber(new Bomber(posX,posY,3,60,500,26,35,true,300,900,"Bomber",subject));
    return std::move(bomber);

}

std::unique_ptr<Vehicle> AirplaneFactory::createTorpedoBomber(int posX, int posY,WarShip &subject) {

    std::unique_ptr<TorpedoBomber> torpedoBomber(new Bomber(posX,posY,3,60,500,26,35,true,300,900,"Bomber",subject));
    return std::move(torpedoBomber);
}

std::unique_ptr<Vehicle> AirplaneFactory::createFighter(int posX, int posY,WarShip &subject) {


}
