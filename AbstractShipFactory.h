//
// Created by pala on 7/2/21.
//

#ifndef SEALION_ABSTRACTSHIPFACTORY_H
#define SEALION_ABSTRACTSHIPFACTORY_H


#include "WarShip.h"


class GameWorld;

class AbstractShipFactory {
public:
    virtual std::unique_ptr<WarShip> createSubmarine(ModelType type, GameWorld &map) = 0;

    virtual std::unique_ptr<WarShip> createAircraftCarrier(ModelType type, GameWorld &map) = 0;

    virtual std::unique_ptr<WarShip> createCruiser(ModelType type, GameWorld &map) = 0;

    virtual std::unique_ptr<WarShip> createBattleship(ModelType type, GameWorld &map) = 0;

    virtual std::unique_ptr<WarShip> createDestroyer(ModelType type, GameWorld &map) = 0;

    virtual std::unique_ptr<WarShip> createAlliedSubmarine(ModelType type) = 0;

    virtual std::unique_ptr<WarShip> createAlliedAircraftCarrier(ModelType type) = 0;

    virtual std::unique_ptr<WarShip> createAlliedCruiser(ModelType type) = 0;

    virtual std::unique_ptr<WarShip> createAlliedBattleship(ModelType type) = 0;

    virtual std::unique_ptr<WarShip> createAlliedDestroyer(ModelType type) = 0;


};


#endif //SEALION_ABSTRACTSHIPFACTORY_H
