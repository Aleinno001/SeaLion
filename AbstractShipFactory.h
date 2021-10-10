//
// Created by alessandro on 7/2/21.
//

#ifndef SEALION_ABSTRACTSHIPFACTORY_H
#define SEALION_ABSTRACTSHIPFACTORY_H


#include "ConcreteWarShip.h"
#include "SFML/Graphics.hpp"
#include "Dice.h"
#include "MvcController.h"


class GameWorld;
class AbstractShipFactory {
public:
    virtual std::shared_ptr<WarShip> createSubmarine(ModelType type, int height, int  width) = 0;
    virtual std::shared_ptr<WarShip> createAircraftCarrier(ModelType type, int height, int  width) = 0;
    virtual std::shared_ptr<WarShip> createCruiser(ModelType type, int height, int  width) = 0;
    virtual std::shared_ptr<WarShip> createBattleship(ModelType type, int height, int  width) = 0;
    virtual std::shared_ptr<WarShip> createDestroyer(ModelType type, int height, int  width) = 0;
    virtual std::shared_ptr<WarShip> createAlliedSubmarine(ModelType type, int height, int  width) = 0;
    virtual std::shared_ptr<WarShip> createAlliedAircraftCarrier(ModelType type, int height, int  width) = 0;
    virtual std::shared_ptr<WarShip> createAlliedCruiser(ModelType type, int height, int  width) = 0;
    virtual std::shared_ptr<WarShip> createAlliedBattleship(ModelType type, int height, int  width) = 0;
    virtual std::shared_ptr<WarShip> createAlliedDestroyer(ModelType type, int height, int  width) = 0;
    virtual ~AbstractShipFactory() = default;
};


#endif //SEALION_ABSTRACTSHIPFACTORY_H
