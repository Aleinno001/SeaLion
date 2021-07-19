//
// Created by davide on 04/07/21.
//

#include "TorpedoBomber.h"

TorpedoBomber::TorpedoBomber(int x, int y, float ac1, float maxVel1, int hp, int le, int wi, bool col, double X,
                             double Y,
                             float ac, const float maxVel, int HP, int length, int numTorpedos, int damage) : Vehicle(x,
                                                                                                                      y,
                                                                                                                      ac1,
                                                                                                                      maxVel1,
                                                                                                                      hp,
                                                                                                                      le,
                                                                                                                      wi,
                                                                                                                      col) {

}

void TorpedoBomber::launchTorpedo(Vehicle enemy) {

}

void TorpedoBomber::calculateDistance(Vehicle target) {
    Vehicle::calculateDistance(target);
}

void TorpedoBomber::attack(Vehicle target) {
    Vehicle::attack(target);
}

void TorpedoBomber::update(bool isDead) {
    Vehicle::update(isDead);
}

void TorpedoBomber::attach() {
    Vehicle::attach();
}

void TorpedoBomber::detach() {
    Vehicle::detach();
}

TorpedoBomber::~TorpedoBomber() {

}
