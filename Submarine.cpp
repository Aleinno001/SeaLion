//
// Created by pala on 7/2/21.
//

#include "Submarine.h"


void Submarine::submerge() {

}

Submarine::Submarine(int x, int y, float ac, const float maxVel, int hp, int arm,
                     std::string nat, int numL, int numH, int numM, int numAA,
                     std::vector<std::unique_ptr<Arsenal>> &arsenalList,
                     std::vector<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi,
                     bool col, ShipType sh, ModelType mo, int numTor, bool isSub) : WarShip(x, y, ac, maxVel, hp, arm,
                                                                                            nat, numL, numH, numM,
                                                                                            numAA,
                                                                                            arsenalList, vehicleList,
                                                                                            le, wi, col, sh, mo),
                                                                                    numTorpedoTubes(
                                                                                            numTor),
                                                                                    isSubmerged(
                                                                                            isSub) {

}

bool Submarine::setUpSprite(std::string textureName) {
    return Vehicle::setUpSprite(textureName);
}

void Submarine::attack(Vehicle target) {
    Vehicle::attack(target);
}

void Submarine::calculateDistance(Vehicle target) {
    Vehicle::calculateDistance(target);
}

void Submarine::update(bool isDead) {
    Vehicle::update(isDead);
}

void Submarine::attach() {
    Vehicle::attach();
}

void Submarine::detach() {
    Vehicle::detach();
}

void Submarine::stopMove() {

}

void Submarine::ceaseFire() {

}

void Submarine::registerArsenals() {

}

void Submarine::removeArsenals() {

}

void Submarine::notifyArsenals() {

}

void Submarine::rotate() {
    Vehicle::rotate();
}

bool Submarine::canEngage(Vehicle target) {
    return Vehicle::canEngage(target);
}


