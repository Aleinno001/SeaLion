//
// Created by alessandro on 19/09/21.
//

#ifndef SEALION_SUBMARINE_H
#define SEALION_SUBMARINE_H

#include "ConcreteWarShip.h"
#include "MvcSubject.h"

class Submarine : public  ConcreteWarShip,MvcSubject{
    std::list<std::shared_ptr<MvcObserver>> listMvcObservers;
public:
    Submarine(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string &nat,ShipType shipType, ModelType modelType, int armour, const std::string &name, int numLCannons,int numMCannons, int numHCannons, int numAntiAircraft);
    ~Submarine() override;
    void torpedoAttack() ;
    void notifyMvcObserver() override;
    void addMvcObserver(std::shared_ptr<MvcObserver> o) override;
    void removeMvcObserver(std::shared_ptr<MvcObserver> o) override;
    const std::list<std::shared_ptr<MvcObserver>> &getListMvcObservers() const;
};

#endif //SEALION_SUBMARINE_H
