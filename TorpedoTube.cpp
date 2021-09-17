//
// Created by davide on 02/07/21.
//

#include "TorpedoTube.h"

TorpedoTube::TorpedoTube(const float range, const int reload, int dispersion,
                         std::shared_ptr<Bullet> type, int power, int le,
                         int wi, std::string texName, WarShip &sub) : subject_(sub),
                                                                      Arsenal(range, reload, dispersion, type,
                                                                              power, 0, 0, le, wi,texName) {
}
TorpedoTube::~TorpedoTube() {
}
bool TorpedoTube::accuracy() {
    return false;
}
void TorpedoTube::openFire(Vehicle enemy) {
}
bool TorpedoTube::engage(Vehicle enemy) {
    return false;
}
void TorpedoTube::rotate() {
}
void TorpedoTube::resetOrigin() {
}
void TorpedoTube::update(sf::Vector2f &vel, double mx) {
}
