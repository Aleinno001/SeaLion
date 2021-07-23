//
// Created by gabriele on 7/2/21.
//

#ifndef SEALION_ARSENAL_H
#define SEALION_ARSENAL_H

#include <cstdlib>
#include <string>
#include "Vehicle.h"
#include "Bullet.h"
#include "SFML/Graphics.hpp"

class WarShip;

class Arsenal {
protected:
    float rangeOfFire;
    int reloadTime;
    int ammoSpeed;
    int maximumDispersion;
    Bullet ammoType;
    float ammoDeceleration;
    int firepower;
    int numAmmo;
    int length;
    int width;
    sf::Vector2f pos;
    std::string textureName;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    //TODO implementare i metodi

    Arsenal(const float range, const int reload, int speed, int dispersion, Bullet type,
            float decelleration, int power, int num, int posX, int posY, int le, int wi, std::string texName);

    virtual ~Arsenal() = default;

    virtual void openFire(Vehicle enemy);

    virtual void update(std::unique_ptr<WarShip> theChangedSubject) = 0;

    virtual void attach();

    virtual void detach();

    virtual bool engage(Vehicle enemy);

    virtual void rotate();

    virtual bool setUpSprite(std::string textureName);

    //getter
    const float getRangeOfFire() const;

    const int getReloadTime() const;

    const int getRateOfFire() const;

    int getAmmoSpeed() const;

    int getMaximumDispersion() const;

    const Bullet &getAmmoType() const;

    float getAmmoDeceleration() const;

    int getFirepower() const;

    int getNumAmmo() const;

    void setAmmoType(const Bullet &ammoType);

    const sf::Sprite &getSprite() const;

    const std::string &getTextureName() const;
};

#endif //SEALION_ARSENAL_H
