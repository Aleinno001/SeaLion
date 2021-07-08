//
// Created by alessandro on 04/07/21.
//

#include "Fighter.h"

Fighter::Fighter(int x, int y, float ac1, float maxVel1, int hp, int length1, sf::Texture tex, sf::Sprite sp,
                 int le, int wi, bool col, std::string textureName, double X, double Y, float ac,
                 const float maxVel, int HP, int length) : Vehicle(x, y, ac1, maxVel1, hp, tex, sp, le, wi,
                                                                   col, textureName) {

}

void Fighter::fight(Vehicle enemy) {

}

void Fighter::attack(Vehicle target) {
    Vehicle::attack(target);
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
