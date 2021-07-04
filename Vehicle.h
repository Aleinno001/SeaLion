//
// Created by alessandro on 02/07/21.
//

#ifndef SEALION_VEHICLE_H
#define SEALION_VEHICLE_H


#include "Map.h"

class Vehicle {
protected:
    double posX;  //TODO ricontrollare meglio con la libreria SFML
    double posY;  //TODO ricontrollare meglio con la libreria SFML
    float acceleration;
    const float maxSpeed;
    int hp;
    int length;

    //TODO controllare la Sfml per le sprite
    //SpriteSheet sprite
    virtual void rotate();

    virtual bool canEngage(Vehicle target);

public:

    Vehicle(double X, double Y, float ac, const float maxVel, int HP, int length/*SpriteSheet sprite*/);

    virtual float calcSpeed(Map battleSea);

    virtual void attack(Vehicle target);

    virtual void calculateDistance(Vehicle target);

    virtual void update(bool isDead);

    virtual void attach();

    virtual void detach();

    virtual ~Vehicle() = default;
};

#endif //SEALION_VEHICLE_H
