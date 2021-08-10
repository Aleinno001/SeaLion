//
// Created by davide on 02/07/21.
//

#include "LightCannon.h"

LightCannon::LightCannon(float range, const int reload, int speed, int dispersion, Bullet type,
                         float decelleration, int power, int num, int posX, int posY, int le, int wi,
                         std::string texName, WarShip &sub)
        : subject_(sub),
          Arsenal(range, reload, speed, dispersion, type, decelleration, power, num, posX, posY, le, wi, texName) {
    subject_.attach(std::shared_ptr<Arsenal>(this));
    setUpSprite(texName);
    sprite.setPosition(pos);
    resetOrigin();
}

LightCannon::~LightCannon() {

}

bool LightCannon::accuracy() {
    return false;
}

void LightCannon::openFire(Vehicle enemy) {
    Arsenal::openFire(enemy);
}

void LightCannon::update() {
    //TODO Implementa l'aggiormnameto delle coordinate del cannone leggero
}



bool LightCannon::engage(Vehicle enemy) {
    return Arsenal::engage(enemy);
}

void LightCannon::rotate() {
    Arsenal::rotate();
}

void LightCannon::resetOrigin() {
    sprite.setOrigin(width / 2, width / 2);
}



