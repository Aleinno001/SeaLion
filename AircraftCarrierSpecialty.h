//
// Created by alessandro on 19/09/21.
//

#ifndef SEALION_AIRCRAFTCARRIERSPECIALTY_H
#define SEALION_AIRCRAFTCARRIERSPECIALTY_H

#include <list>
#include "MvcSubject.h"

class AircraftCarrierSpecialty : public MvcSubject{
protected:
    int numPlanes;
    std::list<std::shared_ptr<WarPlane>> planes;
    std::list<std::shared_ptr<MvcObserver>> listMvcObservers;
public:
    explicit AircraftCarrierSpecialty(int numPlanes) : numPlanes(numPlanes) {}
    ~AircraftCarrierSpecialty() override =0;
    virtual int getNumPlanes() const {return numPlanes;}
    virtual const std::list<std::shared_ptr<WarPlane>> &getPlanes() const {return planes;}
    virtual const std::list<std::shared_ptr<MvcObserver>> &getListMvcObservers() const {return listMvcObservers;}
    virtual void planesAttack()=0;
    virtual void notifyPlanes(sf::Vector2f &vel, double mx) =0;
    virtual void attachPlanes(const std::shared_ptr<WarPlane> &warPlane) =0;
    virtual void detachPlanes(const std::shared_ptr<WarPlane> &warPlane) =0;
};

#endif //SEALION_AIRCRAFTCARRIERSPECIALTY_H
