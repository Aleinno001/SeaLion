//
// Created by davide on 04/07/21.
//

#ifndef SEALION_ABSTRACTBONUSFACTORY_H
#define SEALION_ABSTRACTBONUSFACTORY_H


#include "Bonus.h"

class AbstractBonusFactory {
public:
    virtual std::unique_ptr<Bonus> createRadar() = 0;

    virtual std::unique_ptr<Bonus> createQuickRepair() = 0;

    virtual std::unique_ptr<Bonus> createSonar() = 0;

    virtual std::unique_ptr<Bonus> createFireExtinguisher() = 0;

    virtual std::unique_ptr<Bonus> createSpeedBoost() = 0;

    virtual std::unique_ptr<Bonus> createSmokeScreen() = 0;
};


#endif //SEALION_ABSTRACTBONUSFACTORY_H
