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
    sprite.setPosition(sprite.getPosition() + vel);
    sprite.setRotation(sprite.getRotation() + mx);
    sf::Transform rotation;
    rotation.rotate(mx, subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(sprite.getPosition());
    sprite.setPosition(newPosition);
}

Bomber::Bomber(int x, int y, float ac, float maxVel, int hp, int le, int wi, bool col, int numBombs, int damage,std::string nat,WarShip &subject) : Vehicle(x, y, ac, maxVel, hp, le, wi, col, nat),subject_(subject),bombDamage(damage),numBombs(numBombs) {
    std::string textureName="Bomber";

    try {
        setUpSprite("WarPlanes/" + textureName);
        sprite.setPosition(pos);
        resetOrigin();
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Wrong texture name" << std::endl;
    }
}

void Bomber::resetOrigin() {
    sprite.setOrigin((width - 1) / 2, (length) / 2);
}

int Bomber::getNumBombs() const {
    return numBombs;
}

int Bomber::getBombDamage() const {
    return bombDamage;
}
