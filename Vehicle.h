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
    float currentSpeed;//FIXME valore di default di velocità
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

public:
    const std::string &getNationality() const;

protected:

    virtual float rotate(float mx, float rotatingInPlaceMult);  //Ruota la sprite della nave soltanto

    virtual bool setUpSprite(std::string textureName);

    virtual void attack(std::_List_iterator<std::unique_ptr<Vehicle>> target);

    virtual float calculateDistance(sf::Vector2f &first, sf::Vector2f &second);  //calcola la distanza tra due punti

    virtual float
    calculateMx(float dx, float dy);  //Calcola l'angolo da raggiungere (già tradotto secondo la logica della SFML)

public:

    Vehicle(int X, int Y, float ac, float maxVel, int HP, int le, int wi,
            bool col, std::string nat);

    void setDeath(bool death);

    void setCollision(bool collision);

    virtual void move(sf::Vector2 <double> coordinates,double dt);//FIXME DA METTERE COME INTERFACCIA

    const double getMaxHp() const;

    virtual void update(bool isDead);

    virtual void updatePlanes(sf::Vector2f &vel,double mx); //metodo per design pattern observer tra Planes e Warship

    void setCurrentSpeed(float currentSpeed);

    virtual ~Vehicle() = default;

    bool isDeath() const;

    bool getCol() {
        return collision;
    }

    void setDamage(double damage) {
        hp = hp - damage;
    }

    float getAcceleration() const;

    const float getMaxSpeed() const;

    double getHp() const;

    int getLength() const;

    int getWidth() const;

    bool isCollision() const;

    sf::Sprite &getSprite();

    const sf::Vector2f &getPos() const;
};

#endif //SEALION_VEHICLE_H
