//
// Created by alessandro on 02/07/21.
//

#ifndef SEALION_MEDIUMCANNON_H
#define SEALION_MEDIUMCANNON_H

#include "Arsenal.h"

class MediumCannnon : Arsenal {
public:
    //TODO implementare
    //FIXME coordinate da rivedere + sprite
    MediumCannnon(const float range, const int reload, const int rate, int speed, int dispersion, std::string type,
                  float decelleration, int power, int num, double x, double y);

    ~MediumCannnon();

private:
    bool rapidFire();

    void openFire(Vehicle enemy) override;

    void update(double posX, double posY) override; //FIXME posX,posY da rivedere

    void attach() override;

    void detach() override;

    bool engage(Vehicle enemy) override;

    void rotate() override;
};


#endif //SEALION_MEDIUMCANNON_H
