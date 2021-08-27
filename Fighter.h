//
// Created by davide on 04/07/21.
//

#ifndef SEALION_FIGHTER_H
#define SEALION_FIGHTER_H

#include "Vehicle.h"
#include "WarPlanes.h"
#include "WarShip.h"

class Fighter : public Vehicle,WarPlanes {
public:
    Fighter(int x, int y, float ac1, float maxVel1, int hp,
            int le, int wi, bool col, double X, double Y, float ac,
            const float maxVel, int HP, int length, std::string nat,WarShip &subject);

private:
    void fight(Vehicle enemy);

    //float calcSpeed();

    void attack(Vehicle target);

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void updatePlanes(sf::Vector2f &vel,double mx) override;


    ~Fighter() override;
private:
    WarShip &subject_;
};

#endif //SEALION_FIGHTER_H
