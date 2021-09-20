//
// Created by alessandro on 19/09/21.
//

#include "ConcreteAircraftCarrier.h"
ConcreteAircraftCarrier::ConcreteAircraftCarrier(float x, float y, float ac, float maxVel, int hp, int le, int wi,bool col, std::string &nat, ShipType shipType, ModelType modelType,int armour, const std::string &name, int numLCannons, int numMCannons,int numHCannons, int numAntiAircraft, int numPlanes) : AircraftCarrier(x, y, ac, maxVel, hp, le, wi, col, nat, shipType, modelType, armour, name, numLCannons, numMCannons,numHCannons, numAntiAircraft, numPlanes) {}
void ConcreteAircraftCarrier::notifyMvcObserver() {
    for (auto &it: listMvcObservers)
        it->updateMvcObserver();
}
void ConcreteAircraftCarrier::addMvcObserver(std::shared_ptr<MvcObserver> o) {
    listMvcObservers.push_back(o);
}
void ConcreteAircraftCarrier::removeMvcObserver(std::shared_ptr<MvcObserver> o) {
    listMvcObservers.remove(o);
}
void ConcreteAircraftCarrier::notifyPlanes() {
    for(auto &itPlanes : planes){
        itPlanes->update();
    }
}
void ConcreteAircraftCarrier::attachPlanes(const std::shared_ptr<WarPlane> &warPlane) {
    planes.push_back(warPlane);
}
void ConcreteAircraftCarrier::detachPlanes(const std::shared_ptr<WarPlane> &warPlane) {
    planes.remove(warPlane);
}
void ConcreteAircraftCarrier::planesAttack() {
    for(auto &itPlanes : planes){
        itPlanes->searchTarget();
    }
}
float ConcreteAircraftCarrier::getNumPlanes() const {
    return numPlanes;
}
ConcreteAircraftCarrier::~ConcreteAircraftCarrier() = default;