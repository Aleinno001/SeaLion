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
    Bomber(double X, double Y, float ac, const float maxVel, int HP, int length, int numBombs,
           int damage/*SpriteSheet sprite*/);

    void bombard(Vehicle enemy);

    float calcSpeed(Map battleSea);

    void attack(Vehicle target) override;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach() override;

    void detach() override;

    ~Bomber();
};


#endif //SEALION_BOMBER_H
