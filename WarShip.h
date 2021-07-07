//
// Created by gabriele on 7/1/21.
//

#ifndef SEALION_WARSHIP_H
#define SEALION_WARSHIP_H

#include <string>
#include <memory>
#include <vector>
#include "Vehicle.h"
#include "Arsenal.h"


class WarShip : public Vehicle {
protected:
    const int armour;
    const std::string name;
    const std::string nationality;
    const int numLCannons;
    const int numMCannons;
    const int numHCannons;
    std::vector<std::unique_ptr<Arsenal>> arsenalList;
    std::vector<std::unique_ptr<Vehicle>> vehicleList;
public:
    WarShip(double x, double y, float ac, const float maxVel, int hp, int length, int arm, std::string na,
            std::string nat, int numL, int numH, int numM, std::vector<std::unique_ptr<Arsenal>> &arsenalList,
            std::vector<std::unique_ptr<Vehicle>> &vehicleList);

    virtual void stopMove() = 0;

    virtual void ceaseFire() = 0;

    virtual void registerArsenals() = 0;

    virtual void removeArsenals() = 0;

    virtual void notifyArsenals() = 0;

    const int getArmour() const;

    const std::string &getName() const;

    const std::string &getNationality() const;

    const int getNumLCannons() const;

    const int getNumMCannons() const;

    const int getNumHCannons() const;

    const std::vector<std::unique_ptr<Arsenal>> &getArsenalList() const;

    const std::vector<std::unique_ptr<Vehicle>> &getVehicleList() const;

    virtual ~WarShip() = 0;
};


#endif //SEALION_WARSHIP_H
