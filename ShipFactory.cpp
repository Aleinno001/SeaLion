//
// Created by alessandro on 7/2/21.
//

#include "ShipFactory.h"

std::shared_ptr<WarShip> ShipFactory::createSubmarine(ModelType type,int height, int width) {
    sf::Vector2i coordinates = randomizeEnemyPositions(height,width);
    coordinates.y = coordinates.y - (0.14 * height);
    switch (type) {
        case ModelType::I400: {
            std::shared_ptr<WarShip> i400 = i400Builder(coordinates);
            repositionEnemyShip(i400);
            return i400;
        }
        case ModelType::typeb1: {
            std::shared_ptr<WarShip> typeb1 = typeb1Builder(coordinates);
            repositionEnemyShip(typeb1);
            return typeb1;
        }
        case ModelType::DaVinci: {
            std::shared_ptr<WarShip> daVinci = DaVinciBuilder(coordinates);
            repositionEnemyShip(daVinci);
            return daVinci;
        }
        case ModelType::Papa: {
            std::shared_ptr<WarShip> papa = papaBuilder(coordinates);
            repositionEnemyShip(papa);
            return papa;
        }
        case ModelType::Triton: {
            std::shared_ptr<WarShip> triton = tritonBuilder(coordinates);
            repositionEnemyShip(triton);
            return triton;
        }
        case ModelType::Trenchant: {
            std::shared_ptr<WarShip> trenchant = trenchantBuilder(coordinates);
            repositionEnemyShip(trenchant);
            return trenchant;
        }
        case ModelType::Gato: {
            std::shared_ptr<WarShip> gato = gatoBuilder(coordinates);
            repositionEnemyShip(gato);
            return gato;
        }
        case ModelType::Narwhal: {
            std::shared_ptr<WarShip> narwhal = narwhalBuilder(coordinates);
            repositionEnemyShip(narwhal);
            return narwhal;
        }
    }
}
std::shared_ptr<WarShip>
ShipFactory::gatoBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 9;
    int shipHeight = 95;
    std::shared_ptr<WarShip> Gato(new Submarine(coordinates.x, coordinates.y, 2, 37, 2460,shipHeight,shipWidth,true,"Usa",ShipType::Submarine,ModelType::Gato,0,"Gato",0,0,0,0));
    /*for (int i = 0; i < 6; i++)
        Gato->attach(factory.createSpecialWeapon(WeaponType::torpedo, *Gato));
    */
    std::shared_ptr<LifeBar> life(new LifeBar(*Gato));
    Gato->attachBar(life);
    return Gato;
}

std::shared_ptr<WarShip>
ShipFactory::tritonBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 8;
    int shipHeight = 84;
    std::shared_ptr<WarShip> Triton(new Submarine(coordinates.x, coordinates.y, 2, 28, 1576,shipHeight,shipWidth,true,"Uk",ShipType::Submarine,ModelType::Triton,0,"Triton",0,0,0,0));
    /*for (int i = 0; i < 6; i++)
        Triton->attach(factory.createSpecialWeapon(WeaponType::torpedo, *Triton));
    */
     std::shared_ptr<LifeBar> life(new LifeBar(*Triton));
    Triton->attachBar(life);
    return Triton;
}
std::shared_ptr<WarShip>
ShipFactory::DaVinciBuilder(
        sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 9;
    int shipHeight = 77;
    std::shared_ptr<WarShip> DaVinci(new Submarine(coordinates.x, coordinates.y, 2, 15, 1489,shipHeight,shipWidth,true,"Italy",ShipType::Submarine,ModelType::DaVinci,0,"DaVinci",0,0,0,0));
    /*for (int i = 0; i < 8; i++)
        DaVinci->attach(factory.createSpecialWeapon(WeaponType::torpedo, *DaVinci));
    */
    std::shared_ptr<LifeBar> life(new LifeBar(*DaVinci));
    DaVinci->attachBar(life);
    return DaVinci;
}
std::shared_ptr<WarShip>
ShipFactory::typeb1Builder(
        sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 10;
    int shipHeight = 111;
    std::shared_ptr<WarShip> typeb1(new Submarine(coordinates.x, coordinates.y, 2, 44, 3713,shipHeight,shipWidth,true,"Japan",ShipType::Submarine,ModelType::typeb1,0,"Type-B-1",0,0,0,0));
    /*for (int i = 0; i < 6; i++)
        typeb1->attach(factory.createSpecialWeapon(WeaponType::torpedo, *typeb1));
    */
     std::shared_ptr<LifeBar> life(new LifeBar(*typeb1));
    typeb1->attachBar(life);
    return typeb1;
}
std::shared_ptr<WarShip>
ShipFactory::i400Builder(
        sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 13;
    int shipHeight = 122;
    std::shared_ptr<WarShip> i400(new Submarine(coordinates.x, coordinates.y, 2, 35, 6670,shipHeight,shipWidth,true,"Japan",ShipType::Submarine,ModelType::I400,0,"I400",0,0,0,0));
    //for (int i = 0; i < 8; i++)
      //  i400->attach(factory.createSpecialWeapon(WeaponType::torpedo, *i400));
    std::shared_ptr<LifeBar> life(new LifeBar(*i400));
    i400->attachBar(life);
    return i400;
}
std::shared_ptr<WarShip> ShipFactory::createAircraftCarrier(ModelType type,int height, int width) {
    sf::Vector2i coordinates = randomizeEnemyPositions(height,width);
    coordinates.y = coordinates.y - (0.14 * height);
    switch (type) {
        case ModelType::Tahio: {
            std::shared_ptr<WarShip> tahio = tahioBuilder(coordinates);
            repositionEnemyShip(tahio);
            return tahio;
        }
        case ModelType::Hiryu: {
            std::shared_ptr<WarShip> hiryu = hiryuBuilder(coordinates);
            repositionEnemyShip(hiryu);
            return hiryu;
        }
        case ModelType::GiuseppeGaribaldi: {
            std::shared_ptr<WarShip> giuseppeGaribaldi = giuseppeGaribaldiBuilder(coordinates);
            repositionEnemyShip(giuseppeGaribaldi);
            return giuseppeGaribaldi;
        }
        case ModelType::Cavour: {
            std::shared_ptr<WarShip> cavour = cavourBuilder(coordinates);
            repositionEnemyShip(cavour);
            return cavour;
        }
        case ModelType::ArkRoyal: {
            std::shared_ptr<WarShip> arkRoyal = arkRoyalBuilder(coordinates);
            repositionEnemyShip(arkRoyal);
            return arkRoyal;
        }
        case ModelType::Indomitable: {

            std::shared_ptr<WarShip> indomitable = indomitableBuilder(coordinates);
            repositionEnemyShip(indomitable);
            return indomitable;
        }
        case ModelType::Midway: {
            std::shared_ptr<WarShip> midway = midwayBuilder(coordinates);
            repositionEnemyShip(midway);
            return midway;
        }
        case ModelType::FranklinDRoosevelt: {
            std::shared_ptr<WarShip> franklinDRoosevelt = franklinDelanoRoosveltBuilder(coordinates);
            repositionEnemyShip(franklinDRoosevelt);
            return franklinDRoosevelt;
        }
    }
}
std::shared_ptr<WarShip>
ShipFactory::midwayBuilder(
        sf::Vector2i &coordinates){
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 84;
    int shipHeight = 296;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    WeaponFactory specialFactory;
    int numAntiAir = 15;
    std::shared_ptr<WarShip> mid (new ConcreteAircraftCarrier(coordinates.x, coordinates.y, 1, 61, 64000, shipHeight, shipWidth, true,  "Usa", ShipType::AircraftCarrier, ModelType::Midway, 520, "Midway", 2, 0, 0, numAntiAir, 13));
    mid->attach(factory.createMedium(cannonPosX + 72, cannonPosY + 187, *mid));
    mid->attach(factory.createMedium(cannonPosX + 14, cannonPosY + 230, *mid));
    mid->attach(factory.createMedium(cannonPosX + 69, cannonPosY + 100, *mid));
    AircraftCarrier * dynamic = dynamic_cast<AircraftCarrier *>(mid.get());
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+44,cannonPosY+10, "Usa", *mid));
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+44,cannonPosY+30,"Usa",*mid));
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+44,cannonPosY+50,"Usa",*mid));
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+44,cannonPosY+70,"Usa",*mid));
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+44,cannonPosY+90,"Usa",*mid));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+44,cannonPosY+117,"Usa",*mid));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+44,cannonPosY+137,"Usa",*mid));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+44,cannonPosY+157,"Usa",*mid));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+44,cannonPosY+177,"Usa",*mid));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+44,cannonPosY+197,"Usa",*mid));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+44,cannonPosY+217,"Usa",*mid));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+44,cannonPosY+237,"Usa",*mid));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+44,cannonPosY+257,"Usa",*mid));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+44,cannonPosY+278,"Usa",*mid));
    /*for (int i = 0; i < numAntiAir; i++)
        mid->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir,*mid));
    */
     std::shared_ptr<LifeBar> life(new LifeBar(*mid));
    mid->attachBar(life);
    return mid;
}
std::shared_ptr<WarShip>
ShipFactory::arkRoyalBuilder(
        sf::Vector2i &coordinates){
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 38;
    int shipHeight = 240;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    WeaponFactory specialFactory;
    int numAntiAir = 4;
    std::shared_ptr<WarShip> arkRoyal (new ConcreteAircraftCarrier(coordinates.x, coordinates.y, 1, 56, 28160, shipHeight, shipWidth, true,  "Uk", ShipType::AircraftCarrier, ModelType::ArkRoyal, 20, "ArkRoyal", 2, 0, 0, numAntiAir, 7));
    arkRoyal->attach(factory.createLight(cannonPosX + 7, cannonPosY + 85, *arkRoyal));
    arkRoyal->attach(factory.createLight(cannonPosX + 28, cannonPosY + 85, *arkRoyal));
    AircraftCarrier * dynamic = dynamic_cast<AircraftCarrier *>(arkRoyal.get());
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+19,cannonPosY+15,"Uk",*arkRoyal));
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+19,cannonPosY+40,"Uk",*arkRoyal));
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+19,cannonPosY+65,"Uk",*arkRoyal));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+19,cannonPosY+94,"Uk",*arkRoyal));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+19,cannonPosY+130,"Uk",*arkRoyal));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+19,cannonPosY+166,"Uk",*arkRoyal));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+19,cannonPosY+206,"Uk",*arkRoyal));
    /*for (int i = 0; i < numAntiAir; i++)
        arkRoyal->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir, *arkRoyal));
    */std::shared_ptr<LifeBar> life(new LifeBar(*arkRoyal));
    arkRoyal->attachBar(life);
    return arkRoyal;
}
std::shared_ptr<WarShip> ShipFactory::giuseppeGaribaldiBuilder(sf::Vector2i &coordinates){
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 44;
    int shipHeight = 180;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    std::shared_ptr<WarShip> GiuseppeGaribaldi (new ConcreteAircraftCarrier(coordinates.x, coordinates.y, 1, 56, 14150, shipHeight, shipWidth, true,  "Italy", ShipType::AircraftCarrier, ModelType::GiuseppeGaribaldi, 114, "GiuseppeGaribaldi", 3, 0, 0, 0, 6));
    GiuseppeGaribaldi->attach(factory.createLight(cannonPosX + 4, cannonPosY + 41, *GiuseppeGaribaldi));
    GiuseppeGaribaldi->attach(factory.createLight(cannonPosX + 4, cannonPosY + 69, *GiuseppeGaribaldi));
    GiuseppeGaribaldi->attach(factory.createLight(cannonPosX + 4, cannonPosY + 98, *GiuseppeGaribaldi));
    AircraftCarrier * dynamic = dynamic_cast<AircraftCarrier *>(GiuseppeGaribaldi.get());
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+15,cannonPosY+14,"Italy",*GiuseppeGaribaldi));
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+15,cannonPosY+40,"Italy",*GiuseppeGaribaldi));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+15,cannonPosY+65,"Italy",*GiuseppeGaribaldi));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+15,cannonPosY+94,"Italy",*GiuseppeGaribaldi));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+15,cannonPosY+130,"Italy",*GiuseppeGaribaldi));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+15,cannonPosY+166,"Italy",*GiuseppeGaribaldi));
    std::shared_ptr<LifeBar> life(new LifeBar(*GiuseppeGaribaldi));
    GiuseppeGaribaldi->attachBar(life);
    return GiuseppeGaribaldi;
}
std::shared_ptr<WarShip>
ShipFactory::tahioBuilder(
        sf::Vector2i &coordinates){
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 46;
    int shipHeight = 260;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    WeaponFactory specialFactory;
    int numAntiAir = 20;
    std::shared_ptr<WarShip> Tahio (new ConcreteAircraftCarrier(coordinates.x, coordinates.y, 1, 61, 37866, shipHeight, shipWidth, true,  "Japan", ShipType::AircraftCarrier, ModelType::Tahio, 304, "Tahio", 2, 0, 0, numAntiAir, 7));
    Tahio->attach(factory.createLight(cannonPosX + 20, cannonPosY + 55, *Tahio));
    Tahio->attach(factory.createLight(cannonPosX + 20, cannonPosY + 218, *Tahio));
    AircraftCarrier * dynamic = dynamic_cast<AircraftCarrier *>(Tahio.get());
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+22,cannonPosY+14,"Japan",*Tahio));
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+22,cannonPosY+40,"Japan",*Tahio));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+22,cannonPosY+65,"Japan",*Tahio));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+22,cannonPosY+94,"Japan",*Tahio));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+22,cannonPosY+130,"Japan",*Tahio));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+22,cannonPosY+166,"Japan",*Tahio));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+22,cannonPosY+206,"Japan",*Tahio));
    /*for (int i = 0; i < numAntiAir; i++)
        Tahio->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir, *Tahio));
    */std::shared_ptr<LifeBar> life(new LifeBar(*Tahio));
    Tahio->attachBar(life);
    return Tahio;
}
std::shared_ptr<WarShip> ShipFactory::createCruiser(ModelType type,int height, int width) {
    std::list<std::shared_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(height,width);
    coordinates.y = coordinates.y - (0.14 * height);
    switch (type) {
        case ModelType::Takao: {
            std::shared_ptr<WarShip> takao = takaoBuilder(coordinates);
            repositionEnemyShip(takao);
            return takao;
        }
        case ModelType::IsuzuNagara: {
            std::shared_ptr<WarShip> isuzuNagara = isuzuNagaraBuilder(coordinates);
            repositionEnemyShip(isuzuNagara);
            return isuzuNagara;
        }
        case ModelType::Ijn: {
            std::shared_ptr<WarShip> ijn = ijnBuilder(coordinates);
            repositionEnemyShip(ijn);
            return ijn;
        }
        case ModelType::AlbertoDiGiussano: {
            std::shared_ptr<WarShip> albertoDiGiussano = albertoDiGiussanoBuilder(coordinates);
            repositionEnemyShip(albertoDiGiussano);
            return albertoDiGiussano;
        }
        case ModelType::Gorizia: {
            std::shared_ptr<WarShip> gorizia = goriziaBuilder(coordinates);
            repositionEnemyShip(gorizia);
            return gorizia;
        }
        case ModelType::Trento: {
            std::shared_ptr<WarShip> trento = trentoBuilder(coordinates);
            repositionEnemyShip(trento);
            return trento;
        }
        case ModelType::Belfast: {
            std::shared_ptr<WarShip> belfast = belfastBuilder(coordinates);
            repositionEnemyShip(belfast);
            return belfast;
        }
        case ModelType::Danae: {
            std::shared_ptr<WarShip> danae = danaeBuilder(coordinates);
            repositionEnemyShip(danae);
            return danae;
        }
        case ModelType::Tiger59: {
            std::shared_ptr<WarShip> tiger59 = tiger59Builder(coordinates);
            repositionEnemyShip(tiger59);
            return tiger59;
        }
        case ModelType::Alaska: {
            std::shared_ptr<WarShip> alaska = alaskaBuilder(coordinates);
            repositionEnemyShip(alaska);
            return alaska;
        }
        case ModelType::NewOrleans: {
            std::shared_ptr<WarShip> newOrleans = newOrleansBuilder(coordinates);
            repositionEnemyShip(newOrleans);
            return newOrleans;
        }
        case ModelType::StLouis: {
            std::shared_ptr<WarShip> saintLouis = stLouisBuilder(coordinates);
            repositionEnemyShip(saintLouis);
            return saintLouis;
        }
    }
}
std::shared_ptr<WarShip>ShipFactory::stLouisBuilder(sf::Vector2i &coordinates){
    int shipWidth = 20;
    int shipHeight = 130;
    int cannonPosX =coordinates.x -(shipWidth) /2;
    int cannonPosY = coordinates.y -(shipHeight) /2;
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 8;
    std::shared_ptr<WarShip> saintLouis (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 41, 11013, shipHeight, shipWidth, true,  "Usa", ShipType::Cruiser, ModelType::StLouis, 280, "StLouis", 5, 3, 0, antiAir));
    saintLouis->attach(cf.createMedium(cannonPosX +7,cannonPosY +21, *saintLouis));
    saintLouis->attach(cf.createMedium(cannonPosX +7,cannonPosY +34, *saintLouis));
    saintLouis->attach(cf.createMedium(cannonPosX +7,cannonPosY +111, *saintLouis));
    saintLouis->attach(cf.createLight(cannonPosX +1,cannonPosY +71, *saintLouis));
    saintLouis->attach(cf.createLight(cannonPosX +15,cannonPosY +71, *saintLouis));
    saintLouis->attach(cf.createLight(cannonPosX +8,cannonPosY +80, *saintLouis));
    saintLouis->attach(cf.createLight(cannonPosX +2,cannonPosY +41, *saintLouis));
    saintLouis->attach(cf.createLight(cannonPosX +16,cannonPosY +41, *saintLouis));
    /*for (int i = 0;i < antiAir; i++)
        saintLouis->attach(factory.createSpecialWeapon(WeaponType::antiAir, *saintLouis));
    */std::shared_ptr<LifeBar> life(new LifeBar(*saintLouis));
    saintLouis->attachBar(life);
    return saintLouis;
}
std::shared_ptr<WarShip>
ShipFactory::alaskaBuilder(
        sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 28;
    int shipHeight = 246;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    CannonFactory cf;
    int antiAir = 9;
    std::shared_ptr<WarShip> alaska (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 61, 34803, shipHeight, shipWidth, true,  "Usa", ShipType::Cruiser, ModelType::Alaska, 918, "Alaska", 6, 2, 1, antiAir));
    alaska->attach(cf.createHeavly(cannonPosX + 6, cannonPosY + 179, *alaska));
    alaska->attach(cf.createMedium(cannonPosX + 11, cannonPosY + 60, *alaska));
    alaska->attach(cf.createMedium(cannonPosX + 11, cannonPosY + 77, *alaska));
    alaska->attach(cf.createLight(cannonPosX + 11, cannonPosY + 91, *alaska));
    alaska->attach(cf.createLight(cannonPosX + 1, cannonPosY + 105, *alaska));
    alaska->attach(cf.createLight(cannonPosX + 23, cannonPosY + 105, *alaska));
    alaska->attach(cf.createLight(cannonPosX + 1, cannonPosY + 149, *alaska));
    alaska->attach(cf.createLight(cannonPosX + 23, cannonPosY + 150, *alaska));
    alaska->attach(cf.createLight(cannonPosX + 11, cannonPosY + 172, *alaska));
    /*for (int i = 0; i < antiAir; i++)
        alaska->attach(factory.createSpecialWeapon(WeaponType::antiAir, *alaska));
    */std::shared_ptr<LifeBar> life(new LifeBar(*alaska));
    alaska->attachBar(life);
    return alaska;
}
std::shared_ptr<WarShip>
ShipFactory::danaeBuilder(
        sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 14;
    int shipHeight = 136;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    CannonFactory cf;
    int antiAir = 7;
    std::shared_ptr<WarShip> danae (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 54, 5925, shipHeight, shipWidth, true,  "Uk", ShipType::Cruiser, ModelType::Danae, 190, "Danae", 6, 1, 0, antiAir));
    danae->attach(cf.createMedium(cannonPosX + 4, cannonPosY + 111, *danae));
    danae->attach(cf.createLight(cannonPosX + 5, cannonPosY + 102, *danae));
    danae->attach(cf.createLight(cannonPosX + 5, cannonPosY + 120, *danae));
    danae->attach(cf.createLight(cannonPosX + 5, cannonPosY + 74, *danae));
    danae->attach(cf.createLight(cannonPosX + 5, cannonPosY + 45, *danae));
    danae->attach(cf.createLight(cannonPosX + 5, cannonPosY + 33, *danae));
    danae->attach(cf.createLight(cannonPosX + 5, cannonPosY + 19, *danae));
    /*for (int i = 0; i < antiAir; i++)
        danae->attach(factory.createSpecialWeapon(WeaponType::antiAir, *danae));
    */std::shared_ptr<LifeBar> life(new LifeBar(*danae));
    danae->attachBar(life);
    return danae;
}
std::shared_ptr<WarShip>
ShipFactory::trentoBuilder(
        sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 25;
    int shipHeight = 197;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    CannonFactory cf;
    int antiAir = 12;
    std::shared_ptr<WarShip> trento (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 66, 13548, shipHeight, shipWidth, true,  "Italy", ShipType::Cruiser, ModelType::Trento, 120, "Trento", 6, 4, 0, antiAir));
    trento->attach(cf.createMedium(cannonPosX + 9, cannonPosY + 44, *trento));
    trento->attach(cf.createMedium(cannonPosX + 9, cannonPosY + 52, *trento));
    trento->attach(cf.createMedium(cannonPosX + 9, cannonPosY + 143, *trento));
    trento->attach(cf.createMedium(cannonPosX + 9, cannonPosY + 153, *trento));
    trento->attach(cf.createLight(cannonPosX + 5, cannonPosY + 68, *trento));
    trento->attach(cf.createLight(cannonPosX + 15, cannonPosY + 68, *trento));
    trento->attach(cf.createLight(cannonPosX + 3, cannonPosY + 84, *trento));
    trento->attach(cf.createLight(cannonPosX + 18, cannonPosY + 84, *trento));
    trento->attach(cf.createLight(cannonPosX + 3, cannonPosY + 111, *trento));
    trento->attach(cf.createLight(cannonPosX + 18, cannonPosY + 111, *trento));
    /*for (int i = 0; i < antiAir; i++)
        trento->attach(factory.createSpecialWeapon(WeaponType::antiAir, *trento));
*/
    std::shared_ptr<LifeBar> life(new LifeBar(*trento));
    trento->attachBar(life);
    return trento;
}
std::shared_ptr<WarShip> ShipFactory::albertoDiGiussanoBuilder(
        sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 15;
    int shipHeight = 169;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    CannonFactory cf;
    int antiAir = 12;
    std::shared_ptr<WarShip> albertoDiGiussano (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 69, 6950, shipHeight, shipWidth, true,  "Italy", ShipType::Cruiser, ModelType::AlbertoDiGiussano, 84, "AlbertoDiGiussano", 3, 4, 0, antiAir));
    albertoDiGiussano->attach(cf.createMedium(cannonPosX + 4, cannonPosY + 18, *albertoDiGiussano));
    albertoDiGiussano->attach(cf.createMedium(cannonPosX + 4, cannonPosY + 28, *albertoDiGiussano));
    albertoDiGiussano->attach(cf.createMedium(cannonPosX + 5, cannonPosY + 121, *albertoDiGiussano));
    albertoDiGiussano->attach(cf.createMedium(cannonPosX + 5, cannonPosY + 135, *albertoDiGiussano));
    albertoDiGiussano->attach(cf.createLight(cannonPosX, cannonPosY + 93, *albertoDiGiussano));
    albertoDiGiussano->attach(cf.createLight(cannonPosX + 10, cannonPosY + 93, *albertoDiGiussano));
    albertoDiGiussano->attach(cf.createLight(cannonPosX + 6, cannonPosY + 112, *albertoDiGiussano));
    /*for (int i = 0; i < antiAir; i++)
        albertoDiGiussano->attach(factory.createSpecialWeapon(WeaponType::antiAir, *albertoDiGiussano));
    */std::shared_ptr<LifeBar> life(new LifeBar(*albertoDiGiussano));
    albertoDiGiussano->attachBar(life);
    return albertoDiGiussano;
}
std::shared_ptr<WarShip>
ShipFactory::takaoBuilder(
        sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 25;
    int shipHeight = 193;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    CannonFactory cf;
    int antiAir = 16;
    std::shared_ptr<WarShip> takao (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 66, 15500, shipHeight, shipWidth, true,  "Japan", ShipType::Cruiser, ModelType::Takao, 237, "Takao", 4, 5, 0, antiAir));
    takao->attach(cf.createMedium(cannonPosX + 9, cannonPosY + 36, *takao));
    takao->attach(cf.createMedium(cannonPosX + 9, cannonPosY + 44, *takao));
    takao->attach(cf.createMedium(cannonPosX + 9, cannonPosY + 53, *takao));
    takao->attach(cf.createMedium(cannonPosX + 9, cannonPosY + 137, *takao));
    takao->attach(cf.createMedium(cannonPosX + 9, cannonPosY + 145, *takao));
    takao->attach(cf.createLight(cannonPosX + 3, cannonPosY + 82, *takao));
    takao->attach(cf.createLight(cannonPosX + 18, cannonPosY + 82, *takao));
    takao->attach(cf.createLight(cannonPosX + 3, cannonPosY + 96, *takao));
    takao->attach(cf.createLight(cannonPosX + 18, cannonPosY + 96, *takao));
    /*for (int i = 0; i < antiAir; i++)
        takao->attach(factory.createSpecialWeapon(WeaponType::antiAir, *takao));
    */std::shared_ptr<LifeBar> life(new LifeBar(*takao));
    takao->attachBar(life);
    return takao;
}
std::shared_ptr<WarShip> ShipFactory::createBattleship(ModelType type,int height, int width) {
    std::list<std::shared_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(height,width);
    coordinates.y = coordinates.y - (0.14 * height);
    switch (type) {
        case ModelType::Yamato: {
            std::shared_ptr<WarShip> yamato = yamatoBuilder(coordinates);
            repositionEnemyShip(yamato);
            return yamato;
        }
        case ModelType::Kongo: {
            std::shared_ptr<WarShip> kongo = kongoBuilder(coordinates);
            repositionEnemyShip(kongo);
            return kongo;
        }
        case ModelType::ISE: {
            std::shared_ptr<WarShip> ise = iseBuilder(coordinates);
            repositionEnemyShip(ise);
            return ise;
        }
        case ModelType::Musashi: {
            std::shared_ptr<WarShip> musashi = musashiBuilder(coordinates);
            repositionEnemyShip(musashi);
            return musashi;
        }
        case ModelType::AndreaDoria: {
            std::shared_ptr<WarShip> andreaDoria = andreaDoriaBuilder(coordinates);
            repositionEnemyShip(andreaDoria);
            return andreaDoria;
        }
        case ModelType::ImperatoreAugusto: {
            std::shared_ptr<WarShip> imperatoreAugusto = imperatoreAugustoBuilder(coordinates);
            repositionEnemyShip(imperatoreAugusto);
            return imperatoreAugusto;
        }
        case ModelType::VittorioVeneto: {
            std::shared_ptr<WarShip> vittorioVeneto = vittorioVenetoBuilder(coordinates);
            repositionEnemyShip(vittorioVeneto);
            return vittorioVeneto;
        }
        case ModelType::MichelangeloBuonarroti: {
            std::shared_ptr<WarShip> michelangeloBuonarroti = michelangeloBuonarrotiBuilder(coordinates);
            repositionEnemyShip(michelangeloBuonarroti);
            return michelangeloBuonarroti;
        }
        case ModelType::Dreadnought: {
            std::shared_ptr<WarShip> dreadNought = dreadNoughtBuilder(coordinates);
            repositionEnemyShip(dreadNought);
            return dreadNought;
        }
        case ModelType::IronDuke: {
            std::shared_ptr<WarShip> ironDuke = ironDukeBuilder(coordinates);
            repositionEnemyShip(ironDuke);
            return ironDuke;
        }
        case ModelType::Lion: {
            std::shared_ptr<WarShip> lion = lionBuilder(coordinates);
            repositionEnemyShip(lion);
            return lion;
        }
        case ModelType::Hood: {
            std::shared_ptr<WarShip> hood = hoodBuilder(coordinates);
            repositionEnemyShip(hood);
            return hood;
        }
        case ModelType::Arizona: {
            std::shared_ptr<WarShip> arizona = arizonaBuilder(coordinates);
            repositionEnemyShip(arizona);
            return arizona;
        }
        case ModelType::Montana: {
            std::shared_ptr<WarShip> montana = montanaBuilder(coordinates);
            repositionEnemyShip(montana);
            return montana;
        }
        case ModelType::NewYork: {
            std::shared_ptr<WarShip> newYork = newYorkBuilder(coordinates);
            repositionEnemyShip(newYork);
            return newYork;
        }
        case ModelType::NorthCarolina: {
            std::shared_ptr<WarShip> northCarolina = northCarolinaBuilder(coordinates);
            repositionEnemyShip(northCarolina);
            return northCarolina;
        }
    }
    return std::shared_ptr<WarShip>(); //TODO implementare tutti i costruttori
}
std::shared_ptr<WarShip>
ShipFactory::ironDukeBuilder(
        sf::Vector2i &coordinates){
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 190;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 15;
    std::shared_ptr<WarShip> ironDuke (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 39, 29500, shipHeight, shipWidth, true,  "Uk", ShipType::Battleship, ModelType::IronDuke, 826, "IronDuke", 0, 0, 5, numAntiAir));
    ironDuke->attach(factory.createHeavly(cannonPosX + 12, cannonPosY + 35, *ironDuke));
    ironDuke->attach(factory.createHeavly(cannonPosX + 12, cannonPosY + 49, *ironDuke));
    ironDuke->attach(factory.createHeavly(cannonPosX + 12, cannonPosY + 101, *ironDuke));
    ironDuke->attach(factory.createHeavly(cannonPosX + 12, cannonPosY + 127, *ironDuke));
    ironDuke->attach(factory.createHeavly(cannonPosX + 12, cannonPosY + 135, *ironDuke));
    WeaponFactory specialFactory;
    /*for (int i = 0; i < numAntiAir; i++)
        ironDuke->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir, *ironDuke));
    */std::shared_ptr<LifeBar> life(new LifeBar(*ironDuke));
    ironDuke->attachBar(life);
    return ironDuke;
}
std::shared_ptr<WarShip>
ShipFactory::northCarolinaBuilder(
        sf::Vector2i &coordinates){
    CannonFactory factory;
    int shipWidth = 32;
    int shipHeight = 222;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 34;
    std::shared_ptr<WarShip> northCarolina (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 52, 45500, shipHeight, shipWidth, true,  "Usa", ShipType::Battleship, ModelType::NorthCarolina, 1224, "NorthCarolina", 6, 0, 2, numAntiAir));
    northCarolina->attach(factory.createHeavly(cannonPosX + 8, cannonPosY + 50, *northCarolina));
    northCarolina->attach(factory.createHeavly(cannonPosX + 8, cannonPosY + 139, *northCarolina));
    northCarolina->attach(factory.createHeavly(cannonPosX + 8, cannonPosY + 165, *northCarolina));
    northCarolina->attach(factory.createLight(cannonPosX + 5, cannonPosY + 81, *northCarolina));
    northCarolina->attach(factory.createLight(cannonPosX + 22, cannonPosY + 81, *northCarolina));
    northCarolina->attach(factory.createLight(cannonPosX + 5, cannonPosY + 101, *northCarolina));
    northCarolina->attach(factory.createLight(cannonPosX + 22, cannonPosY + 101, *northCarolina));
    northCarolina->attach(factory.createLight(cannonPosX + 1, cannonPosY + 111, *northCarolina));
    northCarolina->attach(factory.createLight(cannonPosX + 26, cannonPosY + 111, *northCarolina));
    WeaponFactory specialFactory;
    /*for (int i = 0; i < numAntiAir; i++)
        northCarolina->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir, *northCarolina));
    */std::shared_ptr<LifeBar> life(new LifeBar(*northCarolina));
    northCarolina->attachBar(life);
    return northCarolina;
}
std::shared_ptr<WarShip>
ShipFactory::montanaBuilder(
        sf::Vector2i &coordinates){
    //TODO concludere tutte le aggiunte necessarie
    CannonFactory factory;
    int shipWidth = 37;
    int shipHeight = 281;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int numAntiAir = 80;
    std::shared_ptr<WarShip> montana (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 52, 72104, shipHeight, shipWidth, true,  "Usa", ShipType::Battleship, ModelType::Montana, 1810, "Montana", 0, 10, 4, numAntiAir));
    montana->attach(factory.createHeavly(cannonPosX + 11, cannonPosY + 54, *montana));
    montana->attach(factory.createHeavly(cannonPosX + 11, cannonPosY + 82, *montana));
    montana->attach(factory.createHeavly(cannonPosX + 11, cannonPosY + 177, *montana));
    montana->attach(factory.createHeavly(cannonPosX + 11, cannonPosY + 204, *montana));
    montana->attach(factory.createMedium(cannonPosX + 2, cannonPosY + 111, *montana));
    montana->attach(factory.createMedium(cannonPosX + 30, cannonPosY + 111, *montana));
    montana->attach(factory.createMedium(cannonPosX + 5, cannonPosY + 125, *montana));
    montana->attach(factory.createMedium(cannonPosX + 27, cannonPosY + 125, *montana));
    montana->attach(factory.createMedium(cannonPosX + 2, cannonPosY + 138, *montana));
    montana->attach(factory.createMedium(cannonPosX + 30, cannonPosY + 138, *montana));
    montana->attach(factory.createMedium(cannonPosX + 4, cannonPosY + 152, *montana));
    montana->attach(factory.createMedium(cannonPosX + 27, cannonPosY + 152, *montana));
    montana->attach(factory.createMedium(cannonPosX + 2, cannonPosY + 165, *montana));
    montana->attach(factory.createMedium(cannonPosX + 30, cannonPosY + 165, *montana));
    WeaponFactory specialFactory;
    /*for (int i = 0; i < numAntiAir; i++)
        montana->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir, *montana));
    */std::shared_ptr<LifeBar> life(new LifeBar(*montana));
    montana->attachBar(life);
    return montana;
}
std::shared_ptr<WarShip>
ShipFactory::lionBuilder(
        sf::Vector2i &coordinates){
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 242;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 10;
    std::shared_ptr<WarShip> lion (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 52, 49670, shipHeight, shipWidth, true,  "Uk", ShipType::Battleship, ModelType::Lion, 944, "Lion", 0, 0, 4, numAntiAir));
    lion->attach(factory.createHeavly(cannonPosX + 13, cannonPosY + 43, *lion));
    lion->attach(factory.createHeavly(cannonPosX + 13, cannonPosY + 58, *lion));
    lion->attach(factory.createHeavly(cannonPosX + 13, cannonPosY + 120, *lion));
    lion->attach(factory.createHeavly(cannonPosX + 13, cannonPosY + 191, *lion));
    WeaponFactory specialFactory;
    /*for (int i = 0; i < numAntiAir; i++)
        lion->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir, *lion));
    */std::shared_ptr<LifeBar> life(new LifeBar(*lion));
    lion->attachBar(life);
    return lion;
}
std::shared_ptr<WarShip>
ShipFactory::dreadNoughtBuilder(
        sf::Vector2i &coordinates){
    CannonFactory factory;
    int shipWidth = 25;
    int shipHeight = 158;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 20;
    std::shared_ptr<WarShip> dreadNought (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 39, 21060, shipHeight, shipWidth, true,  "Uk", ShipType::Battleship, ModelType::Dreadnought, 837, "Dreadnought", 0, 0, 5, numAntiAir));
    dreadNought->attach(factory.createHeavly(cannonPosX + 5, cannonPosY + 32, *dreadNought));
    dreadNought->attach(factory.createHeavly(cannonPosX + 5, cannonPosY + 87, *dreadNought));
    dreadNought->attach(factory.createHeavly(cannonPosX + 5, cannonPosY + 112, *dreadNought));
    dreadNought->attach(factory.createHeavly(cannonPosX - 1, cannonPosY + 58, *dreadNought));
    dreadNought->attach(factory.createHeavly(cannonPosX + 13, cannonPosY + 58, *dreadNought));
    WeaponFactory specialFactory;
    /*for (int i = 0; i < numAntiAir; i++)
        dreadNought->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir, *dreadNought));
    */std::shared_ptr<LifeBar> life(new LifeBar(*dreadNought));
    dreadNought->attachBar(life);
    return dreadNought;
}
std::shared_ptr<WarShip> ShipFactory::imperatoreAugustoBuilder(
        sf::Vector2i &coordinates){
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 274;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 12;
    std::shared_ptr<WarShip> imperatoreAugusto (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 57, 65232, shipHeight, shipWidth, true,  "Italy", ShipType::Battleship, ModelType::ImperatoreAugusto, 1126, "ImperatoreAugusto", 16, 10, 4, numAntiAir));
    imperatoreAugusto->attach(factory.createHeavly(cannonPosX + 13, cannonPosY + 61, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createHeavly(cannonPosX + 13, cannonPosY + 80, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createHeavly(cannonPosX + 13, cannonPosY + 179, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createHeavly(cannonPosX + 13, cannonPosY + 199, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createMedium(cannonPosX + 2, cannonPosY + 107, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createMedium(cannonPosX + 2, cannonPosY + 116, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createMedium(cannonPosX + 2, cannonPosY + 159, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createMedium(cannonPosX + 2, cannonPosY + 168, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createMedium(cannonPosX + 30, cannonPosY + 107, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createMedium(cannonPosX + 30, cannonPosY + 116, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createMedium(cannonPosX + 30, cannonPosY + 159, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createMedium(cannonPosX + 30, cannonPosY + 168, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createMedium(cannonPosX + 16, cannonPosY + 106, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createMedium(cannonPosX + 16, cannonPosY + 169, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 2, cannonPosY + 131, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 2, cannonPosY + 138, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 2, cannonPosY + 146, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 2, cannonPosY + 153, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 8, cannonPosY + 128, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 8, cannonPosY + 153, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 8, cannonPosY + 149, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 8, cannonPosY + 156, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 27, cannonPosY + 128, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 27, cannonPosY + 153, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 27, cannonPosY + 149, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 27, cannonPosY + 156, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 33, cannonPosY + 131, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 33, cannonPosY + 138, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 33, cannonPosY + 146, *imperatoreAugusto));
    imperatoreAugusto->attach(factory.createLight(cannonPosX + 33, cannonPosY + 153, *imperatoreAugusto));
    WeaponFactory specialFactory;
    /*for (int i = 0; i < numAntiAir; i++)
        imperatoreAugusto->attach(
                specialFactory.createSpecialWeapon(WeaponType::antiAir, *imperatoreAugusto));
    */std::shared_ptr<LifeBar> life(new LifeBar(*imperatoreAugusto));
    imperatoreAugusto->attachBar(life);
    return imperatoreAugusto;
}
std::shared_ptr<WarShip>
ShipFactory::kongoBuilder(
        sf::Vector2i &coordinates){
    CannonFactory factory;
    int shipWidth = 31;
    int shipHeight = 222;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 18;
    std::shared_ptr<WarShip> kongo(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 56, 37187, shipHeight, shipWidth, true,  "Japan", ShipType::Battleship, ModelType::Kongo, 592, "Kongo", 6, 0, 4, numAntiAir));
    kongo->attach(factory.createHeavly(cannonPosX + 9, cannonPosY + 37, *kongo));
    kongo->attach(factory.createHeavly(cannonPosX + 9, cannonPosY + 50, *kongo));
    kongo->attach(factory.createHeavly(cannonPosX + 9, cannonPosY + 125, *kongo));
    kongo->attach(factory.createHeavly(cannonPosX + 9, cannonPosY + 163, *kongo));
    kongo->attach(factory.createLight(cannonPosX + 2, cannonPosY + 81, *kongo));
    kongo->attach(factory.createLight(cannonPosX + 2, cannonPosY + 95, *kongo));
    kongo->attach(factory.createLight(cannonPosX + 2, cannonPosY + 129, *kongo));
    kongo->attach(factory.createLight(cannonPosX + 24, cannonPosY + 81, *kongo));
    kongo->attach(factory.createLight(cannonPosX + 24, cannonPosY + 95, *kongo));
    kongo->attach(factory.createLight(cannonPosX + 24, cannonPosY + 129, *kongo));
    WeaponFactory specialFactory;
    /*for (int i = 0; i < numAntiAir; i++)
        kongo->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir, *kongo));
    */std::shared_ptr<LifeBar> life(new LifeBar(*kongo));
    kongo->attachBar(life);
    return kongo;
}
std::shared_ptr<WarShip>
ShipFactory::musashiBuilder(
        sf::Vector2i &coordinates){
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 244;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 30;
    std::shared_ptr<WarShip> musashi (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 51, 72809, shipHeight, shipWidth, true,  "Japan", ShipType::Battleship, ModelType::Musashi, 1540, "Musashi", 6, 2, 3, numAntiAir));
    musashi->attach(factory.createHeavly(cannonPosX + 12, cannonPosY + 61, *musashi));
    musashi->attach(factory.createHeavly(cannonPosX + 12, cannonPosY + 82, *musashi));
    musashi->attach(factory.createHeavly(cannonPosX + 12, cannonPosY + 167, *musashi));
    musashi->attach(factory.createMedium(cannonPosX + 8, cannonPosY + 112, *musashi));
    musashi->attach(factory.createMedium(cannonPosX + 27, cannonPosY + 112, *musashi));
    musashi->attach(factory.createLight(cannonPosX, cannonPosY + 125, *musashi));
    musashi->attach(factory.createLight(cannonPosX, cannonPosY + 146, *musashi));
    musashi->attach(factory.createLight(cannonPosX + 34, cannonPosY + 125, *musashi));
    musashi->attach(factory.createLight(cannonPosX + 34, cannonPosY + 146, *musashi));
    musashi->attach(factory.createLight(cannonPosX + 24, cannonPosY + 95, *musashi));
    musashi->attach(factory.createLight(cannonPosX + 24, cannonPosY + 129, *musashi));
    WeaponFactory specialFactory;
    /*for (int i = 0; i < numAntiAir; i++)
        musashi->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir, *musashi));
    */std::shared_ptr<LifeBar> life(new LifeBar(*musashi));
    musashi->attachBar(life);
    return musashi;
}
std::shared_ptr<WarShip> ShipFactory::createDestroyer(ModelType type,int height, int width) {
    std::list<std::shared_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(height,width);
    coordinates.y = coordinates.y - (0.14 * height);
    switch (type) {
        case ModelType::Akizuki: {
            std::shared_ptr<WarShip> akizuki = akizukiBuilder(coordinates);
            repositionEnemyShip(akizuki);
            return akizuki;
        }
        case ModelType::Yukikaze: {
            std::shared_ptr<WarShip> yukikaze = yukikazeBuilder(coordinates);
            repositionEnemyShip(yukikaze);
            return yukikaze;
        }
        case ModelType::Fubuki: {
            std::shared_ptr<WarShip> fubuki = fubukiBuilder(coordinates);
            repositionEnemyShip(fubuki);
            return fubuki;
        }
        case ModelType::Impavido: {
            std::shared_ptr<WarShip> impavido = impavidoBuilder(coordinates);
            repositionEnemyShip(impavido);
            return impavido;
        }
        case ModelType::Leone: {
            std::shared_ptr<WarShip> leone = leoneBuilder(coordinates);
            repositionEnemyShip(leone);
            return leone;
        }
        case ModelType::PaoloEmilio: {
            std::shared_ptr<WarShip> paoloEmilio = paoloEmilioBuilder(coordinates);
            repositionEnemyShip(paoloEmilio);
            return paoloEmilio;
        }
        case ModelType::Campbelltown: {
            std::shared_ptr<WarShip> campbelltown = campbeltownBuilder(coordinates);
            repositionEnemyShip(campbelltown);
            return campbelltown;
        }
        case ModelType::Jutland: {
            std::shared_ptr<WarShip> jutLand = jutlandBuilder(coordinates);
            repositionEnemyShip(jutLand);
            return jutLand;
        }
        case ModelType::Gallant: {
            std::shared_ptr<WarShip> gallant = gallandBuilder(coordinates);
            repositionEnemyShip(gallant);
            return gallant;
        }
        case ModelType::Fletcher: {
            std::shared_ptr<WarShip> fletcher = fletcherBuilder(coordinates);
            repositionEnemyShip(fletcher);
            return fletcher;
        }
        case ModelType::Mahan: {
            std::shared_ptr<WarShip> mahan = mahanBuilder(coordinates);
            repositionEnemyShip(mahan);
            return mahan;
        }
        case ModelType::Sims: {
            std::shared_ptr<WarShip> sims = simsBuilder(coordinates);
            repositionEnemyShip(sims);
            return sims;
        }
    }
}
std::shared_ptr<WarShip>ShipFactory::simsBuilder(sf::Vector2i &coordinates){
    CannonFactory cf;
    int shipWidth = 16;
    int shipHeight = 106;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 16;
    WeaponFactory wf;
    //std::shared_ptr<WarShip> sims(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 69, 2293, 30,"Usa", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Sims, 8));
    std::shared_ptr<WarShip> sims(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 69, 2293,shipHeight,shipWidth,true,"Usa",ShipType::Destroyer,ModelType::Sims,30,"Sims",0,4,0,numAntiAir));
    sims->attach(cf.createMedium(cannonPosX + 5, cannonPosY + 12, *sims));
    sims->attach(cf.createMedium(cannonPosX + 5, cannonPosY + 23, *sims));
    sims->attach(cf.createMedium(cannonPosX + 5, cannonPosY + 78, *sims));
    sims->attach(cf.createMedium(cannonPosX + 5, cannonPosY + 90, *sims));
    /*for (int i = 0; i < numAntiAir; i++) {
        sims->attach(wf.createSpecialWeapon(WeaponType::antiAir, *sims));
    }*/
    std::shared_ptr<LifeBar> life(new LifeBar(*sims));
    sims->attachBar(life);
    return sims;
}
std::shared_ptr<WarShip>ShipFactory::fletcherBuilder(sf::Vector2i &coordinates){
    CannonFactory cf;
    int shipWidth = 12;
    int shipHeight = 114;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 14;
    WeaponFactory wf;
    //std::shared_ptr<WarShip> fletcher(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 68, 2500, 33,"Usa", 0, 0, 5, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Fletcher, 10));
    std::shared_ptr<WarShip> fletcher(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 68, 2500,shipHeight,shipWidth,true,"Usa",ShipType::Destroyer,ModelType::Fletcher,33,"Fletcher",0,5,0,numAntiAir));
    fletcher->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 97, *fletcher));
    fletcher->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 85, *fletcher));
    fletcher->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 73, *fletcher));
    fletcher->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 15, *fletcher));
    fletcher->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 27, *fletcher));
    /*for (int i = 0; i < numAntiAir; i++) {
        fletcher->attach(wf.createSpecialWeapon(WeaponType::antiAir, *fletcher));
    }*/
    std::shared_ptr<LifeBar> life(new LifeBar(*fletcher));
    fletcher->attachBar(life);
    return fletcher;
}
std::shared_ptr<WarShip>ShipFactory::jutlandBuilder(sf::Vector2i &coordinates){
    CannonFactory cf;
    int shipWidth = 13;
    int shipHeight = 116;
    WeaponFactory wf;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 16;
    //std::shared_ptr<WarShip> jutLand(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 66, 2480, 26,"Uk", 0, 0, 3, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Jutland, 10));
    std::shared_ptr<WarShip>jutLand(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 66, 2480,shipHeight,shipWidth,true,"Uk",ShipType::Destroyer,ModelType::Jutland,26,"Jutland",0,3,0,numAntiAir));
    jutLand->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 18, *jutLand));
    jutLand->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 28, *jutLand));
    jutLand->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 95, *jutLand));
    /*for (int i = 0; i < numAntiAir; i++) {
        jutLand->attach(wf.createSpecialWeapon(WeaponType::antiAir, *jutLand));
    }*/
    std::shared_ptr<LifeBar> life(new LifeBar(*jutLand));
    jutLand->attachBar(life);
    return jutLand;
}
std::shared_ptr<WarShip>ShipFactory::paoloEmilioBuilder(sf::Vector2i &coordinates){
    CannonFactory cf;
    int shipWidth = 15;
    int shipHeight = 172;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 12;
    WeaponFactory wf;
    //std::shared_ptr<WarShip> paoloEmilio(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 76, 5420, 66,"Italy", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::PaoloEmilio, 8));
    std::shared_ptr<WarShip> paoloEmilio(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 76, 5420,shipHeight,shipWidth,true,"Italy",ShipType::Destroyer,ModelType::PaoloEmilio,66,"PaoloEmilio",0,4,0,numAntiAir));
    paoloEmilio->attach(cf.createMedium(cannonPosX + 4, cannonPosY + 30, *paoloEmilio));
    paoloEmilio->attach(cf.createMedium(cannonPosX + 4, cannonPosY + 38, *paoloEmilio));
    paoloEmilio->attach(cf.createMedium(cannonPosX + 4, cannonPosY + 134, *paoloEmilio));
    paoloEmilio->attach(cf.createMedium(cannonPosX + 4, cannonPosY + 142, *paoloEmilio));
    /*for (int i = 0; i < numAntiAir; i++) {
        paoloEmilio->attach(wf.createSpecialWeapon(WeaponType::antiAir, *paoloEmilio));
    }*/
    std::shared_ptr<LifeBar> life(new LifeBar(*paoloEmilio));
    paoloEmilio->attachBar(life);
    return paoloEmilio;
}
std::shared_ptr<WarShip>ShipFactory::impavidoBuilder(sf::Vector2i &coordinates){
    CannonFactory cf;
    int shipWidth = 15;
    int shipHeight = 131;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int numAntiAir = 40;
    WeaponFactory wf;
    //std::shared_ptr<WarShip> impavido(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 63, 3941, 36,"Italy", 4, 0, 1, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Impavido, 6));
    std::shared_ptr<WarShip> impavido(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 63, 3941,shipHeight,shipWidth,true,"Italy",ShipType::Destroyer,ModelType::Impavido,36,"Impavido",4,1,0,numAntiAir));
    impavido->attach(cf.createMedium(cannonPosX + 4, cannonPosY + 13, *impavido));
    impavido->attach(cf.createLight(cannonPosX + 1, cannonPosY + 67, *impavido));
    impavido->attach(cf.createLight(cannonPosX + 1, cannonPosY + 79, *impavido));
    impavido->attach(cf.createLight(cannonPosX + 10, cannonPosY + 67, *impavido));
    impavido->attach(cf.createLight(cannonPosX + 10, cannonPosY + 79, *impavido));
    /*for (int i = 0; i < numAntiAir; i++) {
        impavido->attach(wf.createSpecialWeapon(WeaponType::antiAir, *impavido));
    }*/
    std::shared_ptr<LifeBar> life(new LifeBar(*impavido));
    impavido->attachBar(life);
    return impavido;
}
std::shared_ptr<WarShip>ShipFactory::yukikazeBuilder(sf::Vector2i &coordinates){
    CannonFactory cf;
    int shipWidth = 12;
    int shipHeight = 119;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int numAntiAir = 32;
    WeaponFactory wf;
    //std::shared_ptr<WarShip> yukikaze(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 65, 2530, 26,"Japan", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Yukikaze, 8));
    std::shared_ptr<WarShip> yukikaze(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 65, 2530,shipHeight,shipWidth,true,"Japan",ShipType::Destroyer,ModelType::Yukikaze,26,"yukikaze",0,4,0,numAntiAir));
    yukikaze->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 16, *yukikaze));
    yukikaze->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 51, *yukikaze));
    yukikaze->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 70, *yukikaze));
    yukikaze->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 93, *yukikaze));
    /*for (int i = 0; i < numAntiAir; i++) {
        yukikaze->attach(wf.createSpecialWeapon(WeaponType::antiAir, *yukikaze));
    }*/
    std::shared_ptr<LifeBar> life(new LifeBar(*yukikaze));
    yukikaze->attachBar(life);
    return yukikaze;
}
std::shared_ptr<WarShip> ShipFactory::createAlliedSubmarine(ModelType type,int height, int width) {
    sf::Vector2i coordinates = randomizeAlliedPositions(height,width);
    //TODO da sistemare con factory
    std::list<std::shared_ptr<Vehicle>> v;
    coordinates.y = coordinates.y + (0.14 * height);
    switch (type) {
        case ModelType::I400: {
            std::shared_ptr<WarShip> i400 = i400Builder(coordinates);
            repositionAlliedShip(i400);
            return i400;
        }
        case ModelType::typeb1: {
            std::shared_ptr<WarShip> typeb1 = typeb1Builder(coordinates);
            repositionAlliedShip(typeb1);
            return typeb1;
        }
        case ModelType::DaVinci: {
            std::shared_ptr<WarShip> DaVinci = DaVinciBuilder(coordinates);
            repositionAlliedShip(DaVinci);
            return DaVinci;
        }
        case ModelType::Papa: {
            std::shared_ptr<WarShip> papa = papaBuilder(coordinates);
            repositionAlliedShip(papa);
            return papa;
        }
        case ModelType::Triton: {
            std::shared_ptr<WarShip> triton = tritonBuilder(coordinates);
            repositionAlliedShip(triton);
            return triton;
        }
        case ModelType::Trenchant: {
            std::shared_ptr<WarShip> trenchant = trenchantBuilder(coordinates);
            repositionAlliedShip(trenchant);
            return trenchant;
        }
        case ModelType::Gato: {
            std::shared_ptr<WarShip> gato = gatoBuilder(coordinates);
            repositionAlliedShip(gato);
            return gato;
        }
        case ModelType::Narwhal: {
            std::shared_ptr<WarShip> narwhal = narwhalBuilder(coordinates);
            repositionAlliedShip(narwhal);
            return narwhal;
        }
    }
}
std::shared_ptr<WarShip>
ShipFactory::narwhalBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 13;
    int shipHeight = 91;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    std::shared_ptr<WarShip> Narwhal(new Submarine(coordinates.x, coordinates.y, 2, 48, 4600,shipHeight,shipWidth,true,"Usa",ShipType::Submarine,ModelType::Narwhal,0,"Narwhal",0,0,0,0));
    /*for (int i = 0; i < 4; i++)
        Narwhal->attach(factory.createSpecialWeapon(WeaponType::torpedo, *Narwhal));
    */std::shared_ptr<LifeBar> life(new LifeBar(*Narwhal));
    Narwhal->attachBar(life);
    return Narwhal;
}
std::shared_ptr<WarShip>
ShipFactory::trenchantBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 14;
    int shipHeight = 85;
    std::shared_ptr<WarShip> Trenchant(new Submarine(coordinates.x, coordinates.y, 2, 56, 5800,shipHeight,shipWidth,true,"Uk",ShipType::Submarine,ModelType::Trenchant,0,"Trenchant",0,0,0,0));
    /*for (int i = 0; i < 5; i++)
        Trenchant->attach(factory.createSpecialWeapon(WeaponType::torpedo, *Trenchant));
    */std::shared_ptr<LifeBar> life(new LifeBar(*Trenchant));
    Trenchant->attachBar(life);
    return Trenchant;
}
std::shared_ptr<WarShip>
ShipFactory::papaBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 19;
    int shipHeight = 106;
    std::shared_ptr<WarShip> Papa(new Submarine(coordinates.x, coordinates.y, 2, 82, 7100,shipHeight,shipWidth,true,"Italy",ShipType::Submarine,ModelType::Papa,0,"Papa",0,0,0,0));
    /*for (int i = 0; i < 10; i++)
        Papa->attach(factory.createSpecialWeapon(WeaponType::torpedo, *Papa));
    */std::shared_ptr<LifeBar> life(new LifeBar(*Papa));
    Papa->attachBar(life);
    return Papa;
}
std::shared_ptr<WarShip> ShipFactory::createAlliedAircraftCarrier(ModelType type,int height, int width) {
    sf::Vector2i coordinates = randomizeAlliedPositions(height,width);
    //TODO da sistemare con factory
    std::list<std::shared_ptr<Vehicle>> v;
    coordinates.y = coordinates.y + (0.14 * height);
    switch (type) {
        case ModelType::Tahio: {
            std::shared_ptr<WarShip> tahio = tahioBuilder(coordinates);
            repositionAlliedShip(tahio);
            return tahio;
        }
        case ModelType::Hiryu: {
            std::shared_ptr<WarShip> hiryu = hiryuBuilder(coordinates);
            repositionAlliedShip(hiryu);
            return hiryu;
        }
        case ModelType::GiuseppeGaribaldi: {
            std::shared_ptr<WarShip> giuseppeGaribaldi = giuseppeGaribaldiBuilder(coordinates);
            repositionAlliedShip(giuseppeGaribaldi);
            return giuseppeGaribaldi;
        }
        case ModelType::Cavour: {
            std::shared_ptr<WarShip> cavour = cavourBuilder(coordinates);
            repositionAlliedShip(cavour);
            return cavour;
        }
        case ModelType::ArkRoyal: {
            std::shared_ptr<WarShip> arkRoyal = arkRoyalBuilder(coordinates);
            repositionAlliedShip(arkRoyal);
            return arkRoyal;
        }
        case ModelType::Indomitable: {
            std::shared_ptr<WarShip> indomitable = indomitableBuilder(coordinates);
            repositionAlliedShip(indomitable);
            return indomitable;
        }
        case ModelType::Midway: {
            std::shared_ptr<WarShip> midway = midwayBuilder(coordinates);
            repositionAlliedShip(midway);
            return midway;
        }
        case ModelType::FranklinDRoosevelt: {
            std::shared_ptr<WarShip> franklinDRoosevelt = franklinDelanoRoosveltBuilder(coordinates);
            repositionAlliedShip(franklinDRoosevelt);
            return franklinDRoosevelt;
        }
    }
}
std::shared_ptr<WarShip>ShipFactory::franklinDelanoRoosveltBuilder(sf::Vector2i &coordinates){
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 70;
    int shipHeight = 295;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    WeaponFactory specialFactory;
    int numAntiAir = 8;
    std::shared_ptr<WarShip> FranklinDRoosevelt (new ConcreteAircraftCarrier(coordinates.x, coordinates.y, 1, 61, 45000, shipHeight, shipWidth, true,  "Usa", ShipType::AircraftCarrier, ModelType::FranklinDRoosevelt, 363, "FranklinDelanoRoosevelt", 0, 2, 0, numAntiAir, 14));
    FranklinDRoosevelt->attach(factory.createMedium(cannonPosX + 55, cannonPosY + 92, *FranklinDRoosevelt));
    FranklinDRoosevelt->attach(factory.createMedium(cannonPosX + 56, cannonPosY + 179, *FranklinDRoosevelt));
    AircraftCarrier * dynamic = dynamic_cast<AircraftCarrier *>(FranklinDRoosevelt.get());
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+35,cannonPosY+12,"Usa",*FranklinDRoosevelt));
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+35,cannonPosY+32,"Usa",*FranklinDRoosevelt));
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+35,cannonPosY+52,"Usa",*FranklinDRoosevelt));
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+35,cannonPosY+72,"Usa",*FranklinDRoosevelt));
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+35,cannonPosY+92,"Usa",*FranklinDRoosevelt));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+35,cannonPosY+112,"Usa",*FranklinDRoosevelt));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+35,cannonPosY+132,"Usa",*FranklinDRoosevelt));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+35,cannonPosY+152,"Usa",*FranklinDRoosevelt));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+35,cannonPosY+172,"Usa",*FranklinDRoosevelt));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+35,cannonPosY+192,"Usa",*FranklinDRoosevelt));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+35,cannonPosY+212,"Usa",*FranklinDRoosevelt));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+35,cannonPosY+232,"Usa",*FranklinDRoosevelt));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+35,cannonPosY+252,"Usa",*FranklinDRoosevelt));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+35,cannonPosY+272,"Usa",*FranklinDRoosevelt));
    /*for (int i = 0; i < numAntiAir; i++)
        FranklinDRoosevelt->attach(
                specialFactory.createSpecialWeapon(WeaponType::antiAir, *FranklinDRoosevelt));
    */std::shared_ptr<LifeBar> life(new LifeBar(*FranklinDRoosevelt));
    FranklinDRoosevelt->attachBar(life);
    return FranklinDRoosevelt;
}
std::shared_ptr<WarShip>
ShipFactory::indomitableBuilder(sf::Vector2i &coordinates){
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 41;
    int shipHeight = 230;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    WeaponFactory specialFactory;
    int numAntiAir = 6;
    //std::shared_ptr<WarShip> Indomitable(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 56, 29730, 240, "Uk", 2, 0, 0, numAntiAir,shipHeight,shipWidth,true,ShipType::AircraftCarrier, ModelType::Indomitable, 5));
    std::shared_ptr<WarShip> Indomitable(new ConcreteAircraftCarrier(coordinates.x, coordinates.y, 1, 56, 29730,shipHeight,shipWidth,true,"Uk",ShipType::AircraftCarrier,ModelType::Indomitable,240,"Indomitable",2,0,0,numAntiAir,5));
    Indomitable->attach(factory.createLight(cannonPosX + 6, cannonPosY + 38, *Indomitable));
    Indomitable->attach(factory.createLight(cannonPosX + 31, cannonPosY + 38, *Indomitable));
    AircraftCarrier * dy = dynamic_cast<AircraftCarrier *>(Indomitable.get());
    dy->attachPlanes(airPlanesFactory.createFighter(cannonPosX+20,cannonPosY+12,"Uk",*Indomitable));
    dy->attachPlanes(airPlanesFactory.createFighter(cannonPosX+20,cannonPosY+32,"Uk",*Indomitable));
    dy->attachPlanes(airPlanesFactory.createBomber(cannonPosX+20,cannonPosY+62,"Uk",*Indomitable));
    dy->attachPlanes(airPlanesFactory.createBomber(cannonPosX+20,cannonPosY+82,"Uk",*Indomitable));
    dy->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+20,cannonPosY+112,"Uk",*Indomitable));
    /*for (int i = 0; i < numAntiAir; i++)
        Indomitable->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir, *Indomitable));
    */std::shared_ptr<LifeBar> life(new LifeBar(*Indomitable));
    Indomitable->attachBar(life);
    return Indomitable;
}
std::shared_ptr<WarShip>
ShipFactory::cavourBuilder(sf::Vector2i &coordinates){
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 50;
    int shipHeight = 244;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    WeaponFactory specialFactory;
    int numAntiAir = 3;
    //std::shared_ptr<WarShip> Cavour(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 52, 29900, 241, "Italy", 4, 0, 0, numAntiAir,shipHeight,shipWidth,true,ShipType::AircraftCarrier, ModelType::Cavour, 6));
    std::shared_ptr<WarShip> Cavour(new ConcreteAircraftCarrier(coordinates.x, coordinates.y, 1, 52, 29900,shipHeight,shipWidth,true,"Italy",ShipType::AircraftCarrier,ModelType::Cavour,241,"Cavour",4,0,0,numAntiAir,6));
    Cavour->attach(factory.createLight(cannonPosX + 16, cannonPosY + 4,*Cavour));
    Cavour->attach(factory.createLight(cannonPosX + 31, cannonPosY + 23,*Cavour));
    Cavour->attach(factory.createLight(cannonPosX + 29, cannonPosY + 78,*Cavour));
    Cavour->attach(factory.createLight(cannonPosX + 26, cannonPosY + 171,*Cavour));
    AircraftCarrier * dy = dynamic_cast<AircraftCarrier *>(Cavour.get());
    dy->attachPlanes(airPlanesFactory.createFighter(cannonPosX+17,cannonPosY+12,"Italy",*Cavour));
    dy->attachPlanes(airPlanesFactory.createFighter(cannonPosX+17,cannonPosY+38,"Italy",*Cavour));
    dy->attachPlanes(airPlanesFactory.createBomber(cannonPosX+17,cannonPosY+66,"Italy",*Cavour));
    dy->attachPlanes(airPlanesFactory.createBomber(cannonPosX+17,cannonPosY+94,"Italy",*Cavour));
    dy->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+17,cannonPosY+125,"Italy",*Cavour));
    dy->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+17,cannonPosY+156,"Italy",*Cavour));
    /*for (int i = 0; i < numAntiAir; i++)
        Cavour->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir,*Cavour));
    */std::shared_ptr<LifeBar> life(new LifeBar(*Cavour));
    Cavour->attachBar(life);
    return Cavour;
}
std::shared_ptr<WarShip>ShipFactory::hiryuBuilder(sf::Vector2i &coordinates){
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 39;
    int shipHeight = 222;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    WeaponFactory specialFactory;
    int numAntiAir = 2;
    //std::shared_ptr<WarShip> Hiryu(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 63, 20570, 70, "Japan", 2, 0, 0, numAntiAir,shipHeight,shipWidth,true,ShipType::ConcreteAircraftCarrier, ModelType::Hiryu, 6));
    std::shared_ptr<WarShip> Hiryu(new ConcreteAircraftCarrier(coordinates.x, coordinates.y, 1, 63, 20570,shipHeight,shipWidth,true,"Japan",ShipType::AircraftCarrier,ModelType::Hiryu,70,"Hiryu",2,0,0,numAntiAir,6));
    Hiryu->attach(factory.createLight(cannonPosX + 18, cannonPosY + 3, *Hiryu));
    Hiryu->attach(factory.createLight(cannonPosX + 5, cannonPosY + 61, *Hiryu));
    ConcreteAircraftCarrier * dynamic = dynamic_cast<ConcreteAircraftCarrier *>(Hiryu.get());
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+19,cannonPosY+32,"Japan",*Hiryu));
    dynamic->attachPlanes(airPlanesFactory.createFighter(cannonPosX+19,cannonPosY+58,"Japan",*Hiryu));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+19,cannonPosY+86,"Japan",*Hiryu));
    dynamic->attachPlanes(airPlanesFactory.createBomber(cannonPosX+19,cannonPosY+114,"Japan",*Hiryu));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+19,cannonPosY+145,"Japan",*Hiryu));
    dynamic->attachPlanes(airPlanesFactory.createTorpedoBomber(cannonPosX+19,cannonPosY+176,"Japan",*Hiryu));
    /*for (int i = 0; i < numAntiAir; i++)
        Hiryu->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir, *Hiryu));
    */std::shared_ptr<LifeBar> life(new LifeBar(*Hiryu));
    Hiryu->attachBar(life);
    return Hiryu;
}
std::shared_ptr<WarShip> ShipFactory::createAlliedCruiser(ModelType type,int height, int width) {
    sf::Vector2i coordinates = randomizeAlliedPositions(height,width);
    //TODO da sistemare con factory
    std::list<std::shared_ptr<Vehicle>> v;
    coordinates.y = coordinates.y + (0.14 * height);
    switch (type) {
        case ModelType::Ijn: {
            std::shared_ptr<WarShip> ijn = ijnBuilder(coordinates);
            repositionAlliedShip(ijn);
            return ijn;
        }
        case ModelType::IsuzuNagara: {
            std::shared_ptr<WarShip> isuzuNagara = isuzuNagaraBuilder(coordinates);
            repositionAlliedShip(isuzuNagara);
            return isuzuNagara;
        }
        case ModelType::Takao: {
            std::shared_ptr<WarShip> takao = takaoBuilder(coordinates);
            repositionAlliedShip(takao);
            return takao;
        }
        case ModelType::AlbertoDiGiussano: {
            std::shared_ptr<WarShip> albertoDiGiussano = albertoDiGiussanoBuilder(coordinates);
            repositionAlliedShip(albertoDiGiussano);
            return albertoDiGiussano;
        }
        case ModelType::Gorizia: {
            std::shared_ptr<WarShip> gorizia = goriziaBuilder(coordinates);
            repositionAlliedShip(gorizia);
            return gorizia;
        }
        case ModelType::Trento: {
            std::shared_ptr<WarShip> trento = trentoBuilder(coordinates);
            repositionAlliedShip(trento);
            return trento;
        }
        case ModelType::Belfast: {
            std::shared_ptr<WarShip> belfast = belfastBuilder(coordinates);
            repositionAlliedShip(belfast);
            return belfast;
        }
        case ModelType::Danae: {
            std::shared_ptr<WarShip> danae = danaeBuilder(coordinates);
            repositionAlliedShip(danae);
            return danae;
        }
        case ModelType::Tiger59: {
            std::shared_ptr<WarShip> tiger59 = tiger59Builder(coordinates);
            repositionAlliedShip(tiger59);
            return tiger59;
        }
        case ModelType::Alaska: {
            std::shared_ptr<WarShip> alaska = alaskaBuilder(coordinates);
            repositionAlliedShip(alaska);
            return alaska;
        }
        case ModelType::NewOrleans: {
            std::shared_ptr<WarShip> newOrleans = newOrleansBuilder(coordinates);
            repositionAlliedShip(newOrleans);
            return newOrleans;
        }
        case ModelType::StLouis: {
            std::shared_ptr<WarShip> saintLouis = stLouisBuilder(coordinates);
            repositionAlliedShip(saintLouis);
            return saintLouis;
        }
    }
}
std::shared_ptr<WarShip>
ShipFactory::newOrleansBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 25;
    int shipHeight = 178;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    CannonFactory cf;
    int antiAir = 12;
    std::shared_ptr<WarShip> NewOrleans (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 61, 12663, shipHeight, shipWidth, true,  "Usa", ShipType::Cruiser, ModelType::NewOrleans, 476, "NewOrleans", 6, 3, 0, antiAir));
    NewOrleans->attach(cf.createMedium(cannonPosX + 10, cannonPosY + 121, *NewOrleans));
    NewOrleans->attach(cf.createMedium(cannonPosX + 10, cannonPosY + 50, *NewOrleans));
    NewOrleans->attach(cf.createMedium(cannonPosX + 10, cannonPosY + 38, *NewOrleans));
    NewOrleans->attach(cf.createLight(cannonPosX + 5, cannonPosY + 73, *NewOrleans));
    NewOrleans->attach(cf.createLight(cannonPosX + 5, cannonPosY + 82, *NewOrleans));
    NewOrleans->attach(cf.createLight(cannonPosX + 5, cannonPosY + 90, *NewOrleans));
    NewOrleans->attach(cf.createLight(cannonPosX + 17, cannonPosY + 73, *NewOrleans));
    NewOrleans->attach(cf.createLight(cannonPosX + 17, cannonPosY + 82, *NewOrleans));
    NewOrleans->attach(cf.createLight(cannonPosX + 17, cannonPosY + 90, *NewOrleans));
    /*for (int i = 0; i < antiAir; i++)
        NewOrleans->attach(factory.createSpecialWeapon(WeaponType::antiAir, *NewOrleans));
    */std::shared_ptr<LifeBar> life(new LifeBar(*NewOrleans));
    NewOrleans->attachBar(life);
    return NewOrleans;
}
std::shared_ptr<WarShip>
ShipFactory::tiger59Builder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 19;
    int shipHeight = 169;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    CannonFactory cf;
    int antiAir = 7;
    std::shared_ptr<WarShip> Tiger59 (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 58, 12080, shipHeight, shipWidth, true,  "Uk", ShipType::Cruiser, ModelType::Tiger59, 191, "Tiger'59", 6, 4, 0, antiAir));
    Tiger59->attach(cf.createMedium(cannonPosX + 6, cannonPosY + 137, *Tiger59));
    Tiger59->attach(cf.createMedium(cannonPosX + 6, cannonPosY + 128, *Tiger59));
    Tiger59->attach(cf.createMedium(cannonPosX + 6, cannonPosY + 32, *Tiger59));
    Tiger59->attach(cf.createMedium(cannonPosX + 6, cannonPosY + 24, *Tiger59));
    Tiger59->attach(cf.createLight(cannonPosX + 1, cannonPosY + 117, *Tiger59));
    Tiger59->attach(cf.createLight(cannonPosX + 1, cannonPosY + 92, *Tiger59));
    Tiger59->attach(cf.createLight(cannonPosX + 1, cannonPosY + 75, *Tiger59));
    Tiger59->attach(cf.createLight(cannonPosX + 13, cannonPosY + 117, *Tiger59));
    Tiger59->attach(cf.createLight(cannonPosX + 13, cannonPosY + 92, *Tiger59));
    Tiger59->attach(cf.createLight(cannonPosX + 13, cannonPosY + 75, *Tiger59));
    /*for (int i = 0; i < antiAir; i++)
        Tiger59->attach(factory.createSpecialWeapon(WeaponType::antiAir, *Tiger59));
*/
    std::shared_ptr<LifeBar> life(new LifeBar(*Tiger59));
    Tiger59->attachBar(life);
    return Tiger59;
}
std::shared_ptr<WarShip>
ShipFactory::belfastBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 27;
    int shipHeight = 187;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    CannonFactory cf;
    int antiAir = 12;
    std::shared_ptr<WarShip> Belfast (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 59, 11550, shipHeight, shipWidth, true,  "Uk", ShipType::Cruiser, ModelType::Belfast, 228, "Belfast", 6, 4, 0, antiAir));
    Belfast->attach(cf.createMedium(cannonPosX + 10, cannonPosY + 151, *Belfast));
    Belfast->attach(cf.createMedium(cannonPosX + 10, cannonPosY + 141, *Belfast));
    Belfast->attach(cf.createMedium(cannonPosX + 10, cannonPosY + 34, *Belfast));
    Belfast->attach(cf.createMedium(cannonPosX + 10, cannonPosY + 25, *Belfast));
    Belfast->attach(cf.createLight(cannonPosX + 4, cannonPosY + 121, *Belfast));
    Belfast->attach(cf.createLight(cannonPosX + 4, cannonPosY + 107, *Belfast));
    Belfast->attach(cf.createLight(cannonPosX + 4, cannonPosY + 95, *Belfast));
    Belfast->attach(cf.createLight(cannonPosX + 18, cannonPosY + 121, *Belfast));
    Belfast->attach(cf.createLight(cannonPosX + 18, cannonPosY + 107, *Belfast));
    Belfast->attach(cf.createLight(cannonPosX + 18, cannonPosY + 95, *Belfast));
    /*for (int i = 0; i < antiAir; i++)
        Belfast->attach(factory.createSpecialWeapon(WeaponType::antiAir, *Belfast));
    */std::shared_ptr<LifeBar> life(new LifeBar(*Belfast));
    Belfast->attachBar(life);
    return Belfast;
}
std::shared_ptr<WarShip>
ShipFactory::goriziaBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 22;
    int shipHeight = 183;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    CannonFactory cf;
    int antiAir = 12;
    std::shared_ptr<WarShip> Gorizia (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 59, 14330, shipHeight, shipWidth, true,  "Italy", ShipType::Cruiser, ModelType::Gorizia, 370, "Gorizia", 6, 4, 0, antiAir));
    Gorizia->attach(cf.createMedium(cannonPosX + 7, cannonPosY + 151, *Gorizia));
    Gorizia->attach(cf.createMedium(cannonPosX + 7, cannonPosY + 141, *Gorizia));
    Gorizia->attach(cf.createMedium(cannonPosX + 7, cannonPosY + 57, *Gorizia));
    Gorizia->attach(cf.createMedium(cannonPosX + 7, cannonPosY + 46, *Gorizia));
    Gorizia->attach(cf.createLight(cannonPosX + 3, cannonPosY + 78, *Gorizia));
    Gorizia->attach(cf.createLight(cannonPosX + 15, cannonPosY + 78, *Gorizia));
    Gorizia->attach(cf.createLight(cannonPosX, cannonPosY + 107, *Gorizia));
    Gorizia->attach(cf.createLight(cannonPosX, cannonPosY + 98, *Gorizia));
    Gorizia->attach(cf.createLight(cannonPosX + 15, cannonPosY + 107, *Gorizia));
    Gorizia->attach(cf.createLight(cannonPosX + 15, cannonPosY + 98, *Gorizia));
   /* for (int i = 0; i < antiAir; i++) {
        Gorizia->attach(factory.createSpecialWeapon(WeaponType::antiAir, *Gorizia));
    }*/
    std::shared_ptr<LifeBar> life(new LifeBar(*Gorizia));
    Gorizia->attachBar(life);
    return Gorizia;
}
std::shared_ptr<WarShip>
ShipFactory::isuzuNagaraBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 14;
    int shipHeight = 159;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    CannonFactory cf;
    int antiAir = 6;
    std::shared_ptr<WarShip> IsuzuNagara (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 67, 5700, shipHeight, shipWidth, true,  "Japan", ShipType::Cruiser, ModelType::IsuzuNagara, 90, "IsuzuNagara", 5, 3, 0, antiAir));
    IsuzuNagara->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 132, *IsuzuNagara));
    IsuzuNagara->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 94, *IsuzuNagara));
    IsuzuNagara->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 18, *IsuzuNagara));
    IsuzuNagara->attach(cf.createLight(cannonPosX + 5, cannonPosY + 142, *IsuzuNagara));
    IsuzuNagara->attach(cf.createLight(cannonPosX + 3, cannonPosY + 77, *IsuzuNagara));
    IsuzuNagara->attach(cf.createLight(cannonPosX + 6, cannonPosY + 77, *IsuzuNagara));
    IsuzuNagara->attach(cf.createLight(cannonPosX + 3, cannonPosY + 30, *IsuzuNagara));
    IsuzuNagara->attach(cf.createLight(cannonPosX + 6, cannonPosY + 30, *IsuzuNagara));
    /*for (int i = 0; i < antiAir; i++)
        IsuzuNagara->attach(factory.createSpecialWeapon(WeaponType::antiAir, *IsuzuNagara));
*/
    std::shared_ptr<LifeBar> life(new LifeBar(*IsuzuNagara));
    IsuzuNagara->attachBar(life);
    return IsuzuNagara;
}
std::shared_ptr<WarShip>
ShipFactory::ijnBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    int shipWidth = 26;
    int shipHeight = 204;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    CannonFactory cf;
    int antiAir = 10;
    std::shared_ptr<WarShip> Ijn (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 66, 15500, shipHeight, shipWidth, true,  "Japan", ShipType::Cruiser, ModelType::Ijn, 230, "IJN", 4, 4, 0, antiAir));
    Ijn->attach(cf.createMedium(cannonPosX + 10, cannonPosY + 31, *Ijn));
    Ijn->attach(cf.createMedium(cannonPosX + 10, cannonPosY + 41, *Ijn));
    Ijn->attach(cf.createMedium(cannonPosX + 10, cannonPosY + 50, *Ijn));
    Ijn->attach(cf.createMedium(cannonPosX + 10, cannonPosY + 64, *Ijn));
    Ijn->attach(cf.createLight(cannonPosX + 1, cannonPosY + 101, *Ijn));
    Ijn->attach(cf.createLight(cannonPosX + 1, cannonPosY + 115, *Ijn));
    Ijn->attach(cf.createLight(cannonPosX + 20, cannonPosY + 102, *Ijn));
    Ijn->attach(cf.createLight(cannonPosX + 20, cannonPosY + 115, *Ijn));
    /*for (int i = 0; i < antiAir; i++)
        Ijn->attach(factory.createSpecialWeapon(WeaponType::antiAir, *Ijn));
    */std::shared_ptr<LifeBar> life(new LifeBar(*Ijn));
    Ijn->attachBar(life);
    return Ijn;
}
std::shared_ptr<WarShip> ShipFactory::createAlliedBattleship(ModelType type,int height, int width) {
    sf::Vector2i coordinates = randomizeAlliedPositions(height,width);
    //TODO da sistemare con factory
    std::list<std::shared_ptr<Vehicle>> v;
    coordinates.y = coordinates.y + (0.14 * height);
    switch (type) {
        case ModelType::ISE: {
            std::shared_ptr<WarShip> ise = iseBuilder(coordinates);
            repositionAlliedShip(ise);
            return ise;
        }
        case ModelType::Kongo: {
            std::shared_ptr<WarShip> kongo = kongoBuilder(coordinates);
            repositionAlliedShip(kongo);
            return kongo;
        }
        case ModelType::Musashi: {
            std::shared_ptr<WarShip> musashi = musashiBuilder(coordinates);
            repositionAlliedShip(musashi);
            return musashi;
        }
        case ModelType::Yamato: {
            std::shared_ptr<WarShip> yamato = yamatoBuilder(coordinates);
            repositionAlliedShip(yamato);
            return yamato;
        }
        case ModelType::AndreaDoria: {
            std::shared_ptr<WarShip> andreaDoria = andreaDoriaBuilder(coordinates);
            repositionAlliedShip(andreaDoria);
            return andreaDoria;
        }
        case ModelType::ImperatoreAugusto: {
            std::shared_ptr<WarShip> imperatoreAugusto = imperatoreAugustoBuilder(coordinates);
            repositionAlliedShip(imperatoreAugusto);
            return imperatoreAugusto;
        }
        case ModelType::MichelangeloBuonarroti: {
            std::shared_ptr<WarShip> michelangeloBuonarroti = michelangeloBuonarrotiBuilder(coordinates);
            repositionAlliedShip(michelangeloBuonarroti);
            return michelangeloBuonarroti;
        }
        case ModelType::VittorioVeneto: {
            std::shared_ptr<WarShip> vittorioVeneto = vittorioVenetoBuilder(coordinates);
            repositionAlliedShip(vittorioVeneto);
            return vittorioVeneto;
        }
        case ModelType::Dreadnought: {
            std::shared_ptr<WarShip> dreadNought = dreadNoughtBuilder(coordinates);
            repositionAlliedShip(dreadNought);
            return dreadNought;
        }
        case ModelType::Hood: {
            std::shared_ptr<WarShip> hood = hoodBuilder(coordinates);
            repositionAlliedShip(hood);
            return hood;
        }
        case ModelType::IronDuke: {
            std::shared_ptr<WarShip> ironDuke = ironDukeBuilder(coordinates);
            repositionAlliedShip(ironDuke);
            return ironDuke;
        }
        case ModelType::Lion: {
            std::shared_ptr<WarShip> lion = lionBuilder(coordinates);
            repositionAlliedShip(lion);
            return lion;
        }
        case ModelType::Arizona: {
            std::shared_ptr<WarShip> arizona = arizonaBuilder(coordinates);
            repositionAlliedShip(arizona);
            return arizona;
        }
        case ModelType::Montana: {
            std::shared_ptr<WarShip> montana = montanaBuilder(coordinates);
            repositionAlliedShip(montana);
            return montana;
        }
        case ModelType::NewYork: {
            std::shared_ptr<WarShip> newYork = newYorkBuilder(coordinates);
            repositionAlliedShip(newYork);
            return newYork;
        }
        case ModelType::NorthCarolina: {
            std::shared_ptr<WarShip> northCarolina = northCarolinaBuilder(coordinates);
            repositionAlliedShip(northCarolina);
            return northCarolina;
        }
    }
}
std::shared_ptr<WarShip>
ShipFactory::vittorioVenetoBuilder(sf::Vector2i &coordinates){
    CannonFactory factory;
    int shipWidth = 33;
    int shipHeight = 238;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 32;
    std::shared_ptr<WarShip> VittorioVeneto (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 56, 45963, shipHeight, shipWidth, true,  "Italy", ShipType::Battleship, ModelType::VittorioVeneto, 862, "VittorioVeneto", 12, 4, 4, numAntiAir));
    VittorioVeneto->attach(factory.createHeavly(cannonPosX + 9, cannonPosY + 55, *VittorioVeneto));
    VittorioVeneto->attach(factory.createHeavly(cannonPosX + 9, cannonPosY + 78, *VittorioVeneto));
    VittorioVeneto->attach(factory.createHeavly(cannonPosX + 9, cannonPosY + 78, *VittorioVeneto));
    VittorioVeneto->attach(factory.createHeavly(cannonPosX + 9, cannonPosY + 140, *VittorioVeneto));
    VittorioVeneto->attach(factory.createMedium(cannonPosX + 2, cannonPosY + 93, *VittorioVeneto));
    VittorioVeneto->attach(factory.createMedium(cannonPosX + 2, cannonPosY + 163, *VittorioVeneto));
    VittorioVeneto->attach(factory.createMedium(cannonPosX + 24, cannonPosY + 93, *VittorioVeneto));
    VittorioVeneto->attach(factory.createMedium(cannonPosX + 24, cannonPosY + 163, *VittorioVeneto));
    VittorioVeneto->attach(factory.createLight(cannonPosX + 3, cannonPosY + 104, *VittorioVeneto));
    VittorioVeneto->attach(factory.createLight(cannonPosX + 3, cannonPosY + 109, *VittorioVeneto));
    VittorioVeneto->attach(factory.createLight(cannonPosX + 3, cannonPosY + 115, *VittorioVeneto));
    VittorioVeneto->attach(factory.createLight(cannonPosX + 3, cannonPosY + 122, *VittorioVeneto));
    VittorioVeneto->attach(factory.createLight(cannonPosX + 3, cannonPosY + 130, *VittorioVeneto));
    VittorioVeneto->attach(factory.createLight(cannonPosX + 3, cannonPosY + 136, *VittorioVeneto));
    VittorioVeneto->attach(factory.createLight(cannonPosX + 26, cannonPosY + 104, *VittorioVeneto));
    VittorioVeneto->attach(factory.createLight(cannonPosX + 26, cannonPosY + 109, *VittorioVeneto));
    VittorioVeneto->attach(factory.createLight(cannonPosX + 26, cannonPosY + 115, *VittorioVeneto));
    VittorioVeneto->attach(factory.createLight(cannonPosX + 26, cannonPosY + 122, *VittorioVeneto));
    VittorioVeneto->attach(factory.createLight(cannonPosX + 26, cannonPosY + 130, *VittorioVeneto));
    VittorioVeneto->attach(factory.createLight(cannonPosX + 26, cannonPosY + 136, *VittorioVeneto));
    WeaponFactory specialFactory;
    /*for (int i = 0; i < numAntiAir; i++)
        VittorioVeneto->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir, *VittorioVeneto));
    */std::shared_ptr<LifeBar> life(new LifeBar(*VittorioVeneto));
    VittorioVeneto->attachBar(life);
    return VittorioVeneto;
}
std::shared_ptr<WarShip>
ShipFactory::newYorkBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    CannonFactory cf;
    int shipWidth = 35;
    int shipHeight = 175;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int antiAir = 6;
    std::shared_ptr<WarShip> NewYork (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 39, 28822, shipHeight, shipWidth, true,  "Usa", ShipType::Battleship, ModelType::NewYork, 939, "NewYork", 0, 0, 5, antiAir));
    NewYork->attach(cf.createHeavly(cannonPosX + 10, cannonPosY + 19, *NewYork));
    NewYork->attach(cf.createHeavly(cannonPosX + 10, cannonPosY + 39, *NewYork));
    NewYork->attach(cf.createHeavly(cannonPosX + 10, cannonPosY + 84, *NewYork));
    NewYork->attach(cf.createHeavly(cannonPosX + 10, cannonPosY + 109, *NewYork));
    NewYork->attach(cf.createHeavly(cannonPosX + 10, cannonPosY + 134, *NewYork));
    /*for (int i = 0; i < antiAir; i++)
        NewYork->attach(factory.createSpecialWeapon(WeaponType::antiAir, *NewYork));
    */std::shared_ptr<LifeBar> life(new LifeBar(*NewYork));
    NewYork->attachBar(life);
    return NewYork;
}
std::shared_ptr<WarShip>
ShipFactory::arizonaBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    CannonFactory cf;
    int shipWidth = 32;
    int shipHeight = 185;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int antiAir = 4;
    std::shared_ptr<WarShip> Arizona (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 39, 32429, shipHeight, shipWidth, true,  "Usa", ShipType::Battleship, ModelType::Arizona, 1536, "Arizona", 8, 0, 4, antiAir));
    Arizona->attach(cf.createHeavly(cannonPosX + 8, cannonPosY + 29, *Arizona));
    Arizona->attach(cf.createHeavly(cannonPosX + 8, cannonPosY + 58, *Arizona));
    Arizona->attach(cf.createHeavly(cannonPosX + 8, cannonPosY + 120, *Arizona));
    Arizona->attach(cf.createHeavly(cannonPosX + 8, cannonPosY + 142, *Arizona));
    Arizona->attach(cf.createLight(cannonPosX + 5, cannonPosY + 97, *Arizona));
    Arizona->attach(cf.createLight(cannonPosX + 2, cannonPosY + 87, *Arizona));
    Arizona->attach(cf.createLight(cannonPosX + 2, cannonPosY + 78, *Arizona));
    Arizona->attach(cf.createLight(cannonPosX + 4, cannonPosY + 69, *Arizona));
    Arizona->attach(cf.createLight(cannonPosX + 23, cannonPosY + 97, *Arizona));
    Arizona->attach(cf.createLight(cannonPosX + 26, cannonPosY + 87, *Arizona));
    Arizona->attach(cf.createLight(cannonPosX + 23, cannonPosY + 78, *Arizona));
    Arizona->attach(cf.createLight(cannonPosX + 21, cannonPosY + 69, *Arizona));
    /*for (int i = 0; i < antiAir; i++)
        Arizona->attach(factory.createSpecialWeapon(WeaponType::antiAir, *Arizona));
    */std::shared_ptr<LifeBar> life(new LifeBar(*Arizona));
    Arizona->attachBar(life);
    return Arizona;
}
std::shared_ptr<WarShip>
ShipFactory::hoodBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    CannonFactory cf;
    int shipWidth = 34;
    int shipHeight = 262;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int antiAir = 20;
    std::shared_ptr<WarShip> Hood (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 54, 49136, shipHeight, shipWidth, true,  "Uk", ShipType::Battleship, ModelType::Hood, 800, "Hood", 0, 2, 2, antiAir));
    Hood->attach(cf.createHeavly(cannonPosX + 9, cannonPosY + 207, *Hood));
    Hood->attach(cf.createHeavly(cannonPosX + 9, cannonPosY + 44, *Hood));
    Hood->attach(cf.createMedium(cannonPosX + 12, cannonPosY + 190, *Hood));
    Hood->attach(cf.createMedium(cannonPosX + 13, cannonPosY + 59, *Hood));
    /*for (int i = 0; i < antiAir; i++)
        Hood->attach(factory.createSpecialWeapon(WeaponType::antiAir, *Hood));
    */std::shared_ptr<LifeBar> life(new LifeBar(*Hood));
    Hood->attachBar(life);
    return Hood;
}
std::shared_ptr<WarShip>
ShipFactory::michelangeloBuonarrotiBuilder(sf::Vector2i &coordinates){
    CannonFactory factory;
    int shipWidth = 35;
    int shipHeight = 246;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 14;
    std::shared_ptr<WarShip> MichelangeloBuonarroti (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 61, 42533, shipHeight, shipWidth, true,  "Italy", ShipType::Battleship, ModelType::MichelangeloBuonarroti, 837, "MichelangeloBuonarroti", 12, 6, 3, numAntiAir));
    MichelangeloBuonarroti->attach(
            factory.createHeavly(cannonPosX + 10, cannonPosY + 56, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createHeavly(cannonPosX + 10, cannonPosY + 78, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createHeavly(cannonPosX + 10, cannonPosY + 166, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createMedium(cannonPosX + 1, cannonPosY + 118, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createMedium(cannonPosX + 1, cannonPosY + 139, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createMedium(cannonPosX + 2, cannonPosY + 95, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createMedium(cannonPosX + 27, cannonPosY + 118, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createMedium(cannonPosX + 27, cannonPosY + 139, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createMedium(cannonPosX + 27, cannonPosY + 94, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createLight(cannonPosX + 5, cannonPosY + 106, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createLight(cannonPosX + 5, cannonPosY + 112, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createLight(cannonPosX + 5, cannonPosY + 132, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createLight(cannonPosX + 5, cannonPosY + 153, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createLight(cannonPosX + 24, cannonPosY + 106, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createLight(cannonPosX + 24, cannonPosY + 112, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createLight(cannonPosX + 24, cannonPosY + 132, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createLight(cannonPosX + 24, cannonPosY + 154, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createLight(cannonPosX + 4, cannonPosY + 166, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createLight(cannonPosX + 4, cannonPosY + 172, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createLight(cannonPosX + 25, cannonPosY + 166, *MichelangeloBuonarroti));
    MichelangeloBuonarroti->attach(
            factory.createLight(cannonPosX + 25, cannonPosY + 172, *MichelangeloBuonarroti));
    WeaponFactory specialFactory;
    /*
    for (int i = 0; i < numAntiAir; i++)
        MichelangeloBuonarroti->attach(
                specialFactory.createSpecialWeapon(WeaponType::antiAir, *MichelangeloBuonarroti));
    */
    std::shared_ptr<LifeBar> life(new LifeBar(*MichelangeloBuonarroti));
    MichelangeloBuonarroti->attachBar(life);
    return MichelangeloBuonarroti;
}
std::shared_ptr<WarShip>ShipFactory::andreaDoriaBuilder(sf::Vector2i &coordinates){
    CannonFactory factory;
    int shipWidth = 29;
    int shipHeight = 176;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 13;
    //std::shared_ptr<WarShip> AndreaDoria(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 39, 24729, 622, "Italy", 10, 4, 4, numAntiAir,shipHeight,shipWidth,true,ShipType::Battleship, ModelType::AndreaDoria, 0));
    std::shared_ptr<WarShip> AndreaDoria(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 39, 24729,shipHeight,shipWidth,true,"Italy",ShipType::Battleship,ModelType::AndreaDoria,622,"AndreaDoria",10,4,4,numAntiAir));
    AndreaDoria->attach(factory.createHeavly(cannonPosX + 7, cannonPosY + 39, *AndreaDoria));
    AndreaDoria->attach(factory.createHeavly(cannonPosX + 7, cannonPosY + 53, *AndreaDoria));
    AndreaDoria->attach(factory.createHeavly(cannonPosX + 7, cannonPosY + 117, *AndreaDoria));
    AndreaDoria->attach(factory.createHeavly(cannonPosX + 7, cannonPosY + 131, *AndreaDoria));
    AndreaDoria->attach(factory.createMedium(cannonPosX + 4, cannonPosY + 68, *AndreaDoria));
    AndreaDoria->attach(factory.createMedium(cannonPosX + 20, cannonPosY + 68, *AndreaDoria));
    AndreaDoria->attach(factory.createMedium(cannonPosX + 3, cannonPosY + 73, *AndreaDoria));
    AndreaDoria->attach(factory.createMedium(cannonPosX + 21, cannonPosY + 73, *AndreaDoria));
    AndreaDoria->attach(factory.createLight(cannonPosX + 3, cannonPosY + 85, *AndreaDoria));
    AndreaDoria->attach(factory.createLight(cannonPosX + 3, cannonPosY + 91, *AndreaDoria));
    AndreaDoria->attach(factory.createLight(cannonPosX + 3, cannonPosY + 97, *AndreaDoria));
    AndreaDoria->attach(factory.createLight(cannonPosX + 3, cannonPosY + 103, *AndreaDoria));
    AndreaDoria->attach(factory.createLight(cannonPosX + 3, cannonPosY + 109, *AndreaDoria));
    AndreaDoria->attach(factory.createLight(cannonPosX + 22, cannonPosY + 85, *AndreaDoria));
    AndreaDoria->attach(factory.createLight(cannonPosX + 22, cannonPosY + 91, *AndreaDoria));
    AndreaDoria->attach(factory.createLight(cannonPosX + 22, cannonPosY + 97, *AndreaDoria));
    AndreaDoria->attach(factory.createLight(cannonPosX + 22, cannonPosY + 103, *AndreaDoria));
    AndreaDoria->attach(factory.createLight(cannonPosX + 22, cannonPosY + 109, *AndreaDoria));
    WeaponFactory specialFactory;
    /*for (int i = 0; i < numAntiAir; i++)
        AndreaDoria->attach(specialFactory.createSpecialWeapon(WeaponType::antiAir, *AndreaDoria));
*/
    std::shared_ptr<LifeBar> life(new LifeBar(*AndreaDoria));
    AndreaDoria->attachBar(life);
    return AndreaDoria;
}
std::shared_ptr<WarShip>ShipFactory::yamatoBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 40;
    int shipWidth = 41;
    int shipHeight = 263;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    //std::shared_ptr<WarShip> Yamato(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 50, 71659, 1286, "Japan", 12, 3, 2, antiAir,shipHeight,shipWidth,true,ShipType::Battleship, ModelType::Yamato, 3));
    std::shared_ptr<WarShip> Yamato(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 50, 71659,shipHeight,shipWidth,true,"Japan",ShipType::Battleship,ModelType::Yamato,1286,"Yamato",12,2,3,antiAir));
    Yamato->attach(cf.createHeavly(cannonPosX + 13, cannonPosY + 65, *Yamato));
    Yamato->attach(cf.createHeavly(cannonPosX + 13, cannonPosY + 87, *Yamato));
    Yamato->attach(cf.createHeavly(cannonPosX + 14, cannonPosY + 178, *Yamato));
    Yamato->attach(cf.createMedium(cannonPosX + 16, cannonPosY + 176, *Yamato));
    Yamato->attach(cf.createMedium(cannonPosX + 16, cannonPosY + 118, *Yamato));
    Yamato->attach(cf.createLight(cannonPosX + 13, cannonPosY + 161, *Yamato));
    Yamato->attach(cf.createLight(cannonPosX + 13, cannonPosY + 150, *Yamato));
    Yamato->attach(cf.createLight(cannonPosX + 13, cannonPosY + 138, *Yamato));
    Yamato->attach(cf.createLight(cannonPosX + 5, cannonPosY + 157, *Yamato));
    Yamato->attach(cf.createLight(cannonPosX + 5, cannonPosY + 146, *Yamato));
    Yamato->attach(cf.createLight(cannonPosX + 4, cannonPosY + 130, *Yamato));
    Yamato->attach(cf.createLight(cannonPosX + 25, cannonPosY + 161, *Yamato));
    Yamato->attach(cf.createLight(cannonPosX + 25, cannonPosY + 150, *Yamato));
    Yamato->attach(cf.createLight(cannonPosX + 26, cannonPosY + 138, *Yamato));
    Yamato->attach(cf.createLight(cannonPosX + 29, cannonPosY + 157, *Yamato));
    Yamato->attach(cf.createLight(cannonPosX + 29, cannonPosY + 146, *Yamato));
    Yamato->attach(cf.createLight(cannonPosX + 32, cannonPosY + 130, *Yamato));
    /*for (int i = 0; i < antiAir; i++)
        Yamato->attach(factory.createSpecialWeapon(WeaponType::antiAir, *Yamato));
*/
    std::shared_ptr<LifeBar> life(new LifeBar(*Yamato));
    Yamato->attachBar(life);
    return Yamato;
}
std::shared_ptr<WarShip>ShipFactory::iseBuilder(sf::Vector2i &coordinates){
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 19;
    int shipWidth = 43;
    int shipHeight = 220;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    //std::shared_ptr<WarShip> Ise(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 45, 40444, 705, "Japan", 8, 4, 0, antiAir, shipHeight,shipWidth,true,ShipType::Battleship, ModelType::ISE, 2));
    std::shared_ptr<WarShip> Ise(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 45, 40444,shipHeight,shipWidth,true,"Japan",ShipType::Battleship,ModelType::ISE,705,"ISE",8,0,4,antiAir));
    Ise->attach(cf.createHeavly(cannonPosX + 14, cannonPosY + 31, *Ise));
    Ise->attach(cf.createHeavly(cannonPosX + 14, cannonPosY + 45, *Ise));
    Ise->attach(cf.createHeavly(cannonPosX + 14, cannonPosY + 107, *Ise));
    Ise->attach(cf.createHeavly(cannonPosX + 14, cannonPosY + 119, *Ise));
    Ise->attach(cf.createLight(cannonPosX + 9, cannonPosY + 102, *Ise));
    Ise->attach(cf.createLight(cannonPosX + 9, cannonPosY + 80, *Ise));
    Ise->attach(cf.createLight(cannonPosX + 12, cannonPosY + 71, *Ise));
    Ise->attach(cf.createLight(cannonPosX + 12, cannonPosY + 62, *Ise));
    Ise->attach(cf.createLight(cannonPosX + 30, cannonPosY + 102, *Ise));
    Ise->attach(cf.createLight(cannonPosX + 32, cannonPosY + 80, *Ise));
    Ise->attach(cf.createLight(cannonPosX + 28, cannonPosY + 71, *Ise));
    Ise->attach(cf.createLight(cannonPosX + 27, cannonPosY + 62, *Ise));
    /*for (int i = 0; i < antiAir; i++)
        Ise->attach(factory.createSpecialWeapon(WeaponType::antiAir, *Ise));
*/
    std::shared_ptr<LifeBar> life(new LifeBar(*Ise));
    Ise->attachBar(life);
    return Ise;
}
std::shared_ptr<WarShip> ShipFactory::createAlliedDestroyer(ModelType type, int height, int width) {
    sf::Vector2i coordinates = randomizeAlliedPositions(height,width);
    coordinates.y = coordinates.y + (0.14 * height);
    switch (type) {
        case ModelType::Akizuki: {
            std::shared_ptr<WarShip> akizuki = akizukiBuilder(coordinates);
            repositionAlliedShip(akizuki);
            return akizuki;
        }
        case ModelType::Fubuki: {
            std::shared_ptr<WarShip> fubuki = fubukiBuilder(coordinates);
            repositionAlliedShip(fubuki);
            return fubuki;
        }
        case ModelType::Yukikaze: {
            std::shared_ptr<WarShip> yukikaze = yukikazeBuilder(coordinates);
            repositionAlliedShip(yukikaze);
            return yukikaze;
        }
        case ModelType::Impavido: {
            std::shared_ptr<WarShip> impavido = impavidoBuilder(coordinates);
            repositionAlliedShip(impavido);
            return impavido;
        }
        case ModelType::Leone: {
            std::shared_ptr<WarShip> leone = leoneBuilder(coordinates);
            repositionAlliedShip(leone);
            return leone;
        }
        case ModelType::PaoloEmilio: {
            std::shared_ptr<WarShip> paoloEmilio = paoloEmilioBuilder(coordinates);
            repositionAlliedShip(paoloEmilio);
            return paoloEmilio;
        }
        case ModelType::Campbelltown: {
            std::shared_ptr<WarShip> campbelltown = campbeltownBuilder(coordinates);
            repositionAlliedShip(campbelltown);
            return campbelltown;
        }
        case ModelType::Gallant: {
            std::shared_ptr<WarShip> gallant = gallandBuilder(coordinates);
            repositionAlliedShip(gallant);
            return gallant;
        }
        case ModelType::Jutland: {
            std::shared_ptr<WarShip> jutLand = jutlandBuilder(coordinates);
            repositionAlliedShip(jutLand);
            return jutLand;
        }
        case ModelType::Fletcher: {
            std::shared_ptr<WarShip> fletcher = fletcherBuilder(coordinates);
            repositionAlliedShip(fletcher);
            return fletcher;
        }
        case ModelType::Mahan: {
            std::shared_ptr<WarShip> mahan = mahanBuilder(coordinates);
            repositionAlliedShip(mahan);
            return mahan;
        }
        case ModelType::Sims: {
            std::shared_ptr<WarShip> sims = simsBuilder(coordinates);
            repositionAlliedShip(sims);
            return sims;
        }
    }
}
std::shared_ptr<WarShip>ShipFactory::mahanBuilder(sf::Vector2i &coordinates){
    CannonFactory cf;
    int shipWidth = 13;
    int shipHeight = 104;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 8;
    //std::shared_ptr<WarShip> Mahan(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 69, 2137, 27,"Usa", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Mahan, 12));
    std::shared_ptr<WarShip> Mahan(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 69, 2137,shipHeight,shipWidth,true,"Usa",ShipType::Destroyer,ModelType::Mahan,27,"Mahan",0,4,0,numAntiAir));
    Mahan->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 11, *Mahan));
    Mahan->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 37, *Mahan));
    Mahan->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 90, *Mahan));
    Mahan->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 72, *Mahan));
    WeaponFactory wf;
    /*for (int i = 0; i < numAntiAir; i++) {
        Mahan->attach(wf.createSpecialWeapon(WeaponType::antiAir, *Mahan));
    }*/
    std::shared_ptr<LifeBar> life(new LifeBar(*Mahan));
    Mahan->attachBar(life);
    return Mahan;
}
std::shared_ptr<WarShip>ShipFactory::gallandBuilder(sf::Vector2i &coordinates){
    CannonFactory cf;
    int shipWidth = 10;
    int shipHeight = 99;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int numAntiAir = 8;
    //std::shared_ptr<WarShip> Gallant(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 67, 1913, 22,"Uk", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Gallant, 8));
    std::shared_ptr<WarShip> Gallant(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 67, 1913,shipHeight,shipWidth,true,"Uk",ShipType::Destroyer,ModelType::Gallant,22,"Gallant",0,4,0,numAntiAir));
    Gallant->attach(cf.createMedium(cannonPosX + 2, cannonPosY + 14, *Gallant));
    Gallant->attach(cf.createMedium(cannonPosX + 2, cannonPosY + 21, *Gallant));
    Gallant->attach(cf.createMedium(cannonPosX + 2, cannonPosY + 75, *Gallant));
    Gallant->attach(cf.createMedium(cannonPosX + 2, cannonPosY + 81, *Gallant));
    WeaponFactory wf;
    /*for (int i = 0; i < numAntiAir; i++) {
        Gallant->attach(wf.createSpecialWeapon(WeaponType::antiAir, *Gallant));
    }*/
    std::shared_ptr<LifeBar> life(new LifeBar(*Gallant));
    Gallant->attachBar(life);
    return Gallant;
}
std::shared_ptr<WarShip> ShipFactory::campbeltownBuilder(sf::Vector2i &coordinates){
    CannonFactory cf;
    int shipWidth = 10;
    int shipHeight = 96;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 10;
    //std::shared_ptr<WarShip> Campbelltown(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 66, 1280, 19,"Uk", 4, 0, 0, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Campbelltown, 6));
    std::shared_ptr<WarShip> Campbelltown(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 66, 1280,shipHeight,shipWidth,true,"Uk",ShipType::Destroyer,ModelType::Campbelltown,19,"Campbelltown",4,0,0,numAntiAir));
    Campbelltown->attach(cf.createLight(cannonPosX + 3, cannonPosY + 14, *Campbelltown));
    Campbelltown->attach(cf.createLight(cannonPosX + 1, cannonPosY + 40, *Campbelltown));
    Campbelltown->attach(cf.createLight(cannonPosX + 5, cannonPosY + 40, *Campbelltown));
    Campbelltown->attach(cf.createLight(cannonPosX + 3, cannonPosY + 81, *Campbelltown));
    WeaponFactory wf;
    /*for (int i = 0; i < numAntiAir; i++) {
        Campbelltown->attach(wf.createSpecialWeapon(WeaponType::antiAir, *Campbelltown));
    }*/
    std::shared_ptr<LifeBar> life(new LifeBar(*Campbelltown));
    Campbelltown->attachBar(life);
    return Campbelltown;
}
std::shared_ptr<WarShip>ShipFactory::leoneBuilder(sf::Vector2i &coordinates){
    CannonFactory cf;
    int shipWidth = 13;
    int shipHeight = 113;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int numAntiAir = 20;
    std::shared_ptr<WarShip> Leone(new ConcreteWarShip(coordinates.x, coordinates.y,4,61,2326,shipHeight,shipWidth,true,"Italy",ShipType::Destroyer,ModelType::Leone,22,"Leone",0,3,0,numAntiAir));
    Leone->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 33, *Leone));
    Leone->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 74, *Leone));
    Leone->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 100, *Leone));
    WeaponFactory wf;
    /*for (int i = 0; i < numAntiAir; i++) {
        Leone->attach(wf.createSpecialWeapon(WeaponType::antiAir, *Leone));
    }*/
    std::shared_ptr<LifeBar> life(new LifeBar(*Leone));
    Leone->attachBar(life);
    return Leone;
}
std::shared_ptr<WarShip>ShipFactory::fubukiBuilder(sf::Vector2i &coordinates){
    CannonFactory cf;
    int shipWidth = 14;
    int shipHeight = 118;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 20;
    //std::shared_ptr<WarShip> Fubuki(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 70, 2080, 26,"Japan", 0, 0, 6, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Fubuki, 9));
    std::shared_ptr<WarShip> Fubuki(new ConcreteWarShip(coordinates.x,coordinates.y,4,70,2080,shipHeight,shipWidth,true,"Japan",ShipType::Destroyer,ModelType::Fubuki,26,"fubuki",0,6,0,numAntiAir));
    Fubuki->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 15, *Fubuki));
    Fubuki->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 47, *Fubuki));
    Fubuki->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 67, *Fubuki));
    Fubuki->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 78, *Fubuki));
    Fubuki->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 90, *Fubuki));
    Fubuki->attach(cf.createMedium(cannonPosX + 3, cannonPosY + 98, *Fubuki));
    WeaponFactory wf;
    /*for (int i = 0; i < numAntiAir; i++) {
        Fubuki->attach(wf.createSpecialWeapon(WeaponType::antiAir, *Fubuki));
    }*/
    std::shared_ptr<LifeBar> life(new LifeBar(*Fubuki));
    Fubuki->attachBar(life);
    return Fubuki;
}
std::shared_ptr<WarShip>ShipFactory::akizukiBuilder(sf::Vector2i &coordinates){
    CannonFactory cf;
    int shipWidth = 12;
    int shipHeight = 134;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 50;
    //std::shared_ptr<WarShip> Akizuki(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 61, 3759, 33,"Japan", 0, 0, 5, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Akizuki, 4));
    std::shared_ptr<WarShip> Akizuki(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 61, 3759, shipHeight, shipWidth, true, "Japan", ShipType::Destroyer, ModelType::Akizuki, 33, "akizuki", 0, 4, 0, numAntiAir));
    Akizuki->attach(cf.createMedium(cannonPosX + 2, cannonPosY + 22, *Akizuki));
    Akizuki->attach(cf.createMedium(cannonPosX + 2, cannonPosY + 29, *Akizuki));
    Akizuki->attach(cf.createMedium(cannonPosX + 2, cannonPosY + 95, *Akizuki));
    Akizuki->attach(cf.createMedium(cannonPosX + 2, cannonPosY + 104, *Akizuki));
    WeaponFactory wf;
    /*for (int i = 0; i < numAntiAir; i++) {
        Akizuki->attach(wf.createSpecialWeapon(WeaponType::antiAir, *Akizuki));
    }*/
    std::shared_ptr<LifeBar> life(new LifeBar(*Akizuki));
    Akizuki->attachBar(life);
    return Akizuki;
}
sf::Vector2i ShipFactory::randomizeEnemyPositions(int height, int width) {
    Dice percentage(2, offset.x + 1);
    int xMap = width;
    int yMap = height;
    if (offset.y == 0) {
        offset.y = (yMap * 0.28) / 2;
    }
    if (offset.x >= xMap - (xMap * 0.03)) {

        offset.x = ((percentage.roll(1) + 1) * xMap / 100);
        offset.y += (yMap * 0.28) / 2;
    } else {
        offset.x = offset.x + xMap * (0.03) + ((percentage.roll(1) + 1) * xMap / 100);
    }
    return offset;
}
sf::Vector2i ShipFactory::randomizeAlliedPositions(int height, int width) {
    Dice percentage(2, offsetAllied.x + 1);
    int xMap = width;
    int yMap = height;
    if (offsetAllied.y == 0) {
        offsetAllied.y = yMap - (yMap * 0.28) / 2;
    }
    if (offsetAllied.x >= xMap - (xMap * 0.03)) {

        offsetAllied.x = ((percentage.roll(1) + 1) * xMap / 100);
        offsetAllied.y -= yMap * 0.28;
    } else {

        offsetAllied.x = offsetAllied.x + xMap * (0.03) + ((percentage.roll(1) + 1) * xMap / 100);
    }
    return offsetAllied;
}
std::shared_ptr<WarShip> &ShipFactory::repositionEnemyShip(std::shared_ptr<WarShip> &ship) {
    ship->getSprite().setOrigin(ship->getWidth() / 2, ship->getLength() / 2);
    ship->getSprite().rotate(180);
    ship->getSprite().move(0, ship->getLength() / 2);
    if(ship->getShipType()!=ShipType::Submarine) {
        for (auto &it: ship->getArsenalList()) {
            it->getSprite().move(0, ship->getLength() / 2);
            it->getSprite().move((ship->getSprite().getPosition().x - it->getSprite().getPosition().x) * 2,(ship->getSprite().getPosition().y - it->getSprite().getPosition().y) * 2);
            it->getSprite().move(-(it->getWidth()/2),-(it->getLength()/2));
            it->getSprite().rotate(180);
        }
    }
    if(ConcreteAircraftCarrier * pShip = dynamic_cast<ConcreteAircraftCarrier*> (ship.get())) {
        for (auto &it: pShip->getPlanes()) {
            it->getSprite().move(0, ship->getLength() / 2);
            it->getSprite().move((ship->getSprite().getPosition().x - it->getSprite().getPosition().x) * 2,
                                 (ship->getSprite().getPosition().y - it->getSprite().getPosition().y) * 2);
            it->getSprite().rotate(180);
        }
    }
    ship->setTargetCoordinates(ship->getSprite().getPosition());
    ship->notifyBars();
    for(auto &it: ship->getBars()){
        it->repositionBar(ship->getSprite().getPosition(), true);
    }
    return ship;
}
std::shared_ptr<WarShip> &ShipFactory::repositionAlliedShip(std::shared_ptr<WarShip> &ship) {
    ship->getSprite().setOrigin(ship->getWidth() / 2, ship->getLength() / 2);
    ship->getSprite().setPosition(ship->getSprite().getPosition().x,ship->getSprite().getPosition().y-(ship->getLength()/2));
    if(ship->getShipType()!=ShipType::Submarine) {
        for (auto &it: ship->getArsenalList()) {
            it->getSprite().setPosition(it->getSprite().getPosition().x,it->getSprite().getPosition().y-(ship->getLength()/2));
            it->getSprite().move((it->getWidth()/2),(it->getLength()/2));
        }
    }
    if(ConcreteAircraftCarrier * pShip = dynamic_cast<ConcreteAircraftCarrier*> (ship.get())) {
        for (auto &it: pShip->getPlanes()) {
            it->getSprite().setPosition(it->getSprite().getPosition().x,it->getSprite().getPosition().y-(ship->getLength()/2));
        }
    }
    ship->setTargetCoordinates(ship->getSprite().getPosition());
    ship->notifyBars();
    for(auto &it: ship->getBars()){
        it->repositionBar(ship->getSprite().getPosition());
    }
    return ship;
}