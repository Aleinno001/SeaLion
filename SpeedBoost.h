//
// Created by alessandro on 02/07/21.
//

#ifndef SEALION_SPEEDBOOST_H
#define SEALION_SPEEDBOOST_H

#include "Bonus.h"

class SpeedBoost : public Bonus {

private:
    int uses;
    float duration;
    float multiplier;

public:
    SpeedBoost(WarShip *m, float c, int u, float d, float mult) : Bonus(m, c), uses(u), duration(d),
                                                                  multiplier(mult) {};

    ~SpeedBoost() override;

    int getUses() const;

    float getDuration() const;

    float getMultiplier() const;

    void activate() override;
};


#endif //SEALION_SPEEDBOOST_H
