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
    ASSERT_EQ(saintLouis->getNumHCannons(),0);
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

    shipWidth = 14;
    shipHeight = 136;
    antiAir = 7;

    std::unique_ptr<Cruiser> danae(new Cruiser(1000,1000, 3, 54, 5925, 190,
                                               "Uk", 6, 0, 1, antiAir,  v, shipHeight, shipWidth, true,
                                               ShipType::Cruiser,
                                               ModelType::Danae, 0));
    
    
    ASSERT_EQ(danae->getPos().x,1000);
    ASSERT_EQ(danae->getPos().y,1000);
    ASSERT_EQ(danae->getAcceleration(),3);
    ASSERT_EQ(danae->getMaxSpeed(),54);
    ASSERT_EQ(danae->getHp(),5925);
    ASSERT_EQ(danae->getArmour(),190);
    ASSERT_EQ(danae->getNationality(),"Uk");
    ASSERT_EQ(danae->getNumLCannons(),6);
    ASSERT_EQ(danae->getNumHCannons(),0);
    ASSERT_EQ(danae->getNumMCannons(),1);
    ASSERT_EQ(danae->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(danae->getWidth(),shipWidth);
    ASSERT_EQ(danae->getLength(),shipHeight);
    ASSERT_EQ(danae->getCol(),true);
    ASSERT_EQ(danae->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(danae->getModelType(),ModelType::Danae);
    ASSERT_EQ(danae->getNumPlanes(),0);
    
    shipWidth = 25;
    shipHeight = 197;
    antiAir = 12;


    std::unique_ptr<Cruiser> trento(new Cruiser(1000,1000, 3, 66, 13548, 120,
                                                "Italy", 6, 0, 4, antiAir,  v, shipHeight, shipWidth, true,
                                                ShipType::Cruiser,
                                                ModelType::Trento, 2));
    
    
    
    ASSERT_EQ(trento->getPos().x,1000);
    ASSERT_EQ(trento->getPos().y,1000);
    ASSERT_EQ(trento->getAcceleration(),3);
    ASSERT_EQ(trento->getMaxSpeed(),66);
    ASSERT_EQ(trento->getHp(),13548);
    ASSERT_EQ(trento->getArmour(),120);
    ASSERT_EQ(trento->getNationality(),"Italy");
    ASSERT_EQ(trento->getNumLCannons(),6);
    ASSERT_EQ(trento->getNumHCannons(),0);
    ASSERT_EQ(trento->getNumMCannons(),4);
    ASSERT_EQ(trento->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(trento->getWidth(),shipWidth);
    ASSERT_EQ(trento->getLength(),shipHeight);
    ASSERT_EQ(trento->getCol(),true);
    ASSERT_EQ(trento->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(trento->getModelType(),ModelType::Trento);
    ASSERT_EQ(trento->getNumPlanes(),2);
    
    
    shipWidth = 15;
    shipHeight = 169;



    antiAir = 12;




    std::unique_ptr<Cruiser> albertoDiGiussano(new Cruiser(1000,1000, 3, 69, 6950, 84,
                                                           "Italy", 3, 0, 4, antiAir,  v, shipHeight, shipWidth, true,
                                                           ShipType::Cruiser,
                                                           ModelType::AlbertoDiGiussano, 1));
    
    
    ASSERT_EQ(albertoDiGiussano->getPos().x,1000);
    ASSERT_EQ(albertoDiGiussano->getPos().y,1000);
    ASSERT_EQ(albertoDiGiussano->getAcceleration(),3);
    ASSERT_EQ(albertoDiGiussano->getMaxSpeed(),69);
    ASSERT_EQ(albertoDiGiussano->getHp(),6950);
    ASSERT_EQ(albertoDiGiussano->getArmour(),84);
    ASSERT_EQ(albertoDiGiussano->getNationality(),"Italy");
    ASSERT_EQ(albertoDiGiussano->getNumLCannons(),3);
    ASSERT_EQ(albertoDiGiussano->getNumHCannons(),0);
    ASSERT_EQ(albertoDiGiussano->getNumMCannons(),4);
    ASSERT_EQ(albertoDiGiussano->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(albertoDiGiussano->getWidth(),shipWidth);
    ASSERT_EQ(albertoDiGiussano->getLength(),shipHeight);
    ASSERT_EQ(albertoDiGiussano->getCol(),true);
    ASSERT_EQ(albertoDiGiussano->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(albertoDiGiussano->getModelType(),ModelType::AlbertoDiGiussano);
    ASSERT_EQ(albertoDiGiussano->getNumPlanes(),1);
    
    
    
   
    shipWidth = 25;
    shipHeight = 193;

    
    
    antiAir = 16;

    std::unique_ptr<Cruiser> takao(new Cruiser(1000,1000, 3, 66, 15500, 237,
                                               "Japan", 4, 0, 5, antiAir,  v, shipHeight, shipWidth, true,
                                               ShipType::Cruiser,
                                               ModelType::Takao, 2));
    
    
    
    ASSERT_EQ(takao->getPos().x,1000);
    ASSERT_EQ(takao->getPos().y,1000);
    ASSERT_EQ(takao->getAcceleration(),3);
    ASSERT_EQ(takao->getMaxSpeed(),66);
    ASSERT_EQ(takao->getHp(),15500);
    ASSERT_EQ(takao->getArmour(),237);
    ASSERT_EQ(takao->getNationality(),"Japan");
    ASSERT_EQ(takao->getNumLCannons(),4);
    ASSERT_EQ(takao->getNumHCannons(),0);
    ASSERT_EQ(takao->getNumMCannons(),5);
    ASSERT_EQ(takao->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(takao->getWidth(),shipWidth);
    ASSERT_EQ(takao->getLength(),shipHeight);
    ASSERT_EQ(takao->getCol(),true);
    ASSERT_EQ(takao->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(takao->getModelType(),ModelType::Takao);
    ASSERT_EQ(takao->getNumPlanes(),2);
    
    shipWidth = 25;
    shipHeight = 178;

    
    antiAir = 12;

    std::unique_ptr<Cruiser> NewOrleans(
            new Cruiser(1000,1000, 3, 61, 12663, 476, "Usa", 6, 0, 3, antiAir,  v, shipHeight,
                        shipWidth,
                        true,
                        ShipType::Cruiser, ModelType::NewOrleans, 0));
    
    
    
    
    
    ASSERT_EQ(NewOrleans->getPos().x,1000);
    ASSERT_EQ(NewOrleans->getPos().y,1000);
    ASSERT_EQ(NewOrleans->getAcceleration(),3);
    ASSERT_EQ(NewOrleans->getMaxSpeed(),61);
    ASSERT_EQ(NewOrleans->getHp(),12663);
    ASSERT_EQ(NewOrleans->getArmour(),476);
    ASSERT_EQ(NewOrleans->getNationality(),"Usa");
    ASSERT_EQ(NewOrleans->getNumLCannons(),6);
    ASSERT_EQ(NewOrleans->getNumHCannons(),0);
    ASSERT_EQ(NewOrleans->getNumMCannons(),3);
    ASSERT_EQ(NewOrleans->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(NewOrleans->getWidth(),shipWidth);
    ASSERT_EQ(NewOrleans->getLength(),shipHeight);
    ASSERT_EQ(NewOrleans->getCol(),true);
    ASSERT_EQ(NewOrleans->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(NewOrleans->getModelType(),ModelType::NewOrleans);
    ASSERT_EQ(NewOrleans->getNumPlanes(),0);


    shipWidth = 19;

    shipHeight = 169;

    antiAir = 7;

    std::unique_ptr<Cruiser> Tiger59(
            new Cruiser(1000, 1000, 3, 58, 12080, 191, "Uk", 6, 0, 4, antiAir,  v, shipHeight,
                        shipWidth,
                        true,
                        ShipType::Cruiser, ModelType::Tiger59, 2));
    
    
    
    
    
    ASSERT_EQ(Tiger59->getPos().x,1000);
    ASSERT_EQ(Tiger59->getPos().y,1000);
    ASSERT_EQ(Tiger59->getAcceleration(),3);
    ASSERT_EQ(Tiger59->getMaxSpeed(),58);
    ASSERT_EQ(Tiger59->getHp(),12080);
    ASSERT_EQ(Tiger59->getArmour(),191);
    ASSERT_EQ(Tiger59->getNationality(),"Uk");
    ASSERT_EQ(Tiger59->getNumLCannons(),5);
    ASSERT_EQ(Tiger59->getNumHCannons(),4);
    ASSERT_EQ(Tiger59->getNumMCannons(),3);
    ASSERT_EQ(Tiger59->getNumAntiAircraft(),antiAir);
    ASSERT_EQ(Tiger59->getWidth(),shipWidth);
    ASSERT_EQ(Tiger59->getLength(),shipHeight);
    ASSERT_EQ(Tiger59->getCol(),true);
    ASSERT_EQ(Tiger59->getShipType(),ShipType::Cruiser);
    ASSERT_EQ(Tiger59->getModelType(),ModelType::Tiger59);
    ASSERT_EQ(Tiger59->getNumPlanes(),0);
    
    
    
    
    
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

*/