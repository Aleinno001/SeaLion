//
// Created by pala on 9/2/21.
//

#include "gtest/gtest.h"
#include "../Bomber.h"
#include "../AircraftCarrier.h"
#include "../AirplaneFactory.h"

TEST(Bomber, Constructor) {

    int posX = 700;
    int posY = 700;
    sf::Vector2i coordinates;
    coordinates.x = 1000;
    coordinates.y = 1000;
    int shipWidth = 44;
    int shipHeight = 180;
    AirplaneFactory airPlanesfactory;
    int ac=3;
    double maxVel = 60;
    double hp = 500;
    int length=26;
    int width = 35;
    bool col = true;
    int numBombs = 150;
    int damage = 900;

    std::unique_ptr<AircraftCarrier> GiuseppeGaribaldi(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 14150, 114, "Italy", 3, 0, 0, 0, shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::GiuseppeGaribaldi, 6));

    std::unique_ptr<Bomber> bomber(new Bomber(posX,posY,ac,maxVel,hp,length,width,col,numBombs,damage,"Italy",*GiuseppeGaribaldi));

    ASSERT_EQ(bomber->getPos().x,posX);
    ASSERT_EQ(bomber->getPos().y,posY);
    ASSERT_EQ(bomber->getAcceleration(),ac);
    ASSERT_EQ(bomber->getMaxSpeed(),maxVel);
    ASSERT_EQ(bomber->getHp(),hp);
    ASSERT_EQ(bomber->getLength(),length);
    ASSERT_EQ(bomber->getWidth(),width);
    ASSERT_EQ(bomber->getCol(),col);
    ASSERT_EQ(bomber->getNumBombs(),numBombs);
    ASSERT_EQ(bomber->getBombDamage(),damage);
    ASSERT_EQ(bomber->getNationality(),"Italy");

    
}
