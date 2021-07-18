//
// Created by alessandro on 7/2/21.
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

void AircraftCarrier::registerArsenals(std::unique_ptr<Arsenal> observer) {


}

void AircraftCarrier::removeArsenals(std::unique_ptr<Arsenal> observer) {

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

AircraftCarrier::AircraftCarrier(int x, int y, float ac, const float maxVel, int hp, int arm, std::string nat, int numL,
                                 int numH, int numM, int numAA, std::list<std::unique_ptr<Arsenal>> &arsenalList,
                                 std::list<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi, bool col,
                                 ShipType sh, ModelType mo, int planes) : WarShip(x, y, ac,
                                                                                  maxVel, hp, arm,
                                                                                  nat, numL, numH,
                                                                                  numM, numAA,
                                                                                  arsenalList,
                                                                                  vehicleList, le, wi,
                                                                                  col, sh,
                                                                                  mo),
                                                                          numPlanes(planes) {}



