//
// Created by davide on 02/07/21.
//

#ifndef SEALION_BONUS_H
#define SEALION_BONUS_H

#include "WarShip.h"

class Bonus {

private:
    WarShip *model;

protected:
    float cooldown;

public:
    Bonus(WarShip *m, float c) : model(m), cooldown(c) {};

    virtual ~Bonus();

    float getCooldown() const;

    virtual void activate() = 0;
};


#endif //SEALION_BONUS_H
