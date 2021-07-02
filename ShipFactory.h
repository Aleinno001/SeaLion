//
// Created by pala on 7/2/21.
//

#ifndef SEALION_SHIPFACTORY_H
#define SEALION_SHIPFACTORY_H


#include "AbstractShipFactory.h"

class ShipFactory : public AbstractShipFactory {
public:
    std::unique_ptr<WarShip> createSubmarine(ModelType type) override;

    std::unique_ptr<WarShip> createAircraftCarrier(ModelType type) override;

    std::unique_ptr<WarShip> createCruiser(ModelType type) override;

    std::unique_ptr<WarShip> createBattleship(ModelType type) override;

    std::unique_ptr<WarShip> createDestroyer(ModelType type) override;

};


#endif //SEALION_SHIPFACTORY_H
