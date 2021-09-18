//
// Created by davide on 18/09/21.
//

#ifndef SEALION_OLDBATTLESHIP_H
#define SEALION_OLDBATTLESHIP_H


#include "WarShip.h"

class OldBattleship : public WarShip {
private:
    int numInterceptors;
public:
    int getNumInterceptors() const;
public:
    OldBattleship(int x, int y, float ac, const float maxVel, int hp, int arm,
               std::string nat, int numL, int numH, int numM, int numAA,
               int le, int wi,
               bool col, ShipType sh, ModelType mo, int numInterceptors);
    void attach(const std::shared_ptr<Arsenal> &gun) override;
    void detach(const std::shared_ptr<Arsenal> &gun) override;
    void notifyPlanes(sf::Vector2f &vel, double mx) override;
    void attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override;
    void detachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override;
    void notifyBars(sf::Vector2f &vel, double mx) override;
    void attachBar(const std::shared_ptr<BarInterface> &bar) override;
    void detachBar(const std::shared_ptr<BarInterface> &bar) override;
    void notifyBarsDamage() override;
    // void registerPlanes(std::unique_ptr<Vehicle> observer) override;
    // void removePlanes(std::unique_ptr<Vehicle> observer) override;
    ~OldBattleship() override;
public:
    void notifyArsenals(sf::Vector2f &vel, double mx);
};


#endif //SEALION_OLDBATTLESHIP_H
