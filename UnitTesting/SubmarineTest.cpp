//
// Created by pala on 8/18/21.
//
#include "gtest/gtest.h"
#include "../Submarine.h"


TEST(Submarine, Constructor) {
    int shipWidth = 9;
    int shipHeight = 95;
    std::list<std::unique_ptr<Vehicle>> v;
    std::unique_ptr<Submarine> Gato(
            new Submarine(1000,1000, 2, 37, 2460, 0, "Usa", 0, 0, 0, 0,  v, shipHeight, shipWidth, true,
                          ShipType::Submarine, ModelType::Gato, 6, false));
    
    ASSERT_EQ(Gato->getPos().x,1000);
    ASSERT_EQ(Gato->getPos().y,1000);
    ASSERT_EQ(Gato->getAcceleration(),2);
    ASSERT_EQ(Gato->getMaxSpeed(),37);
    ASSERT_EQ(Gato->getHp(),2460);
    ASSERT_EQ(Gato->getArmour(),0);
    ASSERT_EQ(Gato->getNationality(),"Usa");
    ASSERT_EQ(Gato->getNumLCannons(),0);
    ASSERT_EQ(Gato->getNumHCannons(),0);
    ASSERT_EQ(Gato->getNumMCannons(),0);
    ASSERT_EQ(Gato->getNumAntiAircraft(),0);
    ASSERT_EQ(Gato->getWidth(),shipWidth);
    ASSERT_EQ(Gato->getLength(),shipHeight);
    ASSERT_EQ(Gato->getCol(),true);
    ASSERT_EQ(Gato->getShipType(),ShipType::Submarine);
    ASSERT_EQ(Gato->getModelType(),ModelType::Gato);
    ASSERT_EQ(Gato->getNumTorpedoTubes(),6);
    ASSERT_EQ(Gato->isSubmerged1(),false);


}
