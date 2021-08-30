//
// Created by davide on 04/07/21.
//

#include "TorpedoBomber.h"

TorpedoBomber::TorpedoBomber(int x, int y, float ac, float maxVel, int hp, int le, int wi, bool col,
                             int numTorpedos, int damage,std::string nat,WarShip &subject) : Vehicle(x, y, ac, maxVel, hp, le, wi, col, nat),subject_(subject),numTorpedos(numTorpedos),torpedoDamage(damage)  {

    std::string textureName="TorpedoBomber.png";

    try {
        setUpSprite("WarPlanes/" + textureName);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Wrong texture name" << std::endl;
    }
}

void TorpedoBomber::launchTorpedo(Vehicle &enemy) {

}

void TorpedoBomber::calculateDistance(Vehicle target) {
    Vehicle::calculateDistance(target);
}

void TorpedoBomber::attack(Vehicle target) {

}

void TorpedoBomber::update(bool isDead) {
    Vehicle::update(isDead);
}



TorpedoBomber::~TorpedoBomber() {

}

void TorpedoBomber::updatePlanes(sf::Vector2f &vel,double mx) {

}
