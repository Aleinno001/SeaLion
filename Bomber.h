//
// Created by davide on 04/07/21.
//

#ifndef SEALION_BOMBER_H
#define SEALION_BOMBER_H


#include "Vehicle.h"
#include "WarPlanes.h"
#include "WarShip.h"

class Bomber : public Vehicle,WarPlanes {
private:
    int numBombs;
    int bombDamage;
    WarShip &subject_;
public:
    //TODO Implementare i metodi
    Bomber(int x, int y, float ac1, float maxVel1, int hp, int le,
           int wi, bool col, float ac, const float maxVel, int HP,
           int length, int numBombs, int damage, std::string nat,WarShip &subject);

    void bombard(Vehicle &enemy);

    //float calcSpeed();

    void attack(Vehicle target);

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;
    void removeMeFromTheList() {
        subject_.detachPlanes(std::shared_ptr<WarPlanes>(this));
    }
    void updatePlanes(sf::Vector2f &vel,double mx) override;


    ~Bomber() override;
};


#endif //SEALION_BOMBER_H
