//
// Created by davide on 04/07/21.
//

#ifndef SEALION_BOMBER_H
#define SEALION_BOMBER_H


#include "Vehicle.h"

#include "WarShip.h"

class Bomber : public Vehicle{
private:


    int numBombs;
    int bombDamage;
    WarShip &subject_;
public:
    //TODO Implementare i metodi
    Bomber(int x, int y, float ac, float maxVel, int hp, int le, int wi, bool col, int numBombs, int damage,
           std::string nat, WarShip &subject);

    void bombard(Vehicle &enemy);

    //float calcSpeed();
    int getNumBombs() const;

    int getBombDamage() const;

    void attack(Vehicle target);

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;


    void removeMeFromTheList() {

        subject_.detachPlanes(std::shared_ptr<Vehicle>(this));
    }

    void updatePlanes(sf::Vector2f &vel,double mx) override;


    ~Bomber() override;

    void resetOrigin();
};


#endif //SEALION_BOMBER_H
