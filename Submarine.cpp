//
// Created by alessandro on 7/2/21.
//

#include "Submarine.h"

void Submarine::submerge() {

}

Submarine::Submarine(int x, int y, float ac, const float maxVel, int hp, int arm,
                     std::string nat, int numL, int numH, int numM, int numAA,
                     std::list<std::unique_ptr<Arsenal>> &arsenalList,
                     std::list<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi,
                     bool col, ShipType sh, ModelType mo, int numTor, bool isSub) : WarShip(x, y, ac, maxVel, hp, arm,
                                                                                            nat, numL, numH, numM,
                                                                                            numAA,
                                                                                            arsenalList, vehicleList,
                                                                                            le, wi, col, sh, mo),
                                                                                    numTorpedoTubes(
                                                                                            numTor),
                                                                                    isSubmerged(
                                                                                            isSub) {
    std::string textureName;
    switch (mo) {
        case ModelType::DaVinci:
            textureName = "DaVinci";
            break;
        case ModelType::Papa:
            textureName = "Papa";
            break;
        case ModelType::I400:
            textureName = "I400";
            break;
        case ModelType::typeb1:
            textureName = "Type-B-1";
            break;
        case ModelType::Trenchant:
            textureName = "Trenchant";
            break;
        case ModelType::Triton:
            textureName = "Triton";
            break;
        case ModelType::Gato:
            textureName = "Gato";
            break;
        case ModelType::Narwhal:
            textureName = "Narwhal";
            break;
    }
    try {
        setUpSprite("Submarines/" + textureName);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Wrong texture name" << std::endl;
    }
}

void Submarine::attack(Vehicle target) {
    Vehicle::attack(target);
}

void Submarine::calculateDistance(Vehicle target) {
    Vehicle::calculateDistance(target);
}

void Submarine::update(bool isDead) {
    Vehicle::update(isDead);
}


void Submarine::stopMove() {

}

void Submarine::ceaseFire() {

}

//void Submarine::registerArsenals(std::unique_ptr<Arsenal> observer) {

//}

//void Submarine::removeArsenals(std::unique_ptr<Arsenal> observer) {

//}

void Submarine::notifyArsenals() {
    std::list<std::unique_ptr<Arsenal>>::iterator it = arsenalList.begin();
    while (it != arsenalList.end()) {
        (*it)->update(static_cast<std::unique_ptr<WarShip>>(this));
        ++it;
    }
}

void Submarine::rotate() {
    Vehicle::rotate();
}

bool Submarine::canEngage(Vehicle target) {
    return Vehicle::canEngage(target);
}


