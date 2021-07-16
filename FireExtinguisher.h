//
// Created by alessandro on 02/07/21.
//

#ifndef SEALION_FIREEXTINGUISHER_H
#define SEALION_FIREEXTINGUISHER_H

#include "Bonus.h"

class FireExtinguisher : public Bonus {

private:
    int uses;

public:
    FireExtinguisher(WarShip *m, float c, int u) : Bonus(m, c), uses(u) {};

    ~FireExtinguisher() override;

    int getUses() const;

    void activate() override;

};


#endif //SEALION_FIREEXTINGUISHER_H
