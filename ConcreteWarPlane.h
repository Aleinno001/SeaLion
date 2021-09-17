//
// Created by pala on 9/17/21.
//
#ifndef SEALION_CONCRETEWARPLANE_H
#define SEALION_CONCRETEWARPLANE_H
#include "WarPlane.h"
#include "WarShip.h"

class ConcreteWarPlane : public WarPlane{
public:
    ConcreteWarPlane(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string &nat,float currCoolDown, float coolDown, int numAmmo, int ammoDamage,WarShip &sub) : WarPlane(x, y, ac, maxVel, hp, le, wi, col, nat, currCoolDown, coolDown, numAmmo, ammoDamage),subject_(sub){}
    void attack() override;
    ~ConcreteWarPlane() override = default;
    void update() override;
    void removeMeFromTheList();
protected:
    bool searchTarget() override;
   float rotate() override;
    bool canEngage() const override;
    void move() override;
private:
    WarShip &subject_;
};
#endif //SEALION_CONCRETEWARPLANE_H
