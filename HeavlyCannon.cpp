//
// Created by pala on 02/07/21.
//

#include "HeavlyCannon.h"

HeavlyCannon::HeavlyCannon(int le, int wi, bool col, std::string texName,
                           const float range, const int reload, int speed, int dispersion,
                           std::string type, float decelleration, int power, int num, double x, double y)
        : Arsenal(range, reload, speed, dispersion, type, decelleration, power, num, x, y, le,
                  wi, texName) {

}

HeavlyCannon::~HeavlyCannon() {

}

bool HeavlyCannon::shoreBombardment() {
    return false;
}

void HeavlyCannon::openFire(Vehicle enemy) {
    Arsenal::openFire(enemy);
}

void HeavlyCannon::update(int posX, int posY) {
    Arsenal::update(posX, posY);
}

void HeavlyCannon::attach() {
    Arsenal::attach();
}

void HeavlyCannon::detach() {
    Arsenal::detach();
}

bool HeavlyCannon::engage(Vehicle enemy) {
    return Arsenal::engage(enemy);
}

void HeavlyCannon::rotate() {
    Arsenal::rotate();
}
