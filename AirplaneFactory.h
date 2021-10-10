//
// Created by davide on 04/07/21.
//

#ifndef SEALION_AIRPLANEFACTORY_H
#define SEALION_AIRPLANEFACTORY_H


#include <memory>
#include "AbstractAirplaneFactory.h"

class AirplaneFactory : public AbstractAirplaneFactory {
public:
    std::unique_ptr<ConcreteWarPlane> createFighter(int posX, int posY,std::string nat,WarShip &subject) override;
    std::unique_ptr<ConcreteWarPlane> createBomber(int posX, int posY,std::string nat,WarShip &subject) override;
    std::unique_ptr<ConcreteWarPlane> createTorpedoBomber(int posX, int posY,std::string nat,WarShip &subject) override;
    virtual ~AirplaneFactory() = default;
};


#endif //SEALION_AIRPLANEFACTORY_H
