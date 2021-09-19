//
// Created by pala on 9/18/21.
//
#ifndef SEALION_LIGHTCANNON_H
#define SEALION_LIGHTCANNON_H

#include "Arsenal.h"
#include <SFML/Graphics.hpp>
#include "WarShip.h"

class LightCannon : public Arsenal {
public:
    //TODO implementare
    LightCannon(float range, const int reload, int dispersion,
                std::shared_ptr<Bullet> type, int power, int posX, int posY, int le, int wi,
                std::string texName, WarShip &sub);

    ~LightCannon() override;
    void removeMeFromTheList() {
        subject_.detach(std::shared_ptr<Arsenal>(this));
    }
private:
    WarShip &subject_;
    bool accuracy();
    void openFire(Vehicle enemy) override;
    bool engage(Vehicle enemy) override;
    void rotate() override;
    void resetOrigin() override;
    void update(sf::Vector2f &vel, double mx);
};


#endif //SEALION_LIGHTCANNON_H