//
// Created by davide on 02/07/21.
//

#include "AntiAircraft.h"

AntiAircraft::AntiAircraft(const float range, const int reload, int speed, int dispersion,
                           Bullet type, float decelleration, int power, int num, int le,
                           int wi, std::string texName) : Arsenal(range, reload, speed, dispersion, type,
                                                                  decelleration, power, num, 0, 0, le, wi,
                                                                  texName) {

}

AntiAircraft::~AntiAircraft() {

}

bool AntiAircraft::airStrafe() {
    return false;
}

void AntiAircraft::openFire(Vehicle enemy) {

}

void AntiAircraft::update(std::unique_ptr<WarShip> theChangedSubject) {

}

void AntiAircraft::attach() {

}

void AntiAircraft::detach() {

}

bool AntiAircraft::engage(Vehicle enemy) {
    return false;
}

void AntiAircraft::rotate() {

}