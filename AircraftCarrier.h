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

    void attach(const std::shared_ptr<Arsenal> &gun) override;

    void detach(const std::shared_ptr<Arsenal> &gun) override;

    void notifyArsenals(sf::Vector2f &vel,double mx) override;

    void notifyPlanes(sf::Vector2f &vel, double mx) override;

    void attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override;

    void detachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override;

    void notifyBars(sf::Vector2f &vel, double mx, double damageReceived) override;

    void attachBar(const std::shared_ptr<BarInterface> &bar) override;

    void detachBar(const std::shared_ptr<BarInterface> &bar) override;


    int HowManyGuns() {
        return arsenalList.size();
    }


    void stopMove() override;

    void ceaseFire() override;


    ~AircraftCarrier() override;

protected:
    void rotate() override;

};


#endif //SEALION_AIRCRAFTCARRIER_H
