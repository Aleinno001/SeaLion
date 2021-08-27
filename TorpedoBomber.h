//
// Created by davide on 04/07/21.
//

#ifndef SEALION_TORPEDOBOMBER_H
#define SEALION_TORPEDOBOMBER_H

#include "Vehicle.h"
#include "WarPlanes.h"
#include "WarShip.h"

class TorpedoBomber : public Vehicle,WarPlanes {
private:
    int numTorpedos;
    int torpedoDamage;
    WarShip &subject_;
private:
    TorpedoBomber(int x, int y, float ac1, float maxVel1, int hp, int le, int wi, bool col,
                  float ac, int length, int numTorpedos, int damage, std::string nat,WarShip &subject);

    void launchTorpedo(Vehicle enemy);

    //float calcSpeed();

    void attack(Vehicle target);

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void updatePlanes(sf::Vector2f &vel,double mx) override;

    void removeMeFromTheList() {
        subject_.detachPlanes(std::shared_ptr<WarPlanes>(this));
    }

    ~TorpedoBomber() override;
};


#endif //SEALION_TORPEDOBOMBER_H
