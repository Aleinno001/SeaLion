
#ifndef SEALION_OldOldBomber_H
#define SEALION_OldBomber_H


#include "Vehicle.h"

#include "WarShip.h"

class OldBomber : public Vehicle{
private:

    float actualCooldown{0};
    float cooldown{6};
    int numBombs;
    int bombDamage;
    WarShip &subject_;
public:
    //TODO Implementare i metodi
    OldBomber(int x, int y, float ac, float maxVel, int hp, int le, int wi, bool col, int numBombs, int damage,
           std::string nat, WarShip &subject);

    void bombard(Vehicle &enemy);

    //float calcSpeed();
    int getNumBombs() const;

    int getBombDamage() const;

    void attack(Vehicle target);

    void update(bool isDead) override;


    void removeMeFromTheList() {

        subject_.detachPlanes(std::shared_ptr<Vehicle>(this));
    }

    void updatePlanes(sf::Vector2f &vel,double mx) override;


    ~OldBomber() override;

    void resetOrigin();

    void planeAttack(std::_List_iterator<std::unique_ptr<Vehicle>> target, float dt);
};


#endif //SEALION_OldBomber_H

