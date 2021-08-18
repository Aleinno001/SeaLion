//
// Created by pala on 8/18/21.
//
#include "gtest/gtest.h"
#include "../Battleship.h"


TEST(Battleship, Constructor) {
    int numAntiAir = 80;
    int shipWidth = 37;
    int shipHeight = 281;
    std::list<std::unique_ptr<Vehicle>> v;
    std::unique_ptr<Battleship> montana(new Battleship(1000,1000,1, 52, 72104, 1810,"Usa", 0, 4, 10, numAntiAir, v, shipHeight, shipWidth, true,ShipType::Battleship,ModelType::Montana, 2));

    ASSERT_EQ(montana->getPos().x,1000);
    ASSERT_EQ(montana->getPos().y,1000);
    ASSERT_EQ(montana->getAcceleration(),1);
    ASSERT_EQ(montana->getMaxSpeed(),52);
    ASSERT_EQ(montana->getHp(),72104);
    ASSERT_EQ(montana->getArmour(),1810);
    ASSERT_EQ(montana->getNationality(),"Usa");
    ASSERT_EQ(montana->getNumLCannons(),0);
    ASSERT_EQ(montana->getNumMCannons(),4);
    ASSERT_EQ(montana->getNumHCannons(),10);
    ASSERT_EQ(montana->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(montana->getWidth(),shipWidth);
    ASSERT_EQ(montana->getLength(),shipHeight);
    ASSERT_EQ(montana->getCol(),true);
    ASSERT_EQ(montana->getShipType(),ShipType::Battleship);
    ASSERT_EQ(montana->getModelType(),ModelType::Montana);
    ASSERT_EQ(montana->getNumInterceptors(),2);
    
    
    shipWidth = 39;
    shipHeight = 274;
    numAntiAir = 12;

    std::unique_ptr<Battleship> imperatoreAugusto(
            new Battleship(1000,1000, 1, 57, 65232, 1126,
                           "Italy", 16, 4, 10, numAntiAir,  v, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::ImperatoreAugusto, 0));

    ASSERT_EQ(imperatoreAugusto->getPos().x,1000);
    ASSERT_EQ(imperatoreAugusto->getPos().y,1000);
    ASSERT_EQ(imperatoreAugusto->getAcceleration(),1);
    ASSERT_EQ(imperatoreAugusto->getMaxSpeed(),57);
    ASSERT_EQ(imperatoreAugusto->getHp(),65232);
    ASSERT_EQ(imperatoreAugusto->getArmour(),1126);
    ASSERT_EQ(imperatoreAugusto->getNationality(),"Italy");
    ASSERT_EQ(imperatoreAugusto->getNumLCannons(),16);
    ASSERT_EQ(imperatoreAugusto->getNumMCannons(),4);
    ASSERT_EQ(imperatoreAugusto->getNumHCannons(),10);
    ASSERT_EQ(imperatoreAugusto->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(imperatoreAugusto->getWidth(),shipWidth);
    ASSERT_EQ(imperatoreAugusto->getLength(),shipHeight);
    ASSERT_EQ(imperatoreAugusto->getCol(),true);
    ASSERT_EQ(imperatoreAugusto->getShipType(),ShipType::Battleship);
    ASSERT_EQ(imperatoreAugusto->getModelType(),ModelType::ImperatoreAugusto);
    ASSERT_EQ(imperatoreAugusto->getNumInterceptors(),0);






}
