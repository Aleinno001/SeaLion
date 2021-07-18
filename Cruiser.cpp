//
// Created by alessandro on 7/2/21.
//

#include "Cruiser.h"
/*
float Cruiser::calcSpeed(Map battleSea) {
    return Vehicle::calcSpeed(battleSea);
}
*/

Cruiser::Cruiser(int x, int y, float ac, const float maxVel, int hp, int arm,
                 std::string nat, int numL, int numH, int numM, int numAA,
                 std::list<std::unique_ptr<Arsenal>> &arsenalList,
                 std::list<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi,
                 bool col, ShipType sh, ModelType mo, int planes) : WarShip(x, y, ac, maxVel, hp, arm, nat,
                                                                            numL, numH, numM, numAA,
                                                                            arsenalList,
                                                                            vehicleList,
                                                                            le, wi, col, sh, mo),
                                                                    numPlanes(planes) {}

void Cruiser::attack(Vehicle target) {
    Vehicle::attack(target);
}

void Cruiser::calculateDistance(Vehicle target) {
    Vehicle::calculateDistance(target);
}

void Cruiser::update(bool isDead) {
    Vehicle::update(isDead);
}

void Cruiser::attach() {
    Vehicle::attach();
}

void Cruiser::detach() {
    Vehicle::detach();
}

void Cruiser::stopMove() {

}

void Cruiser::ceaseFire() {

}

void Cruiser::registerArsenals(std::unique_ptr<Arsenal> observer) {

}

void Cruiser::removeArsenals(std::unique_ptr<Arsenal> observer) {

}

void Cruiser::notifyArsenals() {

}

Cruiser::~Cruiser() {

}

void Cruiser::rotate() {
    Vehicle::rotate();
}

bool Cruiser::canEngage(Vehicle target) {
    return Vehicle::canEngage(target);
}

bool Cruiser::setUpSprite(std::string textureName) {
    return Vehicle::setUpSprite(textureName);
}


