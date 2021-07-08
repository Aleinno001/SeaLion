//
// Created by alessandro on 02/07/21.
//

#ifndef SEALION_VEHICLE_H
#define SEALION_VEHICLE_H
#include "SFML/Graphics.hpp"

class Vehicle {
protected:
    int posX;  //TODO ricontrollare meglio con la libreria SFML
    int posY;  //TODO ricontrollare meglio con la libreria SFML
    float acceleration;
    const float maxSpeed = 0; //FIXME valore di default di velocità
    int hp;
    int length;
    int width;
    bool collision;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f pos;

    //TODO controllare la Sfml per le sprite
    //SpriteSheet sprite
    virtual void rotate();

    virtual bool canEngage(Vehicle target);

public:

    Vehicle(int X, int Y, float ac, float maxVel, int HP, int length, sf::Texture tex, sf::Sprite sp, int le, int wi,
            bool col, std::string textureName);

    //virtual float calcSpeed(); //FIXME da rivedere il calcolo della velocità qua e nelle sottoclassi

    virtual bool setUpSprite(std::string textureName);

    virtual void attack(Vehicle target);

    virtual void calculateDistance(Vehicle target);

    virtual void update(bool isDead);

    virtual void attach();

    virtual void detach();

    virtual ~Vehicle() = default;
};

#endif //SEALION_VEHICLE_H
