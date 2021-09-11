//
// Created by pala on 9/11/21.
//

#ifndef SEALION_MVCCONTROLLER_H
#define SEALION_MVCCONTROLLER_H


#include "AircraftCarrier.h"

class MvcController {
public:
    explicit MvcController(AircraftCarrier &mod): model(mod){}
    void startUpEngine();
private:
    AircraftCarrier &model;
};


#endif //SEALION_MVCCONTROLLER_H
