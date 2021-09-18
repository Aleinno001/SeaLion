//
// Created by davide on 18/09/21.
//

#include "OldAircraftCarrier.h"
OldAircraftCarrier::OldAircraftCarrier(int x, int y, float ac, const float maxVel, int hp, int arm, std::string nat, int numL,
                                 int numH, int numM, int numAA,
                                 int le, int wi, bool col,
                                 ShipType sh, ModelType mo, int planes) : WarShip(x, y, ac,
                                                                                  maxVel, hp, arm,
                                                                                  nat, numL, numH,
                                                                                  numM, numAA,
                                                                                  le, wi,
                                                                                  col, sh,
                                                                                  mo),
                                                                          numPlanes(planes) {
    std::string textureName;
    switch (mo) {
        case ModelType::Hiryu:
            textureName = "Hiryu";
            break;
        case ModelType::Tahio:
            textureName = "Tahio";
            break;
        case ModelType::Cavour:
            textureName = "Cavour";
            break;
        case ModelType::GiuseppeGaribaldi:
            textureName = "GiuseppeGaribaldi";
            break;
        case ModelType::ArkRoyal:
            textureName = "ArkRoyal";
            break;
        case ModelType::Indomitable:
            textureName = "Indomitable";
            break;
        case ModelType::FranklinDRoosevelt:
            textureName = "FranklinDelanoRoosevelt";
            break;
        case ModelType::Midway:
            textureName = "Midway";
            break;
    }
    try {
        setUpSprite("AircraftCarrier/" + textureName);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Wrong texture name" << std::endl;
    }
}
/*
float AircraftCarrier::calcSpeed(Map battleSea) {
    return Vehicle::calcSpeed(battleSea);
}
*/
void OldAircraftCarrier::notifyArsenals(sf::Vector2f &vel, double mx) {
    auto it = arsenalList.begin();
    while (it != arsenalList.end()) {
        (*it)->update(vel, mx);
        ++it;
    }
}
OldAircraftCarrier::~OldAircraftCarrier() = default;
int OldAircraftCarrier::getNumPlanes() const {
    return numPlanes;
}
void OldAircraftCarrier::notifyPlanes(sf::Vector2f &vel, double mx) {
    auto it = vehicleList.begin();
    while (it != vehicleList.end()) {
        (*it)->updatePlanes(vel, mx);
        ++it;
    }
}
void OldAircraftCarrier::detachPlanes(const std::shared_ptr<Vehicle> &warPlanes) {
    vehicleList.remove(warPlanes);
}
void OldAircraftCarrier::attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) {
    vehicleList.push_back(warPlanes);
}
void OldAircraftCarrier::detach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.remove(gun);
}
void OldAircraftCarrier::attach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.push_back(gun);
}
void OldAircraftCarrier::notifyBars(sf::Vector2f &vel, double mx) {
    auto it = bars.begin();
    while (it != bars.end()) {
        (*it)->updateBars(vel, mx);
        ++it;
    }
}
void OldAircraftCarrier::attachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.push_back(bar);
}
void OldAircraftCarrier::detachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.remove(bar);
}
void OldAircraftCarrier::notifyBarsDamage() {
    auto it = bars.begin();
    while (it != bars.end()) {
        (*it)->updateBarsDamage();
        ++it;
    }
}
void OldAircraftCarrier::notifyMvcObserver() {
    for (auto &it: listMvcObservers)
        it->updateMvcObserver();
}
void OldAircraftCarrier::addMvcObserver(std::shared_ptr<MvcObserver> o) {
    listMvcObservers.push_back(o);
}
void OldAircraftCarrier::removeMvcObserver(std::shared_ptr<MvcObserver> o) {
    listMvcObservers.remove(o);
}
void OldAircraftCarriervcraftCarrier::searchAndHuntDownEnemyTargets(std::_List_iterator<std::unique_ptr<WarShip>> &target, double dt) {
    ::searchAndHuntDownEnemyTargets(std::_List_iterator<std::unique_ptr<WarShip>> &target, double dt) {
//TODO code for searching and attacking enemy targets
    for (auto iter = vehicleList.begin(); iter != vehicleList.end(); ++iter) {
        iter->get()->moveAndAttack(reinterpret_cast<const std::_List_iterator<std::unique_ptr<Vehicle>> &>(target), dt);
    }
}
std::list<std::shared_ptr<MvcObserver>> OldAircraftCarrier::getListMvcObservers() {
    return listMvcObservers;
}
OldAircraftCarrier &AircraftCarrier::getInstance() {
    return *this;
}
