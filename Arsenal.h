//
// Created by gabriele on 7/2/21.
//
#ifndef SEALION_ARSENAL_H
#define SEALION_ARSENAL_H
#include <cstdlib>
#include <string>
#include "Bullet.h"
#include "SFML/Graphics.hpp"
#include <memory>
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
    std::string textureName;
    sf::Texture texture;
    sf::Sprite sprite;
    virtual void rotate(sf::Vector2f &coord) = 0;
    virtual float attack(sf::Vector2f &coord,float elapsedTime) = 0;
    virtual bool engage(sf::Vector2f &coord,bool concealed) = 0;
public:
    Arsenal(float range,float reload,int maxDispersion,std::shared_ptr<Bullet> &ammo,int firepower,int le,int wi,std::string texName):rangeOfFire(range),reloadTime(reload),maximumDispersion(maxDispersion),ammoType(ammo),firepower(firepower),length(le),width(wi),textureName(texName){}
    virtual std::shared_ptr<Bullet> getAmmoType()=0;
    virtual void update() = 0; //Metodo per design pattern observer
    virtual void searchTarget(float elapsedTime) = 0;
    virtual bool setUpSprite(std::string textureName)=0;
    virtual void removeMeFromTheList() = 0;//metodo per detach observer cannoni
    virtual float getRangeOfFire() const = 0;
    virtual int getReloadTime() const = 0;
    virtual int getAmmoSpeed() const = 0;
    virtual int getMaximumDispersion() const = 0;
    virtual std::shared_ptr<Bullet> getAmmoType() const =0;
    virtual int getFirepower() const = 0;
    virtual void setAmmoType(std::shared_ptr<Bullet> ammoType)=0;
    virtual sf::Sprite &getSprite() = 0;
    virtual const std::string &getTextureName() = 0;
    virtual int getLength() const =0;
    virtual int getWidth() const =0;
    virtual float getCountdown() const =0;
    virtual void setCountdown(float countdown)=0;
    virtual void drawEquipment(sf::RenderWindow &window)=0;
    ~Arsenal()=default;
};
#endif //SEALION_ARSENAL_H
