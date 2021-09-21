//
// Created by pala on 9/16/21.
//
#ifndef SEALION_WARPLANE_H
#define SEALION_WARPLANE_H

#include "WarShip.h"

class WarPlane : public Vehicle {
protected:
    float currentCoolDown{0};
    const float coolDown{6};
    int numAmmo;
    int ammoDamage;
    std::shared_ptr<WarShip> target;
public:
    WarPlane(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string &nat, int numAmmo, int ammoDamage) : Vehicle(x, y, ac, maxVel, hp, le, wi,col, nat),currentCoolDown(currentCoolDown),coolDown(coolDown), numAmmo(numAmmo),ammoDamage(ammoDamage){};
    void setTarget(const std::shared_ptr<WarShip> &tar) {WarPlane::target = tar;}
    virtual void update()=0; //Metodo per design pattern observer tra planes and Warship
};
#endif //SEALION_WARPLANE_H
