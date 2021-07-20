//
// Created by alessandro on 7/2/21.
//

#include "Cruiser.h"
/*
float Cruiser::calcSpeed(Map battleSea) {
    return Vehicle::calcSpeed(battleSea);
}
*/
Cruiser::Cruiser(int x, int y, float ac, const float maxVel, int hp, int arm,
                 std::string nat, int numL, int numH, int numM, int numAA,
                 std::list<std::unique_ptr<Arsenal>> &arsenalList,
                 std::list<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi,
                 bool col, ShipType sh, ModelType mo, int planes) : WarShip(x, y, ac, maxVel, hp, arm, nat,
                                                                            numL, numH, numM, numAA,
                                                                            arsenalList,
                                                                            vehicleList,
                                                                            le, wi, col, sh, mo),
                                                                    numPlanes(planes) {
    std::string textureName;
    switch (mo) {
        case ModelType::AlbertoDiGiussano:
            textureName = "AlbertoDiGiussano";
            break;
        case ModelType::Gorizia:
            textureName = "Gorizia";
            break;
        case ModelType::Trento:
            textureName = "Trento";
            break;
        case ModelType::Ijn:
            textureName = "IJN";
            break;
        case ModelType::IsuzuNagara:
            textureName = "IsuzuNagara";
            break;
        case ModelType::Takao:
            textureName = "Takao";
            break;
        case ModelType::Belfast:
            textureName = "Belfast";
            break;
        case ModelType::Danae:
            textureName = "Danae";
            break;
        case ModelType::Tiger59:
            textureName = "Tiger'59";
            break;
        case ModelType::Alaska:
            textureName = "Alaska";
            break;
        case ModelType::NewOrleans:
            textureName = "NewOrleans";
            break;
        case ModelType::StLouis:
            textureName = "StLouis";
            break;
    }
    try {
        setUpSprite("Cruiser/" + textureName);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Wrong texture name" << std::endl;
    }
}

void Cruiser::attack(Vehicle target) {
    Vehicle::attack(target);
}

void Cruiser::calculateDistance(Vehicle target) {
    Vehicle::calculateDistance(target);
}

void Cruiser::update(bool isDead) {
    Vehicle::update(isDead);
}

void Cruiser::attach() {
    Vehicle::attach();
}

void Cruiser::detach() {
    Vehicle::detach();
}

void Cruiser::stopMove() {

}

void Cruiser::ceaseFire() {

}

void Cruiser::registerArsenals(std::unique_ptr<Arsenal> observer) {

}

void Cruiser::removeArsenals(std::unique_ptr<Arsenal> observer) {

}

void Cruiser::notifyArsenals() {

}

Cruiser::~Cruiser() {

}

void Cruiser::rotate() {
    Vehicle::rotate();
}

bool Cruiser::canEngage(Vehicle target) {
    return Vehicle::canEngage(target);
}

