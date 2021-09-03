//
// Created by pala on 9/2/21.
//

#include "gtest/gtest.h"

#include "../AircraftCarrier.h"
#include "../AirplaneFactory.h"
#include "../TorpedoBomber.h"

TEST(torpedoBomber, Constructor) {

    int posX = 700;
    int posY = 700;
    sf::Vector2i coordinates;
    coordinates.x = 1000;
    coordinates.y = 1000;
    int shipWidth = 44;
    int shipHeight = 180;
    AirplaneFactory airPlanesfactory;
    int ac=4;
    double maxVel = 70;
    double hp = 400;
    int length=35;
    int width = 35;
    bool col = true;
    int numTor = 20;
    int damage = 1500;

    std::unique_ptr<AircraftCarrier> GiuseppeGaribaldi(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 14150, 114, "Italy", 3, 0, 0, 0, shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::GiuseppeGaribaldi, 6));

    std::unique_ptr<TorpedoBomber> torpedoBomber(new TorpedoBomber(posX,posY,ac,maxVel,hp,length,width,col,numTor,damage,"Italy",*GiuseppeGaribaldi));

    ASSERT_EQ(torpedoBomber->getPos().x,posX);
    ASSERT_EQ(torpedoBomber->getPos().y,posY);
    ASSERT_EQ(torpedoBomber->getAcceleration(),ac);
    ASSERT_EQ(torpedoBomber->getMaxSpeed(),maxVel);
    ASSERT_EQ(torpedoBomber->getHp(),hp);
    ASSERT_EQ(torpedoBomber->getLength(),length);
    ASSERT_EQ(torpedoBomber->getWidth(),width);
    ASSERT_EQ(torpedoBomber->getCol(),col);
    ASSERT_EQ(torpedoBomber->getNumTorpedos(),numTor);
    ASSERT_EQ(torpedoBomber->getTorpedoDamage(),damage);
    ASSERT_EQ(torpedoBomber->getNationality(),"Italy");


}

