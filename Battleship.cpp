//
// Created by alessandro on 7/2/21.
//

#include "Battleship.h"
/*
float Battleship::calcSpeed(Map battleSea) {
    return Vehicle::calcSpeed(battleSea);
}
*/
void Battleship::attack(Vehicle target) {
    Vehicle::attack(target);
}

void Battleship::calculateDistance(Vehicle target) {
    Vehicle::calculateDistance(target);
}

void Battleship::update(bool isDead) {
    Vehicle::update(isDead);
}

void Battleship::attach() {
    Vehicle::attach();
}

void Battleship::detach() {
    Vehicle::detach();
}

void Battleship::stopMove() {

}

void Battleship::ceaseFire() {

}

void Battleship::registerArsenals(std::unique_ptr<Arsenal> observer) {

}

void Battleship::removeArsenals(std::unique_ptr<Arsenal> observer) {

}

void Battleship::notifyArsenals() {

}

Battleship::~Battleship() {

}

void Battleship::rotate() {
    Vehicle::rotate();
}

bool Battleship::canEngage(Vehicle target) {
    return Vehicle::canEngage(target);
}

bool Battleship::setUpSprite(std::string textureName) {
    return Vehicle::setUpSprite(textureName);
}

Battleship::Battleship(int x, int y, float ac, const float maxVel, int hp, int arm, std::string nat, int numL,
                       int numH, int numM, int numAa, std::list<std::unique_ptr<Arsenal>> &arsenalList,
                       std::list<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi, bool col, ShipType sh,
                       ModelType mo, int numInterceptors) : WarShip(x, y, ac, maxVel, hp, arm, nat, numL, numH, numM,
                                                                    numAa, arsenalList, vehicleList, le, wi, col, sh,
                                                                    mo), numInterceptors(numInterceptors) {

}




