//
// Created by davide on 04/07/21.
//

#include "Fighter.h"

Fighter::Fighter(int x, int y, float ac1, float maxVel1, int hp,
                 int le, int wi, bool col, float ac,
                 const float maxVel, int HP, int length, std::string nat,WarShip &subject) : Vehicle(x, y, ac1, maxVel1, hp, le, wi,
                                                                                    col, nat),subject_(subject) {

}

void Fighter::fight(Vehicle enemy) {

}

void Fighter::attack(Vehicle target) {
}

void Fighter::calculateDistance(Vehicle target) {
    Vehicle::calculateDistance(target);
}

void Fighter::update(bool isDead) {
    Vehicle::update(isDead);
}


Fighter::~Fighter() {

}

void Fighter::updatePlanes(sf::Vector2f &vel,double mx) {

}
