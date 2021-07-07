//
// Created by alessandro on 04/07/21.
//

#ifndef SEALION_TORPEDOBOMBER_H
#define SEALION_TORPEDOBOMBER_H

#include "Vehicle.h"

class TorpedoBomber : public Vehicle {
private:
    int numTorpedos;
    int torpedoDamage;
private:
    TorpedoBomber(double X, double Y, float ac, const float maxVel, int HP, int length, int numTorpedos,
                  int damage/*SpriteSheet sprite*/); //FIXME sprite

    void launchTorpedo(Vehicle enemy);

    //float calcSpeed();

    void attack(Vehicle target) override;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach() override;

    void detach() override;

    ~TorpedoBomber();
};


#endif //SEALION_TORPEDOBOMBER_H
