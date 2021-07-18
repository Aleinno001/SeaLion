//
// Created by davide on 18/07/21.
//

#ifndef SEALION_STANDARDBULLET_H
#define SEALION_STANDARDBULLET_H


#include "Bullet.h"

class StandardBullet : public Bullet {
private:
    float dmgMult = {1};
    float speedMult{1};
    float penetrationMult{1};
public:
    StandardBullet() = default;

    float getDmgMult() const;

    float getSpeedMult() const;

    float getPenetrationMult() const;
};


#endif //SEALION_STANDARDBULLET_H
