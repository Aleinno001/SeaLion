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
    Submarine(int x1, int y1, float ac1, const float maxVel1, int hp1, int length1, int arm2,
              std::string na2, std::string nat2, int numL2, int numH2, int numM2,
              std::vector<std::unique_ptr<Arsenal>> &arsenalList2,
              std::vector<std::unique_ptr<Vehicle>> &vehicleList2, sf::Texture tex1, sf::Sprite sp1, int le1,
              int wi1, bool col1, std::string textureName1, ShipType sh, ModelType mo, int x, int y,
              float ac, const float maxVel, int hp, int length, int arm1, std::string na1, std::string nat1,
              int numL1, int numH1, int numM1, std::vector<std::unique_ptr<Arsenal>> &arsenalList1,
              std::vector<std::unique_ptr<Vehicle>> &vehicleList1, int numTubes, bool submerged, int arm,
              std::string na, std::string nat, int numL, int numH, int numM,
              std::vector<std::unique_ptr<Arsenal>> &arsenalList,
              std::vector<std::unique_ptr<Vehicle>> &vehicleList, sf::Texture tex, sf::Sprite sp, int le,
              int wi, bool col, std::string textureName);

    void submerge();
};


#endif //SEALION_SUBMARINE_H
