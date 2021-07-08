//
// Created by alessandro on 04/07/21.
//

#include "Bomber.h"

void Bomber::bombard(Vehicle enemy) {

}

void Bomber::attack(Vehicle target) {
    Vehicle::attack(target);
}

void Bomber::calculateDistance(Vehicle target) {
    Vehicle::calculateDistance(target);
}

void Bomber::update(bool isDead) {
    Vehicle::update(isDead);
}

void Bomber::attach() {
    Vehicle::attach();
}

void Bomber::detach() {
    Vehicle::detach();
}

Bomber::~Bomber() {

}

Bomber::Bomber(int x, int y, float ac1, float maxVel1, int hp, int length1, sf::Texture tex, sf::Sprite sp, int le,
               int wi, bool col, std::string textureName, double X, double Y, float ac, const float maxVel, int HP,
               int length, int numBombs, int damage) : Vehicle(x, y, ac1, maxVel1, hp, tex, sp, le, wi, col,
                                                               textureName) {

}
