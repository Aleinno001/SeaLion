//
// Created by davide on 02/07/21.
//

#include "MediumCannon.h"

MediumCannnon::MediumCannnon(const float range, const int reload, int speed, int dispersion,
                             Bullet type, float decelleration, int power, int num, int posX, int posY, int le,
                             int wi, std::string texName, WarShip &sub) : subject_(sub),
                                                                          Arsenal(range, reload, speed, dispersion,
                                                                                  type,
                                                                                  decelleration, power, num, posX, posY,
                                                                                  le, wi,
                                                                                  texName) {
    setUpSprite(texName);
    sprite.setPosition(pos);
    resetOrigin();
}

MediumCannnon::~MediumCannnon() {

}

bool MediumCannnon::rapidFire() {
    return false;
}

void MediumCannnon::openFire(Vehicle enemy) {
    Arsenal::openFire(enemy);
}

void MediumCannnon::update(sf::Vector2f &vel,double mx) {
    sprite.setPosition(sprite.getPosition() + vel);
    sprite.setRotation(sprite.getRotation() + mx);
    sf::Transform rotation;
    rotation.rotate(mx, subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(sprite.getPosition());
    sprite.setPosition(newPosition);
}



bool MediumCannnon::engage(Vehicle enemy) {
    return Arsenal::engage(enemy);
}

void MediumCannnon::rotate() {
    Arsenal::rotate();
}

void MediumCannnon::resetOrigin() {
    sprite.setOrigin((width - 1) / 2, (width - 1) / 2);
}
