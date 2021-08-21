//
// Created by davide on 02/07/21.
//

#ifndef SEALION_ANTIAIRCRAFT_H
#define SEALION_ANTIAIRCRAFT_H

#include "Arsenal.h"
#include <iostream>
#include "WarShip.h"

class AntiAircraft : public Arsenal {
public:
    //TODO implementare

    AntiAircraft(const float range, const int reload, int speed, int dispersion, Bullet type,
                 float decelleration, int power, int num, int le, int wi, std::string texName, WarShip &sub);

    ~AntiAircraft() override;

private:
    WarShip &subject_;

    bool airStrafe();

    void openFire(Vehicle enemy) override;

    void update(sf::Vector2f &vel,double mx) override;


    void removeMeFromTheList() {
        subject_.detach(std::shared_ptr<Arsenal>(this));
    }

    bool engage(Vehicle enemy) override;

    void rotate() override;

    bool setUpSprite(std::string textureName) override;

    void resetOrigin() override;
};


#endif //SEALION_ANTIAIRCRAFT_H
