//
// Created by alessandro on 19/09/21.
//

#include "Submarine.h"

Submarine::Submarine(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string &nat,ShipType shipType, ModelType modelType, int armour, const std::string &name, int numLCannons,int numMCannons, int numHCannons, int numAntiAircraft) : ConcreteWarShip(x, y, ac, maxVel, hp, le,wi, col, nat, shipType,modelType, armour, name,numLCannons, numMCannons,numHCannons,numAntiAircraft) {}
Submarine::~Submarine() = default;
void Submarine::notifyMvcObserver() {
    for (auto &it: listMvcObservers)
        it->updateMvcObserver();
}
void Submarine::addMvcObserver(std::shared_ptr<MvcObserver> o) {
    listMvcObservers.push_back(o);
}
void Submarine::removeMvcObserver(std::shared_ptr<MvcObserver> o) {
    listMvcObservers.remove(o);
}
void Submarine::torpedoAttack() {
    //TODO implementare
}