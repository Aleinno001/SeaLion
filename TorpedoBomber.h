//
// Created by davide on 04/07/21.
//

#ifndef SEALION_TORPEDOBOMBER_H
#define SEALION_TORPEDOBOMBER_H

#include "Vehicle.h"
#include "WarShip.h"


class TorpedoBomber : public Vehicle{
private:


    int numTorpedos;
    int torpedoDamage;
    WarShip &subject_;


public:
    TorpedoBomber(int x, int y, float ac, float maxVel, int hp, int le, int wi, bool col, int numTorpedos, int damage,
                  std::string nat, WarShip &subject);

    void launchTorpedo(Vehicle &enemy);

    int getNumTorpedos() const;

    int getTorpedoDamage() const;

private:




    //float calcSpeed();

    void attack(Vehicle target);

    void update(bool isDead) override;

    void updatePlanes(sf::Vector2f &vel,double mx) override;

    void removeMeFromTheList() {
        subject_.detachPlanes(std::shared_ptr<Vehicle>(this));
    }
public:
    ~TorpedoBomber() override;

    void resetOrigin();
};


#endif //SEALION_TORPEDOBOMBER_H
