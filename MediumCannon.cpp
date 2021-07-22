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

void MediumCannnon::attach() {
    Arsenal::attach();
}

void MediumCannnon::detach() {
    Arsenal::detach();
}

bool MediumCannnon::engage(Vehicle enemy) {
    return Arsenal::engage(enemy);
}

void MediumCannnon::rotate() {
    Arsenal::rotate();
}
