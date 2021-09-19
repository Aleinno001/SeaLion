//
// Created by alessandro on 19/09/21.
//

#include "AircraftCarrier.h"
AircraftCarrier::AircraftCarrier(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col,std::string &nat, ShipType shipType, ModelType modelType, int armour,const std::string &name, int numLCannons, int numMCannons, int numHCannons,int numAntiAircraft, int numPlanes) : ConcreteWarShip(x, y, ac, maxVel, hp, le, wi,col, nat, shipType, modelType,armour, name, numLCannons,numMCannons, numHCannons,numAntiAircraft),AircraftCarrierSpecialty(numPlanes) {}
void AircraftCarrier::notifyMvcObserver() {
    for (auto &it: listMvcObservers)
        it->updateMvcObserver();
}
void AircraftCarrier::addMvcObserver(std::shared_ptr<MvcObserver> o) {
    listMvcObservers.push_back(o);
}
void AircraftCarrier::removeMvcObserver(std::shared_ptr<MvcObserver> o) {
    listMvcObservers.remove(o);
}
void AircraftCarrier::notifyPlanes(sf::Vector2f &vel, double mx) {
    for(auto &itPlanes : planes){
        itPlanes->update();
    }
}
void AircraftCarrier::attachPlanes(const std::shared_ptr<WarPlane> &warPlane) {
    planes.push_back(warPlane);
}
void AircraftCarrier::detachPlanes(const std::shared_ptr<WarPlane> &warPlane) {
    planes.remove(warPlane);
}
void AircraftCarrier::planesAttack() {
    for(auto &itPlanes : planes){
        itPlanes->searchTarget();
    }
}
AircraftCarrier::~AircraftCarrier() = default;