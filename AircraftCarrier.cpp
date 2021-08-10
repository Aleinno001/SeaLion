//
// Created by alessandro on 7/2/21.
//


#include "AircraftCarrier.h"


AircraftCarrier::AircraftCarrier(int x, int y, float ac, const float maxVel, int hp, int arm, std::string nat, int numL,
                                 int numH, int numM, int numAA, std::list<std::unique_ptr<Arsenal>> &arsenalList,
                                 std::list<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi, bool col,
                                 ShipType sh, ModelType mo, int planes) : WarShip(x, y, ac,
                                                                                  maxVel, hp, arm,
                                                                                  nat, numL, numH,
                                                                                  numM, numAA,
                                                                                  arsenalList,
                                                                                  vehicleList, le, wi,
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
void AircraftCarrier::attack(Vehicle target) {
    Vehicle::attack(target);
}

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

void AircraftCarrier::notifyArsenals() {

    std::list<std::shared_ptr<Arsenal>>::iterator it = arsenalList.begin();
    while (it != arsenalList.end()) {
        (*it)->update();
        ++it;
    }

}

AircraftCarrier::~AircraftCarrier() {

}

void AircraftCarrier::rotate() {
    Vehicle::rotate();
}

bool AircraftCarrier::canEngage(Vehicle target) {
    return Vehicle::canEngage(target);
}



