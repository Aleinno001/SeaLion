//
// Created by pala on 9/15/21.
//

#include "gtest/gtest.h"
#include "../MvcController.h"
#include "../ShipFactory.h"

TEST(MediumCannon, Constructor) {
    /*int x, int y, float ac, const float maxVel, int hp, int arm,
                    std::string nat, int numL, int numH, int numM, int numAA,
                     int le, int wi,
                    bool col, ShipType sh, ModelType mo, int planes*/
    AircraftCarrier giuseppeGaribaldi(100,100,30,30,30,300,"Italy",2,3,5,16,100,20,false,ShipType::AircraftCarrier,ModelType::GiuseppeGaribaldi,10);
    MvcController controller(giuseppeGaribaldi.getInstance());
    controller.getModel().getInstance().HowManyGuns(),giuseppeGaribaldi.getInstance().HowManyGuns()
    controller.getModel().getInstance().getNumPlanes(),giuseppeGaribaldi.getInstance().getNumPlanes()
}