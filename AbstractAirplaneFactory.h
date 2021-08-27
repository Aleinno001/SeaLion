//
// Created by alessandro on 04/07/21.
//

#ifndef SEALION_ABSTRACTAIRPLANEFACTORY_H
#define SEALION_ABSTRACTAIRPLANEFACTORY_H

#include "Vehicle.h"
#include "WarPlanes.h"

class AbstractAirplaneFactory {
public:
    virtual std::unique_ptr<Vehicle> createFighter(int posX, int posY,WarPlanes &subject) = 0;

    virtual std::unique_ptr<Vehicle> createBomber(int posX, int posY,WarPlanes &subject) = 0;

    virtual std::unique_ptr<Vehicle> createTorpedoBomber(int posX, int posY,WarPlanes &subject) = 0;
};

#endif //SEALION_ABSTRACTAIRPLANEFACTORY_H
