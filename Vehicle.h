//
// Created by davide on 02/07/21.
//
#ifndef SEALION_VEHICLE_H
#define SEALION_VEHICLE_H
#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>
#include "ToolBox.h"
#include "Collision.h"
#include "Arsenal.h"
#include "GameTile.h"
#include "BarInterface.h"
#include <math.h>
#include <string>
#include <utility>
#include <vector>
#include <memory>
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
    sf::Vector2f movement;
    const std::string name;
    virtual float rotate(float mx, float rotatingInPlaceMult)=0;
    virtual bool canEngage()=0;
    virtual void move(float elapsedTime)=0;
    virtual void attack(float elapsedTime)=0;
    virtual bool setUpSprite(const std::string &textureName)=0;
public:
    Vehicle(float X, float Y, float ac, float maxVel, int HP, int le, int wi,bool col, std::string nat,std::string n) : posX(X), posY(Y), acceleration(ac), maxSpeed(maxVel), hp(HP),length(le), collision(col), width(wi), nationality(nat), maxHP(HP),currentSpeed(0),movement(0,0),name(n){}
    virtual const std::string &getNationality(){return nationality;}
    virtual bool searchTarget(float elapsedTime)=0;
    bool isDeath() const {return death;}
    void setDeath(bool d) {Vehicle::death = d;}
    double getMaxSpeed() const {return maxSpeed;}
    const sf::Vector2f &getMovement() const {return movement;}
    void setCurrentSpeed(float currSpe) {Vehicle::currentSpeed = currSpe;}
    double getHp() const {return hp;}
    double getMaxHp() const {return maxHP;}
    unsigned int getLength() const {return length;}
    unsigned int getWidth() const {return width;}
    bool isCollision() const {return collision;}
    void setCollision(bool col) {Vehicle::collision = col;}
    void setTexture(const sf::Texture &tex) {Vehicle::texture = tex;}
    sf::Sprite &getSprite() {return sprite;}
    void setDamage(double damage) {hp = hp - damage;}
    virtual void drawEquipment(sf::RenderWindow &window)=0;
    ~Vehicle()=default;
};
#endif //SEALION_VEHICLE_H
