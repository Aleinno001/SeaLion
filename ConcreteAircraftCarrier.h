//
// Created by alessandro on 19/09/21.
//

#ifndef SEALION_CONCRETEAIRCRAFTCARRIER_H
#define SEALION_CONCRETEAIRCRAFTCARRIER_H

#include "AircraftCarrier.h"
#include "MvcView.h"

class ConcreteAircraftCarrier : public AircraftCarrier{
public:
    ConcreteAircraftCarrier(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col,std::string nat, ShipType shipType, ModelType modelType,int armour, std::string name,  int numLCannons, int numMCannons, int numHCannons, int numAntiAircraft, int numPlanes);
    void notifyPlanes() override;
    void attachPlanes(std::shared_ptr<WarPlane> warPlane) override;
    void searchTarget(float elapsedTime) override;
    void notifyArsenals() const override;
    void attach(std::shared_ptr<Arsenal> gun) override;
    void detach(std::shared_ptr<Arsenal> gun) override;
    void notifyBars() const override;
    void notifyBarsDamage() const override;
    void attachBar(std::shared_ptr<BarInterface> bar) override;
    void setMvcTarget(std::shared_ptr<WarShip> target) override;
    void drawEquipment(sf::RenderWindow &window) override;
    ~ConcreteAircraftCarrier()=default;
protected:
    void move(float elapsedTime) override;
    void attack(float elapsedTime) override;
    float rotate(float mx, float rotatingInPlaceMult) override;
    bool canEngage() override;
};


#endif //SEALION_CONCRETEAIRCRAFTCARRIER_H
