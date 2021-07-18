//
// Created by pala on 02/07/21.
//

#include "CannonFactory.h"

std::unique_ptr<Arsenal> CannonFactory::createLight() const {
    std::unique_ptr<LightCannon> lightCannon();
    return std::move();
}

std::unique_ptr<Arsenal> CannonFactory::createMedium() const {

    return std::move();
}

std::unique_ptr<Arsenal> CannonFactory::createHeavly() const {

    return std::move();
}
