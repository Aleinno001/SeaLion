//
// Created by davide on 04/07/21.
//

#include "Fighter.h"

Fighter::Fighter(int x, int y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string nat,WarShip &subject) : Vehicle(x, y, ac, maxVel, hp, le, wi, col, nat),subject_(subject) {
    std::string textureName="Fighter.png";

    try {
        setUpSprite("WarPlanes/" + textureName);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Wrong texture name" << std::endl;
    }
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
    sprite.setPosition(sprite.getPosition() + vel);
    sprite.setRotation(sprite.getRotation() + mx);
    sf::Transform rotation;
    rotation.rotate(mx, subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(sprite.getPosition());
    sprite.setPosition(newPosition);
}
