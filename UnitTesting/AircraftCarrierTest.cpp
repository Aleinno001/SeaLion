//
// Created by pala on 8/18/21.
//
#include "gtest/gtest.h"
#include "../AircraftCarrier.h"


TEST(AircraftCarrier, Constructor) {
    
    int shipWidth = 84;
    int shipHeight = 296;
    int numAntiAir = 15;
    std::list<std::unique_ptr<Vehicle>> v;
    std::unique_ptr<AircraftCarrier> mid(new AircraftCarrier(1000, 1000, 1, 61, 640000, 520,
                                                             "Usa", 2, 0, 0, numAntiAir,  v, shipHeight, shipWidth,
                                                             true,
                                                             ShipType::AircraftCarrier, ModelType::Midway, 14));
    
    ASSERT_EQ(mid->getPos().x,1000);
    ASSERT_EQ(mid->getPos().y,1000);
    ASSERT_EQ(mid->getAcceleration(),1);
    ASSERT_EQ(mid->getMaxSpeed(),61);
    ASSERT_EQ(mid->getHp(),640000);
    ASSERT_EQ(mid->getArmour(),520);
    ASSERT_EQ(mid->getNationality(),"Usa");
    ASSERT_EQ(mid->getNumLCannons(),2);
    ASSERT_EQ(mid->getNumHCannons(),0);
    ASSERT_EQ(mid->getNumMCannons(),0);
    ASSERT_EQ(mid->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(mid->getWidth(),shipWidth);
    ASSERT_EQ(mid->getLength(),shipHeight);
    ASSERT_EQ(mid->getCol(),true);
    ASSERT_EQ(mid->getShipType(),ShipType::AircraftCarrier);
    ASSERT_EQ(mid->getModelType(),ModelType::Midway);
    ASSERT_EQ(mid->getNumPlanes(),14);

    shipWidth = 38;
    shipHeight = 240;
    numAntiAir = 4;

    std::unique_ptr<AircraftCarrier> arkRoyal(
            new AircraftCarrier(1000,1000, 1, 56, 28160, 20,
                                "Uk", 2, 0, 0, numAntiAir,  v, shipHeight, shipWidth, true, ShipType::AircraftCarrier,
                                ModelType::ArkRoyal, 7));
    
    ASSERT_EQ(arkRoyal->getPos().x,1000);
    ASSERT_EQ(arkRoyal->getPos().y,1000);
    ASSERT_EQ(arkRoyal->getAcceleration(),1);
    ASSERT_EQ(arkRoyal->getMaxSpeed(),56);
    ASSERT_EQ(arkRoyal->getHp(),28160);
    ASSERT_EQ(arkRoyal->getArmour(),20);
    ASSERT_EQ(arkRoyal->getNationality(),"Uk");
    ASSERT_EQ(arkRoyal->getNumLCannons(),2);
    ASSERT_EQ(arkRoyal->getNumHCannons(),0);
    ASSERT_EQ(arkRoyal->getNumMCannons(),0);
    ASSERT_EQ(arkRoyal->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(arkRoyal->getWidth(),shipWidth);
    ASSERT_EQ(arkRoyal->getLength(),shipHeight);
    ASSERT_EQ(arkRoyal->getCol(),true);
    ASSERT_EQ(arkRoyal->getShipType(),ShipType::AircraftCarrier);
    ASSERT_EQ(arkRoyal->getModelType(),ModelType::ArkRoyal);
    ASSERT_EQ(arkRoyal->getNumPlanes(),7);
    
    numAntiAir=0;
    shipWidth = 44;
    shipHeight = 180;



    std::unique_ptr<AircraftCarrier> GiuseppeGaribaldi(
            new AircraftCarrier(1000, 1000, 1, 56, 14150, 114, "Italy", 3, 0, 0, 0,  v, shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::GiuseppeGaribaldi, 6));

    ASSERT_EQ(GiuseppeGaribaldi->getPos().x,1000);
    ASSERT_EQ(GiuseppeGaribaldi->getPos().y,1000);
    ASSERT_EQ(GiuseppeGaribaldi->getAcceleration(),1);
    ASSERT_EQ(GiuseppeGaribaldi->getMaxSpeed(),56);
    ASSERT_EQ(GiuseppeGaribaldi->getHp(),14150);
    ASSERT_EQ(GiuseppeGaribaldi->getArmour(),114);
    ASSERT_EQ(GiuseppeGaribaldi->getNationality(),"Italy");
    ASSERT_EQ(GiuseppeGaribaldi->getNumLCannons(),3);
    ASSERT_EQ(GiuseppeGaribaldi->getNumHCannons(),0);
    ASSERT_EQ(GiuseppeGaribaldi->getNumMCannons(),0);
    ASSERT_EQ(GiuseppeGaribaldi->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(GiuseppeGaribaldi->getWidth(),shipWidth);
    ASSERT_EQ(GiuseppeGaribaldi->getLength(),shipHeight);
    ASSERT_EQ(GiuseppeGaribaldi->getCol(),true);
    ASSERT_EQ(GiuseppeGaribaldi->getShipType(),ShipType::AircraftCarrier);
    ASSERT_EQ(GiuseppeGaribaldi->getModelType(),ModelType::GiuseppeGaribaldi);
    ASSERT_EQ(GiuseppeGaribaldi->getNumPlanes(),6);


    shipWidth = 46;
    shipHeight = 260;

    numAntiAir = 20;

    std::unique_ptr<AircraftCarrier> Tahio(
            new AircraftCarrier(1000, 1000, 1, 61, 37866, 304, "Japan", 2, 0, 0, numAntiAir,  v,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::Tahio, 7));


    ASSERT_EQ(Tahio->getPos().x,1000);
    ASSERT_EQ(Tahio->getPos().y,1000);
    ASSERT_EQ(Tahio->getAcceleration(),1);
    ASSERT_EQ(Tahio->getMaxSpeed(),61);
    ASSERT_EQ(Tahio->getHp(),37866);
    ASSERT_EQ(Tahio->getArmour(),304);
    ASSERT_EQ(Tahio->getNationality(),"Japan");
    ASSERT_EQ(Tahio->getNumLCannons(),2);
    ASSERT_EQ(Tahio->getNumHCannons(),0);
    ASSERT_EQ(Tahio->getNumMCannons(),0);
    ASSERT_EQ(Tahio->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(Tahio->getWidth(),shipWidth);
    ASSERT_EQ(Tahio->getLength(),shipHeight);
    ASSERT_EQ(Tahio->getCol(),true);
    ASSERT_EQ(Tahio->getShipType(),ShipType::AircraftCarrier);
    ASSERT_EQ(Tahio->getModelType(),ModelType::Tahio);
    ASSERT_EQ(Tahio->getNumPlanes(),7);


    shipWidth = 70;
    shipHeight = 295;


    numAntiAir = 8;


    std::unique_ptr<AircraftCarrier> FranklinDRoosevelt(
            new AircraftCarrier(1000,1000, 1, 61, 45000, 363, "Usa", 0, 0, 2, numAntiAir,  v,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::FranklinDRoosevelt, 14));

    ASSERT_EQ(FranklinDRoosevelt->getPos().x,1000);
    ASSERT_EQ(FranklinDRoosevelt->getPos().y,1000);
    ASSERT_EQ(FranklinDRoosevelt->getAcceleration(),1);
    ASSERT_EQ(FranklinDRoosevelt->getMaxSpeed(),61);
    ASSERT_EQ(FranklinDRoosevelt->getHp(),45000);
    ASSERT_EQ(FranklinDRoosevelt->getArmour(),363);
    ASSERT_EQ(FranklinDRoosevelt->getNationality(),"Usa");
    ASSERT_EQ(FranklinDRoosevelt->getNumLCannons(),0);
    ASSERT_EQ(FranklinDRoosevelt->getNumHCannons(),0);
    ASSERT_EQ(FranklinDRoosevelt->getNumMCannons(),2);
    ASSERT_EQ(FranklinDRoosevelt->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(FranklinDRoosevelt->getWidth(),shipWidth);
    ASSERT_EQ(FranklinDRoosevelt->getLength(),shipHeight);
    ASSERT_EQ(FranklinDRoosevelt->getCol(),true);
    ASSERT_EQ(FranklinDRoosevelt->getShipType(),ShipType::AircraftCarrier);
    ASSERT_EQ(FranklinDRoosevelt->getModelType(),ModelType::FranklinDRoosevelt);
    ASSERT_EQ(FranklinDRoosevelt->getNumPlanes(),14);
    
    shipWidth = 41;
    shipHeight = 230;

    numAntiAir = 6;

    std::unique_ptr<AircraftCarrier> Indomitable(
            new AircraftCarrier(1000,1000, 1, 56, 29730, 240, "Uk", 2, 0, 0, numAntiAir,  v,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::Indomitable, 5));
    
    
    ASSERT_EQ(Indomitable->getPos().x,1000);
    ASSERT_EQ(Indomitable->getPos().y,1000);
    ASSERT_EQ(Indomitable->getAcceleration(),1);
    ASSERT_EQ(Indomitable->getMaxSpeed(),56);
    ASSERT_EQ(Indomitable->getHp(),29730);
    ASSERT_EQ(Indomitable->getArmour(),240);
    ASSERT_EQ(Indomitable->getNationality(),"Uk");
    ASSERT_EQ(Indomitable->getNumLCannons(),2);
    ASSERT_EQ(Indomitable->getNumHCannons(),0);
    ASSERT_EQ(Indomitable->getNumMCannons(),0);
    ASSERT_EQ(Indomitable->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(Indomitable->getWidth(),shipWidth);
    ASSERT_EQ(Indomitable->getLength(),shipHeight);
    ASSERT_EQ(Indomitable->getCol(),true);
    ASSERT_EQ(Indomitable->getShipType(),ShipType::AircraftCarrier);
    ASSERT_EQ(Indomitable->getModelType(),ModelType::Indomitable);
    ASSERT_EQ(Indomitable->getNumPlanes(),5);
    
    
    shipWidth = 50;
    shipHeight = 244;

    

    numAntiAir = 3;


    std::unique_ptr<AircraftCarrier> Cavour(
            new AircraftCarrier(1000, 1000, 1, 52, 29900, 241, "Italy", 4, 0, 0, numAntiAir,  v,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::Cavour, 5));
    
    ASSERT_EQ(Cavour->getPos().x,1000);
    ASSERT_EQ(Cavour->getPos().y,1000);
    ASSERT_EQ(Cavour->getAcceleration(),1);
    ASSERT_EQ(Cavour->getMaxSpeed(),52);
    ASSERT_EQ(Cavour->getHp(),29900);
    ASSERT_EQ(Cavour->getArmour(),241);
    ASSERT_EQ(Cavour->getNationality(),"Italy");
    ASSERT_EQ(Cavour->getNumLCannons(),4);
    ASSERT_EQ(Cavour->getNumHCannons(),0);
    ASSERT_EQ(Cavour->getNumMCannons(),0);
    ASSERT_EQ(Cavour->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(Cavour->getWidth(),shipWidth);
    ASSERT_EQ(Cavour->getLength(),shipHeight);
    ASSERT_EQ(Cavour->getCol(),true);
    ASSERT_EQ(Cavour->getShipType(),ShipType::AircraftCarrier);
    ASSERT_EQ(Cavour->getModelType(),ModelType::Cavour);
    ASSERT_EQ(Cavour->getNumPlanes(),5);


    shipWidth = 39;
    shipHeight = 222;



   numAntiAir = 2;


    std::unique_ptr<AircraftCarrier> Hiryu(
            new AircraftCarrier(1000, 1000, 1, 63, 20570, 70, "Japan", 2, 0, 0, numAntiAir,  v,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::Hiryu, 6));


    ASSERT_EQ(Hiryu->getPos().x,1000);
    ASSERT_EQ(Hiryu->getPos().y,1000);
    ASSERT_EQ(Hiryu->getAcceleration(),1);
    ASSERT_EQ(Hiryu->getMaxSpeed(),63);
    ASSERT_EQ(Hiryu->getHp(),20570);
    ASSERT_EQ(Hiryu->getArmour(),70);
    ASSERT_EQ(Hiryu->getNationality(),"Japan");
    ASSERT_EQ(Hiryu->getNumLCannons(),2);
    ASSERT_EQ(Hiryu->getNumHCannons(),0);
    ASSERT_EQ(Hiryu->getNumMCannons(),0);
    ASSERT_EQ(Hiryu->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(Hiryu->getWidth(),shipWidth);
    ASSERT_EQ(Hiryu->getLength(),shipHeight);
    ASSERT_EQ(Hiryu->getCol(),true);
    ASSERT_EQ(Hiryu->getShipType(),ShipType::AircraftCarrier);
    ASSERT_EQ(Hiryu->getModelType(),ModelType::Hiryu);
    ASSERT_EQ(Hiryu->getNumPlanes(),6);
    
    

    
    
    
    




    

}
