//
// Created by davide on 02/07/21.
//

#ifndef SEALION_VEHICLE_H
#define SEALION_VEHICLE_H
#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>
#include "CurrentDir.h"
#include "Collision.h"
#include <math.h>
class Vehicle {
protected:
    double acceleration;
    bool death{false};
    const double maxSpeed;
    float currentSpeed;
    double hp;
    const double maxHP;
    unsigned int length;
    unsigned int width;
    bool collision;
    float posX;
    float posY;
    const std::string nationality;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f pos;
protected:
    virtual const bool setUpSprite(std::string textureName)=0;
    virtual const bool searchTarget()=0;
    virtual const float rotate()=0;
    virtual const bool canEngage() const=0;
public:
    virtual const std::string &getNationality() const=0;
    virtual const void attack()=0;
    virtual const void setDeath(bool death)=0;
    virtual const void setCollision(bool collision)=0;
    virtual const void move()=0;
    virtual const double getMaxHp() const=0;
    virtual const void setCurrentSpeed(float currentSpeed)=0;
    virtual const bool isDeath() const=0;
    virtual const bool getCol() const=0;
    virtual const void setDamage(double damage)=0;
    virtual const float getAcceleration() const=0; //Unit Testing
    virtual const float getMaxSpeed() const=0;
    virtual const double getHp() const=0;
    virtual const int getLength() const=0;//Unit Testing
    virtual const int getWidth() const=0;//Unit Testing
    virtual const bool isCollision() const=0;
    virtual sf::Sprite &getSprite() const=0;
    virtual const sf::Vector2f &getPos() const=0; //Unit Testing
    virtual ~Vehicle() = 0;
};
#endif //SEALION_VEHICLE_H
