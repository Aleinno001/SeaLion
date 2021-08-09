//
// Created by alessandro on 7/2/21.
//

#ifndef SEALION_DESTROYER_H
#define SEALION_DESTROYER_H


#include <utility>

#include "WarShip.h"

class Destroyer : public WarShip {
private:
    int numTorpedoTubes;
public:

    Destroyer(int x, int y, float ac, const float maxVel, int hp, int arm,
              std::string nat, int numL, int numH, int numM, int numAA,
              std::list<std::unique_ptr<Arsenal>> &arsenalList,
              std::list<std::unique_ptr<Vehicle>> &vehicleList, int le, int wi,
              bool col, ShipType sh, ModelType mo, int torpedo);


    //float calcSpeed() override;

    void attack(Vehicle target) override;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach(Arsenal *gun) override {
        //arsenalList.push_back(gun);
    };


    void detach(Arsenal *gun) override {
        //arsenalList.remove(gun);
    };

    void stopMove() override;

    void ceaseFire() override;

    //void registerArsenals(std::unique_ptr<Arsenal> observer) override;

    //void removeArsenals(std::unique_ptr<Arsenal> observer) override;

    void notifyArsenals() override;

    ~Destroyer() override;

    bool setUpSprite(std::string textureName) override;

protected:
    void rotate() override;

    bool canEngage(Vehicle target) override;
};


#endif //SEALION_DESTROYER_H
