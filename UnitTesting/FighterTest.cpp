//
// Created by pala on 9/2/21.
//

#include "gtest/gtest.h"
#include "../Fighter.h"
#include "../AircraftCarrier.h"
#include "../AirplaneFactory.h"

TEST(Fighter, Constructor) {

    int posX = 700;
    int posY = 700;
    sf::Vector2i coordinates;
    coordinates.x = 1000;
    coordinates.y = 1000;
    int shipWidth = 44;
    int shipHeight = 180;
    AirplaneFactory airPlanesfactory;
    int ac=5;
    double maxVel = 80;
    double hp = 300;
    int length=27;
    int width = 15;
    bool col = true;
    int numBombs = 150;
    int damage = 900;

    std::unique_ptr<AircraftCarrier> GiuseppeGaribaldi(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 14150, 114, "Italy", 3, 0, 0, 0, shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::GiuseppeGaribaldi, 6));

    std::unique_ptr<Fighter> fighter(new Fighter(posX,posY,ac,maxVel,hp,length,width,col,"Italy",*GiuseppeGaribaldi));

    ASSERT_EQ(fighter->getPos().x,posX);
    ASSERT_EQ(fighter->getPos().y,posY);
    ASSERT_EQ(fighter->getAcceleration(),ac);
    ASSERT_EQ(fighter->getMaxSpeed(),maxVel);
    ASSERT_EQ(fighter->getHp(),hp);
    ASSERT_EQ(fighter->getLength(),length);
    ASSERT_EQ(fighter->getWidth(),width);
    ASSERT_EQ(fighter->getCol(),col);
    ASSERT_EQ(fighter->getNationality(),"Italy");


}

