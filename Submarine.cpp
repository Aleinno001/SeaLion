//
// Created by pala on 7/2/21.
//

#include "Submarine.h"


void Submarine::submerge() {

}

Submarine::Submarine(int x1, int y1, float ac1, const float maxVel1, int hp1, int length1, int arm2,
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
                     int wi, bool col, std::string textureName) : WarShip(x1, y1, ac1, maxVel1, hp1, length1, arm2, na2,
                                                                          nat2, numL2, numH2, numM2, arsenalList2,
                                                                          vehicleList2, tex1, sp1, le1, wi1, col1,
                                                                          textureName1, sh, mo) {


}
