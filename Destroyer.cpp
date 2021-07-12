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

Destroyer::Destroyer(int x1, int y1, float ac1, const float maxVel1, int hp1, int length1, int arm1,
                     std::string na1, std::string nat1, int numL1, int numH1, int numM1,
                     std::vector<std::unique_ptr<Arsenal>> &arsenalList1,
                     std::vector<std::unique_ptr<Vehicle>> &vehicleList1, sf::Texture tex1, sf::Sprite sp1, int le1,
                     int wi1, bool col1, std::string textureName1, ShipType sh, ModelType mo, double x, double y,
                     float ac, const float maxVel, int hp, int length, int arm, std::string na, std::string nat,
                     int numL, int numH, int numM, std::vector<std::unique_ptr<Arsenal>> &arsenalList,
                     std::vector<std::unique_ptr<Vehicle>> &vehicleList, sf::Texture tex, sf::Sprite sp, int le,
                     int wi, bool col, std::string textureName) : WarShip(x1, y1, ac1, maxVel1, hp1, length1, arm1, na1,
                                                                          nat1, numL1, numH1, numM1, arsenalList1,
                                                                          vehicleList1, tex1, sp1, le1, wi1, col1,
                                                                          textureName1, sh, mo) {

}
