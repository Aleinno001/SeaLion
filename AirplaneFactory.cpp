//
// Created by davide on 04/07/21.
//

#include "AirplaneFactory.h"

std::unique_ptr<Vehicle> AirplaneFactory::createBomber() {
    return std::unique_ptr<Vehicle>();
}

std::unique_ptr<Vehicle> AirplaneFactory::createTorpedoBomber() {
    return std::unique_ptr<Vehicle>();
}

std::unique_ptr<Vehicle> AirplaneFactory::createFighter() {
    return std::unique_ptr<Vehicle>();
}
