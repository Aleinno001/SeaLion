//
// Created by davide on 02/07/21.
//

#ifndef SEALION_ANTIAIRCRAFT_H
#define SEALION_ANTIAIRCRAFT_H

#include "Arsenal.h"
#include <iostream>


class AntiAircraft : public Arsenal {
public:
    //TODO implementare

    AntiAircraft(const float range, const int reload, int speed, int dispersion, Bullet type,
                 float decelleration, int power, int num, int le, int wi, std::string texName);

    ~AntiAircraft() override;

private:
    bool airStrafe();

    void openFire(Vehicle enemy) override;

    void update(std::unique_ptr<WarShip> theChangedSubject) override;


    bool engage(Vehicle enemy) override;

    void rotate() override;

    bool setUpSprite(std::string textureName) override;

    void resetOrigin() override;
};


#endif //SEALION_ANTIAIRCRAFT_H
