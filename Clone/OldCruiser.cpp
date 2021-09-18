//
// Created by davide on 18/09/21.
//

#include "OldCruiser.h"
/*
float Cruiser::calcSpeed(Map battleSea) {
    return Vehicle::calcSpeed(battleSea);
}
*/
OldCruiser::OldCruiser(int x, int y, float ac, const float maxVel, int hp, int arm,
                 std::string nat, int numL, int numH, int numM, int numAA,
                 int le, int wi,
                 bool col, ShipType sh, ModelType mo, int planes) : WarShip(x, y, ac, maxVel, hp, arm, nat,
                                                                            numL, numH, numM, numAA,
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
void OldCruiser::update(bool isDead) {
    Vehicle::update(isDead);
}
//void Cruiser::registerArsenals(std::unique_ptr<Arsenal> observer) {
//}
//void Cruiser::removeArsenals(std::unique_ptr<Arsenal> observer) {
//}
void OldCruiser::notifyArsenals(sf::Vector2f &vel,double mx) {
    auto it = arsenalList.begin();
    while (it != arsenalList.end()) {
        (*it)->update(vel,mx);
        ++it;
    }
}
OldCruiser::~OldCruiser() {
}
int OldCruiser::getNumPlanes() const {
    return numPlanes;
}
void OldCruiser::attach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.push_back(gun);
}
void OldCruiser::notifyPlanes(sf::Vector2f &vel, double mx) {
    auto it = vehicleList.begin();
    while (it != vehicleList.end()) {
        (*it)->updatePlanes(vel,mx);
        ++it;
    }
}
void OldCruiser::detachPlanes(const std::shared_ptr<Vehicle> &warPlanes) {
    vehicleList.remove(warPlanes);
}
void OldCruiser::attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) {
    vehicleList.push_back(warPlanes);
}
void OldCruiser::detach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.remove(gun);
}
void OldCruiser::notifyBars(sf::Vector2f &vel, double mx) {
    auto it = bars.begin();
    while(it != bars.end()){
        (*it)->updateBars(vel,mx);
        ++it;
    }
}
void OldCruiser::attachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.push_back(bar);
}
void OldCruiser::detachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.remove(bar);
}
void OldCruiser::notifyBarsDamage() {
    auto it = bars.begin();
    while (it != bars.end()) {
        (*it)->updateBarsDamage();
        ++it;
    }
}
