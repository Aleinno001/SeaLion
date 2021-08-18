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
    ASSERT_EQ(montana->getNumHCannons(),4);
    ASSERT_EQ(montana->getNumMCannons(),10);
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
    ASSERT_EQ(imperatoreAugusto->getNumHCannons(),4);
    ASSERT_EQ(imperatoreAugusto->getNumMCannons(),10);
    ASSERT_EQ(imperatoreAugusto->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(imperatoreAugusto->getWidth(),shipWidth);
    ASSERT_EQ(imperatoreAugusto->getLength(),shipHeight);
    ASSERT_EQ(imperatoreAugusto->getCol(),true);
    ASSERT_EQ(imperatoreAugusto->getShipType(),ShipType::Battleship);
    ASSERT_EQ(imperatoreAugusto->getModelType(),ModelType::ImperatoreAugusto);
    ASSERT_EQ(imperatoreAugusto->getNumInterceptors(),0);
    
    shipWidth = 31;
    shipHeight = 222;

    
    numAntiAir = 18;
    std::unique_ptr<Battleship> kongo(new Battleship(1000, 1000, 1, 56, 37187, 592,
                                                     "Japan", 6, 4, 0, numAntiAir,  v, shipHeight, shipWidth, true,
                                                     ShipType::Battleship,
                                                     ModelType::Kongo, 0));
    
    ASSERT_EQ(kongo->getPos().x,1000);
    ASSERT_EQ(kongo->getPos().y,1000);
    ASSERT_EQ(kongo->getAcceleration(),1);
    ASSERT_EQ(kongo->getMaxSpeed(),56);
    ASSERT_EQ(kongo->getHp(),37187);
    ASSERT_EQ(kongo->getArmour(),592);
    ASSERT_EQ(kongo->getNationality(),"Japan");
    ASSERT_EQ(kongo->getNumLCannons(),6);
    ASSERT_EQ(kongo->getNumHCannons(),4);
    ASSERT_EQ(kongo->getNumMCannons(),0);
    ASSERT_EQ(kongo->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(kongo->getWidth(),shipWidth);
    ASSERT_EQ(kongo->getLength(),shipHeight);
    ASSERT_EQ(kongo->getCol(),true);
    ASSERT_EQ(kongo->getShipType(),ShipType::Battleship);
    ASSERT_EQ(kongo->getModelType(),ModelType::Kongo);
    ASSERT_EQ(kongo->getNumInterceptors(),0);
    
    shipWidth = 39;
    shipHeight = 244;


    numAntiAir = 30;

    std::unique_ptr<Battleship> musashi(new Battleship(1000,1000, 1, 51, 72809, 1540,
                                                       "Japan", 6, 3, 2, numAntiAir,  v, shipHeight, shipWidth, true,
                                                       ShipType::Battleship,
                                                       ModelType::Musashi, 2));
    
    ASSERT_EQ(musashi->getPos().x,1000);
    ASSERT_EQ(musashi->getPos().y,1000);
    ASSERT_EQ(musashi->getAcceleration(),1);
    ASSERT_EQ(musashi->getMaxSpeed(),51);
    ASSERT_EQ(musashi->getHp(),72809);
    ASSERT_EQ(musashi->getArmour(),1540);
    ASSERT_EQ(musashi->getNationality(),"Japan");
    ASSERT_EQ(musashi->getNumLCannons(),6);
    ASSERT_EQ(musashi->getNumHCannons(),3);
    ASSERT_EQ(musashi->getNumMCannons(),2);
    ASSERT_EQ(musashi->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(musashi->getWidth(),shipWidth);
    ASSERT_EQ(musashi->getLength(),shipHeight);
    ASSERT_EQ(musashi->getCol(),true);
    ASSERT_EQ(musashi->getShipType(),ShipType::Battleship);
    ASSERT_EQ(musashi->getModelType(),ModelType::Musashi);
    ASSERT_EQ(musashi->getNumInterceptors(),2);
    
    shipWidth = 25;
    shipHeight = 158;

  
    numAntiAir = 20;
    std::unique_ptr<Battleship> dreadNought(
            new Battleship(1000,1000, 1, 39, 21060, 837,
                           "Uk", 0, 5, 0, numAntiAir,  v, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::Dreadnought, 0));
    
    ASSERT_EQ(dreadNought->getPos().x,1000);
    ASSERT_EQ(dreadNought->getPos().y,1000);
    ASSERT_EQ(dreadNought->getAcceleration(),1);
    ASSERT_EQ(dreadNought->getMaxSpeed(),39);
    ASSERT_EQ(dreadNought->getHp(),21060);
    ASSERT_EQ(dreadNought->getArmour(),837);
    ASSERT_EQ(dreadNought->getNationality(),"Uk");
    ASSERT_EQ(dreadNought->getNumLCannons(),0);
    ASSERT_EQ(dreadNought->getNumHCannons(),5);
    ASSERT_EQ(dreadNought->getNumMCannons(),0);
    ASSERT_EQ(dreadNought->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(dreadNought->getWidth(),shipWidth);
    ASSERT_EQ(dreadNought->getLength(),shipHeight);
    ASSERT_EQ(dreadNought->getCol(),true);
    ASSERT_EQ(dreadNought->getShipType(),ShipType::Battleship);
    ASSERT_EQ(dreadNought->getModelType(),ModelType::Dreadnought);
    ASSERT_EQ(dreadNought->getNumInterceptors(),0);
    
    shipWidth = 39;
    shipHeight = 242;
    numAntiAir = 10;
    std::unique_ptr<Battleship> lion(
            new Battleship(1000,1000, 1, 52, 49670, 944,
                           "Uk", 0, 4, 0, numAntiAir,  v, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::Lion, 0));
    
    ASSERT_EQ(lion->getPos().x,1000);
    ASSERT_EQ(lion->getPos().y,1000);
    ASSERT_EQ(lion->getAcceleration(),1);
    ASSERT_EQ(lion->getMaxSpeed(),52);
    ASSERT_EQ(lion->getHp(),49670);
    ASSERT_EQ(lion->getArmour(),944);
    ASSERT_EQ(lion->getNationality(),"Uk");
    ASSERT_EQ(lion->getNumLCannons(),0);
    ASSERT_EQ(lion->getNumHCannons(),4);
    ASSERT_EQ(lion->getNumMCannons(),0);
    ASSERT_EQ(lion->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(lion->getWidth(),shipWidth);
    ASSERT_EQ(lion->getLength(),shipHeight);
    ASSERT_EQ(lion->getCol(),true);
    ASSERT_EQ(lion->getShipType(),ShipType::Battleship);
    ASSERT_EQ(lion->getModelType(),ModelType::Lion);
    ASSERT_EQ(lion->getNumInterceptors(),0);



    shipWidth = 32;
    shipHeight = 222;
    numAntiAir = 34;

    std::unique_ptr<Battleship> northCarolina(
            new Battleship(1000,1000, 1, 52, 45500, 1224,
                           "Usa", 6, 2, 0, numAntiAir,  v, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::NorthCarolina, 3));


    ASSERT_EQ(northCarolina->getPos().x,1000);
    ASSERT_EQ(northCarolina->getPos().y,1000);
    ASSERT_EQ(northCarolina->getAcceleration(),1);
    ASSERT_EQ(northCarolina->getMaxSpeed(),52);
    ASSERT_EQ(northCarolina->getHp(),45500);
    ASSERT_EQ(northCarolina->getArmour(),1224);
    ASSERT_EQ(northCarolina->getNationality(),"Usa");
    ASSERT_EQ(northCarolina->getNumLCannons(),6);
    ASSERT_EQ(northCarolina->getNumHCannons(),2);
    ASSERT_EQ(northCarolina->getNumMCannons(),0);
    ASSERT_EQ(northCarolina->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(northCarolina->getWidth(),shipWidth);
    ASSERT_EQ(northCarolina->getLength(),shipHeight);
    ASSERT_EQ(northCarolina->getCol(),true);
    ASSERT_EQ(northCarolina->getShipType(),ShipType::Battleship);
    ASSERT_EQ(northCarolina->getModelType(),ModelType::NorthCarolina);
    ASSERT_EQ(northCarolina->getNumInterceptors(),3);





    shipWidth = 39;
    shipHeight = 190;
    numAntiAir = 15;
    std::unique_ptr<Battleship> ironDuke(
            new Battleship(1000, 1000, 1, 39, 29500, 826,
                           "Uk", 0, 5, 0, numAntiAir,  v, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::IronDuke, 0));

    ASSERT_EQ(ironDuke->getPos().x,1000);
    ASSERT_EQ(ironDuke->getPos().y,1000);
    ASSERT_EQ(ironDuke->getAcceleration(),1);
    ASSERT_EQ(ironDuke->getMaxSpeed(),39);
    ASSERT_EQ(ironDuke->getHp(),29500);
    ASSERT_EQ(ironDuke->getArmour(),826);
    ASSERT_EQ(ironDuke->getNationality(),"Uk");
    ASSERT_EQ(ironDuke->getNumLCannons(),0);
    ASSERT_EQ(ironDuke->getNumHCannons(),5);
    ASSERT_EQ(ironDuke->getNumMCannons(),0);
    ASSERT_EQ(ironDuke->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(ironDuke->getWidth(),shipWidth);
    ASSERT_EQ(ironDuke->getLength(),shipHeight);
    ASSERT_EQ(ironDuke->getCol(),true);
    ASSERT_EQ(ironDuke->getShipType(),ShipType::Battleship);
    ASSERT_EQ(ironDuke->getModelType(),ModelType::IronDuke);
    ASSERT_EQ(ironDuke->getNumInterceptors(),0);





}
