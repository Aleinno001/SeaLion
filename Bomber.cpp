//
// Created by davide on 04/07/21.
//

#include "Bomber.h"

void Bomber::bombard(Vehicle enemy) {

}

void Bomber::attack(Vehicle target) {
}

void Bomber::calculateDistance(Vehicle target) {
    Vehicle::calculateDistance(target);
}

void Bomber::update(bool isDead) {
    Vehicle::update(isDead);
}



Bomber::~Bomber() {

}

Bomber::Bomber(int x, int y, float ac1, float maxVel1, int hp, int le,
               int wi, bool col, double X, double Y, float ac, const float maxVel, int HP,
               int length, int numBombs, int damage, std::string nat,WarShip &subject) : Vehicle(x, y, ac1, maxVel1, hp, le, wi, col,
                                                                                nat), subject_(subject) {


}

void Bomber::update() {

}
