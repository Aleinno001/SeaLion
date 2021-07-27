//
// Created by davide on 02/07/21.
//

#include "MediumCannon.h"

MediumCannnon::MediumCannnon(const float range, const int reload, int speed, int dispersion,
                             Bullet type, float decelleration, int power, int num, int posX, int posY, int le,
                             int wi, std::string texName) : Arsenal(range, reload, speed, dispersion, type,
                                                                    decelleration, power, num, posX, posY, le, wi,
                                                                    texName) {
    setUpSprite(texName);
    sprite.setPosition(pos);
    sprite.setOrigin((wi - 1) / 2, le / 2);
}

MediumCannnon::~MediumCannnon() {

}

bool MediumCannnon::rapidFire() {
    return false;
}

void MediumCannnon::openFire(Vehicle enemy) {
    Arsenal::openFire(enemy);
}

void MediumCannnon::update(std::unique_ptr<WarShip> theChangedSubject) {

}



bool MediumCannnon::engage(Vehicle enemy) {
    return Arsenal::engage(enemy);
}

void MediumCannnon::rotate() {
    Arsenal::rotate();
}
