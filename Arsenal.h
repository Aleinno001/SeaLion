//
// Created by gabriele on 7/2/21.
//

#ifndef SEALION_ARSENAL_H
#define SEALION_ARSENAL_H

#include <cstdlib>
#include <string>
#include "Vehicle.h"


class WarShip;

class Arsenal {
protected:
    float rangeOfFire;
    int reloadTime;
    int rateOfFire;
    int ammoSpeed;
    int maximumDispersion;
    std::string ammoType;
    float ammoDeceleration;
    int firepower;
    int numAmmo;
    int length;
    int width;
    sf::Vector2i pos;
    std::string textureName;
public:
    //TODO implementare i metodi

    Arsenal(const float range, const int reload, const int rate, int speed, int dispersion, std::string type,
            float decelleration, int power, int num, int posX, int posY, int le, int wi, std::string texName);

    virtual ~Arsenal() = default;

    virtual void openFire(Vehicle enemy);

    virtual void update(std::unique_ptr<WarShip> theChangedSubject) = 0;

    virtual void attach() = 0;

    virtual void detach() = 0;

    virtual bool engage(Vehicle enemy);

    virtual void rotate();

    virtual bool setUpSprite(std::string textureName);

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

};

#endif //SEALION_ARSENAL_H
