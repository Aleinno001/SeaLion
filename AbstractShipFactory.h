//
// Created by alessandro on 7/2/21.
//

#ifndef SEALION_ABSTRACTSHIPFACTORY_H
#define SEALION_ABSTRACTSHIPFACTORY_H


#include "WarShip.h"
#include "SFML/Graphics.hpp"
#include "Dice.h"
#include "MvcController.h"


class GameWorld;
class AbstractShipFactory {
public:
    virtual std::shared_ptr<WarShip> createSubmarine(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<WarShip> createAircraftCarrier(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<WarShip> createCruiser(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<WarShip> createBattleship(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<WarShip> createDestroyer(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<WarShip> createAlliedSubmarine(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<WarShip> createAlliedAircraftCarrier(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<WarShip> createAlliedCruiser(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<WarShip> createAlliedBattleship(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<WarShip> createAlliedDestroyer(ModelType type, GameWorld &map) = 0;
};


#endif //SEALION_ABSTRACTSHIPFACTORY_H
