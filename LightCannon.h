//
// Created by davide on 02/07/21.
//

#ifndef SEALION_LIGHTCANNON_H
#define SEALION_LIGHTCANNON_H

#include "Arsenal.h"

class LightCannon : public Arsenal {
public:
    //TODO implementare

    LightCannon(float range, const int reload, int speed, int dispersion,
                Bullet type, float decelleration, int power, int num, int x, int y, int le, int wi,
                std::string texName);

    ~LightCannon() override;

private:
    bool accuracy();

    void openFire(Vehicle enemy) override;

    void update(std::unique_ptr<WarShip> theChangedSubject) override;

    void attach() override;

    void detach() override;

    bool engage(Vehicle enemy) override;

    void rotate() override;
};


#endif //SEALION_LIGHTCANNON_H
