//
// Created by pala on 02/07/21.
//

#include "MediumCannon.h"

MediumCannon::MediumCannon(int le, int wi, std::string texName,
                           const float range, const int reload, const int rate, int speed, int dispersion,
                           std::string type, float decelleration, int power, int num, double x, double y)
        : Arsenal(range, reload, rate, speed, dispersion, type, decelleration, power, num, x, y, le,
                  wi, texName) {}

MediumCannon::~MediumCannon() {

}

bool MediumCannon::rapidFire() {
    return false;
}

void MediumCannon::openFire(Vehicle enemy) {
    Arsenal::openFire(enemy);
}

void MediumCannon::update(int posX, int posY) {

}

void MediumCannon::attach() {
    Arsenal::attach();
}

void MediumCannon::detach() {
    Arsenal::detach();
}

bool MediumCannon::engage(Vehicle enemy) {
    return Arsenal::engage(enemy);
}

void MediumCannon::rotate() {
    Arsenal::rotate();
}
