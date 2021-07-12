//
// Created by pala on 02/07/21.
//

#ifndef SEALION_QUICKREPAIR_H
#define SEALION_QUICKREPAIR_H

#include "Bonus.h"

class QuickRepair : public Bonus {

private:
    int uses;

public:
    QuickRepair(WarShip *m, float c, int u) : Bonus(m, c), uses(u) {};

    ~QuickRepair() override;

    int getUses() const;

    void activate() override;

};


#endif //SEALION_QUICKREPAIR_H
