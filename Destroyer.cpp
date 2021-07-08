//
// Created by pala on 7/2/21.
//

#include "Destroyer.h"
/*
float Destroyer::calcSpeed() {
    return Vehicle::calcSpeed();
}
*/
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

void Destroyer::registerArsenals() {

}

void Destroyer::removeArsenals() {

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

Destroyer::Destroyer(double x, double y, float ac, const float maxVel, int hp, int length, int arm, std::string na,
                     std::string nat, int numL, int numH, int numM,
                     std::vector<std::unique_ptr<Arsenal>> &arsenalList,
                     std::vector<std::unique_ptr<Vehicle>> &vehicleList, sf::Texture tex, sf::Sprite sp, int le, int wi,
                     bool col, std::string textureName) : WarShip(x, y, ac, maxVel, hp, length, arm,
                                                                  na, nat, numL, numH, numM,
                                                                  arsenalList, vehicleList, tex, sp, le, wi, col,
                                                                  textureName) {

}
