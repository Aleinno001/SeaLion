//
// Created by alessandro on 7/2/21.
//

#ifndef SEALION_CRUISER_H
#define SEALION_CRUISER_H


#include "WarShip.h"

class Cruiser : public WarShip {
private:
    int numPlanes;
public:
    int getNumPlanes() const;

public:
    Cruiser(int x, int y, float ac, const float maxVel, int hp, int arm,
            std::string nat, int numL, int numH, int numM, int numAA,
             int le, int wi,
            bool col, ShipType sh, ModelType mo, int planes);

    void update(bool isDead) override;

    void attach(const std::shared_ptr<Arsenal> &gun) override;


    void detach(const std::shared_ptr<Arsenal> &gun) override;

    void notifyPlanes(sf::Vector2f &vel, double mx) override;

    void attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override;

    void detachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override;


    void notifyBars(sf::Vector2f &vel, double mx) override;

    void attachBar(const std::shared_ptr<BarInterface> &bar) override;

    void detachBar(const std::shared_ptr<BarInterface> &bar) override;

//    void registerArsenals(std::unique_ptr<Arsenal> observer) override;

    //  void removeArsenals(std::unique_ptr<Arsenal> observer) override;

    void notifyArsenals(sf::Vector2f &vel,double mx) override;

    void notifyBarsDamage() override;

    ~Cruiser() override;
};


#endif //SEALION_CRUISER_H
