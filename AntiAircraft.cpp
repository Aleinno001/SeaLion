//
// Created by pala on 02/07/21.
//

#include "AntiAircraft.h"

AntiAircraft::AntiAircraft(const float range, const int reload, const int rate, int speed, int dispersion,
                           std::string type, float decelleration, int power, int num, int posX, int posY, int le,
                           int wi, std::string texName) : Arsenal(range, reload, rate, speed, dispersion, type,
                                                                  decelleration, power, num, posX, posY, le, wi,
                                                                  texName) {

}

AntiAircraft::~AntiAircraft() {

}

bool AntiAircraft::airStrafe() {
    return false;
}

void AntiAircraft::openFire(Vehicle enemy) {
    Arsenal::openFire(enemy);
}

void AntiAircraft::update(std::unique_ptr<WarShip> theChangedSubject) {

}

void AntiAircraft::attach() {
    Arsenal::attach();
}

void AntiAircraft::detach() {
    Arsenal::detach();
}

bool AntiAircraft::engage(Vehicle enemy) {
    return Arsenal::engage(enemy);
}

void AntiAircraft::rotate() {
    Arsenal::rotate();
}
