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
    int getNumInterceptors() const;


public:

    Battleship(int x, int y, float ac, const float maxVel, int hp, int arm,
               std::string nat, int numL, int numH, int numM, int numAA,
               std::list<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi,
               bool col, ShipType sh, ModelType mo, int numInterceptors);

    //float calcSpeed() override;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach(const std::shared_ptr<Arsenal> &gun) override {
        arsenalList.push_back(gun);
    };

    void detach(const std::shared_ptr<Arsenal> &gun) override {
        arsenalList.remove(gun);
    };

    void stopMove() override;

    void ceaseFire() override;

    // void registerPlanes(std::unique_ptr<Vehicle> observer) override;

    // void removePlanes(std::unique_ptr<Vehicle> observer) override;





    ~Battleship() override;

protected:
    void rotate() override;

public:

    void notifyArsenals(sf::Vector2f &vel, double mx);
};


#endif //SEALION_BATTLESHIP_H
