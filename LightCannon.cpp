//
// Created by davide on 02/07/21.
//

#include "LightCannon.h"

LightCannon::LightCannon(float range, const int reload, int speed, int dispersion, Bullet type,
                         float decelleration, int power, int num, int posX, int posY, int le, int wi,
                         std::string texName)
        : Arsenal(range, reload, speed, dispersion, type, decelleration, power, num, posX, posY, le, wi, texName) {
    setUpSprite(texName);
    sprite.setPosition(pos);
}

LightCannon::~LightCannon() {

}

bool LightCannon::accuracy() {
    return false;
}

void LightCannon::openFire(Vehicle enemy) {
    Arsenal::openFire(enemy);
}

void LightCannon::update(std::unique_ptr<WarShip> theChangedSubject) {

}

void LightCannon::attach() {
    Arsenal::attach();
}

void LightCannon::detach() {
    Arsenal::detach();
}

bool LightCannon::engage(Vehicle enemy) {
    return Arsenal::engage(enemy);
}

void LightCannon::rotate() {
    Arsenal::rotate();
}


