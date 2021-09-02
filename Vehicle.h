//
// Created by davide on 02/07/21.
//

#ifndef SEALION_VEHICLE_H
#define SEALION_VEHICLE_H

#include "SFML/Graphics.hpp"
#include <iostream>

#include "CurrentDir.h"

class Vehicle {
protected:
    int posX;
    int posY;
    float acceleration;
    bool death{false};
public:
    float getCurrentSpeed() const;

protected:
    const float maxSpeed;
    float currentSpeed{0};//FIXME valore di default di velocità
    double hp;
    int length;
    int width;
    bool collision;
public:
    const std::string &getNationality() const;

protected:
    const std::string nationality;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f pos;


    //SpriteSheet sprite
    virtual void rotate();



public:

    Vehicle(int X, int Y, float ac, float maxVel, int HP, int le, int wi,
            bool col, std::string nat);

    //virtual float calcSpeed(); //FIXME da rivedere il calcolo della velocità qua e nelle sottoclassi

    virtual bool setUpSprite(std::string textureName);

    void setDeath(bool death);

    void setCollision(bool collision);

    virtual void attack(std::_List_iterator<std::unique_ptr<Vehicle>>  target);

    virtual void calculateDistance(Vehicle target);

    virtual void update(bool isDead);

    virtual void updatePlanes(sf::Vector2f &vel,double mx); //metodo per design pattern observer tra Planes e Warship

    void setCurrentSpeed(float currentSpeed);

    virtual ~Vehicle() = default;



    bool getCol(){
        return collision;
    }
    int getPosX() const;

    void setDamage(double damage){
        hp=hp-damage;
    }

    int getPosY() const;

    float getAcceleration() const;

    const float getMaxSpeed() const;

    double getHp() const;

    int getLength() const;

    int getWidth() const;

    bool isCollision() const;

    const sf::Texture &getTexture() const;

    sf::Sprite &getSprite();

    const sf::Vector2f &getPos() const;
};

#endif //SEALION_VEHICLE_H
