//
// Created by pala on 7/2/21.
//

#ifndef SEALION_SHIPFACTORY_H
#define SEALION_SHIPFACTORY_H


#include "AbstractShipFactory.h"
#include "WarShip.h"
#include "ArsenalFactory.h"
#include "Submarine.h"
#include "Dice.h"

class ShipFactory : public AbstractShipFactory {

public:
    std::unique_ptr<WarShip> createSubmarine(ModelType type) override;

    std::unique_ptr<WarShip> createAircraftCarrier(ModelType type) override;

    std::unique_ptr<WarShip> createCruiser(ModelType type) override;

    std::unique_ptr<WarShip> createBattleship(ModelType type) override;

    std::unique_ptr<WarShip> createDestroyer(ModelType type) override;

    std::unique_ptr<WarShip> createAlliedSubmarine(ModelType type) override;

    std::unique_ptr<WarShip> createAlliedAircraftCarrier(ModelType type) override;

    std::unique_ptr<WarShip> createAlliedCruiser(ModelType type) override;

    std::unique_ptr<WarShip> createAlliedBattleship(ModelType type) override;

    std::unique_ptr<WarShip> createAlliedDestroyer(ModelType type) override;

    ShipFactory() = default;
};


#endif //SEALION_SHIPFACTORY_H
