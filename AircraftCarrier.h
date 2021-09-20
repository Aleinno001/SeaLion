//
// Created by alessandro on 19/09/21.
//

#ifndef SEALION_AIRCRAFTCARRIER_H
#define SEALION_AIRCRAFTCARRIER_H


#include "ConcreteWarShip.h"
#include "MvcObserver.h"
#include "MvcSubject.h"
#include "WarPlane.h"

class AircraftCarrier : public ConcreteWarShip, MvcSubject{
private:
    float numPlanes;
    std::list<std::shared_ptr<MvcObserver>> listMvcObservers;
    std::list<std::shared_ptr<WarPlane>> planes;
public:
    AircraftCarrier(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string &nat,ShipType shipType, ModelType modelType, int armour, const std::string &name, int numLCannons,int numMCannons, int numHCannons, int numAntiAircraft, int numPlanes);
    ~AircraftCarrier() override;
    void planesAttack();
    void notifyPlanes();
    void attachPlanes(const std::shared_ptr<WarPlane> &warPlane);
    void detachPlanes(const std::shared_ptr<WarPlane> &warPlane);
    void notifyMvcObserver() override;
    void addMvcObserver(std::shared_ptr<MvcObserver> o) override;
    void removeMvcObserver(std::shared_ptr<MvcObserver> o) override;
    float getNumPlanes() const;
};


#endif //SEALION_AIRCRAFTCARRIER_H
