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


    shipWidth = 12;
    shipHeight = 114;

    numAntiAir = 14;


    std::unique_ptr<Destroyer> fletcher(
            new Destroyer(1000,1000, 4, 68, 2500, 33,
                          "Usa", 0, 0, 5, numAntiAir,  v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Fletcher, 10));
    
    ASSERT_EQ(fletcher->getPos().x,1000);
    ASSERT_EQ(fletcher->getPos().y,1000);
    ASSERT_EQ(fletcher->getAcceleration(),4);
    ASSERT_EQ(fletcher->getMaxSpeed(),68);
    ASSERT_EQ(fletcher->getHp(),2500);
    ASSERT_EQ(fletcher->getArmour(),33);
    ASSERT_EQ(fletcher->getNationality(),"Usa");
    ASSERT_EQ(fletcher->getNumLCannons(),0);
    ASSERT_EQ(fletcher->getNumHCannons(),0);
    ASSERT_EQ(fletcher->getNumMCannons(),5);
    ASSERT_EQ(fletcher->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(fletcher->getWidth(),shipWidth);
    ASSERT_EQ(fletcher->getLength(),shipHeight);
    ASSERT_EQ(fletcher->getCol(),true);
    ASSERT_EQ(fletcher->getShipType(),ShipType::Destroyer);
    ASSERT_EQ(fletcher->getModelType(),ModelType::Fletcher);
    ASSERT_EQ(fletcher->getNumTorpedoTubes(),10);

     shipWidth = 13;
     shipHeight = 116;

     numAntiAir = 16;

    std::unique_ptr<Destroyer> jutLand(
            new Destroyer(1000,1000, 4, 66, 2480, 26,
                          "Uk", 0, 0, 3, numAntiAir,  v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Jutland, 10));
    
    
    
    ASSERT_EQ(jutLand->getPos().x,1000);
    ASSERT_EQ(jutLand->getPos().y,1000);
    ASSERT_EQ(jutLand->getAcceleration(),4);
    ASSERT_EQ(jutLand->getMaxSpeed(),66);
    ASSERT_EQ(jutLand->getHp(),2480);
    ASSERT_EQ(jutLand->getArmour(),26);
    ASSERT_EQ(jutLand->getNationality(),"Uk");
    ASSERT_EQ(jutLand->getNumLCannons(),0);
    ASSERT_EQ(jutLand->getNumHCannons(),0);
    ASSERT_EQ(jutLand->getNumMCannons(),3);
    ASSERT_EQ(jutLand->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(jutLand->getWidth(),shipWidth);
    ASSERT_EQ(jutLand->getLength(),shipHeight);
    ASSERT_EQ(jutLand->getCol(),true);
    ASSERT_EQ(jutLand->getShipType(),ShipType::Destroyer);
    ASSERT_EQ(jutLand->getModelType(),ModelType::Jutland);
    ASSERT_EQ(jutLand->getNumTorpedoTubes(),10);
    
    shipWidth = 15;
    shipHeight = 172;

    
    numAntiAir = 12;

    std::unique_ptr<Destroyer> paoloEmilio(
            new Destroyer(1000,1000, 4, 76, 5420, 66,
                          "Italy", 0, 0, 4, numAntiAir,  v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Impavido, 8));
    
    
    ASSERT_EQ(paoloEmilio->getPos().x,1000);
    ASSERT_EQ(paoloEmilio->getPos().y,1000);
    ASSERT_EQ(paoloEmilio->getAcceleration(),4);
    ASSERT_EQ(paoloEmilio->getMaxSpeed(),76);
    ASSERT_EQ(paoloEmilio->getHp(),5420);
    ASSERT_EQ(paoloEmilio->getArmour(),66);
    ASSERT_EQ(paoloEmilio->getNationality(),"Italy");
    ASSERT_EQ(paoloEmilio->getNumLCannons(),0);
    ASSERT_EQ(paoloEmilio->getNumHCannons(),0);
    ASSERT_EQ(paoloEmilio->getNumMCannons(),4);
    ASSERT_EQ(paoloEmilio->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(paoloEmilio->getWidth(),shipWidth);
    ASSERT_EQ(paoloEmilio->getLength(),shipHeight);
    ASSERT_EQ(paoloEmilio->getCol(),true);
    ASSERT_EQ(paoloEmilio->getShipType(),ShipType::Destroyer);
    ASSERT_EQ(paoloEmilio->getModelType(),ModelType::Impavido);
    ASSERT_EQ(paoloEmilio->getNumTorpedoTubes(),8);
    
    
    
    shipWidth = 15;
    shipHeight = 131;

    numAntiAir = 40;
    

    std::unique_ptr<Destroyer> impavido(
            new Destroyer(1000,1000, 4, 63, 3941, 36,
                          "Italy", 4, 0, 1, numAntiAir,  v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Impavido, 6));
    
    ASSERT_EQ(impavido->getPos().x,1000);
    ASSERT_EQ(impavido->getPos().y,1000);
    ASSERT_EQ(impavido->getAcceleration(),4);
    ASSERT_EQ(impavido->getMaxSpeed(),63);
    ASSERT_EQ(impavido->getHp(),3941);
    ASSERT_EQ(impavido->getArmour(),63);
    ASSERT_EQ(impavido->getNationality(),"Italy");
    ASSERT_EQ(impavido->getNumLCannons(),4);
    ASSERT_EQ(impavido->getNumHCannons(),0);
    ASSERT_EQ(impavido->getNumMCannons(),1);
    ASSERT_EQ(impavido->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(impavido->getWidth(),shipWidth);
    ASSERT_EQ(impavido->getLength(),shipHeight);
    ASSERT_EQ(impavido->getCol(),true);
    ASSERT_EQ(impavido->getShipType(),ShipType::Destroyer);
    ASSERT_EQ(impavido->getModelType(),ModelType::Impavido);
    ASSERT_EQ(impavido->getNumTorpedoTubes(),6);

    shipWidth = 12;
    shipHeight = 119;



    numAntiAir = 32;


    std::unique_ptr<Destroyer> yukikaze(
            new Destroyer(1000,1000, 4, 65, 2530, 26,
                          "Japan", 0, 0, 4, numAntiAir,  v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Yukikaze, 8));
    
    ASSERT_EQ(yukikaze->getPos().x,1000);
    ASSERT_EQ(yukikaze->getPos().y,1000);
    ASSERT_EQ(yukikaze->getAcceleration(),4);
    ASSERT_EQ(yukikaze->getMaxSpeed(),65);
    ASSERT_EQ(yukikaze->getHp(),2530);
    ASSERT_EQ(yukikaze->getArmour(),26);
    ASSERT_EQ(yukikaze->getNationality(),"Japan");
    ASSERT_EQ(yukikaze->getNumLCannons(),0);
    ASSERT_EQ(yukikaze->getNumHCannons(),0);
    ASSERT_EQ(yukikaze->getNumMCannons(),4);
    ASSERT_EQ(yukikaze->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(yukikaze->getWidth(),shipWidth);
    ASSERT_EQ(yukikaze->getLength(),shipHeight);
    ASSERT_EQ(yukikaze->getCol(),true);
    ASSERT_EQ(yukikaze->getShipType(),ShipType::Destroyer);
    ASSERT_EQ(yukikaze->getModelType(),ModelType::Yukikaze);
    ASSERT_EQ(yukikaze->getNumTorpedoTubes(),8);
    
    
    shipWidth = 13;
    shipHeight = 104;
    numAntiAir = 8;
    
    std::unique_ptr<Destroyer> Mahan(
            new Destroyer(1000,1000,4, 69, 2137, 27,
                          "Usa", 0, 0, 4, numAntiAir,  v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Mahan, 12));
    
    
    ASSERT_EQ(Mahan->getPos().x,1000);
    ASSERT_EQ(Mahan->getPos().y,1000);
    ASSERT_EQ(Mahan->getAcceleration(),4);
    ASSERT_EQ(Mahan->getMaxSpeed(),69);
    ASSERT_EQ(Mahan->getHp(),2137);
    ASSERT_EQ(Mahan->getArmour(),27);
    ASSERT_EQ(Mahan->getNationality(),"Usa");
    ASSERT_EQ(Mahan->getNumLCannons(),0);
    ASSERT_EQ(Mahan->getNumHCannons(),0);
    ASSERT_EQ(Mahan->getNumMCannons(),4);
    ASSERT_EQ(Mahan->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(Mahan->getWidth(),shipWidth);
    ASSERT_EQ(Mahan->getLength(),shipHeight);
    ASSERT_EQ(Mahan->getCol(),true);
    ASSERT_EQ(Mahan->getShipType(),ShipType::Destroyer);
    ASSERT_EQ(Mahan->getModelType(),ModelType::Mahan);
    ASSERT_EQ(Mahan->getNumTorpedoTubes(),12);
    
    
    shipWidth = 10;
    shipHeight = 99;
    numAntiAir = 8;

    std::unique_ptr<Destroyer> Gallant(
            new Destroyer(1000,1000, 4, 67, 1913, 22,
                          "Japan", 0, 0, 4, numAntiAir,  v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Gallant, 8));
    
    
    ASSERT_EQ(Gallant->getPos().x,1000);
    ASSERT_EQ(Gallant->getPos().y,1000);
    ASSERT_EQ(Gallant->getAcceleration(),4);
    ASSERT_EQ(Gallant->getMaxSpeed(),67);
    ASSERT_EQ(Gallant->getHp(),1913);
    ASSERT_EQ(Gallant->getArmour(),22);
    ASSERT_EQ(Gallant->getNationality(),"Japan");
    ASSERT_EQ(Gallant->getNumLCannons(),0);
    ASSERT_EQ(Gallant->getNumHCannons(),0);
    ASSERT_EQ(Gallant->getNumMCannons(),4);
    ASSERT_EQ(Gallant->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(Gallant->getWidth(),shipWidth);
    ASSERT_EQ(Gallant->getLength(),shipHeight);
    ASSERT_EQ(Gallant->getCol(),true);
    ASSERT_EQ(Gallant->getShipType(),ShipType::Destroyer);
    ASSERT_EQ(Gallant->getModelType(),ModelType::Gallant);
    ASSERT_EQ(Gallant->getNumTorpedoTubes(),8);
    


}
