//
// Created by alessandro on 02/07/21.
//

#ifndef SEALION_ANTIAIRCRAFT_H
#define SEALION_ANTIAIRCRAFT_H

#include "Arsenal.h"

class AntiAircraft : Arsenal {
public:
    //TODO implementare
    //FIXME coordinate da rivedere + sprite
    AntiAircraft(const float range, const int reload, const int rate, int speed, int dispersion, std::string type,
                 float decelleration, int power, int num, double x, double y);

    ~AntiAircraft();

private:
    bool airStrafe();

    void openFire(Vehicle enemy) override;

    void update(double posX, double posY) override; //FIXME posX,posY da rivedere

    void attach() override;

    void detach() override;

    bool engage(Vehicle enemy) override;

    void rotate() override;
};


#endif //SEALION_ANTIAIRCRAFT_H
