//
// Created by gabriele on 7/1/21.
//

#include "WarShip.h"

const int WarShip::getArmour() const {
    return armour;
}

const std::string &WarShip::getName() const {
    return name;
}

const std::string &WarShip::getNationality() const {
    return nationality;
}

const int WarShip::getNumLCannons() const {
    return numLCannons;
}

const int WarShip::getNumMCannons() const {
    return numMCannons;
}

const int WarShip::getNumHCannons() const {
    return numHCannons;
}

const std::vector<std::unique_ptr<Arsenal>> &WarShip::getArsenalList() const {
    return arsenalList;
}

const std::vector<std::unique_ptr<Vehicle>> &WarShip::getVehicleList() const {
    return vehicleList;
}

WarShip::WarShip(int x, int y, float ac, const float maxVel, int hp, int length, int arm, std::string na,
                 std::string nat, int numL, int numH, int numM, std::vector<std::unique_ptr<Arsenal>> &arsenalList,
                 std::vector<std::unique_ptr<Vehicle>> &vehicleList, sf::Texture tex, sf::Sprite sp, int le, int wi,
                 bool col, std::string textureName, ShipType sh, ModelType mo) : Vehicle(x, y, ac, maxVel, hp, tex, sp,
                                                                                         le, wi, col,
                                                                                         textureName),
                                                                                 armour(arm), name(na),
                                                                                 nationality(nat),
                                                                                 numLCannons(numL),
                                                                                 numHCannons(numH), numMCannons(numM),
                                                                                 shipType(sh), modelType(mo) {


}

ShipType WarShip::getShipType() const {
    return shipType;
}

ModelType WarShip::getModelType() const {
    return modelType;
}


