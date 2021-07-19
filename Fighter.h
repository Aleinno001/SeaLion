//
// Created by alessandro on 04/07/21.
//

#ifndef SEALION_FIGHTER_H
#define SEALION_FIGHTER_H

#include "Vehicle.h"

class Fighter : public Vehicle {
private:
    Fighter(int x, int y, float ac1, float maxVel1, int hp,
            int le, int wi, bool col, double X, double Y, float ac,
            const float maxVel, int HP, int length);

    void fight(Vehicle enemy);

    //float calcSpeed();

    void attack(Vehicle target) override;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach() override;

    void detach() override;

    ~Fighter() override;
};

#endif //SEALION_FIGHTER_H
