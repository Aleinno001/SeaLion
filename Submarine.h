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

class Submarine {
private:
    bool isSubmerged{false};
    int numTorpedoTubes;
public:
    Submarine(int numTubes, bool submerged, int arm, std::string na, std::string nat, int numL, int numH, int numM,
              std::vector<std::unique_ptr<Arsenal>> arsenalList, std::vector<std::unique_ptr<Vehicle>> vehicleList);

    void submerge();
};


#endif //SEALION_SUBMARINE_H
