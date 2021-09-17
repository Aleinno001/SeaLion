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
#include <memory>
class WarShip;
class Arsenal {
protected:
    float rangeOfFire;
    float reloadTime;
    float countdown{0};
    int maximumDispersion;
     std::shared_ptr<Bullet> ammoType;
    int firepower;
    int length;
    int width;
    sf::Vector2f pos;
    std::string textureName;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    virtual const std::shared_ptr<Bullet> getAmmoType()=0;
    virtual ~Arsenal() = 0;
    virtual void update() = 0; //Metodo per design pattern observer
    virtual const sf::Vector2f &getPos() const = 0;
    virtual const bool engage() = 0;
    virtual void rotate() = 0;
    virtual const bool setUpSprite(std::string textureName)=0;
    virtual void removeMeFromTheList() = 0;//metodo per detach observer cannoni
    virtual const float getRangeOfFire() const = 0;
    virtual int getReloadTime() const = 0;
    virtual const int getRateOfFire() const = 0;
    virtual const int getAmmoSpeed() const = 0;
    virtual const int getMaximumDispersion() const = 0;
    virtual const std::shared_ptr<Bullet> getAmmoType() const =0;
    virtual int getFirepower() const = 0;
    virtual void setAmmoType(std::shared_ptr<Bullet> ammoType)=0;
    virtual sf::Sprite &getSprite() const = 0;
    virtual const std::string &getTextureName() const = 0;
    virtual void resetOrigin() = 0;
    virtual const int getLength() const=0;
    virtual const int getWidth() const=0;
    virtual const float getCountdown() const=0;
    virtual void setCountdown(float countdown)=0;
};
#endif //SEALION_ARSENAL_H
