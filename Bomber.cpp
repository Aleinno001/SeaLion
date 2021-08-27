//
// Created by davide on 04/07/21.
//

#include "Bomber.h"

void Bomber::bombard(Vehicle &enemy) {

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
               int wi, bool col, float ac, const float maxVel, int HP,
               int length, int numBombs, int damage, std::string nat,WarShip &subject) : Vehicle(x, y, ac1, maxVel1, hp, le, wi, col,
                                                                                nat), subject_(subject),bombDamage(damage),numBombs(numBombs) {


}

void Bomber::updatePlanes(sf::Vector2f &vel,double mx) {

}

