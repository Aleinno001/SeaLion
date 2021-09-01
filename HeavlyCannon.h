//
// Created by davide on 02/07/21.
//

#ifndef SEALION_HEAVLYCANNON_H
#define SEALION_HEAVLYCANNON_H


#include "Arsenal.h"
#include "Bullet.h"
#include "WarShip.h"

class HeavlyCannon : public Arsenal {
public:
    //TODO implementare


    HeavlyCannon(const float range, const int reload, int dispersion, std::shared_ptr<Bullet> type,
                 int power, int num, int posX, int posY, int le, int wi, std::string texName,
                 WarShip &sub);

    ~HeavlyCannon() override;

private:

    WarShip &subject_;

    bool shoreBombardment();

    void openFire(Vehicle enemy) override;


    void removeMeFromTheList() {
        subject_.detach(std::shared_ptr<Arsenal>(this));
    }

    bool engage(Vehicle enemy) override;

    void rotate() override;

    void resetOrigin() override;

    void update(sf::Vector2f &vel, double mx);
};


#endif //SEALION_HEAVLYCANNON_H
