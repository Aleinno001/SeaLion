//
// Created by pala on 7/2/21.
//

#ifndef SEALION_BATTLESHIP_H
#define SEALION_BATTLESHIP_H


#include "WarShip.h"

class Battleship : public WarShip {
private:
    int numInterceptors;

public:

    Battleship(double x, double y, float ac, const float maxVel, int hp, int length, int arm,
               std::string na, std::string nat, int numL, int numH, int numM,
               std::vector<std::unique_ptr<Arsenal>> &arsenalList,
               std::vector<std::unique_ptr<Vehicle>> &vehicleList);

    float calcSpeed(Map battleSea) override;

    void attack(Vehicle target) override;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach() override;

    void detach() override;

    void stopMove() override;

    void ceaseFire() override;

    void registerArsenals() override;

    void removeArsenals() override;

    void notifyArsenals() override;

    ~Battleship() override;

protected:
    void rotate() override;

    bool canEngage(Vehicle target) override;

public:

};


#endif //SEALION_BATTLESHIP_H
