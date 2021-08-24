//
// Created by alessandro on 7/2/21.
//

#include "Battleship.h"

/*
float Battleship::calcSpeed(Map battleSea) {
    return Vehicle::calcSpeed(battleSea);
}
*/

Battleship::Battleship(int x, int y, float ac, const float maxVel, int hp, int arm, std::string nat, int numL,
                       int numH, int numM, int numAa,
                       std::list<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi, bool col, ShipType sh,
                       ModelType mo, int numInterceptors) : WarShip(x, y, ac, maxVel, hp, arm, nat, numL, numH, numM,
                                                                    numAa, vehicleList, le, wi, col, sh,
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

void Battleship::calculateDistance(Vehicle target) {
    Vehicle::calculateDistance(target);
}

void Battleship::update(bool isDead) {
    Vehicle::update(isDead);
}



void Battleship::stopMove() {

}

void Battleship::ceaseFire() {

}

//void Battleship::registerArsenals(std::unique_ptr<Arsenal> observer) {

//}

//void Battleship::removeArsenals(std::unique_ptr<Arsenal> observer) {

//}

void Battleship::notifyArsenals(sf::Vector2f &vel,double mx) {


    std::list<std::shared_ptr<Arsenal>>::iterator it = arsenalList.begin();
    while (it != arsenalList.end()) {
        (*it)->update(vel,mx);
        ++it;
    }


}

Battleship::~Battleship() {

}

void Battleship::rotate() {
    Vehicle::rotate();
}

int Battleship::getNumInterceptors() const {
    return numInterceptors;
}






