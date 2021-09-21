//
// Created by alessandro on 21/09/21.
//

#ifndef SEALION_SPECIALTY_H
#define SEALION_SPECIALTY_H

#include "WarShip.h"
#include "MvcSubject.h"

class Specialty : public WarShip,MvcSubject{
protected:
    std::list<std::shared_ptr<MvcObserver>> listMvcObservers;
public:
    Specialty(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string &nat,ShipType shipType, ModelType modelType, const int armour, const std::string &name, const int numLCannons,const int numMCannons, const int numHCannons, const int numAntiAircraft) : WarShip(x, y, ac, maxVel, hp,le, wi, col, nat,shipType, modelType,armour, name,numLCannons,numMCannons,numHCannons,numAntiAircraft) {}
    const std::list<std::shared_ptr<MvcObserver>> &getListMvcObservers() const {return listMvcObservers;}
    virtual void setMvcTarget(std::shared_ptr<WarShip> target)=0;
    virtual void specialAttack()=0;
    void notifyMvcObserver() override {
        for (auto &it: listMvcObservers)
            it->updateMvcObserver();
    }
    void addMvcObserver(std::shared_ptr<MvcObserver> o) override{listMvcObservers.push_back(o);}
    void removeMvcObserver(std::shared_ptr<MvcObserver> o) override{listMvcObservers.remove(o);}
};

#endif //SEALION_SPECIALTY_H
