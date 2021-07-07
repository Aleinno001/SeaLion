//
// Created by pala on 7/2/21.
//

#ifndef SEALION_AIRCRAFTCARRIER_H
#define SEALION_AIRCRAFTCARRIER_H


#include "WarShip.h"

class AircraftCarrier : public WarShip {
private:
    int numPlanes;
public:
    AircraftCarrier(double x, double y, float ac, const float maxVel, int hp, int length, int arm,
                    std::string na, std::string nat, int numL, int numH, int numM,
                    std::vector<std::unique_ptr<Arsenal>> &arsenalList,
                    std::vector<std::unique_ptr<Vehicle>> &vehicleList);

    //float calcSpeed() override;

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

    ~AircraftCarrier() override;

protected:
    void rotate() override;

    bool canEngage(Vehicle target) override;
};


#endif //SEALION_AIRCRAFTCARRIER_H
