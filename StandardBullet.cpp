//
// Created by davide on 18/07/21.
//

#include <string>
#include "StandardBullet.h"

float StandardBullet::getDmgMult() const {
    return dmgMult;
}

float StandardBullet::getSpeedMult() const {
    return speedMult;
}

float StandardBullet::getPenetrationMult() const {
    return penetrationMult;
}

StandardBullet::StandardBullet(
        const std::__cxx11::basic_string<char> &bulletName, int width, int length) : Bullet(
        bulletName, width,
        length){}
