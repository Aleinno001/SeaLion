//
// Created by alessandro on 02/07/21.
//

#ifndef SEALION_LIGHTCANNON_H
#define SEALION_LIGHTCANNON_H

#include "Arsenal.h"

class LightCannon : Arsenal {
public:
    //TODO implementare
    //FIXME coordinate da rivedere + sprite
    LightCannon(const float range, const int reload, const int rate, int speed, int dispersion, std::string type,
                float decelleration, int power, int num, double x, double y);

    ~LightCannon();

private:
    bool accuracy();

    void openFire(Vehicle enemy) override;

    void update(double posX, double posY) override; //FIXME posX,posY da rivedere

    void attach() override;

    void detach() override;

    bool engage(Vehicle enemy) override;

    void rotate() override;
};


#endif //SEALION_LIGHTCANNON_H
