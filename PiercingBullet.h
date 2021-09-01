//
// Created by davide on 18/07/21.
//

#ifndef SEALION_PIERCINGBULLET_H
#define SEALION_PIERCINGBULLET_H


#include <string>
#include "Bullet.h"

class PiercingBullet : public Bullet {
private:
    float dmgMult = {0.8};
    float speedMult{1.3};
    float penetrationMult{1.3};
public:
    PiercingBullet(const std::string &bulletName, int width, int length);

    float getDmgMult() const;

    float getSpeedMult() const;

    float getPenetrationMult() const;
};


#endif //SEALION_PIERCINGBULLET_H
