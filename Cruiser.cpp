//
// Created by pala on 7/2/21.
//

#include "Cruiser.h"

float Cruiser::calcSpeed(Map battleSea) {
    return Vehicle::calcSpeed(battleSea);
}

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

void Cruiser::registerArsenals() {

}

void Cruiser::removeArsenals() {

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

Cruiser::Cruiser(double x, double y, float ac, const float maxVel, int hp, int length, int arm, std::string na,
                 std::string nat, int numL, int numH, int numM, std::vector<std::unique_ptr<Arsenal>> &arsenalList,
                 std::vector<std::unique_ptr<Vehicle>> &vehicleList) : WarShip(x, y, ac, maxVel, hp, length, arm, na,
                                                                               nat, numL, numH, numM, arsenalList,
                                                                               vehicleList) {

}
