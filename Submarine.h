//
// Created by alessandro on 7/2/21.
//

#ifndef SEALION_SUBMARINE_H
#define SEALION_SUBMARINE_H


#include <string>
#include <memory>
#include <list>
#include "Arsenal.h"
#include "Vehicle.h"
#include "WarShip.h"

class Submarine : public WarShip {
private:
    bool isSubmerged{false};
    int numTorpedoTubes;
public:
    Submarine(int x, int y, float ac, const float maxVel, int hp, int arm,
              std::string nat, int numL, int numH, int numM, int numAA,
              std::list<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi,
              bool col, ShipType sh, ModelType mo, int numTor, bool isSub);

    void submerge();

    bool isSubmerged1() const {
        return isSubmerged;
    }

    int getNumTorpedoTubes() const {
        return numTorpedoTubes;
    }

    void attack(Vehicle target) override;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach(const std::shared_ptr<Arsenal> &gun) override {
        arsenalList.push_back(gun);
    };

    void detach(const std::shared_ptr<Arsenal> &gun) override {
        arsenalList.remove(gun);

    };

    ~Submarine() override{

    };

    void stopMove() override;

    void ceaseFire() override;

    // void registerArsenals(std::unique_ptr<Arsenal> observer) override;

    //void removeArsenals(std::unique_ptr<Arsenal> observer) override;

    void notifyArsenals(sf::Vector2f &vel,double mx) override;


protected:
    void rotate() override;

    bool canEngage(std::_List_iterator<std::unique_ptr<WarShip>> target) override;
};


#endif //SEALION_SUBMARINE_H
