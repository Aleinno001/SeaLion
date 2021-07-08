//
// Created by alessandro on 04/07/21.
//

#ifndef SEALION_BOMBER_H
#define SEALION_BOMBER_H


#include "Vehicle.h"

class Bomber : public Vehicle {
private:
    int numBombs;
    int bombDamage;
private:
    Bomber(int x, int y, float ac1, float maxVel1, int hp, int length1, sf::Texture tex, sf::Sprite sp, int le,
           int wi, bool col, std::string textureName, double X, double Y, float ac, const float maxVel, int HP,
           int length, int numBombs, int damage);//FIXME sprite

    void bombard(Vehicle enemy);

    //float calcSpeed();

    void attack(Vehicle target) override;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach() override;

    void detach() override;

    ~Bomber() override;
};


#endif //SEALION_BOMBER_H
