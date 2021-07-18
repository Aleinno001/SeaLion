//
// Created by pala on 02/07/21.
//

#ifndef SEALION_MEDIUMCANNON_H
#define SEALION_MEDIUMCANNON_H

#include "Arsenal.h"
#include "Bullet.h"

class MediumCannnon : public Arsenal {
public:
    //TODO implementare



    MediumCannnon(const float range, const int reload, int speed, int dispersion, Bullet type,
                  float decelleration, int power, int num, int posX, int posY, int le, int wi, std::string texName);

    ~MediumCannnon() override;

private:
    bool rapidFire();

    void openFire(Vehicle enemy) override;

    void update(std::unique_ptr<WarShip> theChangedSubject) override;

    void attach() override;

    void detach() override;

    bool engage(Vehicle enemy) override;

    void rotate() override;
};


#endif //SEALION_MEDIUMCANNON_H
