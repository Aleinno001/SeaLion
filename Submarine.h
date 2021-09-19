//
// Created by alessandro on 19/09/21.
//

#ifndef SEALION_SUBMARINE_H
#define SEALION_SUBMARINE_H

#include "SubmarineSpecialty.h"
#include "ConcreteWarShip.h"

class Submarine : public SubmarineSpecialty, ConcreteWarShip{
public:
    Submarine(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string &nat,ShipType shipType, ModelType modelType, int armour, const std::string &name, int numLCannons,int numMCannons, int numHCannons, int numAntiAircraft);
    ~Submarine() override;
    void torpedoAttack() override;
    void notifyMvcObserver() override;
    void addMvcObserver(std::shared_ptr<MvcObserver> o) override;
    void removeMvcObserver(std::shared_ptr<MvcObserver> o) override;
};

#endif //SEALION_SUBMARINE_H
