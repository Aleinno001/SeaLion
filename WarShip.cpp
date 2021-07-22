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


WarShip::WarShip(int x, int y, float ac, const float maxVel, int hp, int arm,
                 std::string nat, int numL, int numH, int numM, int numAA,
                 std::list<std::unique_ptr<Arsenal>> &arsenal,
                 std::list<std::unique_ptr<Vehicle>> &vehicle, int le, int wi,
                 bool col, ShipType sh, ModelType mo) : Vehicle(x, y, ac, maxVel, hp,
                                                                le, wi, col, nat),
                                                        armour(arm),
                                                        numLCannons(numL),
                                                        numHCannons(numH), numMCannons(numM), numAntiAircraft(numAA),
                                                        shipType(sh), modelType(mo) {

    /* for(auto it = arsenal.begin(); it!=arsenal.end(); ++it )
         arsenalList.emplace_back(std::move(it->get()));

  */
    arsenalList.push_back(std::move(arsenal.front()));

}

ShipType WarShip::getShipType() const {
    return shipType;
}

ModelType WarShip::getModelType() const {
    return modelType;
}

const std::list<std::unique_ptr<Arsenal>> &WarShip::getArsenalList() const {
    return arsenalList;
}

const std::list<std::unique_ptr<Vehicle>> &WarShip::getVehicleList() const {
    return vehicleList;
}


