//
// Created by pala on 9/11/21.
//

#ifndef SEALION_MVCCONTROLLER_H
#define SEALION_MVCCONTROLLER_H


#include <utility>

#include "AircraftCarrier.h"

class MvcController {
public:
    explicit MvcController(WarShip &mod) : model(mod) {}

    void startUpEngine();

private:
    WarShip &model;
};


#endif //SEALION_MVCCONTROLLER_H
