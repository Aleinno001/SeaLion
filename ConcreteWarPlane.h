//
// Created by pala on 9/17/21.
//
#ifndef SEALION_CONCRETEWARPLANE_H
#define SEALION_CONCRETEWARPLANE_H
#include "WarPlane.h"
#include "ConcreteWarShip.h"
#include "ToolBox.h"
#include "Tools.h"

class ConcreteWarPlane : public WarPlane{
public:
    ConcreteWarPlane(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string &nat, int numAmmo, int ammoDamage,WarShip &sub) : WarPlane(x, y, ac, maxVel, hp, le, wi, col, nat, numAmmo, ammoDamage), subject_(sub){
        target=std::shared_ptr<WarShip>(&subject_);
    }
    void update() override;
    bool searchTarget(float elapsedTime) override;
    void drawEquipment(sf::RenderWindow &window) override;
protected:
    void attack(float elapsedTime) override;
    float rotate(float mx, float rotatingInPlaceMult) override;
    bool canEngage() override;
    void move(float elapsedTime) override;
private:
    WarShip &subject_;
};
#endif //SEALION_CONCRETEWARPLANE_H
