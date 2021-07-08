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
Vehicle::Vehicle(int X, int Y, float ac, float maxVel, int HP, int lenght, sf::Texture tex, sf::Sprite sp, int le,
                 int wi) : posX(X), posY(Y), acceleration(ac), maxSpeed(maxVel), hp(HP), length(lenght) {


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

}

