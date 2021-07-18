//
// Created by alessandro on 7/2/21.
//

#include "Destroyer.h"

/*
float Destroyer::calcSpeed() {
    return Vehicle::calcSpeed();
}
*/

Destroyer::Destroyer(int x, int y, float ac, const float maxVel, int hp, int arm,
                     std::string nat, int numL, int numH, int numM, int numAA,
                     std::list<std::unique_ptr<Arsenal>> &arsenalList,
                     std::list<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi,
                     bool col, ShipType sh, ModelType mo, int torpedo) : WarShip(x, y, ac, maxVel, hp,
                                                                                 arm, nat,
                                                                                 numL, numH, numM, numAA,
                                                                                 arsenalList,
                                                                                 vehicleList,
                                                                                 le, wi, col, sh, mo),
                                                                         numTorpedoTubes(torpedo) {}

void Destroyer::attack(Vehicle target) {
    Vehicle::attack(target);
}

void Destroyer::calculateDistance(Vehicle target) {
    Vehicle::calculateDistance(target);
}

void Destroyer::update(bool isDead) {
    Vehicle::update(isDead);
}

void Destroyer::attach() {
    Vehicle::attach();
}

void Destroyer::detach() {
    Vehicle::detach();
}

void Destroyer::stopMove() {

}

void Destroyer::ceaseFire() {

}

void Destroyer::registerArsenals(std::unique_ptr<Arsenal> observer) {

}

void Destroyer::removeArsenals(std::unique_ptr<Arsenal> observer) {

}

void Destroyer::notifyArsenals() {

}

Destroyer::~Destroyer() {

}

void Destroyer::rotate() {
    Vehicle::rotate();
}

bool Destroyer::canEngage(Vehicle target) {
    return Vehicle::canEngage(target);
}

bool Destroyer::setUpSprite(std::string textureName) {
    return Vehicle::setUpSprite(textureName);
}

