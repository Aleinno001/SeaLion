//
// Created by davide on 02/07/21.
//

#include "AntiAircraft.h"

AntiAircraft::AntiAircraft(const float range, const int reload, int speed, int dispersion,
                           Bullet type, float decelleration, int power, int num, int le,
                           int wi, std::string texName, WarShip &sub) : subject_(sub),
                                                                        Arsenal(range, reload, speed, dispersion, type,
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




bool AntiAircraft::engage(Vehicle enemy) {
    return false;
}

void AntiAircraft::rotate() {

}

bool AntiAircraft::setUpSprite(std::string textureName) {
    return Arsenal::setUpSprite(textureName);
}

void AntiAircraft::resetOrigin() {

}

void AntiAircraft::update() {

}
