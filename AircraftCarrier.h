//
// Created by alessandro on 20/09/21.
//

#ifndef SEALION_AIRCRAFTCARRIER_H
#define SEALION_AIRCRAFTCARRIER_H

#include "Specialty.h"
#include "WarPlane.h"

class AircraftCarrier : public Specialty {
protected:
    int numPlanes;
    std::list<std::shared_ptr<WarPlane>> planes;
public:
    AircraftCarrier(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string &nat,ShipType shipType, ModelType modelType, const int armour, const std::string &name,const int numLCannons, const int numMCannons, const int numHCannons, const int numAntiAircraft,int numPlanes) : Specialty(x, y, ac, maxVel, hp, le, wi, col, nat, shipType, modelType, armour,name, numLCannons, numMCannons, numHCannons, numAntiAircraft),numPlanes(numPlanes) {}
    virtual void notifyPlanes()=0;
    virtual void attachPlanes(const std::shared_ptr<WarPlane> &warPlane)=0;
    virtual void detachPlanes(const std::shared_ptr<WarPlane> &warPlane)=0;
    int getNumPlanes() const {return numPlanes;}
    std::list<std::shared_ptr<WarPlane>> &getPlanes() {return planes;}
    ~AircraftCarrier()=default;
};

#endif //SEALION_AIRCRAFTCARRIER_H
