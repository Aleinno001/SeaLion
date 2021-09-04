//
// Created by davide on 02/07/21.
//

#include "HeavlyCannon.h"

HeavlyCannon::HeavlyCannon(const float range, const int reload, int dispersion,
                           std::shared_ptr<Bullet> type, int power, int posX, int posY, int le,
                           int wi, std::string texName, WarShip &sub) : subject_(sub),
                                                                        Arsenal(range, reload, dispersion, type,
                                                                                power, posX, posY,
                                                                                le, wi,
                                                                                texName) {


    setUpSprite(texName);
    sprite.setPosition(pos);
    resetOrigin();

};

HeavlyCannon::~HeavlyCannon() {

}

bool HeavlyCannon::shoreBombardment() {
    return false;
}

void HeavlyCannon::openFire(Vehicle enemy) {
    Arsenal::openFire(enemy);
}


bool HeavlyCannon::engage(Vehicle enemy) {
    return Arsenal::engage(enemy);
}

void HeavlyCannon::rotate() {
    Arsenal::rotate();
}

void HeavlyCannon::resetOrigin() {
    sprite.setOrigin((width - 1) / 2, (width - 1) / 2);
}

void HeavlyCannon::update(sf::Vector2f &vel, double mx) {
    sprite.setPosition(sprite.getPosition() + vel);
    sprite.setRotation(sprite.getRotation() + mx);
    sf::Transform rotation;
    rotation.rotate(mx, subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(sprite.getPosition());
    sprite.setPosition(newPosition);
}
