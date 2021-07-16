//
// Created by pala on 04/07/21.
//

#ifndef SEALION_AIRPLANEFACTORY_H
#define SEALION_AIRPLANEFACTORY_H


#include <memory>
#include "AbstractAirplaneFactory.h"
#include "Vehicle.h"

class AirplaneFactory : public AbstractAirplaneFactory {
public:
    std::unique_ptr<Vehicle> createFighter() override;

    std::unique_ptr<Vehicle> createBomber() override;

    std::unique_ptr<Vehicle> createTorpedoBomber() override;
};


#endif //SEALION_AIRPLANEFACTORY_H
