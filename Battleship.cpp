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

Battleship::Battleship(double x1, double y1, float ac1, const float maxVel1, int hp1, int length1, int arm1,
                       std::string na1, std::string nat1, int numL1, int numH1, int numM1,
                       std::vector<std::unique_ptr<Arsenal>> &arsenalList1,
                       std::vector<std::unique_ptr<Vehicle>> &vehicleList1, double x, double y, float ac,
                       const float maxVel, int hp, int length, int arm, std::string na, std::string nat, int numL,
                       int numH, int numM, std::vector<std::unique_ptr<Arsenal>> &arsenalList,
                       std::vector<std::unique_ptr<Vehicle>> &vehicleList, int numInter, sf::Texture tex, sf::Sprite sp,
                       int le, int wi,
                       bool col, std::string textureName) : WarShip(x1, y1, ac1, maxVel1,
                                                                    hp1, length1, arm1,
                                                                    na1, nat1, numL1,
                                                                    numH1, numM1,
                                                                    arsenalList1,
                                                                    vehicleList1, tex, sp, le, wi, col, textureName) {

}


