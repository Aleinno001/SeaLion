//
// Created by davide on 18/09/21.
//

#include "OldDestroyer.h"
/*
float Destroyer::calcSpeed() {
    return Vehicle::calcSpeed();
}
*/

OldDestroyer::OldDestroyer(int x, int y, float ac, const float maxVel, int hp, int arm,
                     std::string nat, int numL, int numH, int numM, int numAA,
                     int le, int wi,
                     bool col, ShipType sh, ModelType mo, int torpedo) : WarShip(x, y, ac, maxVel, hp,
                                                                                 arm, nat,
                                                                                 numL, numH, numM, numAA,

                                                                                 le, wi, col, sh, mo),
                                                                         numTorpedoTubes(torpedo) {
    std::string textureName;
    switch (mo) {
        case ModelType::Impavido:
            textureName = "Impavido";
            break;
        case ModelType::Leone:
            textureName = "Leone";
            break;
        case ModelType::PaoloEmilio:
            textureName = "PaoloEmilio";
            break;
        case ModelType::Akizuki:
            textureName = "akizuki";
            break;
        case ModelType::Fubuki:
            textureName = "fubuki";
            break;
        case ModelType::Yukikaze:
            textureName = "yukikaze";
            break;
        case ModelType::Campbelltown:
            textureName = "Campbelltown";
            break;
        case ModelType::Gallant:
            textureName = "Gallant";
            break;
        case ModelType::Jutland:
            textureName = "Jutland";
            break;
        case ModelType::Fletcher:
            textureName = "Fletcher";
            break;
        case ModelType::Mahan:
            textureName = "Mahan";
            break;
        case ModelType::Sims:
            textureName = "Sims";
            break;
    }
    try {
        setUpSprite("Destroyer/" + textureName);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Wrong texture name" << std::endl;
    }
}
void OldDestroyer::update(bool isDead) {
    Vehicle::update(isDead);
}
//void Destroyer::registerArsenals(std::unique_ptr<Arsenal> observer) {
//}
//void Destroyer::removeArsenals(std::unique_ptr<Arsenal> observer) {
//}
void OldDestroyer::notifyArsenals(sf::Vector2f &vel,double mx) {
    auto it = arsenalList.begin();
    while (it != arsenalList.end()) {
        (*it)->update(vel,mx);
        ++it;
    }
}
OldDestroyer::~OldDestroyer() {
}
/*
bool Destroyer::canEngage(std::_List_iterator<std::unique_ptr<WarShip>> target) {
    return WarShip::canEngage(target);
}
*/
bool OldDestroyer::setUpSprite(std::string textureName) {
    return Vehicle::setUpSprite(textureName);
}
int OldDestroyer::getNumTorpedoTubes() const {
    return numTorpedoTubes;
}
void OldDestroyer::notifyPlanes(sf::Vector2f &vel, double mx) {
    auto it = vehicleList.begin();
    while (it != vehicleList.end()) {
        (*it)->updatePlanes(vel,mx);
        ++it;
    }
}
void OldDestroyer::attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) {
    vehicleList.push_back(warPlanes);
}
void OldDestroyer::detachPlanes(const std::shared_ptr<Vehicle> &warPlanes) {
    vehicleList.remove(warPlanes);
}
void OldDestroyer::attach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.push_back(gun);
}

void OldDestroyer::detach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.remove(gun);
}
void OldDestroyer::notifyBars(sf::Vector2f &vel, double mx) {
    auto it = bars.begin();
    while (it != bars.end()) {
        (*it)->updateBars(vel,mx);
        ++it;
    }
}
void OldDestroyer::attachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.push_back(bar);
}
void OldDestroyer::detachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.remove(bar);
}
void OldDestroyer::notifyBarsDamage() {
    auto it = bars.begin();
    while (it != bars.end()) {
        (*it)->updateBarsDamage();
        ++it;
    }
}
