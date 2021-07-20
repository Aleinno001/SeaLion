//
// Created by alessandro on 7/2/21.
//

#ifndef SEALION_BATTLESHIP_H
#define SEALION_BATTLESHIP_H


#include "WarShip.h"

class Battleship : public WarShip {
private:


    int numInterceptors;


public:

    Battleship(int x, int y, float ac, const float maxVel, int hp, int arm,
               std::string nat, int numL, int numH, int numM, int numAA,
               std::list<std::unique_ptr<Arsenal>> &arsenalList,
               std::list<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi,
               bool col, ShipType sh, ModelType mo, int numInterceptors);

    //float calcSpeed() override;

    void attack(Vehicle target) override;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach() override;

    void detach() override;

    void stopMove() override;

    void ceaseFire() override;

    void registerArsenals(std::unique_ptr<Arsenal> observer) override;

    void removeArsenals(std::unique_ptr<Arsenal> observer) override;

    void notifyArsenals() override;

    ~Battleship() override;

protected:
    void rotate() override;

    bool canEngage(Vehicle target) override;

public:

};


#endif //SEALION_BATTLESHIP_H
