//
// Created by pala on 8/18/21.
//
#include "gtest/gtest.h"
#include "../GameTile.h"


TEST(Cruiser, Constructor) {
    
    int shipWidth = 20;
    int shipHeight = 130;
    int antiAir = 8;
    
    std::list<std::unique_ptr<Vehicle>> v;

    std::unique_ptr<Cruiser> saintLouis(
            new Cruiser(
                    1000,
                    1000,
                    3,
                    41,
                    11013,
                    280,
                    "Usa",
                    5,
                    0,
                    3,
                    antiAir,
                    v,
                    shipHeight,
                    shipWidth,
                    true,
                    ShipType::Cruiser,
                    ModelType::StLouis,
                    0));
    
    
    ASSERT_EQ(saintLouis->getPos().x,1000);
    ASSERT_EQ(saintLouis->getPos().y,1000);
    ASSERT_EQ(saintLouis->getAcceleration(),3);
    ASSERT_EQ(saintLouis->getMaxSpeed(),41);
    ASSERT_EQ(saintLouis->getHp(),11013);
    ASSERT_EQ(saintLouis->getArmour(),280);
    ASSERT_EQ(saintLouis->getNationality(),"Usa");
    ASSERT_EQ(saintLouis->getNumLCannons(),5);
    ASSERT_EQ(saintLouis->getNumHCannons(),4);
    ASSERT_EQ(saintLouis->getNumMCannons(),3);
    ASSERT_EQ(saintLouis->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(saintLouis->getWidth(),shipWidth);
    ASSERT_EQ(saintLouis->getLength(),shipHeight);
    ASSERT_EQ(saintLouis->getCol(),true);
    ASSERT_EQ(saintLouis->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(saintLouis->getModelType(),ModelType::StLouis);
    ASSERT_EQ(saintLouis->getNumPlanes(),0);
    
    
    shipWidth = 28;
    shipHeight = 246;



    CannonFactory cf;
    antiAir = 9;


    std::unique_ptr<Cruiser> alaska(new Cruiser(1000,1000, 3, 61, 34803, 918,
                                                "Usa", 6, 1, 2, antiAir,  v, shipHeight, shipWidth, true,
                                                ShipType::Cruiser,
                                                ModelType::Alaska,4));
    
    ASSERT_EQ(alaska->getPos().x,1000);
    ASSERT_EQ(alaska->getPos().y,1000);
    ASSERT_EQ(alaska->getAcceleration(),3);
    ASSERT_EQ(alaska->getMaxSpeed(),61);
    ASSERT_EQ(alaska->getHp(),34803);
    ASSERT_EQ(alaska->getArmour(),918);
    ASSERT_EQ(alaska->getNationality(),"Usa");
    ASSERT_EQ(alaska->getNumLCannons(),6);
    ASSERT_EQ(alaska->getNumHCannons(),1);
    ASSERT_EQ(alaska->getNumMCannons(),2);
    ASSERT_EQ(alaska->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(alaska->getWidth(),shipWidth);
    ASSERT_EQ(alaska->getLength(),shipHeight);
    ASSERT_EQ(alaska->getCol(),true);
    ASSERT_EQ(alaska->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(alaska->getModelType(),ModelType::Alaska);
    ASSERT_EQ(alaska->getNumPlanes(),4);


    
    
    ASSERT_EQ(saintLouis->getPos().x,1000);
    ASSERT_EQ(saintLouis->getPos().y,1000);
    ASSERT_EQ(saintLouis->getAcceleration(),3);
    ASSERT_EQ(saintLouis->getMaxSpeed(),41);
    ASSERT_EQ(saintLouis->getHp(),11013);
    ASSERT_EQ(saintLouis->getArmour(),280);
    ASSERT_EQ(saintLouis->getNationality(),"Usa");
    ASSERT_EQ(saintLouis->getNumLCannons(),5);
    ASSERT_EQ(saintLouis->getNumHCannons(),4);
    ASSERT_EQ(saintLouis->getNumMCannons(),3);
    ASSERT_EQ(saintLouis->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(saintLouis->getWidth(),shipWidth);
    ASSERT_EQ(saintLouis->getLength(),shipHeight);
    ASSERT_EQ(saintLouis->getCol(),true);
    ASSERT_EQ(saintLouis->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(saintLouis->getModelType(),ModelType::StLouis);
    ASSERT_EQ(saintLouis->getNumPlanes(),0);
    
    
    
    
    ASSERT_EQ(saintLouis->getPos().x,1000);
    ASSERT_EQ(saintLouis->getPos().y,1000);
    ASSERT_EQ(saintLouis->getAcceleration(),3);
    ASSERT_EQ(saintLouis->getMaxSpeed(),41);
    ASSERT_EQ(saintLouis->getHp(),11013);
    ASSERT_EQ(saintLouis->getArmour(),280);
    ASSERT_EQ(saintLouis->getNationality(),"Usa");
    ASSERT_EQ(saintLouis->getNumLCannons(),5);
    ASSERT_EQ(saintLouis->getNumHCannons(),4);
    ASSERT_EQ(saintLouis->getNumMCannons(),3);
    ASSERT_EQ(saintLouis->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(saintLouis->getWidth(),shipWidth);
    ASSERT_EQ(saintLouis->getLength(),shipHeight);
    ASSERT_EQ(saintLouis->getCol(),true);
    ASSERT_EQ(saintLouis->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(saintLouis->getModelType(),ModelType::StLouis);
    ASSERT_EQ(saintLouis->getNumPlanes(),0);
    
    
    
    
    ASSERT_EQ(saintLouis->getPos().x,1000);
    ASSERT_EQ(saintLouis->getPos().y,1000);
    ASSERT_EQ(saintLouis->getAcceleration(),3);
    ASSERT_EQ(saintLouis->getMaxSpeed(),41);
    ASSERT_EQ(saintLouis->getHp(),11013);
    ASSERT_EQ(saintLouis->getArmour(),280);
    ASSERT_EQ(saintLouis->getNationality(),"Usa");
    ASSERT_EQ(saintLouis->getNumLCannons(),5);
    ASSERT_EQ(saintLouis->getNumHCannons(),4);
    ASSERT_EQ(saintLouis->getNumMCannons(),3);
    ASSERT_EQ(saintLouis->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(saintLouis->getWidth(),shipWidth);
    ASSERT_EQ(saintLouis->getLength(),shipHeight);
    ASSERT_EQ(saintLouis->getCol(),true);
    ASSERT_EQ(saintLouis->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(saintLouis->getModelType(),ModelType::StLouis);
    ASSERT_EQ(saintLouis->getNumPlanes(),0);
    
    
    
    
    
    ASSERT_EQ(saintLouis->getPos().x,1000);
    ASSERT_EQ(saintLouis->getPos().y,1000);
    ASSERT_EQ(saintLouis->getAcceleration(),3);
    ASSERT_EQ(saintLouis->getMaxSpeed(),41);
    ASSERT_EQ(saintLouis->getHp(),11013);
    ASSERT_EQ(saintLouis->getArmour(),280);
    ASSERT_EQ(saintLouis->getNationality(),"Usa");
    ASSERT_EQ(saintLouis->getNumLCannons(),5);
    ASSERT_EQ(saintLouis->getNumHCannons(),4);
    ASSERT_EQ(saintLouis->getNumMCannons(),3);
    ASSERT_EQ(saintLouis->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(saintLouis->getWidth(),shipWidth);
    ASSERT_EQ(saintLouis->getLength(),shipHeight);
    ASSERT_EQ(saintLouis->getCol(),true);
    ASSERT_EQ(saintLouis->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(saintLouis->getModelType(),ModelType::StLouis);
    ASSERT_EQ(saintLouis->getNumPlanes(),0);
    
    
    
    
    
    ASSERT_EQ(saintLouis->getPos().x,1000);
    ASSERT_EQ(saintLouis->getPos().y,1000);
    ASSERT_EQ(saintLouis->getAcceleration(),3);
    ASSERT_EQ(saintLouis->getMaxSpeed(),41);
    ASSERT_EQ(saintLouis->getHp(),11013);
    ASSERT_EQ(saintLouis->getArmour(),280);
    ASSERT_EQ(saintLouis->getNationality(),"Usa");
    ASSERT_EQ(saintLouis->getNumLCannons(),5);
    ASSERT_EQ(saintLouis->getNumHCannons(),4);
    ASSERT_EQ(saintLouis->getNumMCannons(),3);
    ASSERT_EQ(saintLouis->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(saintLouis->getWidth(),shipWidth);
    ASSERT_EQ(saintLouis->getLength(),shipHeight);
    ASSERT_EQ(saintLouis->getCol(),true);
    ASSERT_EQ(saintLouis->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(saintLouis->getModelType(),ModelType::StLouis);
    ASSERT_EQ(saintLouis->getNumPlanes(),0);
    
    
    
    
    
    ASSERT_EQ(saintLouis->getPos().x,1000);
    ASSERT_EQ(saintLouis->getPos().y,1000);
    ASSERT_EQ(saintLouis->getAcceleration(),3);
    ASSERT_EQ(saintLouis->getMaxSpeed(),41);
    ASSERT_EQ(saintLouis->getHp(),11013);
    ASSERT_EQ(saintLouis->getArmour(),280);
    ASSERT_EQ(saintLouis->getNationality(),"Usa");
    ASSERT_EQ(saintLouis->getNumLCannons(),5);
    ASSERT_EQ(saintLouis->getNumHCannons(),4);
    ASSERT_EQ(saintLouis->getNumMCannons(),3);
    ASSERT_EQ(saintLouis->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(saintLouis->getWidth(),shipWidth);
    ASSERT_EQ(saintLouis->getLength(),shipHeight);
    ASSERT_EQ(saintLouis->getCol(),true);
    ASSERT_EQ(saintLouis->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(saintLouis->getModelType(),ModelType::StLouis);
    ASSERT_EQ(saintLouis->getNumPlanes(),0);
    
    
    
    
    
    ASSERT_EQ(saintLouis->getPos().x,1000);
    ASSERT_EQ(saintLouis->getPos().y,1000);
    ASSERT_EQ(saintLouis->getAcceleration(),3);
    ASSERT_EQ(saintLouis->getMaxSpeed(),41);
    ASSERT_EQ(saintLouis->getHp(),11013);
    ASSERT_EQ(saintLouis->getArmour(),280);
    ASSERT_EQ(saintLouis->getNationality(),"Usa");
    ASSERT_EQ(saintLouis->getNumLCannons(),5);
    ASSERT_EQ(saintLouis->getNumHCannons(),4);
    ASSERT_EQ(saintLouis->getNumMCannons(),3);
    ASSERT_EQ(saintLouis->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(saintLouis->getWidth(),shipWidth);
    ASSERT_EQ(saintLouis->getLength(),shipHeight);
    ASSERT_EQ(saintLouis->getCol(),true);
    ASSERT_EQ(saintLouis->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(saintLouis->getModelType(),ModelType::StLouis);
    ASSERT_EQ(saintLouis->getNumPlanes(),0);
    
    
    
    
    ASSERT_EQ(saintLouis->getPos().x,1000);
    ASSERT_EQ(saintLouis->getPos().y,1000);
    ASSERT_EQ(saintLouis->getAcceleration(),3);
    ASSERT_EQ(saintLouis->getMaxSpeed(),41);
    ASSERT_EQ(saintLouis->getHp(),11013);
    ASSERT_EQ(saintLouis->getArmour(),280);
    ASSERT_EQ(saintLouis->getNationality(),"Usa");
    ASSERT_EQ(saintLouis->getNumLCannons(),5);
    ASSERT_EQ(saintLouis->getNumHCannons(),4);
    ASSERT_EQ(saintLouis->getNumMCannons(),3);
    ASSERT_EQ(saintLouis->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(saintLouis->getWidth(),shipWidth);
    ASSERT_EQ(saintLouis->getLength(),shipHeight);
    ASSERT_EQ(saintLouis->getCol(),true);
    ASSERT_EQ(saintLouis->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(saintLouis->getModelType(),ModelType::StLouis);
    ASSERT_EQ(saintLouis->getNumPlanes(),0);
    
    
    
    
    ASSERT_EQ(saintLouis->getPos().x,1000);
    ASSERT_EQ(saintLouis->getPos().y,1000);
    ASSERT_EQ(saintLouis->getAcceleration(),3);
    ASSERT_EQ(saintLouis->getMaxSpeed(),41);
    ASSERT_EQ(saintLouis->getHp(),11013);
    ASSERT_EQ(saintLouis->getArmour(),280);
    ASSERT_EQ(saintLouis->getNationality(),"Usa");
    ASSERT_EQ(saintLouis->getNumLCannons(),5);
    ASSERT_EQ(saintLouis->getNumHCannons(),4);
    ASSERT_EQ(saintLouis->getNumMCannons(),3);
    ASSERT_EQ(saintLouis->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(saintLouis->getWidth(),shipWidth);
    ASSERT_EQ(saintLouis->getLength(),shipHeight);
    ASSERT_EQ(saintLouis->getCol(),true);
    ASSERT_EQ(saintLouis->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(saintLouis->getModelType(),ModelType::StLouis);
    ASSERT_EQ(saintLouis->getNumPlanes(),0);
    
    
    
    
    ASSERT_EQ(saintLouis->getPos().x,1000);
    ASSERT_EQ(saintLouis->getPos().y,1000);
    ASSERT_EQ(saintLouis->getAcceleration(),3);
    ASSERT_EQ(saintLouis->getMaxSpeed(),41);
    ASSERT_EQ(saintLouis->getHp(),11013);
    ASSERT_EQ(saintLouis->getArmour(),280);
    ASSERT_EQ(saintLouis->getNationality(),"Usa");
    ASSERT_EQ(saintLouis->getNumLCannons(),5);
    ASSERT_EQ(saintLouis->getNumHCannons(),4);
    ASSERT_EQ(saintLouis->getNumMCannons(),3);
    ASSERT_EQ(saintLouis->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(saintLouis->getWidth(),shipWidth);
    ASSERT_EQ(saintLouis->getLength(),shipHeight);
    ASSERT_EQ(saintLouis->getCol(),true);
    ASSERT_EQ(saintLouis->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(saintLouis->getModelType(),ModelType::StLouis);
    ASSERT_EQ(saintLouis->getNumPlanes(),0);
    
    
    
    
    ASSERT_EQ(saintLouis->getPos().x,1000);
    ASSERT_EQ(saintLouis->getPos().y,1000);
    ASSERT_EQ(saintLouis->getAcceleration(),3);
    ASSERT_EQ(saintLouis->getMaxSpeed(),41);
    ASSERT_EQ(saintLouis->getHp(),11013);
    ASSERT_EQ(saintLouis->getArmour(),280);
    ASSERT_EQ(saintLouis->getNationality(),"Usa");
    ASSERT_EQ(saintLouis->getNumLCannons(),5);
    ASSERT_EQ(saintLouis->getNumHCannons(),4);
    ASSERT_EQ(saintLouis->getNumMCannons(),3);
    ASSERT_EQ(saintLouis->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(saintLouis->getWidth(),shipWidth);
    ASSERT_EQ(saintLouis->getLength(),shipHeight);
    ASSERT_EQ(saintLouis->getCol(),true);
    ASSERT_EQ(saintLouis->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(saintLouis->getModelType(),ModelType::StLouis);
    ASSERT_EQ(saintLouis->getNumPlanes(),0);
    
    
    
    
    
    ASSERT_EQ(saintLouis->getPos().x,1000);
    ASSERT_EQ(saintLouis->getPos().y,1000);
    ASSERT_EQ(saintLouis->getAcceleration(),3);
    ASSERT_EQ(saintLouis->getMaxSpeed(),41);
    ASSERT_EQ(saintLouis->getHp(),11013);
    ASSERT_EQ(saintLouis->getArmour(),280);
    ASSERT_EQ(saintLouis->getNationality(),"Usa");
    ASSERT_EQ(saintLouis->getNumLCannons(),5);
    ASSERT_EQ(saintLouis->getNumHCannons(),4);
    ASSERT_EQ(saintLouis->getNumMCannons(),3);
    ASSERT_EQ(saintLouis->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(saintLouis->getWidth(),shipWidth);
    ASSERT_EQ(saintLouis->getLength(),shipHeight);
    ASSERT_EQ(saintLouis->getCol(),true);
    ASSERT_EQ(saintLouis->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(saintLouis->getModelType(),ModelType::StLouis);
    ASSERT_EQ(saintLouis->getNumPlanes(),0);
    
    
    
    

}

