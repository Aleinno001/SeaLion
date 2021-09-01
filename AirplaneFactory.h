//
// Created by davide on 04/07/21.
//

#ifndef SEALION_AIRPLANEFACTORY_H
#define SEALION_AIRPLANEFACTORY_H


#include <memory>
#include "AbstractAirplaneFactory.h"
#include "Vehicle.h"

class AirplaneFactory : public AbstractAirplaneFactory {
public:
    std::unique_ptr<Vehicle> createFighter(int posX, int posY,std::string nat,WarShip &subject) override;

    std::unique_ptr<Vehicle> createBomber(int posX, int posY,std::string nat,WarShip &subject) override;

    std::unique_ptr<Vehicle> createTorpedoBomber(int posX, int posY,std::string nat,WarShip &subject) override;
};


#endif //SEALION_AIRPLANEFACTORY_H
