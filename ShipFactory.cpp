//
// Created by pala on 7/2/21.
//

#include "ShipFactory.h"


std::unique_ptr<WarShip> ShipFactory::createSubmarine(ModelType type) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAircraftCarrier(ModelType type) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createCruiser(ModelType type) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createBattleship(ModelType type) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createDestroyer(ModelType type) {
    return std::unique_ptr<WarShip>();
}
