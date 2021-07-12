//
// Created by pala on 7/2/21.
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

Battleship::Battleship(int x2, int y2, float ac2, const float maxVel2, int hp2, int length2, int arm2,
                       std::string na2, std::string nat2, int numL2, int numH2, int numM2,
                       std::vector<std::unique_ptr<Arsenal>> &arsenalList2,
                       std::vector<std::unique_ptr<Vehicle>> &vehicleList2, sf::Texture tex1, sf::Sprite sp1,
                       int le1, int wi1, bool col1, std::string textureName1, ShipType sh, ModelType mo, int x1,
                       int y1, float ac1, const float maxVel1, int hp1, int length1, int arm1, std::string na1,
                       std::string nat1, int numL1, int numH1, int numM1,
                       std::vector<std::unique_ptr<Arsenal>> &arsenalList1,
                       std::vector<std::unique_ptr<Vehicle>> &vehicleList1, double x, double y, float ac,
                       const float maxVel, int hp, int length, int arm, std::string na, std::string nat, int numL,
                       int numH, int numM, std::vector<std::unique_ptr<Arsenal>> &arsenalList,
                       std::vector<std::unique_ptr<Vehicle>> &vehicleList, int numInter, sf::Texture tex,
                       sf::Sprite sp, int le, int wi, bool col, std::string textureName) : WarShip(x2, y2, ac2, maxVel2,
                                                                                                   hp2, length2, arm2,
                                                                                                   na2, nat2, numL2,
                                                                                                   numH2, numM2,
                                                                                                   arsenalList2,
                                                                                                   vehicleList2, tex1,
                                                                                                   sp1, le1, wi1, col1,
                                                                                                   textureName1, sh,
                                                                                                   mo) {

}


