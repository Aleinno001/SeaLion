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


void Bomber::updatePlanes(sf::Vector2f &vel,double mx) {

}

Bomber::Bomber(int x, int y, float ac, float maxVel, int hp, int le, int wi, bool col, int numBombs, int damage,std::string nat,WarShip &subject) : Vehicle(x, y, ac, maxVel, hp, le, wi, col, nat),subject_(subject),bombDamage(damage),numBombs(numBombs) {

}

