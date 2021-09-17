//
// Created by gabriele on 7/2/21.
//

#ifndef SEALION_OldArsenal_H
#define SEALION_OldArsenal_H

#include <cstdlib>
#include <string>
#include "Vehicle.h"
#include "Bullet.h"
#include "SFML/Graphics.hpp"
#include <memory>

class WarShip;

class OldArsenal {
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
    //TODO implementare i metodi

    OldArsenal(const float range, float reload, int dispersion, std::shared_ptr<Bullet> type, int power, int posX,
            int posY, int le, int wi, std::string texName);

    std::shared_ptr<Bullet> getAmmoType();

    virtual ~OldArsenal() = default;

    virtual void openFire(Vehicle enemy);

    virtual void update(sf::Vector2f &vel,double mx) = 0; //Metodo per design pattern observer

    const sf::Vector2f &getPos() const;

    virtual bool engage(Vehicle enemy);

    virtual void rotate();

    virtual bool setUpSprite(std::string textureName);

    virtual void removeMeFromTheList()=0;//metodo per detach observer cannoni

    //getter
    const float getRangeOfFire() const;

    const int getReloadTime() const;

    const int getRateOfFire() const;

    int getAmmoSpeed() const;

    int getMaximumDispersion() const;

    std::shared_ptr<Bullet> getAmmoType() const;

    int getFirepower() const;

    void setAmmoType(const std::shared_ptr<Bullet> ammoType);

    sf::Sprite &getSprite();

    const std::string &getTextureName() const;

    virtual void resetOrigin() = 0;

    int getLength() const;

    int getWidth() const;

    float getCountdown() const;

    void setCountdown(float countdown);

};

#endif //SEALION_OldArsenal_H
