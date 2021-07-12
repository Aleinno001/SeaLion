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

AircraftCarrier::AircraftCarrier(int x1, int y1, float ac1, const float maxVel1, int hp1, int length1, int arm1,
                                 std::string na1, std::string nat1, int numL1, int numH1, int numM1,
                                 std::vector<std::unique_ptr<Arsenal>> &arsenalList1,
                                 std::vector<std::unique_ptr<Vehicle>> &vehicleList1, sf::Texture tex1,
                                 sf::Sprite sp1, int le1, int wi1, bool col1, std::string textureName1, ShipType sh,
                                 ModelType mo, double x, double y, float ac, const float maxVel, int hp, int length,
                                 int arm, std::string na, std::string nat, int numL, int numH, int numM,
                                 std::vector<std::unique_ptr<Arsenal>> &arsenalList,
                                 std::vector<std::unique_ptr<Vehicle>> &vehicleList, sf::Texture tex, sf::Sprite sp,
                                 int le, int wi, bool col, std::string textureName) : WarShip(x1, y1, ac1, maxVel1, hp1,
                                                                                              length1, arm1, na1, nat1,
                                                                                              numL1, numH1, numM1,
                                                                                              arsenalList1,
                                                                                              vehicleList1, tex1, sp1,
                                                                                              le1, wi1, col1,
                                                                                              textureName1, sh, mo) {

}
