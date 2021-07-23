//
// Created by davide on 02/07/21.
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
Vehicle::Vehicle(int X, int Y, float ac, float maxVel, int HP, int le, int wi,
                 bool col, std::string nat) : posX(X), posY(Y), acceleration(ac), maxSpeed(maxVel), hp(HP),
                                              length(le), collision(col), width(wi), nationality(nat) {

    //setUpSprite(texName);                     /TODO da modificare

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

    std::string currentDir = CurrentDir::GetCurrentWorkingDir();
    std::string unitTestingPath = "UnitTesting";
    std::size_t found = currentDir.find(unitTestingPath);
    if (found != std::string::npos) {
        currentDir.erase(found);
        currentDir.pop_back();
    }
    textureName = currentDir + "/../Res/" + nationality + "/" + textureName + ".png";
    if (!texture.loadFromFile(textureName)) {
        throw std::runtime_error("Path to tile filename invalid!!");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, length));
    return true;
}

int Vehicle::getPosX() const {
    return posX;
}

int Vehicle::getPosY() const {
    return posY;
}

float Vehicle::getAcceleration() const {
    return acceleration;
}

const float Vehicle::getMaxSpeed() const {
    return maxSpeed;
}

int Vehicle::getHp() const {
    return hp;
}

int Vehicle::getLength() const {
    return length;
}

int Vehicle::getWidth() const {
    return width;
}

bool Vehicle::isCollision() const {
    return collision;
}

const sf::Texture &Vehicle::getTexture() const {
    return texture;
}

sf::Sprite &Vehicle::getSprite() {
    return sprite;
}

const sf::Vector2f &Vehicle::getPos() const {
    return pos;
}

