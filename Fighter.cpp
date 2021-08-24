//
// Created by davide on 04/07/21.
//

#include "Fighter.h"

Fighter::Fighter(int x, int y, float ac1, float maxVel1, int hp,
                 int le, int wi, bool col, double X, double Y, float ac,
                 const float maxVel, int HP, int length, std::string nat) : Vehicle(x, y, ac1, maxVel1, hp, le, wi,
                                                                                    col, nat) {

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

void Fighter::attach() {
    Vehicle::attach();
}

void Fighter::detach() {
    Vehicle::detach();
}

Fighter::~Fighter() {

}
