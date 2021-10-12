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
    float ammoDamage;
    std::shared_ptr<WarShip> target;
    bool setUpSprite(const std::string &textureName) override;
public:
    WarPlane(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string nat, int numAmmo, int ammoDamage,std::string name) : Vehicle(x, y, ac, maxVel, hp, le, wi,col, nat,name),currentCoolDown(currentCoolDown),coolDown(coolDown), ammoDamage(ammoDamage){};
    void setTarget(std::shared_ptr<WarShip> tar) {target = tar;}
    virtual void update()=0; //Metodo per design pattern observer tra planes and Warship
    ~WarPlane()=default;
};
#endif //SEALION_WARPLANE_H
