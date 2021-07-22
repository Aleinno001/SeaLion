//
// Created by davide on 02/07/21.
//

#include "HeavlyCannon.h"

HeavlyCannon::HeavlyCannon(const float range, const int reload, int speed, int dispersion,
                           Bullet type, float decelleration, int power, int num, int posX, int posY, int le,
                           int wi, std::string texName) : Arsenal(range, reload, speed, dispersion, type,
                                                                  decelleration, power, num, posX, posY, le, wi,
                                                                  texName) {
    setUpSprite(texName);
};

HeavlyCannon::~HeavlyCannon() {

}

bool HeavlyCannon::shoreBombardment() {
    return false;
}

void HeavlyCannon::openFire(Vehicle enemy) {
    Arsenal::openFire(enemy);
}

void HeavlyCannon::update(std::unique_ptr<WarShip> theChangedSubject) {

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
