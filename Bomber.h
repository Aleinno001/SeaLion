//
// Created by alessandro on 04/07/21.
//

#ifndef SEALION_BOMBER_H
#define SEALION_BOMBER_H


#include "Vehicle.h"

class Bomber : public Vehicle {
private:
    int numBombs;
    int bombDamage;
private:
    //TODO Implementare i metodi
    Bomber(int x, int y, float ac1, float maxVel1, int hp, int le,
           int wi, bool col, double X, double Y, float ac, const float maxVel, int HP,
           int length, int numBombs, int damage);

    void bombard(Vehicle enemy);

    //float calcSpeed();

    void attack(Vehicle target) override;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach() override;

    void detach() override;

    ~Bomber() override;
};


#endif //SEALION_BOMBER_H
