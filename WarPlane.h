//
// Created by pala on 9/16/21.
//
#ifndef SEALION_WARPLANE_H
#define SEALION_WARPLANE_H
#include "Vehicle.h"
class WarPlane : public Vehicle {
protected:
    float currentCoolDown{0};
    const float coolDown{6};
    int numAmmo;
    int ammoDamage;
public:
    WarPlane(float currCoolDown,float coolDown,int numAmmo,int ammoDamage):currentCoolDown(currCoolDown),coolDown(coolDown),numAmmo(numAmmo),ammoDamage(ammoDamage){};
    virtual void update()=0; //Metodo per design pattern observer tra planes and Warship
    ~WarPlane() override=0;
};
#endif //SEALION_WARPLANE_H
