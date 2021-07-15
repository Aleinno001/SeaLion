//
// Created by pala on 7/2/21.
//

#include "AircraftCarrier.h"
/*
float AircraftCarrier::calcSpeed(Map battleSea) {
    return Vehicle::calcSpeed(battleSea);
}
*/
void AircraftCarrier::attack(Vehicle target) {
    Vehicle::attack(target);
}

void AircraftCarrier::calculateDistance(Vehicle target) {
    Vehicle::calculateDistance(target);
}

void AircraftCarrier::update(bool isDead) {
    Vehicle::update(isDead);
}

void AircraftCarrier::attach() {
    Vehicle::attach();
}

void AircraftCarrier::detach() {
    Vehicle::detach();
}

void AircraftCarrier::stopMove() {

}

void AircraftCarrier::ceaseFire() {

}

void AircraftCarrier::registerArsenals() {

}

void AircraftCarrier::removeArsenals() {

}

void AircraftCarrier::notifyArsenals() {

}

AircraftCarrier::~AircraftCarrier() {

}

void AircraftCarrier::rotate() {
    Vehicle::rotate();
}

bool AircraftCarrier::canEngage(Vehicle target) {
    return Vehicle::canEngage(target);
}

bool AircraftCarrier::setUpSprite(std::string textureName) {
    return Vehicle::setUpSprite(textureName);
}

