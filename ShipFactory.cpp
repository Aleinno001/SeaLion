//
// Created by alessandro on 7/2/21.
//

#include "ShipFactory.h"
#include "GameWorld.h"
#include "AirplaneFactory.h"
#include "LifeBar.h"
#include "ConcreteAircraftCarrier.h"
#include "Submarine.h"


std::shared_ptr<ConcreteWarShip> ShipFactory::createSubmarine(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {
        case ModelType::I400: {
            std::shared_ptr<ConcreteWarShip> i400 = i400Builder(coordinates);
            repositionEnemyShip(i400);
            return std::move(i400);
        }
        case ModelType::typeb1: {
            std::shared_ptr<ConcreteWarShip> typeb1 = typeb1Builder(coordinates);
            repositionEnemyShip(typeb1);
            return std::move(typeb1);
        }
        case ModelType::DaVinci: {
            std::shared_ptr<ConcreteWarShip> daVinci = DaVinciBuilder(coordinates);
            repositionEnemyShip(daVinci);
            return std::move(daVinci);
        }
        case ModelType::Papa: {
            std::shared_ptr<ConcreteWarShip> papa = papaBuilder(coordinates);
            repositionEnemyShip(papa);
            return std::move(papa);
        }
        case ModelType::Triton: {
            std::shared_ptr<ConcreteWarShip> triton = tritonBuilder(coordinates);
            repositionEnemyShip(triton);
            return std::move(triton);
        }
        case ModelType::Trenchant: {
            std::shared_ptr<ConcreteWarShip> trenchant = trenchantBuilder(coordinates);
            repositionEnemyShip(trenchant);
            return std::move(trenchant);
        }
        case ModelType::Gato: {
            std::shared_ptr<ConcreteWarShip> gato = gatoBuilder(coordinates);
            repositionEnemyShip(gato);
            return std::move(gato);
        }
        case ModelType::Narwhal: {
            std::shared_ptr<ConcreteWarShip> narwhal = narwhalBuilder(coordinates);
            repositionEnemyShip(narwhal);
            return std::move(narwhal);
        }
    }
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::gatoBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 9;
    int shipHeight = 95;
    std::shared_ptr<ConcreteWarShip> Gato(new Submarine(coordinates.x, coordinates.y, 2, 37, 2460,shipHeight,shipWidth,true,(std::string &)"Usa",ShipType::Submarine,ModelType::Gato,0,(std::string &)"gato",0,0,0,0));
    for (int i = 0; i < 6; i++)
        Gato->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *Gato)));
    std::shared_ptr<LifeBar> life(new LifeBar(*Gato));
    Gato->attachBar(life);
    return Gato;
}

std::shared_ptr<ConcreteWarShip>
ShipFactory::tritonBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 8;
    int shipHeight = 84;
    std::shared_ptr<ConcreteWarShip> Triton(new Submarine(coordinates.x, coordinates.y, 2, 28, 1576,shipHeight,shipWidth,true,(std::string &)"Uk",ShipType::Submarine,ModelType::Triton,0,(std::string &)"triton",0,0,0,0));
    for (int i = 0; i < 6; i++)
        Triton->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *Triton)));
    std::shared_ptr<LifeBar> life(new LifeBar(*Triton));
    Triton->attachBar(life);
    return Triton;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::DaVinciBuilder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 9;
    int shipHeight = 77;
    std::shared_ptr<ConcreteWarShip> DaVinci(new Submarine(coordinates.x, coordinates.y, 2, 15, 1489,shipHeight,shipWidth,true,(std::string &)"Italy",ShipType::Submarine,ModelType::DaVinci,0,(std::string &)"daVinci",0,0,0,0));
    for (int i = 0; i < 8; i++)
        DaVinci->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *DaVinci)));
    std::shared_ptr<LifeBar> life(new LifeBar(*DaVinci));
    DaVinci->attachBar(life);
    return DaVinci;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::typeb1Builder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 10;
    int shipHeight = 111;
    std::shared_ptr<ConcreteWarShip> typeb1(new Submarine(coordinates.x, coordinates.y, 2, 44, 3713,shipHeight,shipWidth,true,(std::string &)"Japan",ShipType::Submarine,ModelType::typeb1,0,(std::string &)"typeb1",0,0,0,0));
    for (int i = 0; i < 6; i++)
        typeb1->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *typeb1)));
    std::shared_ptr<LifeBar> life(new LifeBar(*typeb1));
    typeb1->attachBar(life);
    return typeb1;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::i400Builder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 13;
    int shipHeight = 122;
    std::shared_ptr<ConcreteWarShip> i400(new Submarine(coordinates.x, coordinates.y, 2, 35, 6670,shipHeight,shipWidth,true,(std::string &)"Japan",ShipType::Submarine,ModelType::I400,0,(std::string &)"i400",0,0,0,0));
    for (int i = 0; i < 8; i++)
        i400->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *i400)));
    std::shared_ptr<LifeBar> life(new LifeBar(*i400));
    i400->attachBar(life);
    return i400;
}
std::shared_ptr<ConcreteWarShip> ShipFactory::createAircraftCarrier(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {
        case ModelType::Tahio: {
            std::shared_ptr<ConcreteWarShip> tahio = tahioBuilder(coordinates);
            repositionEnemyShip(tahio);
            return std::move(tahio);
        }
        case ModelType::Hiryu: {
            std::shared_ptr<ConcreteWarShip> hiryu = hiryuBuilder(coordinates);
            repositionEnemyShip(hiryu);
            return std::move(hiryu);
        }
        case ModelType::GiuseppeGaribaldi: {
            std::shared_ptr<ConcreteWarShip> giuseppeGaribaldi = giuseppeGaribaldiBuilder(coordinates);
            repositionEnemyShip(giuseppeGaribaldi);
            return std::move(giuseppeGaribaldi);
        }
        case ModelType::Cavour: {
            std::shared_ptr<ConcreteWarShip> cavour = cavourBuilder(coordinates);
            repositionEnemyShip(cavour);
            return std::move(cavour);
        }
        case ModelType::ArkRoyal: {
            std::shared_ptr<ConcreteWarShip> arkRoyal = arkRoyalBuilder(coordinates);
            repositionEnemyShip(arkRoyal);
            return std::move(arkRoyal);
        }
        case ModelType::Indomitable: {

            std::shared_ptr<ConcreteWarShip> indomitable = indomitableBuilder(coordinates);
            repositionEnemyShip(indomitable);
            return std::move(indomitable);
        }
        case ModelType::Midway: {
            std::shared_ptr<ConcreteWarShip> midway = midwayBuilder(coordinates);
            repositionEnemyShip(midway);
            return std::move(midway);
        }
        case ModelType::FranklinDRoosevelt: {
            std::shared_ptr<ConcreteWarShip> franklinDRoosevelt = franklinDelanoRoosveltBuilder(coordinates);
            repositionEnemyShip(franklinDRoosevelt);
            return std::move(franklinDRoosevelt);
        }
    }
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::midwayBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 84;
    int shipHeight = 296;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    WeaponFactory specialFactory;
    int numAntiAir = 15;
    std::shared_ptr<ConcreteWarShip> mid(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 61, 640000, 520,
                                                             "Usa", 2, 0, 0, numAntiAir, shipHeight, shipWidth,
                                                             true,
                                                             ShipType::AircraftCarrier, ModelType::Midway, 13));
    mid->attach(std::move(factory.createMedium(cannonPosX + 72, cannonPosY + 187, *mid)));
    mid->attach(std::move(factory.createMedium(cannonPosX + 14, cannonPosY + 230, *mid)));
    mid->attach(std::move(factory.createMedium(cannonPosX + 69, cannonPosY + 100, *mid)));
    mid->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+44,cannonPosY+10, "Usa", *mid)));
    mid->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+44,cannonPosY+30,"Usa",*mid)));
    mid->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+44,cannonPosY+50,"Usa",*mid)));
    mid->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+44,cannonPosY+70,"Usa",*mid)));
    mid->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+44,cannonPosY+90,"Usa",*mid)));
    mid->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+44,cannonPosY+117,"Usa",*mid)));
    mid->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+44,cannonPosY+137,"Usa",*mid)));
    mid->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+44,cannonPosY+157,"Usa",*mid)));
    mid->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+44,cannonPosY+177,"Usa",*mid)));
    mid->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+44,cannonPosY+197,"Usa",*mid)));
    mid->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+44,cannonPosY+217,"Usa",*mid)));
    mid->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+44,cannonPosY+237,"Usa",*mid)));
    mid->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+44,cannonPosY+257,"Usa",*mid)));
    mid->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+44,cannonPosY+278,"Usa",*mid)));
    for (int i = 0; i < numAntiAir; i++)
        mid->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir,*mid)));
    std::shared_ptr<LifeBar> life(new LifeBar(*mid));
    mid->attachBar(life);
    return mid;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::arkRoyalBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 38;
    int shipHeight = 240;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    WeaponFactory specialFactory;
    int numAntiAir = 4;
    std::shared_ptr<ConcreteWarShip> arkRoyal(
            new ConcreteWarShip(coordinates.x, coordinates.y, 1, 56, 28160, 20,
                                "Uk", 2, 0, 0, numAntiAir, shipHeight, shipWidth, true, ShipType::AircraftCarrier,
                                ModelType::ArkRoyal, 7));
    arkRoyal->attach(std::move(factory.createLight(cannonPosX + 7, cannonPosY + 85, *arkRoyal)));
    arkRoyal->attach(std::move(factory.createLight(cannonPosX + 28, cannonPosY + 85, *arkRoyal)));
    arkRoyal->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+19,cannonPosY+15,"Uk",*arkRoyal)));
    arkRoyal->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+19,cannonPosY+40,"Uk",*arkRoyal)));
    arkRoyal->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+19,cannonPosY+65,"Uk",*arkRoyal)));
    arkRoyal->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+19,cannonPosY+94,"Uk",*arkRoyal)));
    arkRoyal->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+19,cannonPosY+130,"Uk",*arkRoyal)));
    arkRoyal->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+19,cannonPosY+166,"Uk",*arkRoyal)));
    arkRoyal->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+19,cannonPosY+206,"Uk",*arkRoyal)));
    for (int i = 0; i < numAntiAir; i++)
        arkRoyal->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *arkRoyal)));
    std::shared_ptr<LifeBar> life(new LifeBar(*arkRoyal));
    arkRoyal->attachBar(life);
    return arkRoyal;
}
std::shared_ptr<ConcreteWarShip> ShipFactory::giuseppeGaribaldiBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 44;
    int shipHeight = 180;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    std::shared_ptr<ConcreteWarShip> GiuseppeGaribaldi(
            new ConcreteWarShip(coordinates.x, coordinates.y, 1, 56, 14150, 114, "Italy", 3, 0, 0, 0, shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::GiuseppeGaribaldi, 6));
    GiuseppeGaribaldi->attach(std::move(factory.createLight(cannonPosX + 4, cannonPosY + 41, *GiuseppeGaribaldi)));
    GiuseppeGaribaldi->attach(std::move(factory.createLight(cannonPosX + 4, cannonPosY + 69, *GiuseppeGaribaldi)));
    GiuseppeGaribaldi->attach(std::move(factory.createLight(cannonPosX + 4, cannonPosY + 98, *GiuseppeGaribaldi)));
    GiuseppeGaribaldi->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+15,cannonPosY+14,"Italy",*GiuseppeGaribaldi)));
    GiuseppeGaribaldi->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+15,cannonPosY+40,"Italy",*GiuseppeGaribaldi)));
    GiuseppeGaribaldi->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+15,cannonPosY+65,"Italy",*GiuseppeGaribaldi)));
    GiuseppeGaribaldi->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+15,cannonPosY+94,"Italy",*GiuseppeGaribaldi)));
    GiuseppeGaribaldi->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+15,cannonPosY+130,"Italy",*GiuseppeGaribaldi)));
    GiuseppeGaribaldi->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+15,cannonPosY+166,"Italy",*GiuseppeGaribaldi)));
    std::shared_ptr<LifeBar> life(new LifeBar(*GiuseppeGaribaldi));
    GiuseppeGaribaldi->attachBar(life);
    return GiuseppeGaribaldi;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::tahioBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 46;
    int shipHeight = 260;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    WeaponFactory specialFactory;
    int numAntiAir = 20;
    std::shared_ptr<ConcreteWarShip> Tahio(
            new ConcreteWarShip(coordinates.x, coordinates.y, 1, 61, 37866, 304, "Japan", 2, 0, 0, numAntiAir,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::Tahio, 7));
    Tahio->attach(std::move(factory.createLight(cannonPosX + 20, cannonPosY + 55, *Tahio)));
    Tahio->attach(std::move(factory.createLight(cannonPosX + 20, cannonPosY + 218, *Tahio)));
    Tahio->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+22,cannonPosY+14,"Japan",*Tahio)));
    Tahio->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+22,cannonPosY+40,"Japan",*Tahio)));
    Tahio->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+22,cannonPosY+65,"Japan",*Tahio)));
    Tahio->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+22,cannonPosY+94,"Japan",*Tahio)));
    Tahio->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+22,cannonPosY+130,"Japan",*Tahio)));
    Tahio->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+22,cannonPosY+166,"Japan",*Tahio)));
    Tahio->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+22,cannonPosY+206,"Japan",*Tahio)));
    for (int i = 0; i < numAntiAir; i++)
        Tahio->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *Tahio)));
    std::shared_ptr<LifeBar> life(new LifeBar(*Tahio));
    Tahio->attachBar(life);
    return Tahio;
}
std::shared_ptr<WarShip> ShipFactory::createCruiser(ModelType type, GameWorld &map) {
    std::list<std::shared_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {
        case ModelType::Takao: {
            std::shared_ptr<ConcreteWarShip> takao = takaoBuilder(coordinates);
            repositionEnemyShip(takao);
            return std::move(takao);
        }
        case ModelType::IsuzuNagara: {
            std::shared_ptr<ConcreteWarShip> isuzuNagara = isuzuNagaraBuilder(coordinates);
            repositionEnemyShip(isuzuNagara);
            return std::move(isuzuNagara);
        }
        case ModelType::Ijn: {
            std::shared_ptr<ConcreteWarShip> ijn = ijnBuilder(coordinates);
            repositionEnemyShip(ijn);
            return std::move(ijn);
        }
        case ModelType::AlbertoDiGiussano: {
            std::shared_ptr<ConcreteWarShip> albertoDiGiussano = albertoDiGiussanoBuilder(coordinates);
            repositionEnemyShip(albertoDiGiussano);
            return std::move(albertoDiGiussano);
        }
        case ModelType::Gorizia: {
            std::shared_ptr<ConcreteWarShip> gorizia = goriziaBuilder(coordinates);
            repositionEnemyShip(gorizia);
            return std::move(gorizia);
        }
        case ModelType::Trento: {
            std::shared_ptr<ConcreteWarShip> trento = trentoBuilder(coordinates);
            repositionEnemyShip(trento);
            return std::move(trento);
        }
        case ModelType::Belfast: {
            std::shared_ptr<ConcreteWarShip> belfast = belfastBuilder(coordinates);
            repositionEnemyShip(belfast);
            return std::move(belfast);
        }
        case ModelType::Danae: {
            std::shared_ptr<ConcreteWarShip> danae = danaeBuilder(coordinates);
            repositionEnemyShip(danae);
            return std::move(danae);
        }
        case ModelType::Tiger59: {
            std::shared_ptr<ConcreteWarShip> tiger59 = tiger59Builder(coordinates);
            repositionEnemyShip(tiger59);
            return std::move(tiger59);
        }
        case ModelType::Alaska: {
            std::shared_ptr<ConcreteWarShip> alaska = alaskaBuilder(coordinates);
            repositionEnemyShip(alaska);
            return std::move(alaska);
        }
        case ModelType::NewOrleans: {
            std::shared_ptr<ConcreteWarShip> newOrleans = newOrleansBuilder(coordinates);
            repositionEnemyShip(newOrleans);
            return std::move(newOrleans);
        }
        case ModelType::StLouis: {
            std::shared_ptr<ConcreteWarShip> saintLouis = stLouisBuilder(coordinates);
            repositionEnemyShip(saintLouis);
            return std::move(saintLouis);
        }
    }
}
std::shared_ptr<ConcreteWarShip>ShipFactory::stLouisBuilder(sf::Vector2i &coordinates) const {
    int shipWidth = 20;
    int shipHeight = 130;
    int cannonPosX =coordinates.x -(shipWidth) /2;
    int cannonPosY = coordinates.y -(shipHeight) /2;
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 8;
    std::shared_ptr<ConcreteWarShip> saintLouis (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 41, 11013, shipHeight, shipWidth, true, (std::string&) "Usa", ShipType::Cruiser, ModelType::StLouis, 280, "stLouis", 5, 3, 0, antiAir));
    saintLouis->attach(std::move(cf.createMedium(cannonPosX +7,cannonPosY +21, *saintLouis)));
    saintLouis->attach(std::move(cf.createMedium(cannonPosX +7,cannonPosY +34, *saintLouis)));
    saintLouis->attach(std::move(cf.createMedium(cannonPosX +7,cannonPosY +111, *saintLouis)));
    saintLouis->attach(std::move(cf.createLight(cannonPosX +1,cannonPosY +71, *saintLouis)));
    saintLouis->attach(std::move(cf.createLight(cannonPosX +15,cannonPosY +71, *saintLouis)));
    saintLouis->attach(std::move(cf.createLight(cannonPosX +8,cannonPosY +80, *saintLouis)));
    saintLouis->attach(std::move(cf.createLight(cannonPosX +2,cannonPosY +41, *saintLouis)));
    saintLouis->attach(std::move(cf.createLight(cannonPosX +16,cannonPosY +41, *saintLouis)));
    for (int i = 0;i < antiAir; i++)
        saintLouis->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *saintLouis)));
    std::shared_ptr<LifeBar> life(new LifeBar(*saintLouis));
    saintLouis->attachBar(life);
    return saintLouis;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::alaskaBuilder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 28;
    int shipHeight = 246;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    CannonFactory cf;
    int antiAir = 9;
    std::shared_ptr<ConcreteWarShip> alaska (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 61, 34803, shipHeight, shipWidth, true, (std::string&) "Usa", ShipType::Cruiser, ModelType::Alaska, 918, "alaska", 6, 2, 1, antiAir));
    alaska->attach(std::move(cf.createHeavly(cannonPosX + 6, cannonPosY + 179, *alaska)));
    alaska->attach(std::move(cf.createMedium(cannonPosX + 11, cannonPosY + 60, *alaska)));
    alaska->attach(std::move(cf.createMedium(cannonPosX + 11, cannonPosY + 77, *alaska)));
    alaska->attach(std::move(cf.createLight(cannonPosX + 11, cannonPosY + 91, *alaska)));
    alaska->attach(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 105, *alaska)));
    alaska->attach(std::move(cf.createLight(cannonPosX + 23, cannonPosY + 105, *alaska)));
    alaska->attach(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 149, *alaska)));
    alaska->attach(std::move(cf.createLight(cannonPosX + 23, cannonPosY + 150, *alaska)));
    alaska->attach(std::move(cf.createLight(cannonPosX + 11, cannonPosY + 172, *alaska)));
    for (int i = 0; i < antiAir; i++)
        alaska->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *alaska)));
    std::shared_ptr<LifeBar> life(new LifeBar(*alaska));
    alaska->attachBar(life);
    return alaska;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::danaeBuilder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 14;
    int shipHeight = 136;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    CannonFactory cf;
    int antiAir = 7;
    std::shared_ptr<ConcreteWarShip> danae (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 54, 5925, shipHeight, shipWidth, true, (std::string&) "Uk", ShipType::Cruiser, ModelType::Danae, 190, "danae", 6, 1, 0, antiAir));
    danae->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 111, *danae)));
    danae->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 102, *danae)));
    danae->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 120, *danae)));
    danae->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 74, *danae)));
    danae->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 45, *danae)));
    danae->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 33, *danae)));
    danae->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 19, *danae)));
    for (int i = 0; i < antiAir; i++)
        danae->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *danae)));
    std::shared_ptr<LifeBar> life(new LifeBar(*danae));
    danae->attachBar(life);
    return danae;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::trentoBuilder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 25;
    int shipHeight = 197;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    CannonFactory cf;
    int antiAir = 12;
    std::shared_ptr<ConcreteWarShip> trento (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 66, 13548, shipHeight, shipWidth, true, (std::string&) "Italy", ShipType::Cruiser, ModelType::Trento, 120, "trento", 6, 4, 0, antiAir));
    trento->attach(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 44, *trento)));
    trento->attach(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 52, *trento)));
    trento->attach(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 143, *trento)));
    trento->attach(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 153, *trento)));
    trento->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 68, *trento)));
    trento->attach(std::move(cf.createLight(cannonPosX + 15, cannonPosY + 68, *trento)));
    trento->attach(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 84, *trento)));
    trento->attach(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 84, *trento)));
    trento->attach(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 111, *trento)));
    trento->attach(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 111, *trento)));
    for (int i = 0; i < antiAir; i++)
        trento->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *trento)));

    std::shared_ptr<LifeBar> life(new LifeBar(*trento));
    trento->attachBar(life);
    return trento;
}
std::shared_ptr<ConcreteWarShip> ShipFactory::albertoDiGiussanoBuilder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 15;
    int shipHeight = 169;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    CannonFactory cf;
    int antiAir = 12;
    std::shared_ptr<ConcreteWarShip> albertoDiGiussano (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 69, 6950, shipHeight, shipWidth, true, (std::string&) "Italy", ShipType::Cruiser, ModelType::AlbertoDiGiussano, 84, "albertoDiGiussano", 3, 4, 0, antiAir));
    albertoDiGiussano->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 18, *albertoDiGiussano)));
    albertoDiGiussano->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 28, *albertoDiGiussano)));
    albertoDiGiussano->attach(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 121, *albertoDiGiussano)));
    albertoDiGiussano->attach(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 135, *albertoDiGiussano)));
    albertoDiGiussano->attach(std::move(cf.createLight(cannonPosX, cannonPosY + 93, *albertoDiGiussano)));
    albertoDiGiussano->attach(std::move(cf.createLight(cannonPosX + 10, cannonPosY + 93, *albertoDiGiussano)));
    albertoDiGiussano->attach(std::move(cf.createLight(cannonPosX + 6, cannonPosY + 112, *albertoDiGiussano)));
    for (int i = 0; i < antiAir; i++)
        albertoDiGiussano->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *albertoDiGiussano)));
    std::shared_ptr<LifeBar> life(new LifeBar(*albertoDiGiussano));
    albertoDiGiussano->attachBar(life);
    return albertoDiGiussano;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::takaoBuilder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 25;
    int shipHeight = 193;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    CannonFactory cf;
    int antiAir = 16;
    std::shared_ptr<ConcreteWarShip> takao (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 66, 15500, shipHeight, shipWidth, true, (std::string&) "Japan", ShipType::Cruiser, ModelType::Takao, 237, "takao", 4, 5, 0, antiAir));
    takao->attach(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 36, *takao)));
    takao->attach(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 44, *takao)));
    takao->attach(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 53, *takao)));
    takao->attach(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 137, *takao)));
    takao->attach(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 145, *takao)));
    takao->attach(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 82, *takao)));
    takao->attach(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 82, *takao)));
    takao->attach(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 96, *takao)));
    takao->attach(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 96, *takao)));
    for (int i = 0; i < antiAir; i++)
        takao->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *takao)));
    std::shared_ptr<LifeBar> life(new LifeBar(*takao));
    takao->attachBar(life);
    return takao;
}
std::shared_ptr<ConcreteWarShip> ShipFactory::createBattleship(ModelType type, GameWorld &map) {
    std::list<std::shared_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {
        case ModelType::Yamato: {
            std::shared_ptr<ConcreteWarShip> yamato = yamatoBuilder(coordinates);
            repositionEnemyShip(yamato);
            return std::move(yamato);
        }
        case ModelType::Kongo: {
            std::shared_ptr<ConcreteWarShip> kongo = kongoBuilder(coordinates);
            repositionEnemyShip(kongo);
            return std::move(kongo);
        }
        case ModelType::ISE: {
            std::shared_ptr<ConcreteWarShip> ise = iseBuilder(coordinates);
            repositionEnemyShip(ise);
            return std::move(ise);
        }
        case ModelType::Musashi: {
            std::shared_ptr<ConcreteWarShip> musashi = musashiBuilder(coordinates);
            repositionEnemyShip(musashi);
            return std::move(musashi);
        }
        case ModelType::AndreaDoria: {
            std::shared_ptr<ConcreteWarShip> andreaDoria = andreaDoriaBuilder(coordinates);
            repositionEnemyShip(andreaDoria);
            return std::move(andreaDoria);
        }
        case ModelType::ImperatoreAugusto: {
            std::shared_ptr<ConcreteWarShip> imperatoreAugusto = imperatoreAugustoBuilder(coordinates);
            repositionEnemyShip(imperatoreAugusto);
            return std::move(imperatoreAugusto);
        }
        case ModelType::VittorioVeneto: {
            std::shared_ptr<ConcreteWarShip> vittorioVeneto = vittorioVenetoBuilder(coordinates);
            repositionEnemyShip(vittorioVeneto);
            return std::move(vittorioVeneto);
        }
        case ModelType::MichelangeloBuonarroti: {
            std::shared_ptr<ConcreteWarShip> michelangeloBuonarroti = michelangeloBuonarrotiBuilder(coordinates);
            repositionEnemyShip(michelangeloBuonarroti);
            return std::move(michelangeloBuonarroti);
        }
        case ModelType::Dreadnought: {
            std::shared_ptr<ConcreteWarShip> dreadNought = dreadNoughtBuilder(coordinates);
            repositionEnemyShip(dreadNought);
            return std::move(dreadNought);
        }
        case ModelType::IronDuke: {
            std::shared_ptr<ConcreteWarShip> ironDuke = ironDukeBuilder(coordinates);
            repositionEnemyShip(ironDuke);
            return std::move(ironDuke);
        }
        case ModelType::Lion: {
            std::shared_ptr<ConcreteWarShip> lion = lionBuilder(coordinates);
            repositionEnemyShip(lion);
            return std::move(lion);
        }
        case ModelType::Hood: {
            std::shared_ptr<ConcreteWarShip> hood = hoodBuilder(coordinates);
            repositionEnemyShip(hood);
            return std::move(hood);
        }
        case ModelType::Arizona: {
            std::shared_ptr<ConcreteWarShip> arizona = arizonaBuilder(coordinates);
            repositionEnemyShip(arizona);
            return std::move(arizona);
        }
        case ModelType::Montana: {
            std::shared_ptr<ConcreteWarShip> montana = montanaBuilder(coordinates);
            repositionEnemyShip(montana);
            return std::move(montana);
        }
        case ModelType::NewYork: {
            std::shared_ptr<ConcreteWarShip> newYork = newYorkBuilder(coordinates);
            repositionEnemyShip(newYork);
            return std::move(newYork);
        }
        case ModelType::NorthCarolina: {
            std::shared_ptr<ConcreteWarShip> northCarolina = northCarolinaBuilder(coordinates);
            repositionEnemyShip(northCarolina);
            return std::move(northCarolina);
        }
    }
    return std::shared_ptr<ConcreteWarShip>(); //TODO implementare tutti i costruttori
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::ironDukeBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 190;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 15;
    std::shared_ptr<ConcreteWarShip> ironDuke (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 39, 29500, shipHeight, shipWidth, true, (std::string&) "Uk", ShipType::Battleship, ModelType::IronDuke, 826, "ironDuke", 0, 0, 5, numAntiAir));
    ironDuke->attach(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 35, *ironDuke)));
    ironDuke->attach(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 49, *ironDuke)));
    ironDuke->attach(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 101, *ironDuke)));
    ironDuke->attach(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 127, *ironDuke)));
    ironDuke->attach(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 135, *ironDuke)));
    WeaponFactory specialFactory;
    for (int i = 0; i < numAntiAir; i++)
        ironDuke->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *ironDuke)));
    std::shared_ptr<LifeBar> life(new LifeBar(*ironDuke));
    ironDuke->attachBar(life);
    return ironDuke;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::northCarolinaBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 32;
    int shipHeight = 222;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 34;
    std::shared_ptr<ConcreteWarShip> northCarolina (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 52, 45500, shipHeight, shipWidth, true, (std::string&) "Usa", ShipType::Battleship, ModelType::NorthCarolina, 1224, "northCarolina", 6, 0, 2, numAntiAir));
    northCarolina->attach(std::move(factory.createHeavly(cannonPosX + 8, cannonPosY + 50, *northCarolina)));
    northCarolina->attach(std::move(factory.createHeavly(cannonPosX + 8, cannonPosY + 139, *northCarolina)));
    northCarolina->attach(std::move(factory.createHeavly(cannonPosX + 8, cannonPosY + 165, *northCarolina)));
    northCarolina->attach(std::move(factory.createLight(cannonPosX + 5, cannonPosY + 81, *northCarolina)));
    northCarolina->attach(std::move(factory.createLight(cannonPosX + 22, cannonPosY + 81, *northCarolina)));
    northCarolina->attach(std::move(factory.createLight(cannonPosX + 5, cannonPosY + 101, *northCarolina)));
    northCarolina->attach(std::move(factory.createLight(cannonPosX + 22, cannonPosY + 101, *northCarolina)));
    northCarolina->attach(std::move(factory.createLight(cannonPosX + 1, cannonPosY + 111, *northCarolina)));
    northCarolina->attach(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 111, *northCarolina)));
    WeaponFactory specialFactory;
    for (int i = 0; i < numAntiAir; i++)
        northCarolina->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *northCarolina)));
    std::shared_ptr<LifeBar> life(new LifeBar(*northCarolina));
    northCarolina->attachBar(life);
    return northCarolina;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::montanaBuilder(
        sf::Vector2i &coordinates) const {
    //TODO concludere tutte le aggiunte necessarie
    CannonFactory factory;
    int shipWidth = 37;
    int shipHeight = 281;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int numAntiAir = 80;
    std::shared_ptr<ConcreteWarShip> montana (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 52, 72104, shipHeight, shipWidth, true, (std::string&) "Usa", ShipType::Battleship, ModelType::Montana, 1810, "montana", 0, 10, 4, numAntiAir));
    montana->attach(std::move(factory.createHeavly(cannonPosX + 11, cannonPosY + 54, *montana)));
    montana->attach(std::move(factory.createHeavly(cannonPosX + 11, cannonPosY + 82, *montana)));
    montana->attach(std::move(factory.createHeavly(cannonPosX + 11, cannonPosY + 177, *montana)));
    montana->attach(std::move(factory.createHeavly(cannonPosX + 11, cannonPosY + 204, *montana)));
    montana->attach(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 111, *montana)));
    montana->attach(std::move(factory.createMedium(cannonPosX + 30, cannonPosY + 111, *montana)));
    montana->attach(std::move(factory.createMedium(cannonPosX + 5, cannonPosY + 125, *montana)));
    montana->attach(std::move(factory.createMedium(cannonPosX + 27, cannonPosY + 125, *montana)));
    montana->attach(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 138, *montana)));
    montana->attach(std::move(factory.createMedium(cannonPosX + 30, cannonPosY + 138, *montana)));
    montana->attach(std::move(factory.createMedium(cannonPosX + 4, cannonPosY + 152, *montana)));
    montana->attach(std::move(factory.createMedium(cannonPosX + 27, cannonPosY + 152, *montana)));
    montana->attach(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 165, *montana)));
    montana->attach(std::move(factory.createMedium(cannonPosX + 30, cannonPosY + 165, *montana)));
    WeaponFactory specialFactory;
    for (int i = 0; i < numAntiAir; i++)
        montana->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *montana)));
    std::shared_ptr<LifeBar> life(new LifeBar(*montana));
    montana->attachBar(life);
    return montana;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::lionBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 242;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 10;
    std::shared_ptr<ConcreteWarShip> lion (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 52, 49670, shipHeight, shipWidth, true, (std::string&) "Uk", ShipType::Battleship, ModelType::Lion, 944, "lion", 0, 0, 4, numAntiAir));
    lion->attach(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 43, *lion)));
    lion->attach(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 58, *lion)));
    lion->attach(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 120, *lion)));
    lion->attach(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 191, *lion)));
    WeaponFactory specialFactory;
    for (int i = 0; i < numAntiAir; i++)
        lion->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *lion)));
    std::shared_ptr<LifeBar> life(new LifeBar(*lion));
    lion->attachBar(life);
    return lion;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::dreadNoughtBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 25;
    int shipHeight = 158;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 20;
    std::shared_ptr<ConcreteWarShip> dreadNought (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 39, 21060, shipHeight, shipWidth, true, (std::string&) "Uk", ShipType::Battleship, ModelType::Dreadnought, 837, "dreadNought", 0, 0, 5, numAntiAir));
    dreadNought->attach(std::move(factory.createHeavly(cannonPosX + 5, cannonPosY + 32, *dreadNought)));
    dreadNought->attach(std::move(factory.createHeavly(cannonPosX + 5, cannonPosY + 87, *dreadNought)));
    dreadNought->attach(std::move(factory.createHeavly(cannonPosX + 5, cannonPosY + 112, *dreadNought)));
    dreadNought->attach(std::move(factory.createHeavly(cannonPosX - 1, cannonPosY + 58, *dreadNought)));
    dreadNought->attach(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 58, *dreadNought)));
    WeaponFactory specialFactory;
    for (int i = 0; i < numAntiAir; i++)
        dreadNought->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *dreadNought)));
    std::shared_ptr<LifeBar> life(new LifeBar(*dreadNought));
    dreadNought->attachBar(life);
    return dreadNought;
}
std::shared_ptr<ConcreteWarShip> ShipFactory::imperatoreAugustoBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 274;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 12;
    std::shared_ptr<ConcreteWarShip> imperatoreAugusto (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 57, 65232, shipHeight, shipWidth, true, (std::string&) "Italy", ShipType::Battleship, ModelType::ImperatoreAugusto, 1126, "imperatoreAugusto", 16, 10, 4, numAntiAir));
    imperatoreAugusto->attach(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 61, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 80, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 179, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 199, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 107, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 116, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 159, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 168, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createMedium(cannonPosX + 30, cannonPosY + 107, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createMedium(cannonPosX + 30, cannonPosY + 116, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createMedium(cannonPosX + 30, cannonPosY + 159, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createMedium(cannonPosX + 30, cannonPosY + 168, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createMedium(cannonPosX + 16, cannonPosY + 106, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createMedium(cannonPosX + 16, cannonPosY + 169, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 2, cannonPosY + 131, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 2, cannonPosY + 138, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 2, cannonPosY + 146, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 2, cannonPosY + 153, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 8, cannonPosY + 128, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 8, cannonPosY + 153, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 8, cannonPosY + 149, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 8, cannonPosY + 156, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 27, cannonPosY + 128, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 27, cannonPosY + 153, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 27, cannonPosY + 149, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 27, cannonPosY + 156, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 33, cannonPosY + 131, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 33, cannonPosY + 138, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 33, cannonPosY + 146, *imperatoreAugusto)));
    imperatoreAugusto->attach(std::move(factory.createLight(cannonPosX + 33, cannonPosY + 153, *imperatoreAugusto)));
    WeaponFactory specialFactory;
    for (int i = 0; i < numAntiAir; i++)
        imperatoreAugusto->attach(
                std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *imperatoreAugusto)));
    std::shared_ptr<LifeBar> life(new LifeBar(*imperatoreAugusto));
    imperatoreAugusto->attachBar(life);
    return imperatoreAugusto;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::kongoBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 31;
    int shipHeight = 222;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 18;
    std::shared_ptr<ConcreteWarShip> kongo(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 56, 37187, shipHeight, shipWidth, true, (std::string&) "Japan", ShipType::Battleship, ModelType::Kongo, 592, "kongo", 6, 0, 4, numAntiAir));
    kongo->attach(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 37, *kongo)));
    kongo->attach(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 50, *kongo)));
    kongo->attach(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 125, *kongo)));
    kongo->attach(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 163, *kongo)));
    kongo->attach(std::move(factory.createLight(cannonPosX + 2, cannonPosY + 81, *kongo)));
    kongo->attach(std::move(factory.createLight(cannonPosX + 2, cannonPosY + 95, *kongo)));
    kongo->attach(std::move(factory.createLight(cannonPosX + 2, cannonPosY + 129, *kongo)));
    kongo->attach(std::move(factory.createLight(cannonPosX + 24, cannonPosY + 81, *kongo)));
    kongo->attach(std::move(factory.createLight(cannonPosX + 24, cannonPosY + 95, *kongo)));
    kongo->attach(std::move(factory.createLight(cannonPosX + 24, cannonPosY + 129, *kongo)));
    WeaponFactory specialFactory;
    for (int i = 0; i < numAntiAir; i++)
        kongo->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *kongo)));
    std::shared_ptr<LifeBar> life(new LifeBar(*kongo));
    kongo->attachBar(life);
    return kongo;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::musashiBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 244;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 30;
    std::shared_ptr<ConcreteWarShip> musashi (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 51, 72809, shipHeight, shipWidth, true, (std::string&) "Japan", ShipType::Battleship, ModelType::Musashi, 1540, "musashi", 6, 2, 3, numAntiAir));
    musashi->attach(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 61, *musashi)));
    musashi->attach(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 82, *musashi)));
    musashi->attach(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 167, *musashi)));
    musashi->attach(std::move(factory.createMedium(cannonPosX + 8, cannonPosY + 112, *musashi)));
    musashi->attach(std::move(factory.createMedium(cannonPosX + 27, cannonPosY + 112, *musashi)));
    musashi->attach(std::move(factory.createLight(cannonPosX, cannonPosY + 125, *musashi)));
    musashi->attach(std::move(factory.createLight(cannonPosX, cannonPosY + 146, *musashi)));
    musashi->attach(std::move(factory.createLight(cannonPosX + 34, cannonPosY + 125, *musashi)));
    musashi->attach(std::move(factory.createLight(cannonPosX + 34, cannonPosY + 146, *musashi)));
    musashi->attach(std::move(factory.createLight(cannonPosX + 24, cannonPosY + 95, *musashi)));
    musashi->attach(std::move(factory.createLight(cannonPosX + 24, cannonPosY + 129, *musashi)));
    WeaponFactory specialFactory;
    for (int i = 0; i < numAntiAir; i++)
        musashi->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *musashi)));
    std::shared_ptr<LifeBar> life(new LifeBar(*musashi));
    musashi->attachBar(life);
    return musashi;
}
std::shared_ptr<ConcreteWarShip> ShipFactory::createDestroyer(ModelType type, GameWorld &map) {
    std::list<std::shared_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {
        case ModelType::Akizuki: {
            std::shared_ptr<ConcreteWarShip> akizuki = akizukiBuilder(coordinates);
            repositionEnemyShip(akizuki);
            return std::move(akizuki);
        }
        case ModelType::Yukikaze: {
            std::shared_ptr<ConcreteWarShip> yukikaze = yukikazeBuilder(coordinates);
            repositionEnemyShip(yukikaze);
            return std::move(yukikaze);
        }
        case ModelType::Fubuki: {
            std::shared_ptr<ConcreteWarShip> fubuki = fubukiBuilder(coordinates);
            repositionEnemyShip(fubuki);
            return std::move(fubuki);
        }
        case ModelType::Impavido: {
            std::shared_ptr<ConcreteWarShip> impavido = impavidoBuilder(coordinates);
            repositionEnemyShip(impavido);
            return std::move(impavido);
        }
        case ModelType::Leone: {
            std::shared_ptr<ConcreteWarShip> leone = leoneBuilder(coordinates);
            repositionEnemyShip(leone);
            return std::move(leone);
        }
        case ModelType::PaoloEmilio: {
            std::shared_ptr<ConcreteWarShip> paoloEmilio = paoloEmilioBuilder(coordinates);
            repositionEnemyShip(paoloEmilio);
            return std::move(paoloEmilio);
        }
        case ModelType::Campbelltown: {
            std::shared_ptr<ConcreteWarShip> campbelltown = campbeltownBuilder(coordinates);
            repositionEnemyShip(campbelltown);
            return std::move(campbelltown);
        }
        case ModelType::Jutland: {
            std::shared_ptr<ConcreteWarShip> jutLand = jutlandBuilder(coordinates);
            repositionEnemyShip(jutLand);
            return std::move(jutLand);
        }
        case ModelType::Gallant: {
            std::shared_ptr<ConcreteWarShip> gallant = gallandBuilder(coordinates);
            repositionEnemyShip(gallant);
            return std::move(gallant);
        }
        case ModelType::Fletcher: {
            std::shared_ptr<ConcreteWarShip> fletcher = fletcherBuilder(coordinates);
            repositionEnemyShip(fletcher);
            return std::move(fletcher);
        }
        case ModelType::Mahan: {
            std::shared_ptr<ConcreteWarShip> mahan = mahanBuilder(coordinates);
            repositionEnemyShip(mahan);
            return std::move(mahan);
        }
        case ModelType::Sims: {
            std::shared_ptr<ConcreteWarShip> sims = simsBuilder(coordinates);
            repositionEnemyShip(sims);
            return std::move(sims);
        }
    }
}
std::shared_ptr<ConcreteWarShip>ShipFactory::simsBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 16;
    int shipHeight = 106;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 16;
    WeaponFactory wf;
    //std::shared_ptr<ConcreteWarShip> sims(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 69, 2293, 30,"Usa", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Sims, 8));
    std::shared_ptr<ConcreteWarShip> sims(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 69, 2293,shipHeight,shipWidth,true,(std::string &)"Usa",ShipType::Destroyer,ModelType::Sims,30,"Titan",0,4,0,numAntiAir));
    sims->attach(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 12, *sims)));
    sims->attach(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 23, *sims)));
    sims->attach(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 78, *sims)));
    sims->attach(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 90, *sims)));
    for (int i = 0; i < numAntiAir; i++) {
        sims->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *sims)));
    }
    std::shared_ptr<LifeBar> life(new LifeBar(*sims));
    sims->attachBar(life);
    return sims;
}
std::shared_ptr<ConcreteWarShip>ShipFactory::fletcherBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 12;
    int shipHeight = 114;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 14;
    WeaponFactory wf;
    //std::shared_ptr<ConcreteWarShip> fletcher(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 68, 2500, 33,"Usa", 0, 0, 5, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Fletcher, 10));
    std::shared_ptr<ConcreteWarShip> fletcher(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 68, 2500,shipHeight,shipWidth,true,(std::string &)"Usa",ShipType::Destroyer,ModelType::Fletcher,33,"Ambusher",0,5,0,numAntiAir));
    fletcher->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 97, *fletcher)));
    fletcher->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 85, *fletcher)));
    fletcher->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 73, *fletcher)));
    fletcher->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 15, *fletcher)));
    fletcher->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 27, *fletcher)));
    for (int i = 0; i < numAntiAir; i++) {
        fletcher->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *fletcher)));
    }
    std::shared_ptr<LifeBar> life(new LifeBar(*fletcher));
    fletcher->attachBar(life);
    return fletcher;
}
std::shared_ptr<ConcreteWarShip>ShipFactory::jutlandBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 13;
    int shipHeight = 116;
    WeaponFactory wf;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 16;
    //std::shared_ptr<ConcreteWarShip> jutLand(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 66, 2480, 26,"Uk", 0, 0, 3, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Jutland, 10));
    std::shared_ptr<ConcreteWarShip>jutLand(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 66, 2480,shipHeight,shipWidth,true,(std::string &)"Uk",ShipType::Destroyer,ModelType::Jutland,26,"Antioka",0,3,0,numAntiAir));
    jutLand->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 18, *jutLand)));
    jutLand->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 28, *jutLand)));
    jutLand->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 95, *jutLand)));
    for (int i = 0; i < numAntiAir; i++) {
        jutLand->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *jutLand)));
    }
    std::shared_ptr<LifeBar> life(new LifeBar(*jutLand));
    jutLand->attachBar(life);
    return jutLand;
}
std::shared_ptr<ConcreteWarShip>ShipFactory::paoloEmilioBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 15;
    int shipHeight = 172;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 12;
    WeaponFactory wf;
    //std::shared_ptr<ConcreteWarShip> paoloEmilio(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 76, 5420, 66,"Italy", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::PaoloEmilio, 8));
    std::shared_ptr<ConcreteWarShip> paoloEmilio(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 76, 5420,shipHeight,shipWidth,true,(std::string &)"Italy",ShipType::Destroyer,ModelType::PaoloEmilio,66,"LoSvevo",0,4,0,numAntiAir));
    paoloEmilio->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 30, *paoloEmilio)));
    paoloEmilio->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 38, *paoloEmilio)));
    paoloEmilio->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 134, *paoloEmilio)));
    paoloEmilio->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 142, *paoloEmilio)));
    for (int i = 0; i < numAntiAir; i++) {
        paoloEmilio->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *paoloEmilio)));
    }
    std::shared_ptr<LifeBar> life(new LifeBar(*paoloEmilio));
    paoloEmilio->attachBar(life);
    return paoloEmilio;
}
std::shared_ptr<ConcreteWarShip>ShipFactory::impavidoBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 15;
    int shipHeight = 131;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int numAntiAir = 40;
    WeaponFactory wf;
    //std::shared_ptr<ConcreteWarShip> impavido(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 63, 3941, 36,"Italy", 4, 0, 1, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Impavido, 6));
    std::shared_ptr<ConcreteWarShip> impavido(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 63, 3941,shipHeight,shipWidth,true,(std::string &)"Italy",ShipType::Destroyer,ModelType::Impavido,36,"Avanti",4,1,0,numAntiAir));
    impavido->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 13, *impavido)));
    impavido->attach(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 67, *impavido)));
    impavido->attach(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 79, *impavido)));
    impavido->attach(std::move(cf.createLight(cannonPosX + 10, cannonPosY + 67, *impavido)));
    impavido->attach(std::move(cf.createLight(cannonPosX + 10, cannonPosY + 79, *impavido)));
    for (int i = 0; i < numAntiAir; i++) {
        impavido->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *impavido)));
    }
    std::shared_ptr<LifeBar> life(new LifeBar(*impavido));
    impavido->attachBar(life);
    return impavido;
}
std::shared_ptr<ConcreteWarShip>ShipFactory::yukikazeBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 12;
    int shipHeight = 119;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int numAntiAir = 32;
    WeaponFactory wf;
    //std::shared_ptr<ConcreteWarShip> yukikaze(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 65, 2530, 26,"Japan", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Yukikaze, 8));
    std::shared_ptr<ConcreteWarShip> yukikaze(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 65, 2530,shipHeight,shipWidth,true,(std::string &)"Japan",ShipType::Destroyer,ModelType::Yukikaze,26,"Taokau",0,4,0,numAntiAir));
    yukikaze->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 16, *yukikaze)));
    yukikaze->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 51, *yukikaze)));
    yukikaze->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 70, *yukikaze)));
    yukikaze->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 93, *yukikaze)));
    for (int i = 0; i < numAntiAir; i++) {
        yukikaze->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *yukikaze)));
    }
    std::shared_ptr<LifeBar> life(new LifeBar(*yukikaze));
    yukikaze->attachBar(life);
    return yukikaze;
}
std::shared_ptr<ConcreteWarShip> ShipFactory::createAlliedSubmarine(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    //TODO da sistemare con factory
    std::list<std::shared_ptr<Vehicle>> v;
    coordinates.y = coordinates.y + (0.14 * map.getMapHeight());
    switch (type) {
        case ModelType::I400: {
            std::shared_ptr<ConcreteWarShip> i400 = i400Builder(coordinates);
            repositionAlliedShip(i400);
            return std::move(i400);
        }
        case ModelType::typeb1: {
            std::shared_ptr<ConcreteWarShip> typeb1 = typeb1Builder(coordinates);
            repositionAlliedShip(typeb1);
            return std::move(typeb1);
        }
        case ModelType::DaVinci: {
            std::shared_ptr<ConcreteWarShip> DaVinci = DaVinciBuilder(coordinates);
            repositionAlliedShip(DaVinci);
            return std::move(DaVinci);
        }
        case ModelType::Papa: {
            std::shared_ptr<ConcreteWarShip> papa = papaBuilder(coordinates);
            repositionAlliedShip(papa);
            return std::move(papa);
        }
        case ModelType::Triton: {
            std::shared_ptr<ConcreteWarShip> triton = tritonBuilder(coordinates);
            repositionAlliedShip(triton);
            return std::move(triton);
        }
        case ModelType::Trenchant: {
            std::shared_ptr<ConcreteWarShip> trenchant = trenchantBuilder(coordinates);
            repositionAlliedShip(trenchant);
            return std::move(trenchant);
        }
        case ModelType::Gato: {
            std::shared_ptr<ConcreteWarShip> gato = gatoBuilder(coordinates);
            repositionAlliedShip(gato);
            return std::move(gato);
        }
        case ModelType::Narwhal: {
            std::shared_ptr<ConcreteWarShip> narwhal = narwhalBuilder(coordinates);
            repositionAlliedShip(narwhal);
            return std::move(narwhal);
        }
    }
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::narwhalBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 13;
    int shipHeight = 91;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    std::shared_ptr<ConcreteWarShip> Narwhal(new Submarine(coordinates.x, coordinates.y, 2, 48, 4600,shipHeight,shipWidth,true,(std::string &)"Usa",ShipType::Submarine,ModelType::Narwhal,0,(std::string &)"narwhal",0,0,0,0));
    for (int i = 0; i < 4; i++)
        Narwhal->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *Narwhal)));
    std::shared_ptr<LifeBar> life(new LifeBar(*Narwhal));
    Narwhal->attachBar(life);
    return Narwhal;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::trenchantBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 14;
    int shipHeight = 85;
    std::shared_ptr<ConcreteWarShip> Trenchant(new Submarine(coordinates.x, coordinates.y, 2, 56, 5800,shipHeight,shipWidth,true,(std::string &)"Uk",ShipType::Submarine,ModelType::Trenchant,0,(std::string &)"triton",0,0,0,0));
    for (int i = 0; i < 5; i++)
        Trenchant->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *Trenchant)));
    std::shared_ptr<LifeBar> life(new LifeBar(*Trenchant));
    Trenchant->attachBar(life);
    return Trenchant;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::papaBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 19;
    int shipHeight = 106;
    std::shared_ptr<ConcreteWarShip> Papa(new Submarine(coordinates.x, coordinates.y, 2, 82, 7100,shipHeight,shipWidth,true,(std::string &)"Italy",ShipType::Submarine,ModelType::Papa,0,(std::string &)"papa",0,0,0,0));
    for (int i = 0; i < 10; i++)
        Papa->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *Papa)));
    std::shared_ptr<LifeBar> life(new LifeBar(*Papa));
    Papa->attachBar(life);
    return Papa;
}
std::shared_ptr<ConcreteWarShip> ShipFactory::createAlliedAircraftCarrier(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    //TODO da sistemare con factory
    std::list<std::shared_ptr<Vehicle>> v;
    coordinates.y = coordinates.y + (0.14 * map.getMapHeight());
    switch (type) {
        case ModelType::Tahio: {
            std::shared_ptr<ConcreteWarShip> tahio = tahioBuilder(coordinates);
            repositionAlliedShip(tahio);
            return std::move(tahio);
        }
        case ModelType::Hiryu: {
            std::shared_ptr<ConcreteWarShip> hiryu = hiryuBuilder(coordinates);
            repositionAlliedShip(hiryu);
            return std::move(hiryu);
        }
        case ModelType::GiuseppeGaribaldi: {
            std::shared_ptr<ConcreteWarShip> giuseppeGaribaldi = giuseppeGaribaldiBuilder(coordinates);
            repositionAlliedShip(giuseppeGaribaldi);
            return std::move(giuseppeGaribaldi);
        }
        case ModelType::Cavour: {
            std::shared_ptr<ConcreteWarShip> cavour = cavourBuilder(coordinates);
            repositionAlliedShip(cavour);
            return std::move(cavour);
        }
        case ModelType::ArkRoyal: {
            std::shared_ptr<ConcreteWarShip> arkRoyal = arkRoyalBuilder(coordinates);
            repositionAlliedShip(arkRoyal);
            return std::move(arkRoyal);
        }
        case ModelType::Indomitable: {
            std::shared_ptr<ConcreteWarShip> indomitable = indomitableBuilder(coordinates);
            repositionAlliedShip(indomitable);
            return std::move(indomitable);
        }
        case ModelType::Midway: {
            std::shared_ptr<ConcreteWarShip> midway = midwayBuilder(coordinates);
            repositionAlliedShip(midway);
            return std::move(midway);
        }
        case ModelType::FranklinDRoosevelt: {
            std::shared_ptr<ConcreteWarShip> franklinDRoosevelt = franklinDelanoRoosveltBuilder(coordinates);
            repositionAlliedShip(franklinDRoosevelt);
            return std::move(franklinDRoosevelt);
        }
    }
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::franklinDelanoRoosveltBuilder(sf::Vector2i &coordinates) const {
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 70;
    int shipHeight = 295;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    WeaponFactory specialFactory;
    int numAntiAir = 8;
    std::shared_ptr<ConcreteWarShip> FranklinDRoosevelt(
            new ConcreteWarShip(coordinates.x, coordinates.y, 1, 61, 45000, 363, "Usa", 0, 0, 2, numAntiAir,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::FranklinDRoosevelt, 14));
    FranklinDRoosevelt->attach(std::move(factory.createMedium(cannonPosX + 55, cannonPosY + 92, *FranklinDRoosevelt)));
    FranklinDRoosevelt->attach(std::move(factory.createMedium(cannonPosX + 56, cannonPosY + 179, *FranklinDRoosevelt)));
    FranklinDRoosevelt->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+35,cannonPosY+12,"Usa",*FranklinDRoosevelt)));
    FranklinDRoosevelt->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+35,cannonPosY+32,"Usa",*FranklinDRoosevelt)));
    FranklinDRoosevelt->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+35,cannonPosY+52,"Usa",*FranklinDRoosevelt)));
    FranklinDRoosevelt->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+35,cannonPosY+72,"Usa",*FranklinDRoosevelt)));
    FranklinDRoosevelt->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+35,cannonPosY+92,"Usa",*FranklinDRoosevelt)));
    FranklinDRoosevelt->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+35,cannonPosY+112,"Usa",*FranklinDRoosevelt)));
    FranklinDRoosevelt->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+35,cannonPosY+132,"Usa",*FranklinDRoosevelt)));
    FranklinDRoosevelt->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+35,cannonPosY+152,"Usa",*FranklinDRoosevelt)));
    FranklinDRoosevelt->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+35,cannonPosY+172,"Usa",*FranklinDRoosevelt)));
    FranklinDRoosevelt->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+35,cannonPosY+192,"Usa",*FranklinDRoosevelt)));
    FranklinDRoosevelt->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+35,cannonPosY+212,"Usa",*FranklinDRoosevelt)));
    FranklinDRoosevelt->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+35,cannonPosY+232,"Usa",*FranklinDRoosevelt)));
    FranklinDRoosevelt->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+35,cannonPosY+252,"Usa",*FranklinDRoosevelt)));
    FranklinDRoosevelt->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+35,cannonPosY+272,"Usa",*FranklinDRoosevelt)));
    for (int i = 0; i < numAntiAir; i++)
        FranklinDRoosevelt->attach(
                std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *FranklinDRoosevelt)));
    std::shared_ptr<LifeBar> life(new LifeBar(*FranklinDRoosevelt));
    FranklinDRoosevelt->attachBar(life);
    return FranklinDRoosevelt;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::indomitableBuilder(sf::Vector2i &coordinates) const {
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 41;
    int shipHeight = 230;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    WeaponFactory specialFactory;
    int numAntiAir = 6;
    std::shared_ptr<ConcreteWarShip> Indomitable(
            new ConcreteWarShip(coordinates.x, coordinates.y, 1, 56, 29730, 240, "Uk", 2, 0, 0, numAntiAir,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::Indomitable, 5));
    Indomitable->attach(std::move(factory.createLight(cannonPosX + 6, cannonPosY + 38, *Indomitable)));
    Indomitable->attach(std::move(factory.createLight(cannonPosX + 31, cannonPosY + 38, *Indomitable)));
    Indomitable->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+20,cannonPosY+12,"Uk",*Indomitable)));
    Indomitable->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+20,cannonPosY+32,"Uk",*Indomitable)));
    Indomitable->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+20,cannonPosY+62,"Uk",*Indomitable)));
    Indomitable->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+20,cannonPosY+82,"Uk",*Indomitable)));
    Indomitable->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+20,cannonPosY+112,"Uk",*Indomitable)));
    for (int i = 0; i < numAntiAir; i++)
        Indomitable->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *Indomitable)));
    std::shared_ptr<LifeBar> life(new LifeBar(*Indomitable));
    Indomitable->attachBar(life);
    return Indomitable;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::cavourBuilder(sf::Vector2i &coordinates) const {
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 50;
    int shipHeight = 244;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    WeaponFactory specialFactory;
    int numAntiAir = 3;
    std::shared_ptr<ConcreteWarShip> Cavour(
            new ConcreteWarShip(coordinates.x, coordinates.y, 1, 52, 29900, 241, "Italy", 4, 0, 0, numAntiAir,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::Cavour, 6));
    Cavour->attach(std::move(factory.createLight(cannonPosX + 16, cannonPosY + 4,*Cavour)));
    Cavour->attach(std::move(factory.createLight(cannonPosX + 31, cannonPosY + 23,*Cavour)));
    Cavour->attach(std::move(factory.createLight(cannonPosX + 29, cannonPosY + 78,*Cavour)));
    Cavour->attach(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 171,*Cavour)));
    Cavour->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+17,cannonPosY+12,"Italy",*Cavour)));
    Cavour->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+17,cannonPosY+38,"Italy",*Cavour)));
    Cavour->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+17,cannonPosY+66,"Italy",*Cavour)));
    Cavour->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+17,cannonPosY+94,"Italy",*Cavour)));
    Cavour->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+17,cannonPosY+125,"Italy",*Cavour)));
    Cavour->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+17,cannonPosY+156,"Italy",*Cavour)));
    for (int i = 0; i < numAntiAir; i++)
        Cavour->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir,*Cavour)));
    std::shared_ptr<LifeBar> life(new LifeBar(*Cavour));
    Cavour->attachBar(life);
    return Cavour;
}
std::shared_ptr<ConcreteWarShip>ShipFactory::hiryuBuilder(sf::Vector2i &coordinates) const {
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 39;
    int shipHeight = 222;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    WeaponFactory specialFactory;
    int numAntiAir = 2;
    //std::shared_ptr<ConcreteWarShip> Hiryu(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 63, 20570, 70, "Japan", 2, 0, 0, numAntiAir,shipHeight,shipWidth,true,ShipType::ConcreteAircraftCarrier, ModelType::Hiryu, 6));
    std::shared_ptr<ConcreteWarShip> Hiryu(new ConcreteAircraftCarrier(coordinates.x, coordinates.y, 1, 63, 20570,shipHeight,shipWidth,true,(std::string &)"Japan",ShipType::AircraftCarrier,ModelType::Hiryu,70,"Hiryu",2,0,0,numAntiAir,6));
    Hiryu->attach(std::move(factory.createLight(cannonPosX + 18, cannonPosY + 3, *Hiryu)));
    Hiryu->attach(std::move(factory.createLight(cannonPosX + 5, cannonPosY + 61, *Hiryu)));
    ConcreteAircraftCarrier * dynamic = dynamic_cast<ConcreteAircraftCarrier *>(Hiryu.get());
    dynamic->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+19,cannonPosY+32,"Japan",*Hiryu)));
    dynamic->attachPlanes(std::move(airPlanesFactory.createFighter(cannonPosX+19,cannonPosY+58,"Japan",*Hiryu)));
    dynamic->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+19,cannonPosY+86,"Japan",*Hiryu)));
    dynamic->attachPlanes(std::move(airPlanesFactory.createBomber(cannonPosX+19,cannonPosY+114,"Japan",*Hiryu)));
    dynamic->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+19,cannonPosY+145,"Japan",*Hiryu)));
    dynamic->attachPlanes(std::move(airPlanesFactory.createTorpedoBomber(cannonPosX+19,cannonPosY+176,"Japan",*Hiryu)));
    for (int i = 0; i < numAntiAir; i++)
        Hiryu->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *Hiryu)));
    std::shared_ptr<LifeBar> life(new LifeBar(*Hiryu));
    Hiryu->attachBar(life);
    return Hiryu;
}
std::shared_ptr<ConcreteWarShip> ShipFactory::createAlliedCruiser(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    //TODO da sistemare con factory
    std::list<std::shared_ptr<Vehicle>> v;
    coordinates.y = coordinates.y + (0.14 * map.getMapHeight());
    switch (type) {
        case ModelType::Ijn: {
            std::shared_ptr<ConcreteWarShip> ijn = ijnBuilder(coordinates);
            repositionAlliedShip(ijn);
            return std::move(ijn);
        }
        case ModelType::IsuzuNagara: {
            std::shared_ptr<ConcreteWarShip> isuzuNagara = isuzuNagaraBuilder(coordinates);
            repositionAlliedShip(isuzuNagara);
            return std::move(isuzuNagara);
        }
        case ModelType::Takao: {
            std::shared_ptr<ConcreteWarShip> takao = takaoBuilder(coordinates);
            repositionAlliedShip(takao);
            return std::move(takao);
        }
        case ModelType::AlbertoDiGiussano: {
            std::shared_ptr<ConcreteWarShip> albertoDiGiussano = albertoDiGiussanoBuilder(coordinates);
            repositionAlliedShip(albertoDiGiussano);
            return std::move(albertoDiGiussano);
        }
        case ModelType::Gorizia: {
            std::shared_ptr<ConcreteWarShip> gorizia = goriziaBuilder(coordinates);
            repositionAlliedShip(gorizia);
            return std::move(gorizia);
        }
        case ModelType::Trento: {
            std::shared_ptr<ConcreteWarShip> trento = trentoBuilder(coordinates);
            repositionAlliedShip(trento);
            return std::move(trento);
        }
        case ModelType::Belfast: {
            std::shared_ptr<ConcreteWarShip> belfast = belfastBuilder(coordinates);
            repositionAlliedShip(belfast);
            return std::move(belfast);
        }
        case ModelType::Danae: {
            std::shared_ptr<ConcreteWarShip> danae = danaeBuilder(coordinates);
            repositionAlliedShip(danae);
            return std::move(danae);
        }
        case ModelType::Tiger59: {
            std::shared_ptr<ConcreteWarShip> tiger59 = tiger59Builder(coordinates);
            repositionAlliedShip(tiger59);
            return std::move(tiger59);
        }
        case ModelType::Alaska: {
            std::shared_ptr<ConcreteWarShip> alaska = alaskaBuilder(coordinates);
            repositionAlliedShip(alaska);
            return std::move(alaska);
        }
        case ModelType::NewOrleans: {
            std::shared_ptr<ConcreteWarShip> newOrleans = newOrleansBuilder(coordinates);
            repositionAlliedShip(newOrleans);
            return std::move(newOrleans);
        }
        case ModelType::StLouis: {
            std::shared_ptr<ConcreteWarShip> saintLouis = stLouisBuilder(coordinates);
            repositionAlliedShip(saintLouis);
            return std::move(saintLouis);
        }
    }
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::newOrleansBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 25;
    int shipHeight = 178;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    CannonFactory cf;
    int antiAir = 12;
    std::shared_ptr<ConcreteWarShip> NewOrleans (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 61, 12663, shipHeight, shipWidth, true, (std::string&) "Usa", ShipType::Cruiser, ModelType::NewOrleans, 476, "newOrleans", 6, 3, 0, antiAir));
    NewOrleans->attach(std::move(cf.createMedium(cannonPosX + 10, cannonPosY + 121, *NewOrleans)));
    NewOrleans->attach(std::move(cf.createMedium(cannonPosX + 10, cannonPosY + 50, *NewOrleans)));
    NewOrleans->attach(std::move(cf.createMedium(cannonPosX + 10, cannonPosY + 38, *NewOrleans)));
    NewOrleans->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 73, *NewOrleans)));
    NewOrleans->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 82, *NewOrleans)));
    NewOrleans->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 90, *NewOrleans)));
    NewOrleans->attach(std::move(cf.createLight(cannonPosX + 17, cannonPosY + 73, *NewOrleans)));
    NewOrleans->attach(std::move(cf.createLight(cannonPosX + 17, cannonPosY + 82, *NewOrleans)));
    NewOrleans->attach(std::move(cf.createLight(cannonPosX + 17, cannonPosY + 90, *NewOrleans)));
    for (int i = 0; i < antiAir; i++)
        NewOrleans->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *NewOrleans)));
    std::shared_ptr<LifeBar> life(new LifeBar(*NewOrleans));
    NewOrleans->attachBar(life);
    return NewOrleans;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::tiger59Builder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 19;
    int shipHeight = 169;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    CannonFactory cf;
    int antiAir = 7;
    std::shared_ptr<ConcreteWarShip> Tiger59 (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 58, 12080, shipHeight, shipWidth, true, (std::string&) "Uk", ShipType::Cruiser, ModelType::Tiger59, 191, "tiger59", 6, 4, 0, antiAir));
    Tiger59->attach(std::move(cf.createMedium(cannonPosX + 6, cannonPosY + 137, *Tiger59)));
    Tiger59->attach(std::move(cf.createMedium(cannonPosX + 6, cannonPosY + 128, *Tiger59)));
    Tiger59->attach(std::move(cf.createMedium(cannonPosX + 6, cannonPosY + 32, *Tiger59)));
    Tiger59->attach(std::move(cf.createMedium(cannonPosX + 6, cannonPosY + 24, *Tiger59)));
    Tiger59->attach(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 117, *Tiger59)));
    Tiger59->attach(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 92, *Tiger59)));
    Tiger59->attach(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 75, *Tiger59)));
    Tiger59->attach(std::move(cf.createLight(cannonPosX + 13, cannonPosY + 117, *Tiger59)));
    Tiger59->attach(std::move(cf.createLight(cannonPosX + 13, cannonPosY + 92, *Tiger59)));
    Tiger59->attach(std::move(cf.createLight(cannonPosX + 13, cannonPosY + 75, *Tiger59)));
    for (int i = 0; i < antiAir; i++)
        Tiger59->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *Tiger59)));

    std::shared_ptr<LifeBar> life(new LifeBar(*Tiger59));
    Tiger59->attachBar(life);
    return Tiger59;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::belfastBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 27;
    int shipHeight = 187;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    CannonFactory cf;
    int antiAir = 12;
    std::shared_ptr<ConcreteWarShip> Belfast (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 59, 11550, shipHeight, shipWidth, true, (std::string&) "Uk", ShipType::Cruiser, ModelType::Belfast, 228, "belfast", 6, 4, 0, antiAir));
    Belfast->attach(std::move(cf.createMedium(cannonPosX + 10, cannonPosY + 151, *Belfast)));
    Belfast->attach(std::move(cf.createMedium(cannonPosX + 10, cannonPosY + 141, *Belfast)));
    Belfast->attach(std::move(cf.createMedium(cannonPosX + 10, cannonPosY + 34, *Belfast)));
    Belfast->attach(std::move(cf.createMedium(cannonPosX + 10, cannonPosY + 25, *Belfast)));
    Belfast->attach(std::move(cf.createLight(cannonPosX + 4, cannonPosY + 121, *Belfast)));
    Belfast->attach(std::move(cf.createLight(cannonPosX + 4, cannonPosY + 107, *Belfast)));
    Belfast->attach(std::move(cf.createLight(cannonPosX + 4, cannonPosY + 95, *Belfast)));
    Belfast->attach(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 121, *Belfast)));
    Belfast->attach(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 107, *Belfast)));
    Belfast->attach(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 95, *Belfast)));
    for (int i = 0; i < antiAir; i++)
        Belfast->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *Belfast)));
    std::shared_ptr<LifeBar> life(new LifeBar(*Belfast));
    Belfast->attachBar(life);
    return Belfast;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::goriziaBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 22;
    int shipHeight = 183;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    CannonFactory cf;
    int antiAir = 12;
    std::shared_ptr<ConcreteWarShip> Gorizia (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 59, 14330, shipHeight, shipWidth, true, (std::string&) "Italy", ShipType::Cruiser, ModelType::Gorizia, 370, "gorizia", 6, 4, 0, antiAir));
    Gorizia->attach(std::move(cf.createMedium(cannonPosX + 7, cannonPosY + 151, *Gorizia)));
    Gorizia->attach(std::move(cf.createMedium(cannonPosX + 7, cannonPosY + 141, *Gorizia)));
    Gorizia->attach(std::move(cf.createMedium(cannonPosX + 7, cannonPosY + 57, *Gorizia)));
    Gorizia->attach(std::move(cf.createMedium(cannonPosX + 7, cannonPosY + 46, *Gorizia)));
    Gorizia->attach(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 78, *Gorizia)));
    Gorizia->attach(std::move(cf.createLight(cannonPosX + 15, cannonPosY + 78, *Gorizia)));
    Gorizia->attach(std::move(cf.createLight(cannonPosX, cannonPosY + 107, *Gorizia)));
    Gorizia->attach(std::move(cf.createLight(cannonPosX, cannonPosY + 98, *Gorizia)));
    Gorizia->attach(std::move(cf.createLight(cannonPosX + 15, cannonPosY + 107, *Gorizia)));
    Gorizia->attach(std::move(cf.createLight(cannonPosX + 15, cannonPosY + 98, *Gorizia)));
    for (int i = 0; i < antiAir; i++) {
        Gorizia->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *Gorizia)));
    }
    std::shared_ptr<LifeBar> life(new LifeBar(*Gorizia));
    Gorizia->attachBar(life);
    return Gorizia;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::isuzuNagaraBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 14;
    int shipHeight = 159;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    CannonFactory cf;
    int antiAir = 6;
    std::shared_ptr<ConcreteWarShip> IsuzuNagara (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 67, 5700, shipHeight, shipWidth, true, (std::string&) "Japan", ShipType::Cruiser, ModelType::IsuzuNagara, 90, "isuzuNagara", 5, 3, 0, antiAir));
    IsuzuNagara->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 132, *IsuzuNagara)));
    IsuzuNagara->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 94, *IsuzuNagara)));
    IsuzuNagara->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 18, *IsuzuNagara)));
    IsuzuNagara->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 142, *IsuzuNagara)));
    IsuzuNagara->attach(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 77, *IsuzuNagara)));
    IsuzuNagara->attach(std::move(cf.createLight(cannonPosX + 6, cannonPosY + 77, *IsuzuNagara)));
    IsuzuNagara->attach(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 30, *IsuzuNagara)));
    IsuzuNagara->attach(std::move(cf.createLight(cannonPosX + 6, cannonPosY + 30, *IsuzuNagara)));
    for (int i = 0; i < antiAir; i++)
        IsuzuNagara->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *IsuzuNagara)));

    std::shared_ptr<LifeBar> life(new LifeBar(*IsuzuNagara));
    IsuzuNagara->attachBar(life);
    return IsuzuNagara;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::ijnBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 26;
    int shipHeight = 204;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    CannonFactory cf;
    int antiAir = 10;
    std::shared_ptr<ConcreteWarShip> Ijn (new ConcreteWarShip(coordinates.x, coordinates.y, 3, 66, 15500, shipHeight, shipWidth, true, (std::string&) "Japan", ShipType::Cruiser, ModelType::Ijn, 230, "ijn", 4, 4, 0, antiAir));
    Ijn->attach(std::move(cf.createMedium(cannonPosX + 10, cannonPosY + 31, *Ijn)));
    Ijn->attach(std::move(cf.createMedium(cannonPosX + 10, cannonPosY + 41, *Ijn)));
    Ijn->attach(std::move(cf.createMedium(cannonPosX + 10, cannonPosY + 50, *Ijn)));
    Ijn->attach(std::move(cf.createMedium(cannonPosX + 10, cannonPosY + 64, *Ijn)));
    Ijn->attach(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 101, *Ijn)));
    Ijn->attach(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 115, *Ijn)));
    Ijn->attach(std::move(cf.createLight(cannonPosX + 20, cannonPosY + 102, *Ijn)));
    Ijn->attach(std::move(cf.createLight(cannonPosX + 20, cannonPosY + 115, *Ijn)));
    for (int i = 0; i < antiAir; i++)
        Ijn->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *Ijn)));
    std::shared_ptr<LifeBar> life(new LifeBar(*Ijn));
    Ijn->attachBar(life);
    return Ijn;
}
std::shared_ptr<ConcreteWarShip> ShipFactory::createAlliedBattleship(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    //TODO da sistemare con factory
    std::list<std::shared_ptr<Vehicle>> v;
    coordinates.y = coordinates.y + (0.14 * map.getMapHeight());
    switch (type) {
        case ModelType::ISE: {
            std::shared_ptr<ConcreteWarShip> ise = iseBuilder(coordinates);
            repositionAlliedShip(ise);
            return std::move(ise);
        }
        case ModelType::Kongo: {
            std::shared_ptr<ConcreteWarShip> kongo = kongoBuilder(coordinates);
            repositionAlliedShip(kongo);
            return std::move(kongo);
        }
        case ModelType::Musashi: {
            std::shared_ptr<ConcreteWarShip> musashi = musashiBuilder(coordinates);
            repositionAlliedShip(musashi);
            return std::move(musashi);
        }
        case ModelType::Yamato: {
            std::shared_ptr<ConcreteWarShip> yamato = yamatoBuilder(coordinates);
            repositionAlliedShip(yamato);
            return std::move(yamato);
        }
        case ModelType::AndreaDoria: {
            std::shared_ptr<ConcreteWarShip> andreaDoria = andreaDoriaBuilder(coordinates);
            repositionAlliedShip(andreaDoria);
            return std::move(andreaDoria);
        }
        case ModelType::ImperatoreAugusto: {
            std::shared_ptr<ConcreteWarShip> imperatoreAugusto = imperatoreAugustoBuilder(coordinates);
            repositionAlliedShip(imperatoreAugusto);
            return std::move(imperatoreAugusto);
        }
        case ModelType::MichelangeloBuonarroti: {
            std::shared_ptr<ConcreteWarShip> michelangeloBuonarroti = michelangeloBuonarrotiBuilder(coordinates);
            repositionAlliedShip(michelangeloBuonarroti);
            return std::move(michelangeloBuonarroti);
        }
        case ModelType::VittorioVeneto: {
            std::shared_ptr<ConcreteWarShip> vittorioVeneto = vittorioVenetoBuilder(coordinates);
            repositionAlliedShip(vittorioVeneto);
            return std::move(vittorioVeneto);
        }
        case ModelType::Dreadnought: {
            std::shared_ptr<ConcreteWarShip> dreadNought = dreadNoughtBuilder(coordinates);
            repositionAlliedShip(dreadNought);
            return std::move(dreadNought);
        }
        case ModelType::Hood: {
            std::shared_ptr<ConcreteWarShip> hood = hoodBuilder(coordinates);
            repositionAlliedShip(hood);
            return std::move(hood);
        }
        case ModelType::IronDuke: {
            std::shared_ptr<ConcreteWarShip> ironDuke = ironDukeBuilder(coordinates);
            repositionAlliedShip(ironDuke);
            return std::move(ironDuke);
        }
        case ModelType::Lion: {
            std::shared_ptr<ConcreteWarShip> lion = lionBuilder(coordinates);
            repositionAlliedShip(lion);
            return std::move(lion);
        }
        case ModelType::Arizona: {
            std::shared_ptr<ConcreteWarShip> arizona = arizonaBuilder(coordinates);
            repositionAlliedShip(arizona);
            return std::move(arizona);
        }
        case ModelType::Montana: {
            std::shared_ptr<ConcreteWarShip> montana = montanaBuilder(coordinates);
            repositionAlliedShip(montana);
            return std::move(montana);
        }
        case ModelType::NewYork: {
            std::shared_ptr<ConcreteWarShip> newYork = newYorkBuilder(coordinates);
            repositionAlliedShip(newYork);
            return std::move(newYork);
        }
        case ModelType::NorthCarolina: {
            std::shared_ptr<ConcreteWarShip> northCarolina = northCarolinaBuilder(coordinates);
            repositionAlliedShip(northCarolina);
            return std::move(northCarolina);
        }
    }
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::vittorioVenetoBuilder(sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 33;
    int shipHeight = 238;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 32;
    std::shared_ptr<ConcreteWarShip> VittorioVeneto (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 56, 45963, shipHeight, shipWidth, true, (std::string&) "Italy", ShipType::Battleship, ModelType::VittorioVeneto, 862, "vittorioVeneto", 12, 4, 4, numAntiAir));
    VittorioVeneto->attach(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 55, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 78, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 78, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 140, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 93, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 163, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createMedium(cannonPosX + 24, cannonPosY + 93, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createMedium(cannonPosX + 24, cannonPosY + 163, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 104, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 109, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 115, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 122, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 130, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 136, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 104, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 109, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 115, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 122, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 130, *VittorioVeneto)));
    VittorioVeneto->attach(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 136, *VittorioVeneto)));
    WeaponFactory specialFactory;
    for (int i = 0; i < numAntiAir; i++)
        VittorioVeneto->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *VittorioVeneto)));
    std::shared_ptr<LifeBar> life(new LifeBar(*VittorioVeneto));
    VittorioVeneto->attachBar(life);
    return VittorioVeneto;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::newYorkBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int shipWidth = 35;
    int shipHeight = 175;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int antiAir = 6;
    std::shared_ptr<ConcreteWarShip> NewYork (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 39, 28822, shipHeight, shipWidth, true, (std::string&) "Usa", ShipType::Battleship, ModelType::NewYork, 939, "newYork", 0, 0, 5, antiAir));
    NewYork->attach(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 19, *NewYork)));
    NewYork->attach(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 39, *NewYork)));
    NewYork->attach(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 84, *NewYork)));
    NewYork->attach(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 109, *NewYork)));
    NewYork->attach(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 134, *NewYork)));
    for (int i = 0; i < antiAir; i++)
        NewYork->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *NewYork)));
    std::shared_ptr<LifeBar> life(new LifeBar(*NewYork));
    NewYork->attachBar(life);
    return NewYork;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::arizonaBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int shipWidth = 32;
    int shipHeight = 185;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int antiAir = 4;
    std::shared_ptr<ConcreteWarShip> Arizona (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 39, 32429, shipHeight, shipWidth, true, (std::string&) "Usa", ShipType::Battleship, ModelType::Arizona, 1536, "arizona", 8, 0, 4, antiAir));
    Arizona->attach(std::move(cf.createHeavly(cannonPosX + 8, cannonPosY + 29, *Arizona)));
    Arizona->attach(std::move(cf.createHeavly(cannonPosX + 8, cannonPosY + 58, *Arizona)));
    Arizona->attach(std::move(cf.createHeavly(cannonPosX + 8, cannonPosY + 120, *Arizona)));
    Arizona->attach(std::move(cf.createHeavly(cannonPosX + 8, cannonPosY + 142, *Arizona)));
    Arizona->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 97, *Arizona)));
    Arizona->attach(std::move(cf.createLight(cannonPosX + 2, cannonPosY + 87, *Arizona)));
    Arizona->attach(std::move(cf.createLight(cannonPosX + 2, cannonPosY + 78, *Arizona)));
    Arizona->attach(std::move(cf.createLight(cannonPosX + 4, cannonPosY + 69, *Arizona)));
    Arizona->attach(std::move(cf.createLight(cannonPosX + 23, cannonPosY + 97, *Arizona)));
    Arizona->attach(std::move(cf.createLight(cannonPosX + 26, cannonPosY + 87, *Arizona)));
    Arizona->attach(std::move(cf.createLight(cannonPosX + 23, cannonPosY + 78, *Arizona)));
    Arizona->attach(std::move(cf.createLight(cannonPosX + 21, cannonPosY + 69, *Arizona)));
    for (int i = 0; i < antiAir; i++)
        Arizona->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *Arizona)));
    std::shared_ptr<LifeBar> life(new LifeBar(*Arizona));
    Arizona->attachBar(life);
    return Arizona;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::hoodBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int shipWidth = 34;
    int shipHeight = 262;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int antiAir = 20;
    std::shared_ptr<ConcreteWarShip> Hood (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 54, 49136, shipHeight, shipWidth, true, (std::string&) "Uk", ShipType::Battleship, ModelType::Hood, 800, "hood", 0, 2, 2, antiAir));
    Hood->attach(std::move(cf.createHeavly(cannonPosX + 9, cannonPosY + 207, *Hood)));
    Hood->attach(std::move(cf.createHeavly(cannonPosX + 9, cannonPosY + 44, *Hood)));
    Hood->attach(std::move(cf.createMedium(cannonPosX + 12, cannonPosY + 190, *Hood)));
    Hood->attach(std::move(cf.createMedium(cannonPosX + 13, cannonPosY + 59, *Hood)));
    for (int i = 0; i < antiAir; i++)
        Hood->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *Hood)));
    std::shared_ptr<LifeBar> life(new LifeBar(*Hood));
    Hood->attachBar(life);
    return Hood;
}
std::shared_ptr<ConcreteWarShip>
ShipFactory::michelangeloBuonarrotiBuilder(sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 35;
    int shipHeight = 246;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 14;
    std::shared_ptr<ConcreteWarShip> MichelangeloBuonarroti (new ConcreteWarShip(coordinates.x, coordinates.y, 1, 61, 42533, shipHeight, shipWidth, true, (std::string&) "Italy", ShipType::Battleship, ModelType::MichelangeloBuonarroti, 837, "michelangeloBuonarroti", 12, 6, 3, numAntiAir));
    MichelangeloBuonarroti->attach(
            std::move(factory.createHeavly(cannonPosX + 10, cannonPosY + 56, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createHeavly(cannonPosX + 10, cannonPosY + 78, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createHeavly(cannonPosX + 10, cannonPosY + 166, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createMedium(cannonPosX + 1, cannonPosY + 118, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createMedium(cannonPosX + 1, cannonPosY + 139, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 95, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createMedium(cannonPosX + 27, cannonPosY + 118, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createMedium(cannonPosX + 27, cannonPosY + 139, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createMedium(cannonPosX + 27, cannonPosY + 94, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createLight(cannonPosX + 5, cannonPosY + 106, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createLight(cannonPosX + 5, cannonPosY + 112, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createLight(cannonPosX + 5, cannonPosY + 132, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createLight(cannonPosX + 5, cannonPosY + 153, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createLight(cannonPosX + 24, cannonPosY + 106, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createLight(cannonPosX + 24, cannonPosY + 112, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createLight(cannonPosX + 24, cannonPosY + 132, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createLight(cannonPosX + 24, cannonPosY + 154, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createLight(cannonPosX + 4, cannonPosY + 166, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createLight(cannonPosX + 4, cannonPosY + 172, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createLight(cannonPosX + 25, cannonPosY + 166, *MichelangeloBuonarroti)));
    MichelangeloBuonarroti->attach(
            std::move(factory.createLight(cannonPosX + 25, cannonPosY + 172, *MichelangeloBuonarroti)));
    WeaponFactory specialFactory;
    for (int i = 0; i < numAntiAir; i++)
        MichelangeloBuonarroti->attach(
                std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *MichelangeloBuonarroti)));

    std::shared_ptr<LifeBar> life(new LifeBar(*MichelangeloBuonarroti));
    MichelangeloBuonarroti->attachBar(life);
    return MichelangeloBuonarroti;
}
std::shared_ptr<ConcreteWarShip>ShipFactory::andreaDoriaBuilder(sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 29;
    int shipHeight = 176;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 13;
    //std::shared_ptr<ConcreteWarShip> AndreaDoria(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 39, 24729, 622, "Italy", 10, 4, 4, numAntiAir,shipHeight,shipWidth,true,ShipType::Battleship, ModelType::AndreaDoria, 0));
    std::shared_ptr<ConcreteWarShip> AndreaDoria(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 39, 24729,shipHeight,shipWidth,true,(std::string &)"Italy",ShipType::Battleship,ModelType::AndreaDoria,622,"Dartagnan",10,4,4,numAntiAir));
    AndreaDoria->attach(std::move(factory.createHeavly(cannonPosX + 7, cannonPosY + 39, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createHeavly(cannonPosX + 7, cannonPosY + 53, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createHeavly(cannonPosX + 7, cannonPosY + 117, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createHeavly(cannonPosX + 7, cannonPosY + 131, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createMedium(cannonPosX + 4, cannonPosY + 68, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createMedium(cannonPosX + 20, cannonPosY + 68, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createMedium(cannonPosX + 3, cannonPosY + 73, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createMedium(cannonPosX + 21, cannonPosY + 73, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 85, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 91, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 97, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 103, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 109, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createLight(cannonPosX + 22, cannonPosY + 85, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createLight(cannonPosX + 22, cannonPosY + 91, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createLight(cannonPosX + 22, cannonPosY + 97, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createLight(cannonPosX + 22, cannonPosY + 103, *AndreaDoria)));
    AndreaDoria->attach(std::move(factory.createLight(cannonPosX + 22, cannonPosY + 109, *AndreaDoria)));
    WeaponFactory specialFactory;
    for (int i = 0; i < numAntiAir; i++)
        AndreaDoria->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *AndreaDoria)));

    std::shared_ptr<LifeBar> life(new LifeBar(*AndreaDoria));
    AndreaDoria->attachBar(life);
    return AndreaDoria;
}
std::shared_ptr<ConcreteWarShip>ShipFactory::yamatoBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 40;
    int shipWidth = 41;
    int shipHeight = 263;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    //std::shared_ptr<ConcreteWarShip> Yamato(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 50, 71659, 1286, "Japan", 12, 3, 2, antiAir,shipHeight,shipWidth,true,ShipType::Battleship, ModelType::Yamato, 3));
    std::shared_ptr<ConcreteWarShip> Yamato(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 50, 71659,shipHeight,shipWidth,true,(std::string &)"Japan",ShipType::Battleship,ModelType::Yamato,1286,"DahYo",12,2,3,antiAir));
    Yamato->attach(std::move(cf.createHeavly(cannonPosX + 13, cannonPosY + 65, *Yamato)));
    Yamato->attach(std::move(cf.createHeavly(cannonPosX + 13, cannonPosY + 87, *Yamato)));
    Yamato->attach(std::move(cf.createHeavly(cannonPosX + 14, cannonPosY + 178, *Yamato)));
    Yamato->attach(std::move(cf.createMedium(cannonPosX + 16, cannonPosY + 176, *Yamato)));
    Yamato->attach(std::move(cf.createMedium(cannonPosX + 16, cannonPosY + 118, *Yamato)));
    Yamato->attach(std::move(cf.createLight(cannonPosX + 13, cannonPosY + 161, *Yamato)));
    Yamato->attach(std::move(cf.createLight(cannonPosX + 13, cannonPosY + 150, *Yamato)));
    Yamato->attach(std::move(cf.createLight(cannonPosX + 13, cannonPosY + 138, *Yamato)));
    Yamato->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 157, *Yamato)));
    Yamato->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 146, *Yamato)));
    Yamato->attach(std::move(cf.createLight(cannonPosX + 4, cannonPosY + 130, *Yamato)));
    Yamato->attach(std::move(cf.createLight(cannonPosX + 25, cannonPosY + 161, *Yamato)));
    Yamato->attach(std::move(cf.createLight(cannonPosX + 25, cannonPosY + 150, *Yamato)));
    Yamato->attach(std::move(cf.createLight(cannonPosX + 26, cannonPosY + 138, *Yamato)));
    Yamato->attach(std::move(cf.createLight(cannonPosX + 29, cannonPosY + 157, *Yamato)));
    Yamato->attach(std::move(cf.createLight(cannonPosX + 29, cannonPosY + 146, *Yamato)));
    Yamato->attach(std::move(cf.createLight(cannonPosX + 32, cannonPosY + 130, *Yamato)));
    for (int i = 0; i < antiAir; i++)
        Yamato->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *Yamato)));

    std::shared_ptr<LifeBar> life(new LifeBar(*Yamato));
    Yamato->attachBar(life);
    return Yamato;
}
std::shared_ptr<ConcreteWarShip>ShipFactory::iseBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 19;
    int shipWidth = 43;
    int shipHeight = 220;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    //std::shared_ptr<ConcreteWarShip> Ise(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 45, 40444, 705, "Japan", 8, 4, 0, antiAir, shipHeight,shipWidth,true,ShipType::Battleship, ModelType::ISE, 2));
    std::shared_ptr<ConcreteWarShip> Ise(new ConcreteWarShip(coordinates.x, coordinates.y, 1, 45, 40444,shipHeight,shipWidth,true,(std::string &)"Japan",ShipType::Battleship,ModelType::ISE,705,"Fuhituke",8,0,4,antiAir));
    Ise->attach(std::move(cf.createHeavly(cannonPosX + 14, cannonPosY + 31, *Ise)));
    Ise->attach(std::move(cf.createHeavly(cannonPosX + 14, cannonPosY + 45, *Ise)));
    Ise->attach(std::move(cf.createHeavly(cannonPosX + 14, cannonPosY + 107, *Ise)));
    Ise->attach(std::move(cf.createHeavly(cannonPosX + 14, cannonPosY + 119, *Ise)));
    Ise->attach(std::move(cf.createLight(cannonPosX + 9, cannonPosY + 102, *Ise)));
    Ise->attach(std::move(cf.createLight(cannonPosX + 9, cannonPosY + 80, *Ise)));
    Ise->attach(std::move(cf.createLight(cannonPosX + 12, cannonPosY + 71, *Ise)));
    Ise->attach(std::move(cf.createLight(cannonPosX + 12, cannonPosY + 62, *Ise)));
    Ise->attach(std::move(cf.createLight(cannonPosX + 30, cannonPosY + 102, *Ise)));
    Ise->attach(std::move(cf.createLight(cannonPosX + 32, cannonPosY + 80, *Ise)));
    Ise->attach(std::move(cf.createLight(cannonPosX + 28, cannonPosY + 71, *Ise)));
    Ise->attach(std::move(cf.createLight(cannonPosX + 27, cannonPosY + 62, *Ise)));
    for (int i = 0; i < antiAir; i++)
        Ise->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *Ise)));

    std::shared_ptr<LifeBar> life(new LifeBar(*Ise));
    Ise->attachBar(life);
    return Ise;
}
std::shared_ptr<ConcreteWarShip> ShipFactory::createAlliedDestroyer(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    coordinates.y = coordinates.y + (0.14 * map.getMapHeight());
    switch (type) {
        case ModelType::Akizuki: {
            std::shared_ptr<ConcreteWarShip> akizuki = akizukiBuilder(coordinates);
            repositionAlliedShip(akizuki);
            return std::move(akizuki);
        }
        case ModelType::Fubuki: {
            std::shared_ptr<ConcreteWarShip> fubuki = fubukiBuilder(coordinates);
            repositionAlliedShip(fubuki);
            return std::move(fubuki);
        }
        case ModelType::Yukikaze: {
            std::shared_ptr<ConcreteWarShip> yukikaze = yukikazeBuilder(coordinates);
            repositionAlliedShip(yukikaze);
            return std::move(yukikaze);
        }
        case ModelType::Impavido: {
            std::shared_ptr<ConcreteWarShip> impavido = impavidoBuilder(coordinates);
            repositionAlliedShip(impavido);
            return std::move(impavido);
        }
        case ModelType::Leone: {
            std::shared_ptr<ConcreteWarShip> leone = leoneBuilder(coordinates);
            repositionAlliedShip(leone);
            return std::move(leone);
        }
        case ModelType::PaoloEmilio: {
            std::shared_ptr<ConcreteWarShip> paoloEmilio = paoloEmilioBuilder(coordinates);
            repositionAlliedShip(paoloEmilio);
            return std::move(paoloEmilio);
        }
        case ModelType::Campbelltown: {
            std::shared_ptr<ConcreteWarShip> campbelltown = campbeltownBuilder(coordinates);
            repositionAlliedShip(campbelltown);
            return std::move(campbelltown);
        }
        case ModelType::Gallant: {
            std::shared_ptr<ConcreteWarShip> gallant = gallandBuilder(coordinates);
            repositionAlliedShip(gallant);
            return std::move(gallant);
        }
        case ModelType::Jutland: {
            std::shared_ptr<ConcreteWarShip> jutLand = jutlandBuilder(coordinates);
            repositionAlliedShip(jutLand);
            return std::move(jutLand);
        }
        case ModelType::Fletcher: {
            std::shared_ptr<ConcreteWarShip> fletcher = fletcherBuilder(coordinates);
            repositionAlliedShip(fletcher);
            return std::move(fletcher);
        }
        case ModelType::Mahan: {
            std::shared_ptr<ConcreteWarShip> mahan = mahanBuilder(coordinates);
            repositionAlliedShip(mahan);
            return std::move(mahan);
        }
        case ModelType::Sims: {
            std::shared_ptr<ConcreteWarShip> sims = simsBuilder(coordinates);
            repositionAlliedShip(sims);
            return std::move(sims);
        }
    }
}
std::shared_ptr<ConcreteWarShip>ShipFactory::mahanBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 13;
    int shipHeight = 104;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 8;
    //std::shared_ptr<ConcreteWarShip> Mahan(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 69, 2137, 27,"Usa", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Mahan, 12));
    std::shared_ptr<ConcreteWarShip> Mahan(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 69, 2137,shipHeight,shipWidth,true,(std::string &)"Usa",ShipType::Destroyer,ModelType::Mahan,27,"Patton",0,4,0,numAntiAir));
    Mahan->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 11, *Mahan)));
    Mahan->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 37, *Mahan)));
    Mahan->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 90, *Mahan)));
    Mahan->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 72, *Mahan)));
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        Mahan->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *Mahan)));
    }
    std::shared_ptr<LifeBar> life(new LifeBar(*Mahan));
    Mahan->attachBar(life);
    return Mahan;
}
std::shared_ptr<ConcreteWarShip>ShipFactory::gallandBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 10;
    int shipHeight = 99;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int numAntiAir = 8;
    //std::shared_ptr<ConcreteWarShip> Gallant(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 67, 1913, 22,"Uk", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Gallant, 8));
    std::shared_ptr<ConcreteWarShip> Gallant(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 67, 1913,shipHeight,shipWidth,true,(std::string &)"Uk",ShipType::Destroyer,ModelType::Gallant,22,"Viking",0,4,0,numAntiAir));
    Gallant->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 14, *Gallant)));
    Gallant->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 21, *Gallant)));
    Gallant->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 75, *Gallant)));
    Gallant->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 81, *Gallant)));
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        Gallant->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *Gallant)));
    }
    std::shared_ptr<LifeBar> life(new LifeBar(*Gallant));
    Gallant->attachBar(life);
    return Gallant;
}
std::shared_ptr<ConcreteWarShip> ShipFactory::campbeltownBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 10;
    int shipHeight = 96;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 10;
    //std::shared_ptr<ConcreteWarShip> Campbelltown(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 66, 1280, 19,"Uk", 4, 0, 0, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Campbelltown, 6));
    std::shared_ptr<ConcreteWarShip> Campbelltown(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 66, 1280,shipHeight,shipWidth,true,(std::string &)"Uk",ShipType::Destroyer,ModelType::Campbelltown,19,"Demolisher",4,0,0,numAntiAir));
    Campbelltown->attach(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 14, *Campbelltown)));
    Campbelltown->attach(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 40, *Campbelltown)));
    Campbelltown->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 40, *Campbelltown)));
    Campbelltown->attach(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 81, *Campbelltown)));
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        Campbelltown->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *Campbelltown)));
    }
    std::shared_ptr<LifeBar> life(new LifeBar(*Campbelltown));
    Campbelltown->attachBar(life);
    return Campbelltown;
}
std::shared_ptr<ConcreteWarShip>ShipFactory::leoneBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 13;
    int shipHeight = 113;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int numAntiAir = 20;
    //std::shared_ptr<ConcreteWarShip> Leone(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 61, 2326, 22,"Italy", 0, 0, 3, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Leone, 6));
    std::shared_ptr<ConcreteWarShip> Leone(new ConcreteWarShip(coordinates.x, coordinates.y,4,61,2326,shipHeight,shipWidth,true,(std::string &)"Italy",ShipType::Destroyer,ModelType::Leone,22,"Tokimune",0,3,0,numAntiAir));
    Leone->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 33, *Leone)));
    Leone->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 74, *Leone)));
    Leone->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 100, *Leone)));
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        Leone->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *Leone)));
    }
    std::shared_ptr<LifeBar> life(new LifeBar(*Leone));
    Leone->attachBar(life);
    return Leone;
}
std::shared_ptr<ConcreteWarShip>ShipFactory::fubukiBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 14;
    int shipHeight = 118;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 20;
    //std::shared_ptr<ConcreteWarShip> Fubuki(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 70, 2080, 26,"Japan", 0, 0, 6, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Fubuki, 9));
    std::shared_ptr<ConcreteWarShip> Fubuki(new ConcreteWarShip(coordinates.x,coordinates.y,4,70,2080,shipHeight,shipWidth,true,(std::string &)"Japan",ShipType::Destroyer,ModelType::Fubuki,26,"Hoimoto",0,6,0,numAntiAir));
    Fubuki->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 15, *Fubuki)));
    Fubuki->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 47, *Fubuki)));
    Fubuki->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 67, *Fubuki)));
    Fubuki->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 78, *Fubuki)));
    Fubuki->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 90, *Fubuki)));
    Fubuki->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 98, *Fubuki)));
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        Fubuki->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *Fubuki)));
    }
    std::shared_ptr<LifeBar> life(new LifeBar(*Fubuki));
    Fubuki->attachBar(life);
    return Fubuki;
}
std::shared_ptr<ConcreteWarShip>ShipFactory::akizukiBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 12;
    int shipHeight = 134;
    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 50;
    //std::shared_ptr<ConcreteWarShip> Akizuki(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 61, 3759, 33,"Japan", 0, 0, 5, numAntiAir, shipHeight, shipWidth, true,ShipType::Destroyer,ModelType::Akizuki, 4));
    std::shared_ptr<ConcreteWarShip> Akizuki(new ConcreteWarShip(coordinates.x, coordinates.y, 4, 61, 3759, shipHeight, shipWidth, true,(std::string &) "Japan", ShipType::Destroyer, ModelType::Akizuki, 33, "TheStriker", 0, 4, 0, numAntiAir));
    Akizuki->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 22, *Akizuki)));
    Akizuki->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 29, *Akizuki)));
    Akizuki->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 95, *Akizuki)));
    Akizuki->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 104, *Akizuki)));
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        Akizuki->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *Akizuki)));
    }
    std::shared_ptr<LifeBar> life(new LifeBar(*Akizuki));
    Akizuki->attachBar(life);
    return Akizuki;
}
sf::Vector2i ShipFactory::randomizeEnemyPositions(GameWorld &map) {
    Dice percentage(2, offset.x + 1);
    int xMap = map.getMapWidth();
    int yMap = map.getMapHeight();
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
sf::Vector2i ShipFactory::randomizeAlliedPositions(GameWorld &map) {
    Dice percentage(2, offsetAllied.x + 1);
    int xMap = map.getMapWidth();
    int yMap = map.getMapHeight();
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
std::shared_ptr<ConcreteWarShip> &ShipFactory::repositionEnemyShip(std::shared_ptr<ConcreteWarShip> &ship) {
    ship->getSprite().setOrigin(ship->getWidth() / 2, ship->getLength() / 2);
    ship->getSprite().rotate(180);
    ship->getSprite().move(0, ship->getLength() / 2);
    for (auto &it: ship->getArsenalList()) {
        it->getSprite().move(0, ship->getLength() / 2);
        it->getSprite().move((ship->getSprite().getPosition().x - it->getSprite().getPosition().x) * 2,
                             (ship->getSprite().getPosition().y - it->getSprite().getPosition().y) * 2);
    }
    for (auto &it: ship->getVehicleList()) {
        it->getSprite().move(0, ship->getLength() / 2);
        it->getSprite().move((ship->getSprite().getPosition().x - it->getSprite().getPosition().x) * 2,
                             (ship->getSprite().getPosition().y - it->getSprite().getPosition().y) * 2);
        it->getSprite().rotate(180);
    }
    return ship;
}
std::shared_ptr<ConcreteWarShip> &ShipFactory::repositionAlliedShip(std::shared_ptr<ConcreteWarShip> &ship) {
    ship->getSprite().setOrigin(ship->getWidth() / 2, ship->getLength() / 2);
    ship->getSprite().move(0, -ship->getLength() / 2);
    for (auto &it: ship->getArsenalList()) {
        it->getSprite().move(0, -ship->getLength() / 2);
        it->getSprite().rotate(180);
    }
    for (auto &it: ship->getVehicleList()) {
        it->getSprite().move(0, -ship->getLength() / 2);
    }
    sf::Vector2f f;
    f.x=0;
    f.y=0;
    ship->notifyBars(f,0);
    return ship;
}