//
// Created by davide on 04/07/21.
//

#include "OldFigther.h"

OldFigther::OldFigther(int x, int y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string nat,
                 WarShip &subject) : Vehicle(x, y, ac, maxVel, hp, le, wi, col, nat), subject_(subject) {
    std::string textureName = "OldFigther";

    try {
        setUpSprite("WarPlanes/" + textureName);
        sprite.setPosition(pos);
        resetOrigin();
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Wrong texture name" << std::endl;
    }
}

void OldFigther::fight(Vehicle enemy) {

}

void OldFigther::attack(Vehicle target) {
}

void OldFigther::update(bool isDead) {
    Vehicle::update(isDead);
}


OldFigther::~OldFigther() {

}

void OldFigther::updatePlanes(sf::Vector2f &vel, double mx) {
    sprite.setPosition(sprite.getPosition() + vel);
    sprite.setRotation(sprite.getRotation() + mx);
    sf::Transform rotation;
    rotation.rotate(mx, subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(sprite.getPosition());
    sprite.setPosition(newPosition);
}

void OldFigther::resetOrigin() {
    sprite.setOrigin((width - 1) / 2, (length - 1) / 2);
}

void OldFigther::planeAttack(std::_List_iterator<std::unique_ptr<Vehicle>> target, float dt) {
    if (WarShip *pTarget = dynamic_cast<WarShip *> (target->get())) {
        pTarget->setDamage(damage);
        pTarget->notifyBarsDamage();                                //notify per Observer Bars
    }
}