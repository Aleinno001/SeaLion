//
// Created by pala on 9/16/21.
//
#ifndef SEALION_WARPLANE_H
#define SEALION_WARPLANE_H
#include "Vehicle.h"
class WarPlane : public Vehicle {
public:
    virtual const void update()=0; //Metodo per design pattern observer tra planes and Warship
    ~WarPlane() override =0;
};
#endif //SEALION_WARPLANE_H
