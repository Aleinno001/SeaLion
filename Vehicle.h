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
    const float maxSpeed; //FIXME valore di default di velocità
    int hp;
    int length;
    int width;
    bool collision;
    const std::string nationality;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f pos;


    //SpriteSheet sprite
    virtual void rotate();

    virtual bool canEngage(Vehicle target);

public:

    Vehicle(int X, int Y, float ac, float maxVel, int HP, int le, int wi,
            bool col, std::string nat);

    //virtual float calcSpeed(); //FIXME da rivedere il calcolo della velocità qua e nelle sottoclassi

    virtual bool setUpSprite(std::string textureName);

    virtual void attack(Vehicle target);

    virtual void calculateDistance(Vehicle target);

    virtual void update(bool isDead);

    virtual void attach();

    virtual void detach();

    virtual ~Vehicle() = default;

    int getPosX() const;

    int getPosY() const;

    float getAcceleration() const;

    const float getMaxSpeed() const;

    int getHp() const;

    int getLength() const;

    int getWidth() const;

    bool isCollision() const;

    const sf::Texture &getTexture() const;

    sf::Sprite &getSprite();

    const sf::Vector2f &getPos() const;
};

#endif //SEALION_VEHICLE_H
