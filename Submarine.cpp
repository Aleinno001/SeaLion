//
// Created by pala on 7/2/21.
//

#include "Submarine.h"


void Submarine::submerge() {

}

Submarine::Submarine(int x, int y, float ac, const float maxVel, int hp, int length, int arm, std::string na,
                     std::string nat, int numL, int numH, int numM, std::vector<std::unique_ptr<Arsenal>> &arsenalList,
                     std::vector<std::unique_ptr<Vehicle>> &vehicleList, sf::Texture tex, sf::Sprite sp, int le, int wi,
                     bool col, std::string textureName, ShipType sh, ModelType mo, int numTor, bool isSub) : WarShip(x,
                                                                                                                     y,
                                                                                                                     ac,
                                                                                                                     maxVel,
                                                                                                                     hp,
                                                                                                                     length,
                                                                                                                     arm,
                                                                                                                     na,
                                                                                                                     nat,
                                                                                                                     numL,
                                                                                                                     numH,
                                                                                                                     numM,
                                                                                                                     arsenalList,
                                                                                                                     vehicleList,
                                                                                                                     tex,
                                                                                                                     sp,
                                                                                                                     le,
                                                                                                                     wi,
                                                                                                                     col,
                                                                                                                     textureName,
                                                                                                                     sh,
                                                                                                                     mo),
                                                                                                             numTorpedoTubes(
                                                                                                                     numTor),
                                                                                                             isSubmerged(
                                                                                                                     isSub) {

}

