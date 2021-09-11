//
// Created by davide on 02/07/21.
//

#ifndef SEALION_MEDIUMCANNON_H
#define SEALION_MEDIUMCANNON_H

#include "Arsenal.h"
#include "Bullet.h"
#include "WarShip.h"
class MediumCannnon : public Arsenal {
public:
    //TODO implementare



    MediumCannnon(const float range, const int reload, int dispersion, std::shared_ptr<Bullet> type,
                  int power, int posX, int posY, int le, int wi, std::string texName,
                  WarShip &sub);

    ~MediumCannnon() override;

    void removeMeFromTheList() {
        subject_.detach(std::shared_ptr<Arsenal>(this));
    }

private:

    WarShip &subject_;

    bool rapidFire();

    void openFire(Vehicle enemy) override;





    bool engage(Vehicle enemy) override;

    void rotate() override;

    void resetOrigin() override;

    void update(sf::Vector2f &vel, double mx);
};


#endif //SEALION_MEDIUMCANNON_H
