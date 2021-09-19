//
// Created by pala on 9/17/21.
//
#ifndef SEALION_CONCRETEWARPLANE_H
#define SEALION_CONCRETEWARPLANE_H
#include "WarPlane.h"

class ConcreteWarPlane : public WarPlane{
public:
    ConcreteWarPlane(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string &nat,float currCoolDown, float coolDown, int numAmmo, int ammoDamage,WarShip &sub) : WarPlane(x, y, ac, maxVel, hp, le, wi, col, nat, currCoolDown, coolDown, numAmmo, ammoDamage),subject_(sub){}
    ~ConcreteWarPlane() override = default;
    void update() override;
    bool searchTarget() override;
protected:
    void attack() override;
    float rotate(float mx, float rotatingInPlaceMult) override;
    bool canEngage() override;
    void move() override;
private:
    WarShip &subject_;
};
#endif //SEALION_CONCRETEWARPLANE_H
