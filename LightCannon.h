//
// Created by davide on 02/07/21.
//

#ifndef SEALION_LIGHTCANNON_H
#define SEALION_LIGHTCANNON_H

#include "Arsenal.h"
#include <SFML/Graphics.hpp>
#include "WarShip.h"

class LightCannon : public Arsenal {
public:
    //TODO implementare

    LightCannon(float range, const int reload, int speed, int dispersion,
                Bullet type, float decelleration, int power, int num, int posX, int posY, int le, int wi,
                std::string texName, WarShip &sub);

    ~LightCannon() override;

private:

    WarShip &subject_;

    bool accuracy();

    void openFire(Vehicle enemy) override;

    void update() override;

    void removeMeFromTheList() {
        subject_.detach(std::shared_ptr<Arsenal>(this));
    }

    bool engage(Vehicle enemy) override;

    void rotate() override;

    void resetOrigin() override;

    void update(sf::Vector2f &vel, double mx);
};


#endif //SEALION_LIGHTCANNON_H
