//
// Created by pala on 9/15/21.
//

#include "gtest/gtest.h"
#include "../MvcController.h"
#include "../ShipFactory.h"

TEST(MvcController, Constructor) {
    /*int x, int y, float ac, const float maxVel, int hp, int arm,
                    std::string nat, int numL, int numH, int numM, int numAA,
                     int le, int wi,
                    bool col, ShipType sh, ModelType mo, int planes*/
    AircraftCarrier giuseppeGaribaldi(100,100,30,30,30,300,"Italy",2,3,5,16,100,20,false,ShipType::AircraftCarrier,ModelType::GiuseppeGaribaldi,10);
    MvcController controller(giuseppeGaribaldi.getInstance());
    ASSERT_EQ(controller.getModel().getInstance().HowManyGuns(),giuseppeGaribaldi.getInstance().HowManyGuns());
    ASSERT_EQ(controller.getModel().getInstance().getNumPlanes(),giuseppeGaribaldi.getInstance().getNumPlanes());
    for(auto &it:giuseppeGaribaldi.getListMvcObservers())
        for(auto &itController:controller.getModel().getListMvcObservers())
            ASSERT_EQ(itController.get(),it.get());

    ASSERT_EQ(controller.getModel().getSprite().getPosition(),giuseppeGaribaldi.getSprite().getPosition());
    ASSERT_EQ(controller.getModel().getArmour(),giuseppeGaribaldi.getArmour());
    ASSERT_EQ(controller.getModel().getModelType(),giuseppeGaribaldi.getModelType());
    ASSERT_EQ(controller.getModel().getNationality(),giuseppeGaribaldi.getNationality());
    ASSERT_EQ(controller.getModel().getWidth(),giuseppeGaribaldi.getWidth());
    ASSERT_EQ(controller.getModel().getLength(),giuseppeGaribaldi.getLength());
    ASSERT_EQ(controller.getModel().getMaxHp(),giuseppeGaribaldi.getMaxHp());
    ASSERT_EQ(controller.getModel().getHp(),giuseppeGaribaldi.getHp());
    ASSERT_EQ(controller.getModel().getCol(),giuseppeGaribaldi.getCol());
    ASSERT_EQ(controller.getModel().getMaxSpeed(),giuseppeGaribaldi.getMaxSpeed());
    ASSERT_EQ(controller.getModel().getAcceleration(),giuseppeGaribaldi.getAcceleration());
    ASSERT_EQ(controller.getModel().getPos(),giuseppeGaribaldi.getPos());
    ASSERT_EQ(controller.getModel().getShipType(),giuseppeGaribaldi.getShipType());
    ASSERT_EQ(controller.getModel().getNumAntiAircraft(),giuseppeGaribaldi.getNumAntiAircraft());
    ASSERT_EQ(controller.getModel().getNumHCannons(),giuseppeGaribaldi.getNumHCannons());
    ASSERT_EQ(controller.getModel().getNumLCannons(),giuseppeGaribaldi.getNumLCannons());
    ASSERT_EQ(controller.getModel().getNumMCannons(),giuseppeGaribaldi.getNumMCannons());
    ASSERT_EQ(controller.getModel().getSprite().getColor(),giuseppeGaribaldi.getSprite().getColor());
    ASSERT_EQ(controller.getModel().getSprite().getOrigin(),giuseppeGaribaldi.getSprite().getOrigin());
    ASSERT_EQ(controller.getModel().getSprite().getTexture(),giuseppeGaribaldi.getSprite().getTexture());


}