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







    

}
