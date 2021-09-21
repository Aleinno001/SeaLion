//
// Created by alessandro on 19/09/21.
//

#ifndef SEALION_CONCRETEAIRCRAFTCARRIER_H
#define SEALION_CONCRETEAIRCRAFTCARRIER_H

#include "AircraftCarrier.h"

class ConcreteAircraftCarrier : public AircraftCarrier{
private:
    std::list<std::shared_ptr<MvcObserver>> listMvcObservers;
public:
    ConcreteAircraftCarrier(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col,std::string &nat, ShipType shipType, ModelType modelType, const int armour,const std::string &name, const int numLCannons, const int numMCannons,const int numHCannons, const int numAntiAircraft, int numPlanes);
    ~ConcreteAircraftCarrier() override;
    void specialAttack()override;
    void notifyPlanes() override;
    void attachPlanes(const std::shared_ptr<WarPlane> &warPlane) override;
    void detachPlanes(const std::shared_ptr<WarPlane> &warPlane) override;
    bool searchTarget() override;
    void notifyArsenals() const override;
    void attach(const std::shared_ptr<Arsenal> &gun) override;
    void detach(const std::shared_ptr<Arsenal> &gun) override;
    void notifyBars() const override;
    void notifyBarsDamage() const override;
    void attachBar(const std::shared_ptr<BarInterface> &bar) override;
    void detachBar(const std::shared_ptr<BarInterface> &bar) override;
    void setMvcTarget(std::shared_ptr<WarShip> target) override;
protected:
    void move() override;
    void attack() override;
    float rotate(float mx, float rotatingInPlaceMult) override;
    bool canEngage() override;
};


#endif //SEALION_CONCRETEAIRCRAFTCARRIER_H
