//
// Created by davide on 02/07/21.
//

#include "LightCannon.h"

LightCannon::LightCannon(float range, const int reload, int speed, int dispersion, Bullet type,
                         float deceleration, int power, int num, int posX, int posY, int le, int wi,
                         std::string texName, WarShip &sub)
        : subject_(sub),
          Arsenal(range, reload, speed, dispersion, type, deceleration, power, num, posX, posY, le, wi, texName) {
    setUpSprite(texName);
    sprite.setPosition(pos);
    resetOrigin();
}

LightCannon::~LightCannon() {

}

bool LightCannon::accuracy() {
    return false;
}

void LightCannon::openFire(Vehicle enemy) {
    Arsenal::openFire(enemy);
}

void LightCannon::update(sf::Vector2f &vel,double mx) {
    sprite.setPosition(sprite.getPosition() + vel);
    sprite.setRotation(sprite.getRotation() + mx);
    sf::Transform rotation;
    rotation.rotate(mx, subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(sprite.getPosition());
    sprite.setPosition(newPosition);
}



bool LightCannon::engage(Vehicle enemy) {
    return Arsenal::engage(enemy);
}

void LightCannon::rotate() {
    Arsenal::rotate();
}

void LightCannon::resetOrigin() {
    sprite.setOrigin(width / 2, width / 2);
}



