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
    int getNumPlanes() const;

public:
    AircraftCarrier(int x, int y, float ac, const float maxVel, int hp, int arm,
                    std::string nat, int numL, int numH, int numM, int numAA,
                     int le, int wi,
                    bool col, ShipType sh, ModelType mo, int planes);

    //float calcSpeed() override;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach(const std::shared_ptr<Arsenal> &gun) override {
        arsenalList.push_back(gun);
    };

    void detach(const std::shared_ptr<Arsenal> &gun) override {
        arsenalList.remove(gun);
    };

    void notifyArsenals(sf::Vector2f &vel,double mx) override;

    void notifyPlanes(sf::Vector2f &vel, double mx) override;

    void attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override{
        vehicleList.push_back(warPlanes);
    };

    void detachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override{
        vehicleList.remove(warPlanes);
    };

    int HowManyObserver() {
        return arsenalList.size();
    }

    void stopMove() override;

    void ceaseFire() override;


    ~AircraftCarrier() override;

protected:
    void rotate() override;

};


#endif //SEALION_AIRCRAFTCARRIER_H
