//
// Created by alessandro on 04/07/21.
//

#ifndef SEALION_FIGHTER_H
#define SEALION_FIGHTER_H

#include "Vehicle.h"

class Fighter : public Vehicle {
private:
    Fighter(double X, double Y, float ac, const float maxVel, int HP, int length/*SpriteSheet sprite*/);//FIXME sprite

    void fight(Vehicle enemy);

    float calcSpeed(Map battleSea);

    void attack(Vehicle target) override;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach() override;

    void detach() override;

    ~Fighter();
};

#endif //SEALION_FIGHTER_H
