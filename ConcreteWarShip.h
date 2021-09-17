//
// Created by alessandro on 17/09/21.
//

#ifndef SEALION_CONCRETEWARSHIP_H
#define SEALION_CONCRETEWARSHIP_H

#include "WarShip.h"

class ConcreteWarShip : public WarShip {
public:
    ConcreteWarShip(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string &nat,
                    ShipType shipType, ModelType modelType, const int armour, const std::string &name,
                    const int numLCannons, const int numMCannons, const int numHCannons, const int numAntiAircraft,
                    bool concealed, bool selected, bool air, std::list<std::shared_ptr<Arsenal>> &arsenalList,
                    std::list<std::shared_ptr<Vehicle>> &vehicleList, std::list<std::shared_ptr<BarInterface>> &bars);
    const void attack() override;
    const void notifyArsenals() const override;
    const void attach(const std::shared_ptr<Arsenal> &gun) override;
    const void detach(const std::shared_ptr<Arsenal> &gun) override;
    const void notifyPlanes() const override;
    const void attachPlanes(const std::shared_ptr<WarPlane> &warPlanes) override;
    const void detachPlanes(const std::shared_ptr<WarPlane> &warPlanes) override;
    const void notifyBars() const override;
    const void notifyBarsDamage() const override;
    const void attachBar(const std::shared_ptr<BarInterface> &bar) override;
    const void detachBar(const std::shared_ptr<BarInterface> &bar) override;
protected:
    const void move() override;
    const bool searchTarget() override;
    const float rotate() override;
    const bool canEngage() const override;
};


#endif //SEALION_CONCRETEWARSHIP_H
