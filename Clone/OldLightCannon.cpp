//
// Created by pala on 9/18/21.
//

#include "OldLightCannon.h"



LightCannon::LightCannon(float range, const int reload, int dispersion, std::shared_ptr<Bullet> type,
                         int power, int posX, int posY, int le, int wi,
                         std::string texName, WarShip &sub)
        : subject_(sub),
          Arsenal(range, reload, dispersion, type, power, posX, posY, le, wi, texName) {
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


