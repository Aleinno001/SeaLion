//
// Created by davide on 04/07/21.
//

#ifndef SEALION_FIGHTER_H
#define SEALION_FIGHTER_H

#include "Vehicle.h"

#include "WarShip.h"

class Fighter : public Vehicle{
public:
    Fighter(int x, int y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string nat, WarShip &subject);
    ~Fighter() override;
private:


    void fight(Vehicle enemy);

    //float calcSpeed();

    void attack(Vehicle target);

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void updatePlanes(sf::Vector2f &vel,double mx) override;

    void removeMeFromTheList() {
        subject_.detachPlanes(std::shared_ptr<Vehicle>(this));
    }


private:
    WarShip &subject_;
};

#endif //SEALION_FIGHTER_H
