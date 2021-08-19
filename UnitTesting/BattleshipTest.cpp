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


    shipWidth = 33;
    shipHeight = 238;

    
    numAntiAir = 32;

    std::unique_ptr<Battleship> VittorioVeneto(
            new Battleship(1000,1000, 1, 56, 45963, 862, "Italy", 12, 4, 4, numAntiAir,  v,
                           shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::VittorioVeneto, 1));
        
    ASSERT_EQ(VittorioVeneto->getPos().x,1000);
    ASSERT_EQ(VittorioVeneto->getPos().y,1000);
    ASSERT_EQ(VittorioVeneto->getAcceleration(),1);
    ASSERT_EQ(VittorioVeneto->getMaxSpeed(),56);
    ASSERT_EQ(VittorioVeneto->getHp(),45963);
    ASSERT_EQ(VittorioVeneto->getArmour(),862);
    ASSERT_EQ(VittorioVeneto->getNationality(),"Italy");
    ASSERT_EQ(VittorioVeneto->getNumLCannons(),12);
    ASSERT_EQ(VittorioVeneto->getNumHCannons(),4);
    ASSERT_EQ(VittorioVeneto->getNumMCannons(),4);
    ASSERT_EQ(VittorioVeneto->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(VittorioVeneto->getWidth(),shipWidth);
    ASSERT_EQ(VittorioVeneto->getLength(),shipHeight);
    ASSERT_EQ(VittorioVeneto->getCol(),true);
    ASSERT_EQ(VittorioVeneto->getShipType(),ShipType::Battleship);
    ASSERT_EQ(VittorioVeneto->getModelType(),ModelType::VittorioVeneto);
    ASSERT_EQ(VittorioVeneto->getNumInterceptors(),1);
    
    
    shipWidth = 35;
    shipHeight = 175;
    numAntiAir = 6;

    std::unique_ptr<Battleship> NewYork(
            new Battleship(1000,1000, 1, 39, 28822, 939,
                           "Usa", 0, 5, 0, numAntiAir,  v, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::NewYork, 0));
    
    
    ASSERT_EQ(NewYork->getPos().x,1000);
    ASSERT_EQ(NewYork->getPos().y,1000);
    ASSERT_EQ(NewYork->getAcceleration(),1);
    ASSERT_EQ(NewYork->getMaxSpeed(),39);
    ASSERT_EQ(NewYork->getHp(),28822);
    ASSERT_EQ(NewYork->getArmour(),939);
    ASSERT_EQ(NewYork->getNationality(),"Usa");
    ASSERT_EQ(NewYork->getNumLCannons(),0);
    ASSERT_EQ(NewYork->getNumHCannons(),5);
    ASSERT_EQ(NewYork->getNumMCannons(),0);
    ASSERT_EQ(NewYork->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(NewYork->getWidth(),shipWidth);
    ASSERT_EQ(NewYork->getLength(),shipHeight);
    ASSERT_EQ(NewYork->getCol(),true);
    ASSERT_EQ(NewYork->getShipType(),ShipType::Battleship);
    ASSERT_EQ(NewYork->getModelType(),ModelType::NewYork);
    ASSERT_EQ(NewYork->getNumInterceptors(),0);
    
    
    shipWidth = 32;
    shipHeight = 185;
    numAntiAir = 4;

    std::unique_ptr<Battleship> Arizona(
            new Battleship(1000, 1000, 1, 39, 32429, 1536,
                           "Usa", 8, 4, 0, numAntiAir,  v, 185, 32, true,
                           ShipType::Battleship,
                           ModelType::Arizona, 0));    
    
    ASSERT_EQ(Arizona->getPos().x,1000);
    ASSERT_EQ(Arizona->getPos().y,1000);
    ASSERT_EQ(Arizona->getAcceleration(),1);
    ASSERT_EQ(Arizona->getMaxSpeed(),39);
    ASSERT_EQ(Arizona->getHp(),32429);
    ASSERT_EQ(Arizona->getArmour(),1536);
    ASSERT_EQ(Arizona->getNationality(),"Usa");
    ASSERT_EQ(Arizona->getNumLCannons(),8);
    ASSERT_EQ(Arizona->getNumHCannons(),4);
    ASSERT_EQ(Arizona->getNumMCannons(),0);
    ASSERT_EQ(Arizona->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(Arizona->getWidth(),shipWidth);
    ASSERT_EQ(Arizona->getLength(),shipHeight);
    ASSERT_EQ(Arizona->getCol(),true);
    ASSERT_EQ(Arizona->getShipType(),ShipType::Battleship);
    ASSERT_EQ(Arizona->getModelType(),ModelType::Arizona);
    ASSERT_EQ(Arizona->getNumInterceptors(),0);
    
    
    shipWidth = 34;
    shipHeight = 262;

    numAntiAir = 20;

    std::unique_ptr<Battleship> Hood(
            new Battleship(1000,1000, 1, 54, 49136, 800, "Uk", 0, 2, 2,numAntiAir,  v, shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::Hood, 0));
    
    ASSERT_EQ(Hood->getPos().x,1000);
    ASSERT_EQ(Hood->getPos().y,1000);
    ASSERT_EQ(Hood->getAcceleration(),1);
    ASSERT_EQ(Hood->getMaxSpeed(),54);
    ASSERT_EQ(Hood->getHp(),49136);
    ASSERT_EQ(Hood->getArmour(),800);
    ASSERT_EQ(Hood->getNationality(),"Uk");
    ASSERT_EQ(Hood->getNumLCannons(),0);
    ASSERT_EQ(Hood->getNumHCannons(),2);
    ASSERT_EQ(Hood->getNumMCannons(),2);
    ASSERT_EQ(Hood->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(Hood->getWidth(),shipWidth);
    ASSERT_EQ(Hood->getLength(),shipHeight);
    ASSERT_EQ(Hood->getCol(),true);
    ASSERT_EQ(Hood->getShipType(),ShipType::Battleship);
    ASSERT_EQ(Hood->getModelType(),ModelType::Hood);
    ASSERT_EQ(Hood->getNumInterceptors(),0);
    
    shipWidth = 35;
    shipHeight = 246;

    numAntiAir = 14;
    std::unique_ptr<Battleship> MichelangeloBuonarroti(
            new Battleship(1000,1000, 1, 61, 42533, 837, "Italy", 12, 3, 6, numAntiAir,  v,
                           shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::MichelangeloBuonarroti, 1));    
    
    
    
    ASSERT_EQ(MichelangeloBuonarroti->getPos().x,1000);
    ASSERT_EQ(MichelangeloBuonarroti->getPos().y,1000);
    ASSERT_EQ(MichelangeloBuonarroti->getAcceleration(),1);
    ASSERT_EQ(MichelangeloBuonarroti->getMaxSpeed(),61);
    ASSERT_EQ(MichelangeloBuonarroti->getHp(),42533);
    ASSERT_EQ(MichelangeloBuonarroti->getArmour(),837);
    ASSERT_EQ(MichelangeloBuonarroti->getNationality(),"Italy");
    ASSERT_EQ(MichelangeloBuonarroti->getNumLCannons(),12);
    ASSERT_EQ(MichelangeloBuonarroti->getNumHCannons(),3);
    ASSERT_EQ(MichelangeloBuonarroti->getNumMCannons(),6);
    ASSERT_EQ(MichelangeloBuonarroti->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(MichelangeloBuonarroti->getWidth(),shipWidth);
    ASSERT_EQ(MichelangeloBuonarroti->getLength(),shipHeight);
    ASSERT_EQ(MichelangeloBuonarroti->getCol(),true);
    ASSERT_EQ(MichelangeloBuonarroti->getShipType(),ShipType::Battleship);
    ASSERT_EQ(MichelangeloBuonarroti->getModelType(),ModelType::MichelangeloBuonarroti);
    ASSERT_EQ(MichelangeloBuonarroti->getNumInterceptors(),1);
    
    
    shipWidth = 29;
    shipHeight = 176;

    numAntiAir = 13;
    std::unique_ptr<Battleship> AndreaDoria(
            new Battleship(1000,1000, 1, 39, 24729, 622, "Italy", 10, 4, 4, numAntiAir,  v,
                           shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::AndreaDoria, 0));
    
    ASSERT_EQ(AndreaDoria->getPos().x,1000);
    ASSERT_EQ(AndreaDoria->getPos().y,1000);
    ASSERT_EQ(AndreaDoria->getAcceleration(),1);
    ASSERT_EQ(AndreaDoria->getMaxSpeed(),39);
    ASSERT_EQ(AndreaDoria->getHp(),24729);
    ASSERT_EQ(AndreaDoria->getArmour(),622);
    ASSERT_EQ(AndreaDoria->getNationality(),"Italy");
    ASSERT_EQ(AndreaDoria->getNumLCannons(),10);
    ASSERT_EQ(AndreaDoria->getNumHCannons(),4);
    ASSERT_EQ(AndreaDoria->getNumMCannons(),4);
    ASSERT_EQ(AndreaDoria->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(AndreaDoria->getWidth(),shipWidth);
    ASSERT_EQ(AndreaDoria->getLength(),shipHeight);
    ASSERT_EQ(AndreaDoria->getCol(),true);
    ASSERT_EQ(AndreaDoria->getShipType(),ShipType::Battleship);
    ASSERT_EQ(AndreaDoria->getModelType(),ModelType::AndreaDoria);
    ASSERT_EQ(AndreaDoria->getNumInterceptors(),0);
    
    
     numAntiAir = 40;
     shipWidth = 41;
     shipHeight = 263;


    std::unique_ptr<Battleship> Yamato(
            new Battleship(1000,1000, 1, 50, 71659, 1286, "Japan", 12, 3, 2, numAntiAir,  v,
                           shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::Yamato, 3));
    
    ASSERT_EQ(Yamato->getPos().x,1000);
    ASSERT_EQ(Yamato->getPos().y,1000);
    ASSERT_EQ(Yamato->getAcceleration(),1);
    ASSERT_EQ(Yamato->getMaxSpeed(),50);
    ASSERT_EQ(Yamato->getHp(),71659);
    ASSERT_EQ(Yamato->getArmour(),1286);
    ASSERT_EQ(Yamato->getNationality(),"Japan");
    ASSERT_EQ(Yamato->getNumLCannons(),12);
    ASSERT_EQ(Yamato->getNumHCannons(),3);
    ASSERT_EQ(Yamato->getNumMCannons(),2);
    ASSERT_EQ(Yamato->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(Yamato->getWidth(),shipWidth);
    ASSERT_EQ(Yamato->getLength(),shipHeight);
    ASSERT_EQ(Yamato->getCol(),true);
    ASSERT_EQ(Yamato->getShipType(),ShipType::Battleship);
    ASSERT_EQ(Yamato->getModelType(),ModelType::Yamato);
    ASSERT_EQ(Yamato->getNumInterceptors(),3);
    
    
    numAntiAir = 19;
    shipWidth = 43;
    shipHeight = 220;

 
    
    std::unique_ptr<Battleship> Ise(
            new Battleship(1000,1000, 1, 45, 40444, 705, "Japan", 8, 4, 0, numAntiAir,  v, shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::ISE, 2));
    
    ASSERT_EQ(Ise->getPos().x,1000);
    ASSERT_EQ(Ise->getPos().y,1000);
    ASSERT_EQ(Ise->getAcceleration(),1);
    ASSERT_EQ(Ise->getMaxSpeed(),45);
    ASSERT_EQ(Ise->getHp(),40444);
    ASSERT_EQ(Ise->getArmour(),705);
    ASSERT_EQ(Ise->getNationality(),"Japan");
    ASSERT_EQ(Ise->getNumLCannons(),8);
    ASSERT_EQ(Ise->getNumHCannons(),4);
    ASSERT_EQ(Ise->getNumMCannons(),0);
    ASSERT_EQ(Ise->getNumAntiAircraft(),numAntiAir);
    ASSERT_EQ(Ise->getWidth(),shipWidth);
    ASSERT_EQ(Ise->getLength(),shipHeight);
    ASSERT_EQ(Ise->getCol(),true);
    ASSERT_EQ(Ise->getShipType(),ShipType::Battleship);
    ASSERT_EQ(Ise->getModelType(),ModelType::ISE);
    ASSERT_EQ(Ise->getNumInterceptors(),2);
    
    


}
