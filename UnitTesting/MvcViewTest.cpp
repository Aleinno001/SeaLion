//
// Created by pala on 9/15/21.
//
#include "gtest/gtest.h"
#include "../MvcView.h"


TEST(MvcView, Constructor) {
    /*int x, int y, float ac, const float maxVel, int hp, int arm,
                    std::string nat, int numL, int numH, int numM, int numAA,
                     int le, int wi,
                    bool col, ShipType sh, ModelType mo, int planes*/
    AircraftCarrier giuseppeGaribaldi(100,100,30,30,30,300,"Italy",2,3,5,16,100,20,false,ShipType::AircraftCarrier,ModelType::GiuseppeGaribaldi,10);
    MvcController controller(giuseppeGaribaldi.getInstance());
    sf::RenderWindow window;
    MvcView view(giuseppeGaribaldi.getInstance(),controller,window);

    ASSERT_EQ(view.getModel().getSprite().getPosition(),giuseppeGaribaldi.getSprite().getPosition());
    ASSERT_EQ(view.getModel().getArmour(),giuseppeGaribaldi.getArmour());
    ASSERT_EQ(view.getModel().getModelType(),giuseppeGaribaldi.getModelType());
    ASSERT_EQ(view.getModel().getNationality(),giuseppeGaribaldi.getNationality());
    ASSERT_EQ(view.getModel().getWidth(),giuseppeGaribaldi.getWidth());
    ASSERT_EQ(view.getModel().getLength(),giuseppeGaribaldi.getLength());
    ASSERT_EQ(view.getModel().getMaxHp(),giuseppeGaribaldi.getMaxHp());
    ASSERT_EQ(view.getModel().getHp(),giuseppeGaribaldi.getHp());
    ASSERT_EQ(view.getModel().getCol(),giuseppeGaribaldi.getCol());
    ASSERT_EQ(view.getModel().getMaxSpeed(),giuseppeGaribaldi.getMaxSpeed());
    ASSERT_EQ(view.getModel().getAcceleration(),giuseppeGaribaldi.getAcceleration());
    ASSERT_EQ(view.getModel().getPos(),giuseppeGaribaldi.getPos());
    ASSERT_EQ(view.getModel().getShipType(),giuseppeGaribaldi.getShipType());
    ASSERT_EQ(view.getModel().getNumAntiAircraft(),giuseppeGaribaldi.getNumAntiAircraft());
    ASSERT_EQ(view.getModel().getNumHCannons(),giuseppeGaribaldi.getNumHCannons());
    ASSERT_EQ(view.getModel().getNumLCannons(),giuseppeGaribaldi.getNumLCannons());
    ASSERT_EQ(view.getModel().getNumMCannons(),giuseppeGaribaldi.getNumMCannons());
    ASSERT_EQ(view.getModel().getSprite().getColor(),giuseppeGaribaldi.getSprite().getColor());
    ASSERT_EQ(view.getModel().getSprite().getOrigin(),giuseppeGaribaldi.getSprite().getOrigin());
    ASSERT_EQ(view.getModel().getSprite().getTexture(),giuseppeGaribaldi.getSprite().getTexture());


}
