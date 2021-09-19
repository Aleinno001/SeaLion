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
    virtual std::shared_ptr<ConcreteWarShip> createSubmarine(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<ConcreteWarShip> createAircraftCarrier(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<ConcreteWarShip> createCruiser(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<ConcreteWarShip> createBattleship(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<ConcreteWarShip> createDestroyer(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<ConcreteWarShip> createAlliedSubmarine(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<ConcreteWarShip> createAlliedAircraftCarrier(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<ConcreteWarShip> createAlliedCruiser(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<ConcreteWarShip> createAlliedBattleship(ModelType type, GameWorld &map) = 0;
    virtual std::shared_ptr<ConcreteWarShip> createAlliedDestroyer(ModelType type, GameWorld &map) = 0;
};


#endif //SEALION_ABSTRACTSHIPFACTORY_H
