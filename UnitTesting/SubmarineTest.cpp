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

    shipWidth = 8;
    shipHeight = 84;



    std::unique_ptr<Submarine> Triton(
            new Submarine(1000,1000, 2, 28, 1576, 0, "Uk", 0, 0, 0, 0,  v, shipHeight, shipWidth, true,
                          ShipType::Submarine, ModelType::Triton, 6, false));

    ASSERT_EQ(Triton->getPos().x,1000);
    ASSERT_EQ(Triton->getPos().y,1000);
    ASSERT_EQ(Triton->getAcceleration(),2);
    ASSERT_EQ(Triton->getMaxSpeed(),28);
    ASSERT_EQ(Triton->getHp(),1576);
    ASSERT_EQ(Triton->getArmour(),0);
    ASSERT_EQ(Triton->getNationality(),"Uk");
    ASSERT_EQ(Triton->getNumLCannons(),0);
    ASSERT_EQ(Triton->getNumHCannons(),0);
    ASSERT_EQ(Triton->getNumMCannons(),0);
    ASSERT_EQ(Triton->getNumAntiAircraft(),0);
    ASSERT_EQ(Triton->getWidth(),shipWidth);
    ASSERT_EQ(Triton->getLength(),shipHeight);
    ASSERT_EQ(Triton->getCol(),true);
    ASSERT_EQ(Triton->getShipType(),ShipType::Submarine);
    ASSERT_EQ(Triton->getModelType(),ModelType::Triton);
    ASSERT_EQ(Triton->getNumTorpedoTubes(),6);
    ASSERT_EQ(Triton->isSubmerged1(),false);


    shipWidth = 9;
    shipHeight = 77;



    std::unique_ptr<Submarine> DaVinci(
            new Submarine(1000,1000, 2, 15, 1489, 0, "Italy", 0, 0, 0, 0,  v, shipHeight, shipWidth, true,
                          ShipType::Submarine, ModelType::DaVinci, 8, false));

    ASSERT_EQ(DaVinci->getPos().x,1000);
    ASSERT_EQ(DaVinci->getPos().y,1000);
    ASSERT_EQ(DaVinci->getAcceleration(),2);
    ASSERT_EQ(DaVinci->getMaxSpeed(),15);
    ASSERT_EQ(DaVinci->getHp(),1489);
    ASSERT_EQ(DaVinci->getArmour(),0);
    ASSERT_EQ(DaVinci->getNationality(),"Italy");
    ASSERT_EQ(DaVinci->getNumLCannons(),0);
    ASSERT_EQ(DaVinci->getNumHCannons(),0);
    ASSERT_EQ(DaVinci->getNumMCannons(),0);
    ASSERT_EQ(DaVinci->getNumAntiAircraft(),0);
    ASSERT_EQ(DaVinci->getWidth(),shipWidth);
    ASSERT_EQ(DaVinci->getLength(),shipHeight);
    ASSERT_EQ(DaVinci->getCol(),true);
    ASSERT_EQ(DaVinci->getShipType(),ShipType::Submarine);
    ASSERT_EQ(DaVinci->getModelType(),ModelType::DaVinci);
    ASSERT_EQ(DaVinci->getNumTorpedoTubes(),8);
    ASSERT_EQ(DaVinci->isSubmerged1(),false);

    
    shipWidth = 10;
    shipHeight = 111;

    std::unique_ptr<Submarine> typeb1(
            new Submarine(1000,1000, 2, 44, 3713, 0, "Japan", 0, 0, 0, 0,  v, shipHeight, shipWidth,
                          true,
                          ShipType::Submarine, ModelType::typeb1, 6,
                          false));

    ASSERT_EQ(typeb1->getPos().x,1000);
    ASSERT_EQ(typeb1->getPos().y,1000);
    ASSERT_EQ(typeb1->getAcceleration(),2);
    ASSERT_EQ(typeb1->getMaxSpeed(),44);
    ASSERT_EQ(typeb1->getHp(),3713);
    ASSERT_EQ(typeb1->getArmour(),0);
    ASSERT_EQ(typeb1->getNationality(),"Japan");
    ASSERT_EQ(typeb1->getNumLCannons(),0);
    ASSERT_EQ(typeb1->getNumHCannons(),0);
    ASSERT_EQ(typeb1->getNumMCannons(),0);
    ASSERT_EQ(typeb1->getNumAntiAircraft(),0);
    ASSERT_EQ(typeb1->getWidth(),shipWidth);
    ASSERT_EQ(typeb1->getLength(),shipHeight);
    ASSERT_EQ(typeb1->getCol(),true);
    ASSERT_EQ(typeb1->getShipType(),ShipType::Submarine);
    ASSERT_EQ(typeb1->getModelType(),ModelType::typeb1);
    ASSERT_EQ(typeb1->getNumTorpedoTubes(),6);
    ASSERT_EQ(typeb1->isSubmerged1(),false);



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
