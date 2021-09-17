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
protected:
    virtual const bool searchTarget()=0;
    virtual const float rotate()=0;
    virtual const bool canEngage() const=0;
    virtual const bool setUpSprite(std::string textureName){
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
    virtual const std::string &getNationality() const=0;
    virtual const void attack()=0;
    virtual const void move()=0;
    double getAcceleration() const {return acceleration;}
    void setAcceleration(double acceleration) {Vehicle::acceleration = acceleration;}
    bool isDeath() const {return death;}
    void setDeath(bool death) {Vehicle::death = death;}
    const double getMaxSpeed() const {return maxSpeed;}
    float getCurrentSpeed() const {return currentSpeed;}
    void setCurrentSpeed(float currentSpeed) {Vehicle::currentSpeed = currentSpeed;}
    double getHp() const {return hp;}
    void setHp(double hp) {Vehicle::hp = hp;}
    const double getMaxHp() const {return maxHP;}
    unsigned int getLength() const {return length;}
    void setLength(unsigned int length) {Vehicle::length = length;}
    unsigned int getWidth() const {return width;}
    void setWidth(unsigned int width) {Vehicle::width = width;}
    bool isCollision() const {return collision;}
    void setCollision(bool collision) {Vehicle::collision = collision;}
    float getPosX() const {return posX;}
    void setPosX(float posX) {Vehicle::posX = posX;}
    float getPosY() const {return posY;}
    void setPosY(float posY) {Vehicle::posY = posY;}
    const sf::Texture &getTexture() const {return texture;}
    void setTexture(const sf::Texture &texture) {Vehicle::texture = texture;}
    const sf::Sprite &getSprite() const {return sprite;}
    void setSprite(const sf::Sprite &sprite) {Vehicle::sprite = sprite;}
    const sf::Vector2f &getPos() const {return pos;}
    void setPos(const sf::Vector2f &pos) {Vehicle::pos = pos;}
    virtual ~Vehicle() = 0;
};
#endif //SEALION_VEHICLE_H
