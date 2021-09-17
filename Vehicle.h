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
    sf::Vector2f movement;
protected:
    virtual bool searchTarget()=0;
    virtual float rotate(float mx, float rotatingInPlaceMult)=0;
    virtual bool canEngage() const =0;
    virtual void move()=0;
    bool setUpSprite(const std::string &textureName){
        std::string currentDir = ToolBox::GetCurrentWorkingDir();
        std::string unitTestingPath = "UnitTesting";
        std::size_t found = currentDir.find(unitTestingPath);
        if (found != std::string::npos) {
            currentDir.erase(found);
            currentDir.pop_back();
        }
        std::string textPath;
        textPath = currentDir + "/../Res/Buttons/" + textureName + ".png";
        if (!Collision::CreateTextureAndBitmask(texture, textPath)) {
            throw std::runtime_error("Path to tile filename invalid!!");
        }
        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, width, length));
        return true;
    }
public:
    Vehicle(float X, float Y, float ac, float maxVel, int HP, int le, int wi,bool col, std::string &nat) : posX(X), posY(Y), acceleration(ac), maxSpeed(maxVel), hp(HP),length(le), collision(col), width(wi), nationality(nat), maxHP(HP),currentSpeed(0),movement(0,0){}
    virtual const std::string &getNationality(){return nationality;}
    virtual void attack()=0;
    double getAcceleration() const {return acceleration;}
    void setAcceleration(double accel) {Vehicle::acceleration = accel;}
    bool isDeath() const {return death;}
    void setDeath(bool d) {Vehicle::death = d;}
    double getMaxSpeed() const {return maxSpeed;}
    float getCurrentSpeed() const {return currentSpeed;}
    const sf::Vector2f &getMovement() const {return movement;}
    void setCurrentSpeed(float currSpe) {Vehicle::currentSpeed = currSpe;}
    double getHp() const {return hp;}
    void setHp(double HP) {Vehicle::hp = HP;}
    double getMaxHp() const {return maxHP;}
    unsigned int getLength() const {return length;}
    void setLength(unsigned int le) {Vehicle::length = le;}
    unsigned int getWidth() const {return width;}
    void setWidth(unsigned int wi) {Vehicle::width = wi;}
    bool isCollision() const {return collision;}
    void setCollision(bool col) {Vehicle::collision = col;}
    float getPosX() const {return posX;}
    void setPosX(float x) {Vehicle::posX = x;}
    float getPosY() const {return posY;}
    void setPosY(float y) {Vehicle::posY = y;}
    const sf::Texture &getTexture() const {return texture;}
    void setTexture(const sf::Texture &tex) {Vehicle::texture = tex;}
    const sf::Sprite &getSprite() const {return sprite;}
    void setSprite(const sf::Sprite &sp) {Vehicle::sprite = sp;}
    const sf::Vector2f &getPos() const {return pos;}
    void setPos(const sf::Vector2f &p) {Vehicle::pos = p;}
    virtual ~Vehicle() = 0;
};
#endif //SEALION_VEHICLE_H
