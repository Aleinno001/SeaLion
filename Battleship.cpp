//
// Created by pala on 7/2/21.
//

#include "Battleship.h"

float Battleship::calcSpeed(Map battleSea) {
    return Vehicle::calcSpeed(battleSea);
}

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

void Battleship::registerArsenals() {

}

void Battleship::removeArsenals() {

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
