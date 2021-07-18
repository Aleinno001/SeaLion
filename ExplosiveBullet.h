//
// Created by davide on 18/07/21.
//

#ifndef SEALION_EXPLOSIVEBULLET_H
#define SEALION_EXPLOSIVEBULLET_H


#include "Bullet.h"

class ExplosiveBullet : public Bullet {
private:
    float dmgMult = {1.3};
    float speedMult{0.8};
    float penetrationMult{0.8};
public:
    float getDmgMult() const;

    float getSpeedMult() const;

    float getPenetrationMult() const;
};


#endif //SEALION_EXPLOSIVEBULLET_H