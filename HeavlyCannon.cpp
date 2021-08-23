//
// Created by davide on 02/07/21.
//

#include "HeavlyCannon.h"

HeavlyCannon::HeavlyCannon(const float range, const int reload, int speed, int dispersion,
                           Bullet type, float decelleration, int power, int num, int posX, int posY, int le,
                           int wi, std::string texName, WarShip &sub) : subject_(sub),
                                                                        Arsenal(range, reload, speed, dispersion, type,
                                                                                decelleration, power, num, posX, posY,
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
    //TODO Implementa l'aggiornameto delle coordinate del cannone pesante
    sprite.setPosition(sprite.getPosition() + vel);
    sprite.setRotation(sprite.getRotation() + mx);
    sf::Transform rotation;
    rotation.rotate(mx, subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(sprite.getPosition());
    sprite.setPosition(newPosition);

    /*float side = sqrt(pow(sprite.getPosition().x - subject_.getSprite().getPosition().x, 2) +
                      pow(sprite.getPosition().y - subject_.getSprite().getPosition().y, 2));
    float distance;
    float dx, dy;
    //sprite.getTransform().transformPoint(subject_.getSprite().getOrigin());
    std::cerr << "pattume : " << (pow(sprite.getPosition().x - subject_.getSprite().getPosition().x, 2) +
                                  pow(sprite.getPosition().y - subject_.getSprite().getPosition().y, 2)) << std::endl;
    std::cerr << "side: " << side << std::endl;
    distance = sqrt(pow(side, 2) + pow(side, 2) - 2 * side * side * std::cos(mx));
    std::cerr << "distance:" << distance << std::endl;
    dx = distance * std::sin(mx);
    dy = distance * std::cos(mx);
    std::cerr << dx << "," << dy << std::endl;
    sprite.setPosition(sprite.getPosition().x + dx, sprite.getPosition().y + dy);
    // sprite.setRotation(mx);
*/
}
