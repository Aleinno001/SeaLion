//
// Created by davide on 02/07/21.
//

#include "TorpedoTube.h"

TorpedoTube::TorpedoTube(const float range, const int reload, int speed, int dispersion,
                         Bullet type, float decelleration, int power, int num, int le,
                         int wi, std::string texName) : Arsenal(range, reload, speed, dispersion, type,
                                                                decelleration, power, num, 0, 0, le, wi,
                                                                texName) {

}

TorpedoTube::~TorpedoTube() {

}

bool TorpedoTube::accuracy() {
    return false;
}

void TorpedoTube::openFire(Vehicle enemy) {

}

void TorpedoTube::update(std::unique_ptr<WarShip> theChangedSubject) {

}



bool TorpedoTube::engage(Vehicle enemy) {
    return false;
}

void TorpedoTube::rotate() {

}

void TorpedoTube::resetOrigin() {

}
