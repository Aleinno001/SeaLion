//
// Created by pala on 7/2/21.
//

#include "Submarine.h"


void Submarine::submerge() {

}

Submarine::Submarine(int x, int y, float ac, const float maxVel, int hp, int length, int arm1,
                     std::string na1, std::string nat1, int numL1, int numH1, int numM1,
                     std::vector<std::unique_ptr<Arsenal>> &arsenalList1,
                     std::vector<std::unique_ptr<Vehicle>> &vehicleList1, int numTubes, bool submerged, int arm,
                     std::string na, std::string nat, int numL, int numH, int numM,
                     std::vector<std::unique_ptr<Arsenal>> &arsenalList,
                     std::vector<std::unique_ptr<Vehicle>> &vehicleList, sf::Texture tex, sf::Sprite sp, int le, int wi,
                     bool col, std::string textureName) : WarShip(x, y, ac, maxVel, hp, length, arm1,
                                                                  na1, nat1, numL1, numH1, numM1,
                                                                  arsenalList1, vehicleList1, tex, sp, le, wi, col,
                                                                  textureName) {


}
