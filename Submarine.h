//
// Created by pala on 7/2/21.
//

#ifndef SEALION_SUBMARINE_H
#define SEALION_SUBMARINE_H


#include <string>
#include <memory>
#include <vector>
#include "Arsenal.h"
#include "Vehicle.h"
#include "WarShip.h"

class Submarine : public WarShip {
private:
    bool isSubmerged{false};
    int numTorpedoTubes;
public:
    Submarine(int x, int y, float ac, const float maxVel, int hp, int arm,
              std::string nat, int numL, int numH, int numM, std::vector<std::unique_ptr<Arsenal>> &arsenalList,
              std::vector<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi,
              bool col, ShipType sh, ModelType mo, int numTor, bool isSub);

    void submerge();
};


#endif //SEALION_SUBMARINE_H
