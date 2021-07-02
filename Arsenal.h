//
// Created by gabriele on 7/2/21.
//

#ifndef SEALION_ARSENAL_H
#define SEALION_ARSENAL_H

#include <cstdlib>
#include <string>
#include "Vehicle.h"

class Arsenal {
protected:
    const float rangeOfFire;
    const int reloadTime;
    const int rateOfFire;
    int ammoSpeed;
    int maximumDispersion;
    std::string ammoType;
    float ammoDeceleration;
    int firepower;
    int numAmmo;
    double posX;
    double posY;  //FIXME posX,posY da rivedere quando la mappa sarà definita
    //TODO sprite/grafica
public:
    //TODO implementare i metodi
    virtual void openFire(Vehicle enemy);

    virtual void update(double posX, double posY); //FIXME posX,posY da rivedere
    virtual void attach();

    virtual void detach();

    //getter
    const float getRangeOfFire() const;

    const int getReloadTime() const;

    const int getRateOfFire() const;

    int getAmmoSpeed() const;

    int getMaximumDispersion() const;

    const std::string &getAmmoType() const;

    float getAmmoDeceleration() const;

    int getFirepower() const;

    int getNumAmmo() const;

    double getPosX() const;

    double getPosY() const;

protected:
    virtual bool engage(Vehicle enemy) const = 0;

    virtual void rotate() const = 0;
};

#endif //SEALION_ARSENAL_H
