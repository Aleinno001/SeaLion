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
               int le, int wi,
              bool col, ShipType sh, ModelType mo, int torpedo);


    //float calcSpeed() override;
    int getNumTorpedoTubes() const;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach(const std::shared_ptr<Arsenal> &gun) override {
        arsenalList.push_back(gun);
    };


    void detach(const std::shared_ptr<Arsenal> &gun) override {
        arsenalList.remove(gun);
    };
    void notifyPlanes(sf::Vector2f &vel, double mx) override;

    void attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override{
        vehicleList.push_back(warPlanes);
    };

    void detachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override{
        vehicleList.remove(warPlanes);
    };
    void stopMove() override;

    void ceaseFire() override;

    //void registerArsenals(std::unique_ptr<Arsenal> observer) override;

    //void removeArsenals(std::unique_ptr<Arsenal> observer) override;

    void notifyArsenals(sf::Vector2f &vel,double mx) override;

    ~Destroyer() override;

    bool setUpSprite(std::string textureName) override;

protected:
    void rotate() override;

    //bool canEngage(std::_List_iterator<std::unique_ptr<WarShip>> target) override;
};


#endif //SEALION_DESTROYER_H
