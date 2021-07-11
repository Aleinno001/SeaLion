//
// Created by alessandro on 02/07/21.
//

#include "Vehicle.h"

void Vehicle::rotate() {

}

bool Vehicle::canEngage(Vehicle target) {
    return false;
}

/*
float Vehicle::calcSpeed() {
    return 0;
}
*/
Vehicle::Vehicle(int X, int Y, float ac, float maxVel, int HP, sf::Texture tex, sf::Sprite sp, int le, int wi,
                 bool col, std::string texName) : posX(X), posY(Y), acceleration(ac), maxSpeed(maxVel), hp(HP),
                                                  length(le), collision(col), width(wi), texture(tex),
                                                  sprite(sp) {

    setUpSprite(texName)

    pos = sf::Vector2f(posX, posY);
    sprite.setPosition(pos);


}

void Vehicle::attack(Vehicle target) {

}

void Vehicle::calculateDistance(Vehicle target) {

}

void Vehicle::update(bool isDead) {

}

void Vehicle::attach() {

}

void Vehicle::detach() {

}

bool Vehicle::setUpSprite(std::string textureName) {

    if (!texture.loadFromFile(textureName)) {
        throw std::runtime_error("Path to tile filename invalid, for the vehicle object sprite");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, length, width));
    return true;
}

