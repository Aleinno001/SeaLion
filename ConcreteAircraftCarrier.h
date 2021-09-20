//
// Created by alessandro on 19/09/21.
//

#ifndef SEALION_CONCRETEAIRCRAFTCARRIER_H
#define SEALION_CONCRETEAIRCRAFTCARRIER_H

#include "AircraftCarrier.h"

class ConcreteAircraftCarrier : public AircraftCarrier{
private:
    std::list<std::shared_ptr<MvcObserver>> listMvcObservers;
public:
    ConcreteAircraftCarrier(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col,std::string &nat, ShipType shipType, ModelType modelType, int armour,const std::string &name, int numLCannons, int numMCannons, int numHCannons,int numAntiAircraft, int numPlanes);
    ~ConcreteAircraftCarrier() override;
    void planesAttack();
    void notifyPlanes() override;
    void attachPlanes(const std::shared_ptr<WarPlane> &warPlane) override;
    void detachPlanes(const std::shared_ptr<WarPlane> &warPlane) override;
    void notifyMvcObserver() override;
    void addMvcObserver(std::shared_ptr<MvcObserver> o) override;
    void removeMvcObserver(std::shared_ptr<MvcObserver> o) override;
    float getNumPlanes() const;
};


#endif //SEALION_CONCRETEAIRCRAFTCARRIER_H
