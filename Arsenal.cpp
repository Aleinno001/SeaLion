//
// Created by gabriele on 7/2/21.
//

#include "Arsenal.h"

//getter
const float Arsenal::getRangeOfFire() const {
    return rangeOfFire;
}

const int Arsenal::getReloadTime() const {
    return reloadTime;
}

const int Arsenal::getRateOfFire() const {
    return rateOfFire;
}

int Arsenal::getAmmoSpeed() const {
    return ammoSpeed;
}

int Arsenal::getMaximumDispersion() const {
    return maximumDispersion;
}

const std::string &Arsenal::getAmmoType() const {
    return ammoType;
}

float Arsenal::getAmmoDeceleration() const {
    return ammoDeceleration;
}

int Arsenal::getFirepower() const {
    return firepower;
}

int Arsenal::getNumAmmo() const {
    return numAmmo;
}

Arsenal::Arsenal(const float range, const int reload, const int rate, int speed, int dispersion, std::string type,
                 float decelleration, int power, int num, int posX, int posY, int le, int wi,
                 std::string texName) : rangeOfFire(range), reloadTime(reload), rateOfFire(rate),
                                        ammoSpeed(speed), maximumDispersion(dispersion),
                                        ammoDeceleration(decelleration), firepower(power), numAmmo(num), length(le),
                                        width(wi), textureName(texName) {
    ammoType = type;

    //setUpSprite(texName); TODO da rifare


    pos = sf::Vector2i(posX, posY);


}

bool Arsenal::setUpSprite(std::string textureName) {
    /*
    if (!texture.loadFromFile(textureName)) {
        throw std::runtime_error("Path to tile filename invalid, for the arsenal object sprite");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, length, width));
    return true;
    */
}

void Arsenal::openFire(Vehicle enemy) {

}





