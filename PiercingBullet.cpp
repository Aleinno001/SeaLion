//
// Created by davide on 18/07/21.
//

#include "PiercingBullet.h"

float PiercingBullet::getDmgMult() const {
    return dmgMult;
}

float PiercingBullet::getSpeedMult() const {
    return speedMult;
}

float PiercingBullet::getPenetrationMult() const {
    return penetrationMult;
}

PiercingBullet::PiercingBullet(const std::string &bulletName, int width, int length) : Bullet(bulletName, width,
                                                                                              length) {}
