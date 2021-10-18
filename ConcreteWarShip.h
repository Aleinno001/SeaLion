//
// Created by alessandro on 17/09/21.
//
#ifndef SEALION_CONCRETEWARSHIP_H
#define SEALION_CONCRETEWARSHIP_H
#include "WarShip.h"
#include "ConcreteAircraftCarrier.h"

class ConcreteWarShip : public WarShip {
public:
    ConcreteWarShip(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string nat,ShipType shipType, ModelType modelType, int armour, std::string name,int numLCannons, int numMCannons, int numHCannons, int numAntiAircraft);
    void searchTarget(float elapsedTime) override;
    void notifyArsenals() const override;
    void attach(std::shared_ptr<Arsenal> gun) override;
    void detach(std::shared_ptr<Arsenal> gun) override;
    void notifyBars() const override;
    void notifyBarsDamage() const override;
    void attachBar(std::shared_ptr<BarInterface> bar) override;
    void drawEquipment(sf::RenderWindow &window) override;
    ~ConcreteWarShip()=default;
protected:
    void move(float elapsedTime) override;
    void attack(float elapsedTime) override;
    float rotate(float mx, float rotatingInPlaceMult) override;
    bool canEngage() override;
};
#endif //SEALION_CONCRETEWARSHIP_H
