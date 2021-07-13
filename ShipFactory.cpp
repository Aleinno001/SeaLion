//
// Created by pala on 7/2/21.
//

#include "ShipFactory.h"



std::unique_ptr<WarShip> ShipFactory::createSubmarine(ModelType type) {

    switch (type) {

        case ModelType::I400:
            //std::unique_ptr<Submarine> i400(new Submarine()); //TODO da concludere
            break;

        case ModelType::typeb1:

            break;

        case ModelType::DaVinci:

            break;

        case ModelType::Papa:

            break;

        case ModelType::Triton:

            break;

        case ModelType::Trenchant:

            break;

        case ModelType::Gato:

            break;

        case ModelType::Narwhal:

            break;
    }

}

std::unique_ptr<WarShip> ShipFactory::createAircraftCarrier(ModelType type) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createCruiser(ModelType type) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createBattleship(ModelType type) {
    return std::unique_ptr<WarShip>(); //TODO implementare tutti i costruttori
}

std::unique_ptr<WarShip> ShipFactory::createDestroyer(ModelType type) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedSubmarine(ModelType type) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedAircraftCarrier(ModelType type) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedCruiser(ModelType type) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedBattleship(ModelType type) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedDestroyer(ModelType type) {
    return std::unique_ptr<WarShip>();
}
