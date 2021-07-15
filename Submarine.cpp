//
// Created by pala on 7/2/21.
//

#include "Submarine.h"


void Submarine::submerge() {

}

Submarine::Submarine(int x, int y, float ac, const float maxVel, int hp, int arm,
                     std::string nat, int numL, int numH, int numM, std::vector<std::unique_ptr<Arsenal>> &arsenalList,
                     std::vector<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi,
                     bool col, ShipType sh, ModelType mo, int numTor, bool isSub) : WarShip(x, y, ac, maxVel, hp, arm,
                                                                                            nat, numL, numH, numM,
                                                                                            arsenalList, vehicleList,
                                                                                            le, wi, col, sh, mo),
                                                                                    numTorpedoTubes(
                                                                                            numTor),
                                                                                    isSubmerged(
                                                                                            isSub) {

}

