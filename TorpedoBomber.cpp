//
// Created by davide on 04/07/21.
//

#include "TorpedoBomber.h"

TorpedoBomber::TorpedoBomber(int x, int y, float ac1, float maxVel1, int hp, int le, int wi, bool col,
                             float ac, const float maxVel, int HP, int length, int numTorpedos, int damage,
                             std::string nat,WarShip &subject) : Vehicle(x,
                                                        y,
                                                        ac1,
                                                        maxVel1,
                                                        hp,
                                                        le,
                                                        wi,
                                                        col, nat),subject_(subject) {

}

void TorpedoBomber::launchTorpedo(Vehicle enemy) {

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
