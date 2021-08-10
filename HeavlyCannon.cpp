//
// Created by davide on 02/07/21.
//

#include "HeavlyCannon.h"

HeavlyCannon::HeavlyCannon(const float range, const int reload, int speed, int dispersion,
                           Bullet type, float decelleration, int power, int num, int posX, int posY, int le,
                           int wi, std::string texName, WarShip &sub) : subject_(sub),
                                                                        Arsenal(range, reload, speed, dispersion, type,
                                                                                decelleration, power, num, posX, posY,
                                                                                le, wi,
                                                                                texName) {


    subject_.attach(std::shared_ptr<Arsenal>(this));
    setUpSprite(texName);
    sprite.setPosition(pos);
    resetOrigin();

};

HeavlyCannon::~HeavlyCannon() {

}

bool HeavlyCannon::shoreBombardment() {
    return false;
}

void HeavlyCannon::openFire(Vehicle enemy) {
    Arsenal::openFire(enemy);
}



bool HeavlyCannon::engage(Vehicle enemy) {
    return Arsenal::engage(enemy);
}

void HeavlyCannon::rotate() {
    Arsenal::rotate();
}

void HeavlyCannon::resetOrigin() {
    sprite.setOrigin((width - 1) / 2, (width - 1) / 2);
}

void HeavlyCannon::update() {
    //TODO Implementa l'aggiormnameto delle coordinate del cannone pesante

}
