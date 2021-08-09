//
// Created by alessandro on 7/2/21.
//

#ifndef SEALION_AIRCRAFTCARRIER_H
#define SEALION_AIRCRAFTCARRIER_H


#include "WarShip.h"

class AircraftCarrier : public WarShip {
private:
    int numPlanes;
public:
    AircraftCarrier(int x, int y, float ac, const float maxVel, int hp, int arm,
                    std::string nat, int numL, int numH, int numM, int numAA,
                    std::list<std::unique_ptr<Arsenal>> &arsenalList,
                    std::list<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi,
                    bool col, ShipType sh, ModelType mo, int planes);

    //float calcSpeed() override;

    void attack(Vehicle target) override;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach(std::unique_ptr<Arsenal> gun) override {
        arsenalList.push_back(gun);
    };

    void detach(std::unique_ptr<Arsenal> gun) override {
        arsenalList.remove(gun);
    };

    void notifyArsenals() override;

    int HowManyObserver() {
        return arsenalList.size();
    }

    void stopMove() override;

    void ceaseFire() override;

    void registerArsenals(std::unique_ptr<Arsenal> observer) override;

    void removeArsenals(std::unique_ptr<Arsenal> observer) override;



    ~AircraftCarrier() override;

protected:
    void rotate() override;

    bool canEngage(Vehicle target) override;
};


#endif //SEALION_AIRCRAFTCARRIER_H
