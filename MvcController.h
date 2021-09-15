//
// Created by pala on 9/11/21.
//

#ifndef SEALION_MVCCONTROLLER_H
#define SEALION_MVCCONTROLLER_H


#include <utility>

#include "AircraftCarrier.h"

class MvcController {
public:
    explicit MvcController(AircraftCarrier &mod) : model(mod) {}

    void startUpEngine(std::_List_iterator<std::unique_ptr<WarShip>> &target,double dt);

    AircraftCarrier &getModel() const;

private:
    AircraftCarrier &model;
};


#endif //SEALION_MVCCONTROLLER_H
