//
// Created by davide on 18/07/21.
//

#include "ExplosiveBullet.h"

float ExplosiveBullet::getDmgMult() const {
    return dmgMult;
}

float ExplosiveBullet::getSpeedMult() const {
    return speedMult;
}

float ExplosiveBullet::getPenetrationMult() const {
    return penetrationMult;
}

ExplosiveBullet::ExplosiveBullet(const std::string &bulletName, int width, int length) : Bullet(bulletName, width, length) {}
