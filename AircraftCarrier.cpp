//
// Created by alessandro on 7/2/21.
//


#include "AircraftCarrier.h"


AircraftCarrier::AircraftCarrier(int x, int y, float ac, const float maxVel, int hp, int arm, std::string nat, int numL,
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

void AircraftCarrier::calculateDistance(Vehicle target) {
    Vehicle::calculateDistance(target);
}

void AircraftCarrier::update(bool isDead) {
    Vehicle::update(isDead);
}


void AircraftCarrier::stopMove() {

}

void AircraftCarrier::ceaseFire() {

}

void AircraftCarrier::notifyArsenals(sf::Vector2f &vel,double mx) {

    auto it = arsenalList.begin();
    while (it != arsenalList.end()) {
        (*it)->update(vel,mx);
        ++it;
    }

}

AircraftCarrier::~AircraftCarrier() = default;

void AircraftCarrier::rotate() {
    Vehicle::rotate();
}

int AircraftCarrier::getNumPlanes() const {
    return numPlanes;
}

void AircraftCarrier::notifyPlanes(sf::Vector2f &vel, double mx) {
    auto it = vehicleList.begin();
    while (it != vehicleList.end()) {
        (*it)->updatePlanes(vel,mx);
        ++it;
    }
}

void AircraftCarrier::detachPlanes(const std::shared_ptr<Vehicle> &warPlanes) {
    vehicleList.remove(warPlanes);
}

void AircraftCarrier::attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) {
    vehicleList.push_back(warPlanes);
}

void AircraftCarrier::detach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.remove(gun);

}

void AircraftCarrier::attach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.push_back(gun);

}

void AircraftCarrier::notifyBars(sf::Vector2f &vel, double mx) {
    auto it = bars.begin();
    while(it != bars.end()){
        (*it)->updateBars(vel,mx);
        ++it;
    }
}

void AircraftCarrier::attachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.push_back(bar);
}

void AircraftCarrier::detachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.remove(bar);

}

void AircraftCarrier::notifyBarsDamage() {

    auto it = bars.begin();
    while(it != bars.end()){
        (*it)->updateBarsDamage();
        ++it;
    }

}





