//
// Created by alessandro on 04/07/21.
//

#ifndef SEALION_ABSTRACTAIRPLANEFACTORY_H
#define SEALION_ABSTRACTAIRPLANEFACTORY_H

#include "ConcreteWarPlane.h"
#include "ConcreteWarShip.h"


class AbstractAirplaneFactory {
public:
    virtual std::unique_ptr<ConcreteWarPlane> createFighter(int posX, int posY,std::string nat,ConcreteWarShip &subject) = 0;
    virtual std::unique_ptr<ConcreteWarPlane> createBomber(int posX, int posY,std::string nat,ConcreteWarShip &subject) = 0;
    virtual std::unique_ptr<ConcreteWarPlane> createTorpedoBomber(int posX, int posY,std::string nat,ConcreteWarShip &subject) = 0;
};
#endif //SEALION_ABSTRACTAIRPLANEFACTORY_H
