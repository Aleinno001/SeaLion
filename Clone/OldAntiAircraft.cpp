//
// Created by pala on 9/18/21.
//

#include "OldAntiAircraft.h"


AntiAircraft::AntiAircraft(const float range, const int reload, int dispersion,
                           std::shared_ptr<Bullet> type, int power, int le,
                           int wi, std::string texName, WarShip &sub) : subject_(sub),
                                                                        Arsenal(range, reload, dispersion, type,
                                                                                power, 0, 0, le, wi,
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
void AntiAircraft::update(sf::Vector2f &vel, double mx) {
}

