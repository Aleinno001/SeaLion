//
// Created by alessandro on 17/09/21.
//
#ifndef SEALION_CONCRETEWARSHIP_H
#define SEALION_CONCRETEWARSHIP_H
#include "WarShip.h"
#include "ConcreteAircraftCarrier.h"
#include "Tools.h"
class ConcreteWarShip : public WarShip {
public:
    ConcreteWarShip(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string &nat,ShipType shipType, ModelType modelType, int armour, const std::string &name,int numLCannons, int numMCannons, int numHCannons, int numAntiAircraft);
    bool searchTarget() override;
    void notifyArsenals() const override;
    void attach(const std::shared_ptr<Arsenal> &gun) override;
    void detach(const std::shared_ptr<Arsenal> &gun) override;
    void notifyBars() const override;
    void notifyBarsDamage() const override;
    void attachBar(const std::shared_ptr<BarInterface> &bar) override;
    void detachBar(const std::shared_ptr<BarInterface> &bar) override;
    void drawEquipment(sf::RenderWindow &window) override;
protected:
    void move() override;
    void attack() override;
    float rotate(float mx, float rotatingInPlaceMult) override;
    bool canEngage() override;
};
#endif //SEALION_CONCRETEWARSHIP_H
