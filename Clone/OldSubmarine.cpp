//
// Created by davide on 18/09/21.
//

#include "OldSubmarine.h"
void OldSubmarine::submerge() {

}

OldSubmarine::OldSubmarine(int x, int y, float ac, const float maxVel, int hp, int arm,
                     std::string nat, int numL, int numH, int numM, int numAA,
                     int le, int wi,
                     bool col, ShipType sh, ModelType mo, int numTor, bool isSub) : WarShip(x, y, ac, maxVel, hp, arm,
                                                                                            nat, numL, numH, numM,
                                                                                            numAA,
                                                                                            le, wi, col, sh, mo),
                                                                                    numTorpedoTubes(
                                                                                            numTor),
                                                                                    isSubmerged(
                                                                                            isSub) {
    std::string textureName;
    switch (mo) {
        case ModelType::DaVinci:
            textureName = "DaVinci";
            break;
        case ModelType::Papa:
            textureName = "Papa";
            break;
        case ModelType::I400:
            textureName = "I400";
            break;
        case ModelType::typeb1:
            textureName = "Type-B-1";
            break;
        case ModelType::Trenchant:
            textureName = "Trenchant";
            break;
        case ModelType::Triton:
            textureName = "Triton";
            break;
        case ModelType::Gato:
            textureName = "Gato";
            break;
        case ModelType::Narwhal:
            textureName = "Narwhal";
            break;
    }
    try {
        setUpSprite("Submarines/" + textureName);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Wrong texture name" << std::endl;
    }
}
void OldSubmarine::update(bool isDead) {
    Vehicle::update(isDead);
}
//void Submarine::registerArsenals(std::unique_ptr<Arsenal> observer) {
//}
//void Submarine::removeArsenals(std::unique_ptr<Arsenal> observer) {
//}
void OldSubmarine::notifyArsenals(sf::Vector2f &vel,double mx) {
    auto it = arsenalList.begin();
    while (it != arsenalList.end()) {
        (*it)->update(vel,mx);
        ++it;
    }
}
/*
bool Submarine::canEngage(std::_List_iterator<std::unique_ptr<WarShip>> target) {
    return WarShip::canEngage(target);
}
*/
void OldSubmarine::notifyPlanes(sf::Vector2f &vel, double mx) {
    auto it = vehicleList.begin();
    while (it != vehicleList.end()) {
        (*it)->updatePlanes(vel,mx);
        ++it;
    }
}
void OldSubmarine::notifyBars(sf::Vector2f &vel, double mx) {
    auto it = bars.begin();
    while (it != bars.end()) {
        (*it)->updateBars(vel,mx);
        ++it;
    }
}
void OldSubmarine::attachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.push_back(bar);
}
void OldSubmarine::detachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.push_back(bar);
}
void OldSubmarine::attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) {
    vehicleList.push_back(warPlanes);
}
void OldSubmarine::detachPlanes(const std::shared_ptr<Vehicle> &warPlanes) {
    vehicleList.remove(warPlanes);
}

void OldSubmarine::detach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.remove(gun);

}
void OldSubmarine::attach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.push_back(gun);
}
void OldSubmarine::notifyBarsDamage() {
    auto it = bars.begin();
    while (it != bars.end()) {
        (*it)->updateBarsDamage();
        ++it;
    }
}