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


    shipWidth = 13;
    shipHeight = 122;


    std::unique_ptr<Submarine> i400(
            new Submarine(1000,1000, 2, 35, 6670, 0, "Japan", 0, 0, 0, 0,  v, shipHeight, shipWidth,
                          true,
                          ShipType::Submarine, ModelType::I400, 8, false));



    ASSERT_EQ(i400->getPos().x,1000);
    ASSERT_EQ(i400->getPos().y,1000);
    ASSERT_EQ(i400->getAcceleration(),2);
    ASSERT_EQ(i400->getMaxSpeed(),35);
    ASSERT_EQ(i400->getHp(),6670);
    ASSERT_EQ(i400->getArmour(),0);
    ASSERT_EQ(i400->getNationality(),"Japan");
    ASSERT_EQ(i400->getNumLCannons(),0);
    ASSERT_EQ(i400->getNumHCannons(),0);
    ASSERT_EQ(i400->getNumMCannons(),0);
    ASSERT_EQ(i400->getNumAntiAircraft(),0);
    ASSERT_EQ(i400->getWidth(),shipWidth);
    ASSERT_EQ(i400->getLength(),shipHeight);
    ASSERT_EQ(i400->getCol(),true);
    ASSERT_EQ(i400->getShipType(),ShipType::Submarine);
    ASSERT_EQ(i400->getModelType(),ModelType::I400);
    ASSERT_EQ(i400->getNumTorpedoTubes(),8);
    ASSERT_EQ(i400->isSubmerged1(),false);
    
    
    shipWidth = 13;
    shipHeight = 91;

  
    std::unique_ptr<Submarine> Narwhal(
            new Submarine(1000,1000, 2, 48, 4600, 0, "Usa", 0, 0, 0, 0,  v, shipHeight, shipWidth, true,
                          ShipType::Submarine, ModelType::Narwhal, 4, false));



    ASSERT_EQ(Narwhal->getPos().x,1000);
    ASSERT_EQ(Narwhal->getPos().y,1000);
    ASSERT_EQ(Narwhal->getAcceleration(),2);
    ASSERT_EQ(Narwhal->getMaxSpeed(),48);
    ASSERT_EQ(Narwhal->getHp(),4600);
    ASSERT_EQ(Narwhal->getArmour(),0);
    ASSERT_EQ(Narwhal->getNationality(),"Usa");
    ASSERT_EQ(Narwhal->getNumLCannons(),0);
    ASSERT_EQ(Narwhal->getNumHCannons(),0);
    ASSERT_EQ(Narwhal->getNumMCannons(),0);
    ASSERT_EQ(Narwhal->getNumAntiAircraft(),0);
    ASSERT_EQ(Narwhal->getWidth(),shipWidth);
    ASSERT_EQ(Narwhal->getLength(),shipHeight);
    ASSERT_EQ(Narwhal->getCol(),true);
    ASSERT_EQ(Narwhal->getShipType(),ShipType::Submarine);
    ASSERT_EQ(Narwhal->getModelType(),ModelType::Narwhal);
    ASSERT_EQ(Narwhal->getNumTorpedoTubes(),4);
    ASSERT_EQ(Narwhal->isSubmerged1(),false);

    shipWidth = 14;
    shipHeight = 85;

    std::unique_ptr<Submarine> Trenchant(
            new Submarine(1000,1000, 2, 56, 5800, 0, "Uk", 0, 0, 0, 0,  v, shipHeight, shipWidth, true,
                          ShipType::Submarine, ModelType::Trenchant, 5, false));



    ASSERT_EQ(Trenchant->getPos().x,1000);
    ASSERT_EQ(Trenchant->getPos().y,1000);
    ASSERT_EQ(Trenchant->getAcceleration(),2);
    ASSERT_EQ(Trenchant->getMaxSpeed(),56);
    ASSERT_EQ(Trenchant->getHp(),5800);
    ASSERT_EQ(Trenchant->getArmour(),0);
    ASSERT_EQ(Trenchant->getNationality(),"Uk");
    ASSERT_EQ(Trenchant->getNumLCannons(),0);
    ASSERT_EQ(Trenchant->getNumHCannons(),0);
    ASSERT_EQ(Trenchant->getNumMCannons(),0);
    ASSERT_EQ(Trenchant->getNumAntiAircraft(),0);
    ASSERT_EQ(Trenchant->getWidth(),shipWidth);
    ASSERT_EQ(Trenchant->getLength(),shipHeight);
    ASSERT_EQ(Trenchant->getCol(),true);
    ASSERT_EQ(Trenchant->getShipType(),ShipType::Submarine);
    ASSERT_EQ(Trenchant->getModelType(),ModelType::Trenchant);
    ASSERT_EQ(Trenchant->getNumTorpedoTubes(),5);
    ASSERT_EQ(Trenchant->isSubmerged1(),false);



    shipWidth = 19;
    shipHeight = 106;


    std::unique_ptr<Submarine> Papa(
            new Submarine(1000,1000, 2, 82, 7100, 0, "Italy", 0, 0, 0, 0,  v, shipHeight, shipWidth,
                          true,
                          ShipType::Submarine, ModelType::Papa,10, false));


    ASSERT_EQ(Papa->getPos().x,1000);
    ASSERT_EQ(Papa->getPos().y,1000);
    ASSERT_EQ(Papa->getAcceleration(),2);
    ASSERT_EQ(Papa->getMaxSpeed(),82);
    ASSERT_EQ(Papa->getHp(),7100);
    ASSERT_EQ(Papa->getArmour(),0);
    ASSERT_EQ(Papa->getNationality(),"Italy");
    ASSERT_EQ(Papa->getNumLCannons(),0);
    ASSERT_EQ(Papa->getNumHCannons(),0);
    ASSERT_EQ(Papa->getNumMCannons(),0);
    ASSERT_EQ(Papa->getNumAntiAircraft(),0);
    ASSERT_EQ(Papa->getWidth(),shipWidth);
    ASSERT_EQ(Papa->getLength(),shipHeight);
    ASSERT_EQ(Papa->getCol(),true);
    ASSERT_EQ(Papa->getShipType(),ShipType::Submarine);
    ASSERT_EQ(Papa->getModelType(),ModelType::Papa);
    ASSERT_EQ(Papa->getNumTorpedoTubes(),10);
    ASSERT_EQ(Papa->isSubmerged1(),false);






}
