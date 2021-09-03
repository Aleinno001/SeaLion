//
// Created by davide on 02/07/21.
//

#ifndef SEALION_CANNONFACTORY_H
#define SEALION_CANNONFACTORY_H


#include "ArsenalFactory.h"
#include "LightCannon.h"
#include "MediumCannon.h"
#include "HeavlyCannon.h"


class CannonFactory : public ArsenalFactory {
public:
    //TODO implementare i metodi
    std::unique_ptr<Arsenal> createLight(int posX, int posY,WarShip &subject) const override;

    std::unique_ptr<Arsenal> createMedium(int posX, int posY,WarShip &subject) const override;

    std::unique_ptr<Arsenal> createHeavly(int posX, int posY,WarShip &subject) const override;
};


#endif //SEALION_CANNONFACTORY_H
