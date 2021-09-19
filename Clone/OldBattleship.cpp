//
// Created by davide on 18/09/21.
//

#include "OldBattleship.h"
/*
float Battleship::calcSpeed(Map battleSea) {
    return Vehicle::calcSpeed(battleSea);
}
*/

OldBattleship::OldBattleship(int x, int y, float ac, const float maxVel, int hp, int arm, std::string nat, int numL,
                       int numH, int numM, int numAa,
                       int le, int wi, bool col, ShipType sh,
                       ModelType mo, int numInterceptors) : WarShip(x, y, ac, maxVel, hp, arm, nat, numL, numH, numM,
                                                                    numAa, le, wi, col, sh,
                                                                    mo), numInterceptors(numInterceptors) {
    std::string textureName;
    switch (mo) {
        case ModelType::AndreaDoria:
            textureName = "AndreaDoria";
            break;
        case ModelType::ImperatoreAugusto:
            textureName = "ImperatoreAugusto";
            break;
        case ModelType::MichelangeloBuonarroti:
            textureName = "MichelangeloBuonarroti";
            break;
        case ModelType::VittorioVeneto:
            textureName = "VittorioVeneto";
            break;
        case ModelType::ISE:
            textureName = "ISE";
            break;
        case ModelType::Kongo:
            textureName = "Kongo";
            break;
        case ModelType::Musashi:
            textureName = "Musashi";
            break;
        case ModelType::Yamato:
            textureName = "Yamato";
            break;
        case ModelType::Dreadnought:
            textureName = "Dreadnought";
            break;
        case ModelType::Hood:
            textureName = "Hood";
            break;
        case ModelType::IronDuke:
            textureName = "IronDuke";
            break;
        case ModelType::Lion:
            textureName = "Lion";
            break;
        case ModelType::Arizona:
            textureName = "Arizona";
            break;
        case ModelType::Montana:
            textureName = "Montana";
            break;
        case ModelType::NewYork:
            textureName = "NewYork";
            break;
        case ModelType::NorthCarolina:
            textureName = "NorthCarolina";
            break;
    }
    try {
        setUpSprite("Battleship/" + textureName);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Wrong texture name" << std::endl;
    }
}
//void Battleship::registerArsenals(std::unique_ptr<Arsenal> observer) {
//}
//void Battleship::removeArsenals(std::unique_ptr<Arsenal> observer) {
//}
void OldBattleship::notifyArsenals(sf::Vector2f &vel,double mx) {
    auto it = arsenalList.begin();
    while (it != arsenalList.end()) {
        (*it)->update(vel,mx);
        ++it;
    }
}
Battleship::~Battleship() {
}
int OldBattleship::getNumInterceptors() const {
    return numInterceptors;
}
void OldBattleship::notifyPlanes(sf::Vector2f &vel, double mx) {
    auto it = vehicleList.begin();
    while (it != vehicleList.end()) {
        (*it)->updatePlanes(vel,mx);
        ++it;
    }
}
void OldBattleship::notifyBars(sf::Vector2f &vel, double mx) {
    auto it = bars.begin();
    while(it != bars.end()){
        (*it)->updateBars(vel,mx);
        ++it;
    }
}
void OldBattleship::attachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.push_back(bar);
}
void OldBattleship::detachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.remove(bar);
}
void OldBattleship::detachPlanes(const std::shared_ptr<Vehicle> &warPlanes) {
    vehicleList.remove(warPlanes);
}
void OldBattleship::attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) {
    vehicleList.push_back(warPlanes);
}
void OldBattleship::detach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.remove(gun);
}
void OldBattleship::attach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.push_back(gun);
}
void OldBattleship::notifyBarsDamage() {
    auto it = bars.begin();
    while (it != bars.end()) {
        (*it)->updateBarsDamage();
        ++it;
    }
}