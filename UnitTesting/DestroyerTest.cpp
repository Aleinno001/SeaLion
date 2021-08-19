//
// Created by pala on 8/18/21.
//
#include "gtest/gtest.h"
#include "../Destroyer.h"


TEST(Destroyer, Constructor) {
    int shipWidth = 16;
    int shipHeight = 106;
    
    std::list<std::unique_ptr<Vehicle>> v;


    int numAntiAir = 16;



    std::unique_ptr<Destroyer> sims(
            new Destroyer(1000,1000, 4, 69, 2293, 30,
                          "Usa", 0, 0, 4, numAntiAir,  v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Sims, 8));

    
    ASSERT_EQ(sims->getPos().x,1000);
    ASSERT_EQ(sims->getPos().y,1000);
    ASSERT_EQ(sims->getAcceleration(),4);
    ASSERT_EQ(sims->getMaxSpeed(),69);
    ASSERT_EQ(sims->getHp(),2293);
    ASSERT_EQ(sims->getArmour(),30);
    ASSERT_EQ(sims->getNationality(),"Usa");
    ASSERT_EQ(sims->getNumLCannons(),0);
    ASSERT_EQ(sims->getNumHCannons(),0);
    ASSERT_EQ(sims->getNumMCannons(),4);
    ASSERT_EQ(sims->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(sims->getWidth(),shipWidth);
    ASSERT_EQ(sims->getLength(),shipHeight);
    ASSERT_EQ(sims->getCol(),true);
    ASSERT_EQ(sims->getShipType(),ShipType::Destroyer);
    ASSERT_EQ(sims->getModelType(),ModelType::Sims);
    ASSERT_EQ(sims->getNumTorpedoTubes(),8);

}
