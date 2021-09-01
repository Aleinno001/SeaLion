//
// Created by alessandro on 7/2/21.
//

#include "ShipFactory.h"
#include "GameWorld.h"
#include "AirplaneFactory.h"


std::unique_ptr<WarShip> ShipFactory::createSubmarine(ModelType type, GameWorld &map) {


    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::I400: {

            std::unique_ptr<WarShip> i400 = i400Builder(coordinates);
            repositionEnemyShip(i400);
            return std::move(i400);
        }
        case ModelType::typeb1: {
            std::unique_ptr<WarShip> typeb1 = typeb1Builder(coordinates);
            repositionEnemyShip(typeb1);
            return std::move(typeb1);
        }

        case ModelType::DaVinci: {
            std::unique_ptr<WarShip> daVinci = DaVinciBuilder(coordinates);
            repositionEnemyShip(daVinci);
            return std::move(daVinci);
        }
        case ModelType::Papa: {
            std::unique_ptr<WarShip> papa = papaBuilder(coordinates);
            repositionEnemyShip(papa);
            return std::move(papa);
        }
        case ModelType::Triton: {
            std::unique_ptr<WarShip> triton = tritonBuilder(coordinates);
            repositionEnemyShip(triton);
            return std::move(triton);
        }
        case ModelType::Trenchant: {
            std::unique_ptr<WarShip> trenchant = trenchantBuilder(coordinates);
            repositionEnemyShip(trenchant);
            return std::move(trenchant);
        }
        case ModelType::Gato: {
            std::unique_ptr<WarShip> gato = gatoBuilder(coordinates);
            repositionEnemyShip(gato);
            return std::move(gato);
        }
        case ModelType::Narwhal: {
            std::unique_ptr<WarShip> narwhal = narwhalBuilder(coordinates);
            repositionEnemyShip(narwhal);
            return std::move(narwhal);
        }
    }

}

std::unique_ptr<Submarine>
ShipFactory::gatoBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 9;
    int shipHeight = 95;

    std::unique_ptr<Submarine> Gato(
            new Submarine(coordinates.x, coordinates.y, 2, 37, 2460, 0, "Usa", 0, 0, 0, 0, shipHeight, shipWidth, true,
                          ShipType::Submarine, ModelType::Gato, 6, false));
    for (int i = 0; i < 6; i++)
        Gato->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *Gato)));
    return Gato;
}

std::unique_ptr<Submarine>
ShipFactory::tritonBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 8;
    int shipHeight = 84;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;


    std::unique_ptr<Submarine> Triton(
            new Submarine(coordinates.x, coordinates.y, 2, 28, 1576, 0, "Uk", 0, 0, 0, 0, shipHeight, shipWidth, true,
                          ShipType::Submarine, ModelType::Triton, 6, false));

    for (int i = 0; i < 6; i++)
        Triton->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *Triton)));
    return Triton;
}

std::unique_ptr<Submarine>
ShipFactory::DaVinciBuilder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 9;
    int shipHeight = 77;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    std::unique_ptr<Submarine> DaVinci(
            new Submarine(coordinates.x, coordinates.y, 2, 15, 1489, 0, "Italy", 0, 0, 0, 0, shipHeight, shipWidth,
                          true,
                          ShipType::Submarine, ModelType::DaVinci, 8, false));

    for (int i = 0; i < 8; i++)
        DaVinci->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *DaVinci)));

    return DaVinci;
}

std::unique_ptr<Submarine>
ShipFactory::typeb1Builder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 10;
    int shipHeight = 111;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    std::unique_ptr<Submarine> typeb1(
            new Submarine(coordinates.x, coordinates.y, 2, 44, 3713, 0, "Japan", 0, 0, 0, 0, shipHeight, shipWidth,
                          true,
                          ShipType::Submarine, ModelType::typeb1, 6,
                          false));

    for (int i = 0; i < 6; i++)
        typeb1->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *typeb1)));

    return typeb1;
}

std::unique_ptr<Submarine>
ShipFactory::i400Builder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 13;
    int shipHeight = 122;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;


    std::unique_ptr<Submarine> i400(
            new Submarine(coordinates.x, coordinates.y, 2, 35, 6670, 0, "Japan", 0, 0, 0, 0, shipHeight, shipWidth,
                          true,
                          ShipType::Submarine, ModelType::I400, 8, false));
    for (int i = 0; i < 8; i++)
        i400->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *i400)));
    return i400;
}

std::unique_ptr<WarShip> ShipFactory::createAircraftCarrier(ModelType type, GameWorld &map) {

    std::list<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {
        case ModelType::Tahio: {
            std::unique_ptr<WarShip> tahio = tahioBuilder(coordinates);
            repositionEnemyShip(tahio);
            return std::move(tahio);
        }


        case ModelType::Hiryu: {
            std::unique_ptr<WarShip> hiryu = hiryuBuilder(coordinates);
            repositionEnemyShip(hiryu);
            return std::move(hiryu);
        }

        case ModelType::GiuseppeGaribaldi: {
            std::unique_ptr<WarShip> giuseppeGaribaldi = giuseppeGaribaldiBuilder(coordinates);
            repositionEnemyShip(giuseppeGaribaldi);
            return std::move(giuseppeGaribaldi);
        }

        case ModelType::Cavour: {
            std::unique_ptr<WarShip> cavour = cavourBuilder(coordinates);
            repositionEnemyShip(cavour);
            return std::move(cavour);
        }
        case ModelType::ArkRoyal: {
            std::unique_ptr<WarShip> arkRoyal = arkRoyalBuilder(coordinates);
            repositionEnemyShip(arkRoyal);
            return std::move(arkRoyal);
        }

        case ModelType::Indomitable: {

            std::unique_ptr<WarShip> indomitable = indomitableBuilder(coordinates);
            repositionEnemyShip(indomitable);
            return std::move(indomitable);
        }

        case ModelType::Midway: {
            std::unique_ptr<WarShip> midway = midwayBuilder(coordinates);
            repositionEnemyShip(midway);
            return std::move(midway);
        }

        case ModelType::FranklinDRoosevelt: {
            std::unique_ptr<WarShip> franklinDRoosevelt = franklinDelanoRoosveltBuilder(coordinates);
            repositionEnemyShip(franklinDRoosevelt);
            return std::move(franklinDRoosevelt);
        }


    }

}

std::unique_ptr<AircraftCarrier>
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

    std::unique_ptr<AircraftCarrier> mid(new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 640000, 520,
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

    return mid;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::arkRoyalBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;

    int shipWidth = 38;
    int shipHeight = 240;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;



    WeaponFactory specialFactory;
    int numAntiAir = 4;

    std::unique_ptr<AircraftCarrier> arkRoyal(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 28160, 20,
                                "Uk", 2, 0, 0, numAntiAir, shipHeight, shipWidth, true, ShipType::AircraftCarrier,
                                ModelType::ArkRoyal, 7));
    arkRoyal->attach(std::move(factory.createLight(cannonPosX + 7, cannonPosY + 85, *arkRoyal)));
    arkRoyal->attach(std::move(factory.createLight(cannonPosX + 28, cannonPosY + 85, *arkRoyal)));
    for (int i = 0; i < numAntiAir; i++)
        arkRoyal->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *arkRoyal)));
    return arkRoyal;
}

std::unique_ptr<AircraftCarrier> ShipFactory::giuseppeGaribaldiBuilder(

        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 44;
    int shipHeight = 180;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;


    std::unique_ptr<AircraftCarrier> GiuseppeGaribaldi(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 14150, 114, "Italy", 3, 0, 0, 0, shipHeight,
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
    return GiuseppeGaribaldi;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::tahioBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;


    int shipWidth = 46;
    int shipHeight = 260;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;


    WeaponFactory specialFactory;
    int numAntiAir = 20;

    std::unique_ptr<AircraftCarrier> Tahio(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 37866, 304, "Japan", 2, 0, 0, numAntiAir,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::Tahio, 7));

    Tahio->attach(std::move(factory.createLight(cannonPosX + 20, cannonPosY + 55, *Tahio)));
    Tahio->attach(std::move(factory.createLight(cannonPosX + 20, cannonPosY + 218, *Tahio)));

    for (int i = 0; i < numAntiAir; i++)
        Tahio->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *Tahio)));
    return Tahio;
}

std::unique_ptr<WarShip> ShipFactory::createCruiser(ModelType type, GameWorld &map) {

    std::list<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::Takao: {
            std::unique_ptr<WarShip> takao = takaoBuilder(coordinates);
            repositionEnemyShip(takao);
            return std::move(takao);
        }

        case ModelType::IsuzuNagara: {
            std::unique_ptr<WarShip> isuzuNagara = isuzuNagaraBuilder(coordinates);
            repositionEnemyShip(isuzuNagara);
            return std::move(isuzuNagara);
        }


        case ModelType::Ijn: {
            std::unique_ptr<WarShip> ijn = ijnBuilder(coordinates);
            repositionEnemyShip(ijn);
            return std::move(ijn);
        }


        case ModelType::AlbertoDiGiussano: {
            std::unique_ptr<WarShip> albertoDiGiussano = albertoDiGiussanoBuilder(coordinates);
            repositionEnemyShip(albertoDiGiussano);
            return std::move(albertoDiGiussano);
        }

        case ModelType::Gorizia: {
            std::unique_ptr<WarShip> gorizia = goriziaBuilder(coordinates);
            repositionEnemyShip(gorizia);
            return std::move(gorizia);
        }

        case ModelType::Trento: {
            std::unique_ptr<WarShip> trento = trentoBuilder(coordinates);
            repositionEnemyShip(trento);
            return std::move(trento);
        }
        case ModelType::Belfast: {
            std::unique_ptr<WarShip> belfast = belfastBuilder(coordinates);
            repositionEnemyShip(belfast);
            return std::move(belfast);
        }

        case ModelType::Danae: {
            std::unique_ptr<WarShip> danae = danaeBuilder(coordinates);
            repositionEnemyShip(danae);
            return std::move(danae);
        }

        case ModelType::Tiger59: {
            std::unique_ptr<WarShip> tiger59 = tiger59Builder(coordinates);
            repositionEnemyShip(tiger59);
            return std::move(tiger59);
        }
        case ModelType::Alaska: {
            std::unique_ptr<WarShip> alaska = alaskaBuilder(coordinates);
            repositionEnemyShip(alaska);
            return std::move(alaska);
        }
        case ModelType::NewOrleans: {
            std::unique_ptr<WarShip> newOrleans = newOrleansBuilder(coordinates);
            repositionEnemyShip(newOrleans);
            return std::move(newOrleans);
        }
        case ModelType::StLouis: {
            std::unique_ptr<WarShip> saintLouis = stLouisBuilder(coordinates);
            repositionEnemyShip(saintLouis);
            return std::move(saintLouis);
        }
    }

}

//TODO aggiungere aerei
std::unique_ptr<Cruiser>
ShipFactory::stLouisBuilder(
        sf::Vector2i &coordinates) const {

    int shipWidth = 20;
    int shipHeight = 130;

    int cannonPosX =
            coordinates.x -
            (shipWidth) /
            2;
    int cannonPosY =
            coordinates.y -
            (shipHeight) /
            2;


    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 8;


    std::unique_ptr<Cruiser> saintLouis(
            new Cruiser(
                    coordinates.x,
                    coordinates.y,
                    3,
                    41,
                    11013,
                    280,
                    "Usa",
                    5,
                    0,
                    3,
                    antiAir,


                    shipHeight,
                    shipWidth,
                    true,
                    ShipType::Cruiser,
                    ModelType::StLouis,
                    0));
    saintLouis->attach(
            std::move(
                    cf.createMedium(
                            cannonPosX +
                            7,
                            cannonPosY +
                            21, *saintLouis)));
    saintLouis->attach(
            std::move(
                    cf.createMedium(
                            cannonPosX +
                            7,
                            cannonPosY +
                            34, *saintLouis)));
    saintLouis->attach(
            std::move(
                    cf.createMedium(
                            cannonPosX +
                            7,
                            cannonPosY +
                            111, *saintLouis)));
    saintLouis->attach(
            std::move(
                    cf.createLight(
                            cannonPosX +
                            1,
                            cannonPosY +
                            71, *saintLouis)));
    saintLouis->attach(
            std::move(
                    cf.createLight(
                            cannonPosX +
                            15,
                            cannonPosY +
                            71, *saintLouis)));
    saintLouis->attach(
            std::move(
                    cf.createLight(
                            cannonPosX +
                            8,
                            cannonPosY +
                            80, *saintLouis)));
    saintLouis->attach(
            std::move(
                    cf.createLight(
                            cannonPosX +
                            2,
                            cannonPosY +
                            41, *saintLouis)));
    saintLouis->attach(
            std::move(
                    cf.createLight(
                            cannonPosX +
                            16,
                            cannonPosY +
                            41, *saintLouis)));
    for (int i = 0;
         i <
         antiAir; i++)
        saintLouis->attach(
                std::move(
                        factory.createSpecialWeapon(
                                WeaponType::antiAir, *saintLouis)));
    return saintLouis;
}

std::unique_ptr<Cruiser>
ShipFactory::alaskaBuilder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 28;
    int shipHeight = 246;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    CannonFactory cf;
    int antiAir = 9;


    std::unique_ptr<Cruiser> alaska(new Cruiser(coordinates.x, coordinates.y, 3, 61, 34803, 918,
                                                "Usa", 6, 1, 2, antiAir, shipHeight, shipWidth, true,
                                                ShipType::Cruiser,
                                                ModelType::Alaska, 4));
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

    return alaska;
}

std::unique_ptr<Cruiser>
ShipFactory::danaeBuilder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 14;
    int shipHeight = 136;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    CannonFactory cf;
    int antiAir = 7;

    std::unique_ptr<Cruiser> danae(new Cruiser(coordinates.x, coordinates.y, 3, 54, 5925, 190,
                                               "Uk", 6, 0, 1, antiAir, shipHeight, shipWidth, true,
                                               ShipType::Cruiser,
                                               ModelType::Danae, 0));

    danae->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 111, *danae)));
    danae->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 102, *danae)));
    danae->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 120, *danae)));
    danae->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 74, *danae)));
    danae->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 45, *danae)));
    danae->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 33, *danae)));
    danae->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 19, *danae)));
    for (int i = 0; i < antiAir; i++)
        danae->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *danae)));
    return danae;
}

std::unique_ptr<Cruiser>
ShipFactory::trentoBuilder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 25;
    int shipHeight = 197;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    CannonFactory cf;
    int antiAir = 12;


    std::unique_ptr<Cruiser> trento(new Cruiser(coordinates.x, coordinates.y, 3, 66, 13548, 120,
                                                "Italy", 6, 0, 4, antiAir, shipHeight, shipWidth, true,
                                                ShipType::Cruiser,
                                                ModelType::Trento, 2));
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
    return trento;
}

std::unique_ptr<Cruiser> ShipFactory::albertoDiGiussanoBuilder(

        sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 15;
    int shipHeight = 169;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    CannonFactory cf;
    int antiAir = 12;


    std::unique_ptr<Cruiser> albertoDiGiussano(new Cruiser(coordinates.x, coordinates.y, 3, 69, 6950, 84,
                                                           "Italy", 3, 0, 4, antiAir, shipHeight, shipWidth, true,
                                                           ShipType::Cruiser,
                                                           ModelType::AlbertoDiGiussano, 1));

    albertoDiGiussano->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 18, *albertoDiGiussano)));
    albertoDiGiussano->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 28, *albertoDiGiussano)));
    albertoDiGiussano->attach(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 121, *albertoDiGiussano)));
    albertoDiGiussano->attach(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 135, *albertoDiGiussano)));
    albertoDiGiussano->attach(std::move(cf.createLight(cannonPosX, cannonPosY + 93, *albertoDiGiussano)));
    albertoDiGiussano->attach(std::move(cf.createLight(cannonPosX + 10, cannonPosY + 93, *albertoDiGiussano)));
    albertoDiGiussano->attach(std::move(cf.createLight(cannonPosX + 6, cannonPosY + 112, *albertoDiGiussano)));

    for (int i = 0; i < antiAir; i++)
        albertoDiGiussano->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *albertoDiGiussano)));
    return albertoDiGiussano;
}

std::unique_ptr<Cruiser>
ShipFactory::takaoBuilder(
        sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 25;
    int shipHeight = 193;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    CannonFactory cf;
    int antiAir = 16;

    std::unique_ptr<Cruiser> takao(new Cruiser(coordinates.x, coordinates.y, 3, 66, 15500, 237,
                                               "Japan", 4, 0, 5, antiAir, shipHeight, shipWidth, true,
                                               ShipType::Cruiser,
                                               ModelType::Takao, 2));
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
    return takao;
}

std::unique_ptr<WarShip> ShipFactory::createBattleship(ModelType type, GameWorld &map) {

    std::list<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::Yamato: {
            std::unique_ptr<WarShip> yamato = yamatoBuilder(coordinates);
            repositionEnemyShip(yamato);
            return std::move(yamato);
        }

        case ModelType::Kongo: {
            std::unique_ptr<WarShip> kongo = kongoBuilder(coordinates);
            repositionEnemyShip(kongo);
            return std::move(kongo);
        }

        case ModelType::ISE: {
            std::unique_ptr<WarShip> ise = iseBuilder(coordinates);
            repositionEnemyShip(ise);
            return std::move(ise);
        }

        case ModelType::Musashi: {
            std::unique_ptr<WarShip> musashi = musashiBuilder(coordinates);
            repositionEnemyShip(musashi);
            return std::move(musashi);
        }

        case ModelType::AndreaDoria: {
            std::unique_ptr<WarShip> andreaDoria = andreaDoriaBuilder(coordinates);
            repositionEnemyShip(andreaDoria);
            return std::move(andreaDoria);
        }

        case ModelType::ImperatoreAugusto: {
            std::unique_ptr<WarShip> imperatoreAugusto = imperatoreAugustoBuilder(coordinates);
            repositionEnemyShip(imperatoreAugusto);
            return std::move(imperatoreAugusto);
        }
        case ModelType::VittorioVeneto: {
            std::unique_ptr<WarShip> vittorioVeneto = vittorioVenetoBuilder(coordinates);
            repositionEnemyShip(vittorioVeneto);
            return std::move(vittorioVeneto);
        }

        case ModelType::MichelangeloBuonarroti: {
            std::unique_ptr<WarShip> michelangeloBuonarroti = michelangeloBuonarrotiBuilder(coordinates);
            repositionEnemyShip(michelangeloBuonarroti);
            return std::move(michelangeloBuonarroti);
        }
        case ModelType::Dreadnought: {
            std::unique_ptr<WarShip> dreadNought = dreadNoughtBuilder(coordinates);
            repositionEnemyShip(dreadNought);
            return std::move(dreadNought);
        }
        case ModelType::IronDuke: {
            std::unique_ptr<WarShip> ironDuke = ironDukeBuilder(coordinates);
            repositionEnemyShip(ironDuke);
            return std::move(ironDuke);
        }
        case ModelType::Lion: {
            std::unique_ptr<WarShip> lion = lionBuilder(coordinates);
            repositionEnemyShip(lion);
            return std::move(lion);
        }
        case ModelType::Hood: {
            std::unique_ptr<WarShip> hood = hoodBuilder(coordinates);
            repositionEnemyShip(hood);
            return std::move(hood);
        }
        case ModelType::Arizona: {
            std::unique_ptr<WarShip> arizona = arizonaBuilder(coordinates);
            repositionEnemyShip(arizona);
            return std::move(arizona);
        }
        case ModelType::Montana: {
            std::unique_ptr<WarShip> montana = montanaBuilder(coordinates);
            repositionEnemyShip(montana);
            return std::move(montana);
        }
        case ModelType::NewYork: {
            std::unique_ptr<WarShip> newYork = newYorkBuilder(coordinates);
            repositionEnemyShip(newYork);
            return std::move(newYork);
        }
        case ModelType::NorthCarolina: {
            std::unique_ptr<WarShip> northCarolina = northCarolinaBuilder(coordinates);
            repositionEnemyShip(northCarolina);
            return std::move(northCarolina);
        }
    }
    return std::unique_ptr<WarShip>(); //TODO implementare tutti i costruttori
}

std::unique_ptr<Battleship>
ShipFactory::ironDukeBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 190;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 15;
    std::unique_ptr<Battleship> ironDuke(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 29500, 826,
                           "Uk", 0, 5, 0, numAntiAir, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::IronDuke, 0));
    ironDuke->attach(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 35, *ironDuke)));
    ironDuke->attach(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 49, *ironDuke)));
    ironDuke->attach(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 101, *ironDuke)));
    ironDuke->attach(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 127, *ironDuke)));
    ironDuke->attach(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 135, *ironDuke)));
    WeaponFactory specialFactory;

    for (int i = 0; i < numAntiAir; i++)
        ironDuke->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *ironDuke)));
    return ironDuke;
}

std::unique_ptr<Battleship>
ShipFactory::northCarolinaBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 32;
    int shipHeight = 222;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 34;

    std::unique_ptr<Battleship> northCarolina(
            new Battleship(coordinates.x, coordinates.y, 1, 52, 45500, 1224,
                           "Usa", 6, 2, 0, numAntiAir, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::NorthCarolina, 3));
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
    return northCarolina;
}

std::unique_ptr<Battleship>
ShipFactory::montanaBuilder(
        sf::Vector2i &coordinates) const {
    //TODO concludere tutte le aggiunte necessarie
    CannonFactory factory;
    int shipWidth = 37;
    int shipHeight = 281;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int numAntiAir = 80;

    std::unique_ptr<Battleship> montana(
            new Battleship(coordinates.x, coordinates.y, 1, 52, 72104, 1810,
                           "Usa", 0, 4, 10, numAntiAir, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::Montana, 2));
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
    return montana;
}

std::unique_ptr<Battleship>
ShipFactory::lionBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 242;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 10;
    std::unique_ptr<Battleship> lion(
            new Battleship(coordinates.x, coordinates.y, 1, 52, 49670, 944,
                           "Uk", 0, 4, 0, numAntiAir, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::Lion, 0));
    lion->attach(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 43, *lion)));
    lion->attach(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 58, *lion)));
    lion->attach(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 120, *lion)));
    lion->attach(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 191, *lion)));
    WeaponFactory specialFactory;

    for (int i = 0; i < numAntiAir; i++)
        lion->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *lion)));
    return lion;
}

std::unique_ptr<Battleship>
ShipFactory::dreadNoughtBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 25;
    int shipHeight = 158;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 20;
    std::unique_ptr<Battleship> dreadNought(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 21060, 837,
                           "Uk", 0, 5, 0, numAntiAir, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::Dreadnought, 0));
    dreadNought->attach(std::move(factory.createHeavly(cannonPosX + 5, cannonPosY + 32, *dreadNought)));
    dreadNought->attach(std::move(factory.createHeavly(cannonPosX + 5, cannonPosY + 87, *dreadNought)));
    dreadNought->attach(std::move(factory.createHeavly(cannonPosX + 5, cannonPosY + 112, *dreadNought)));
    dreadNought->attach(std::move(factory.createHeavly(cannonPosX - 1, cannonPosY + 58, *dreadNought)));
    dreadNought->attach(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 58, *dreadNought)));
    WeaponFactory specialFactory;

    for (int i = 0; i < numAntiAir; i++)
        dreadNought->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *dreadNought)));
    return dreadNought;
}

std::unique_ptr<Battleship> ShipFactory::imperatoreAugustoBuilder(

        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 274;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 12;

    std::unique_ptr<Battleship> imperatoreAugusto(
            new Battleship(coordinates.x, coordinates.y, 1, 57, 65232, 1126,
                           "Italy", 16, 4, 10, numAntiAir, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::ImperatoreAugusto, 0));
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
    return imperatoreAugusto;
}

std::unique_ptr<Battleship>
ShipFactory::kongoBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 31;
    int shipHeight = 222;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 18;
    std::unique_ptr<Battleship> kongo(new Battleship(coordinates.x, coordinates.y, 1, 56, 37187, 592,
                                                     "Japan", 6, 4, 0, numAntiAir, shipHeight, shipWidth, true,
                                                     ShipType::Battleship,
                                                     ModelType::Kongo, 0));
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
    return kongo;
}

std::unique_ptr<Battleship>
ShipFactory::musashiBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 244;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 30;

    std::unique_ptr<Battleship> musashi(new Battleship(coordinates.x, coordinates.y, 1, 51, 72809, 1540,
                                                       "Japan", 6, 3, 2, numAntiAir, shipHeight, shipWidth, true,
                                                       ShipType::Battleship,
                                                       ModelType::Musashi, 2));
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
    return musashi;
}

std::unique_ptr<WarShip> ShipFactory::createDestroyer(ModelType type, GameWorld &map) {

    std::list<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::Akizuki: {
            std::unique_ptr<WarShip> akizuki = akizukiBuilder(coordinates);
            repositionEnemyShip(akizuki);
            return std::move(akizuki);
        }

        case ModelType::Yukikaze: {
            std::unique_ptr<WarShip> yukikaze = yukikazeBuilder(coordinates);
            repositionEnemyShip(yukikaze);
            return std::move(yukikaze);
        }
        case ModelType::Fubuki: {
            std::unique_ptr<WarShip> fubuki = fubukiBuilder(coordinates);
            repositionEnemyShip(fubuki);
            return std::move(fubuki);
        }
        case ModelType::Impavido: {
            std::unique_ptr<WarShip> impavido = impavidoBuilder(coordinates);
            repositionEnemyShip(impavido);
            return std::move(impavido);
        }

        case ModelType::Leone: {
            std::unique_ptr<WarShip> leone = leoneBuilder(coordinates);
            repositionEnemyShip(leone);
            return std::move(leone);
        }

        case ModelType::PaoloEmilio: {
            std::unique_ptr<WarShip> paoloEmilio = paoloEmilioBuilder(coordinates);
            repositionEnemyShip(paoloEmilio);
            return std::move(paoloEmilio);
        }
        case ModelType::Campbelltown: {
            std::unique_ptr<WarShip> campbelltown = campbeltownBuilder(coordinates);
            repositionEnemyShip(campbelltown);
            return std::move(campbelltown);
        }

        case ModelType::Jutland: {
            std::unique_ptr<WarShip> jutLand = jutlandBuilder(coordinates);
            repositionEnemyShip(jutLand);
            return std::move(jutLand);
        }

        case ModelType::Gallant: {
            std::unique_ptr<WarShip> gallant = gallandBuilder(coordinates);
            repositionEnemyShip(gallant);
            return std::move(gallant);
        }

        case ModelType::Fletcher: {
            std::unique_ptr<WarShip> fletcher = fletcherBuilder(coordinates);
            repositionEnemyShip(fletcher);
            return std::move(fletcher);
        }

        case ModelType::Mahan: {
            std::unique_ptr<WarShip> mahan = mahanBuilder(coordinates);
            repositionEnemyShip(mahan);
            return std::move(mahan);


        }
        case ModelType::Sims: {
            std::unique_ptr<WarShip> sims = simsBuilder(coordinates);
            repositionEnemyShip(sims);
            return std::move(sims);
        }
    }

}

std::unique_ptr<Destroyer>
ShipFactory::simsBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 16;
    int shipHeight = 106;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    int numAntiAir = 16;
    WeaponFactory wf;


    std::unique_ptr<Destroyer> sims(
            new Destroyer(coordinates.x, coordinates.y, 4, 69, 2293, 30,
                          "Usa", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Sims, 8));

    sims->attach(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 12, *sims)));
    sims->attach(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 23, *sims)));
    sims->attach(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 78, *sims)));
    sims->attach(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 90, *sims)));

    for (int i = 0; i < numAntiAir; i++) {
        sims->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *sims)));
    }
    return sims;
}

std::unique_ptr<Destroyer>
ShipFactory::fletcherBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 12;
    int shipHeight = 114;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    int numAntiAir = 14;
    WeaponFactory wf;


    std::unique_ptr<Destroyer> fletcher(
            new Destroyer(coordinates.x, coordinates.y, 4, 68, 2500, 33,
                          "Usa", 0, 0, 5, numAntiAir, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Fletcher, 10));
    fletcher->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 97, *fletcher)));
    fletcher->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 85, *fletcher)));
    fletcher->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 73, *fletcher)));
    fletcher->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 15, *fletcher)));
    fletcher->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 27, *fletcher)));
    for (int i = 0; i < numAntiAir; i++) {
        fletcher->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *fletcher)));
    }
    return fletcher;
}

std::unique_ptr<Destroyer>
ShipFactory::jutlandBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 13;
    int shipHeight = 116;
    WeaponFactory wf;
    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    int numAntiAir = 16;

    std::unique_ptr<Destroyer> jutLand(
            new Destroyer(coordinates.x, coordinates.y, 4, 66, 2480, 26,
                          "Uk", 0, 0, 3, numAntiAir, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Jutland, 10));
    jutLand->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 18, *jutLand)));
    jutLand->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 28, *jutLand)));
    jutLand->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 95, *jutLand)));
    for (int i = 0; i < numAntiAir; i++) {
        jutLand->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *jutLand)));
    }
    return jutLand;
}

std::unique_ptr<Destroyer>
ShipFactory::paoloEmilioBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 15;
    int shipHeight = 172;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    int numAntiAir = 12;
    WeaponFactory wf;

    std::unique_ptr<Destroyer> paoloEmilio(
            new Destroyer(coordinates.x, coordinates.y, 4, 76, 5420, 66,
                          "Italy", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::PaoloEmilio, 8));
    paoloEmilio->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 30, *paoloEmilio)));
    paoloEmilio->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 38, *paoloEmilio)));
    paoloEmilio->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 134, *paoloEmilio)));
    paoloEmilio->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 142, *paoloEmilio)));

    for (int i = 0; i < numAntiAir; i++) {
        paoloEmilio->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *paoloEmilio)));
    }
    return paoloEmilio;
}

std::unique_ptr<Destroyer>
ShipFactory::impavidoBuilder(
        sf::Vector2i &coordinates) const {

    CannonFactory cf;
    int shipWidth = 15;
    int shipHeight = 131;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    int numAntiAir = 40;
    WeaponFactory wf;

    std::unique_ptr<Destroyer> impavido(
            new Destroyer(coordinates.x, coordinates.y, 4, 63, 3941, 36,
                          "Italy", 4, 0, 1, numAntiAir, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Impavido, 6));
    impavido->attach(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 13, *impavido)));
    impavido->attach(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 67, *impavido)));
    impavido->attach(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 79, *impavido)));
    impavido->attach(std::move(cf.createLight(cannonPosX + 10, cannonPosY + 67, *impavido)));
    impavido->attach(std::move(cf.createLight(cannonPosX + 10, cannonPosY + 79, *impavido)));
    for (int i = 0; i < numAntiAir; i++) {
        impavido->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *impavido)));
    }
    return impavido;
}

std::unique_ptr<Destroyer>
ShipFactory::yukikazeBuilder(
        sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 12;
    int shipHeight = 119;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    int numAntiAir = 32;
    WeaponFactory wf;

    std::unique_ptr<Destroyer> yukikaze(
            new Destroyer(coordinates.x, coordinates.y, 4, 65, 2530, 26,
                          "Japan", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Yukikaze, 8));
    yukikaze->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 16, *yukikaze)));
    yukikaze->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 51, *yukikaze)));
    yukikaze->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 70, *yukikaze)));
    yukikaze->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 93, *yukikaze)));
    for (int i = 0; i < numAntiAir; i++) {
        yukikaze->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *yukikaze)));
    }
    return yukikaze;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedSubmarine(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;
    coordinates.y = coordinates.y + (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::I400: {
            std::unique_ptr<WarShip> i400 = i400Builder(coordinates);
            repositionAlliedShip(i400);
            return std::move(i400);
        }

        case ModelType::typeb1: {
            std::unique_ptr<WarShip> typeb1 = typeb1Builder(coordinates);
            repositionAlliedShip(typeb1);
            return std::move(typeb1);
        }

        case ModelType::DaVinci: {
            std::unique_ptr<WarShip> DaVinci = DaVinciBuilder(coordinates);
            repositionAlliedShip(DaVinci);
            return std::move(DaVinci);
        }

        case ModelType::Papa: {
            std::unique_ptr<WarShip> papa = papaBuilder(coordinates);
            repositionAlliedShip(papa);
            return std::move(papa);
        }

        case ModelType::Triton: {
            std::unique_ptr<WarShip> triton = tritonBuilder(coordinates);
            repositionAlliedShip(triton);
            return std::move(triton);
        }

        case ModelType::Trenchant: {
            std::unique_ptr<WarShip> trenchant = trenchantBuilder(coordinates);
            repositionAlliedShip(trenchant);
            return std::move(trenchant);
        }

        case ModelType::Gato: {
            std::unique_ptr<WarShip> gato = gatoBuilder(coordinates);
            repositionAlliedShip(gato);
            return std::move(gato);
        }

        case ModelType::Narwhal: {
            std::unique_ptr<WarShip> narwhal = narwhalBuilder(coordinates);
            repositionAlliedShip(narwhal);
            return std::move(narwhal);
        }
    }

}

std::unique_ptr<Submarine>
ShipFactory::narwhalBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 13;
    int shipHeight = 91;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    std::unique_ptr<Submarine> Narwhal(
            new Submarine(coordinates.x, coordinates.y, 2, 48, 4600, 0, "Usa", 0, 0, 0, 0, shipHeight, shipWidth, true,
                          ShipType::Submarine, ModelType::Narwhal, 4, false));
    for (int i = 0; i < 4; i++)
        Narwhal->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *Narwhal)));
    return Narwhal;
}

std::unique_ptr<Submarine>
ShipFactory::trenchantBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 14;
    int shipHeight = 85;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    std::unique_ptr<Submarine> Trenchant(
            new Submarine(coordinates.x, coordinates.y, 2, 56, 5800, 0, "Uk", 0, 0, 0, 0, shipHeight, shipWidth, true,
                          ShipType::Submarine, ModelType::Trenchant, 5, false));
    for (int i = 0; i < 5; i++)
        Trenchant->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *Trenchant)));
    return Trenchant;
}

std::unique_ptr<Submarine>
ShipFactory::papaBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 19;
    int shipHeight = 106;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    std::unique_ptr<Submarine> Papa(
            new Submarine(coordinates.x, coordinates.y, 2, 82, 7100, 0, "Italy", 0, 0, 0, 0, shipHeight, shipWidth,
                          true,
                          ShipType::Submarine, ModelType::Papa, 10, false));
    for (int i = 0; i < 10; i++)
        Papa->attach(std::move(factory.createSpecialWeapon(WeaponType::torpedo, *Papa)));
    return Papa;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedAircraftCarrier(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;
    coordinates.y = coordinates.y + (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::Tahio: {
            std::unique_ptr<WarShip> tahio = tahioBuilder(coordinates);
            repositionAlliedShip(tahio);
            return std::move(tahio);
        }


        case ModelType::Hiryu: {
            std::unique_ptr<WarShip> hiryu = hiryuBuilder(coordinates);
            repositionAlliedShip(hiryu);
            return std::move(hiryu);
        }

        case ModelType::GiuseppeGaribaldi: {
            std::unique_ptr<WarShip> giuseppeGaribaldi = giuseppeGaribaldiBuilder(coordinates);
            repositionAlliedShip(giuseppeGaribaldi);
            return std::move(giuseppeGaribaldi);
        }

        case ModelType::Cavour: {
            std::unique_ptr<WarShip> cavour = cavourBuilder(coordinates);
            repositionAlliedShip(cavour);
            return std::move(cavour);
        }

        case ModelType::ArkRoyal: {
            std::unique_ptr<WarShip> arkRoyal = arkRoyalBuilder(coordinates);
            repositionAlliedShip(arkRoyal);
            return std::move(arkRoyal);
        }


        case ModelType::Indomitable: {
            std::unique_ptr<WarShip> indomitable = indomitableBuilder(coordinates);
            repositionAlliedShip(indomitable);
            return std::move(indomitable);
        }

        case ModelType::Midway: {
            std::unique_ptr<WarShip> midway = midwayBuilder(coordinates);
            repositionAlliedShip(midway);
            return std::move(midway);
        }

        case ModelType::FranklinDRoosevelt: {
            std::unique_ptr<WarShip> franklinDRoosevelt = franklinDelanoRoosveltBuilder(coordinates);
            repositionAlliedShip(franklinDRoosevelt);
            return std::move(franklinDRoosevelt);
        }

    }

}

std::unique_ptr<AircraftCarrier>
ShipFactory::franklinDelanoRoosveltBuilder(sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 70;
    int shipHeight = 295;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    WeaponFactory specialFactory;
    int numAntiAir = 8;


    std::unique_ptr<AircraftCarrier> FranklinDRoosevelt(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 45000, 363, "Usa", 0, 0, 2, numAntiAir,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::FranklinDRoosevelt, 14));
    FranklinDRoosevelt->attach(std::move(factory.createMedium(cannonPosX + 55, cannonPosY + 92, *FranklinDRoosevelt)));
    FranklinDRoosevelt->attach(std::move(factory.createMedium(cannonPosX + 56, cannonPosY + 179, *FranklinDRoosevelt)));
    for (int i = 0; i < numAntiAir; i++)
        FranklinDRoosevelt->attach(
                std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *FranklinDRoosevelt)));
    return FranklinDRoosevelt;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::indomitableBuilder(sf::Vector2i &coordinates) const {
    CannonFactory factory;


    int shipWidth = 41;
    int shipHeight = 230;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;


    WeaponFactory specialFactory;
    int numAntiAir = 6;

    std::unique_ptr<AircraftCarrier> Indomitable(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 29730, 240, "Uk", 2, 0, 0, numAntiAir,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::Indomitable, 5));
    Indomitable->attach(std::move(factory.createLight(cannonPosX + 6, cannonPosY + 38, *Indomitable)));
    Indomitable->attach(std::move(factory.createLight(cannonPosX + 31, cannonPosY + 38, *Indomitable)));

    for (int i = 0; i < numAntiAir; i++)
        Indomitable->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *Indomitable)));
    return Indomitable;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::cavourBuilder(sf::Vector2i &coordinates) const {
    CannonFactory factory;
    AirplaneFactory airPlanesFactory;
    int shipWidth = 50;
    int shipHeight = 244;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;


    WeaponFactory specialFactory;
    int numAntiAir = 3;


    std::unique_ptr<AircraftCarrier> Cavour(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 52, 29900, 241, "Italy", 4, 0, 0, numAntiAir,
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



    return Cavour;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::hiryuBuilder(sf::Vector2i &coordinates) const {
    CannonFactory factory;

    int shipWidth = 39;
    int shipHeight = 222;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;


    WeaponFactory specialFactory;
    int numAntiAir = 2;


    std::unique_ptr<AircraftCarrier> Hiryu(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 63, 20570, 70, "Japan", 2, 0, 0, numAntiAir,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::Hiryu, 6));
    Hiryu->attach(std::move(factory.createLight(cannonPosX + 18, cannonPosY + 3, *Hiryu)));
    Hiryu->attach(std::move(factory.createLight(cannonPosX + 5, cannonPosY + 61, *Hiryu)));
    for (int i = 0; i < numAntiAir; i++)
        Hiryu->attach(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir, *Hiryu)));
    return Hiryu;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedCruiser(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;
    coordinates.y = coordinates.y + (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::Ijn: {
            std::unique_ptr<WarShip> ijn = ijnBuilder(coordinates);
            repositionAlliedShip(ijn);
            return std::move(ijn);
        }

        case ModelType::IsuzuNagara: {
            std::unique_ptr<WarShip> isuzuNagara = isuzuNagaraBuilder(coordinates);
            repositionAlliedShip(isuzuNagara);
            return std::move(isuzuNagara);
        }

        case ModelType::Takao: {
            std::unique_ptr<WarShip> takao = takaoBuilder(coordinates);
            repositionAlliedShip(takao);
            return std::move(takao);
        }

        case ModelType::AlbertoDiGiussano: {
            std::unique_ptr<WarShip> albertoDiGiussano = albertoDiGiussanoBuilder(coordinates);
            repositionAlliedShip(albertoDiGiussano);
            return std::move(albertoDiGiussano);
        }

        case ModelType::Gorizia: {
            std::unique_ptr<WarShip> gorizia = goriziaBuilder(coordinates);
            repositionAlliedShip(gorizia);
            return std::move(gorizia);
        }


        case ModelType::Trento: {
            std::unique_ptr<WarShip> trento = trentoBuilder(coordinates);
            repositionAlliedShip(trento);
            return std::move(trento);
        }


        case ModelType::Belfast: {
            std::unique_ptr<WarShip> belfast = belfastBuilder(coordinates);
            repositionAlliedShip(belfast);
            return std::move(belfast);
        }

        case ModelType::Danae: {
            std::unique_ptr<WarShip> danae = danaeBuilder(coordinates);
            repositionAlliedShip(danae);
            return std::move(danae);
        }


        case ModelType::Tiger59: {
            std::unique_ptr<WarShip> tiger59 = tiger59Builder(coordinates);
            repositionAlliedShip(tiger59);
            return std::move(tiger59);
        }


        case ModelType::Alaska: {
            std::unique_ptr<WarShip> alaska = alaskaBuilder(coordinates);
            repositionAlliedShip(alaska);
            return std::move(alaska);
        }


        case ModelType::NewOrleans: {
            std::unique_ptr<WarShip> newOrleans = newOrleansBuilder(coordinates);
            repositionAlliedShip(newOrleans);
            return std::move(newOrleans);
        }


        case ModelType::StLouis: {

            std::unique_ptr<WarShip> saintLouis = stLouisBuilder(coordinates);
            repositionAlliedShip(saintLouis);
            return std::move(saintLouis);
        }


    }

}


std::unique_ptr<Cruiser>
ShipFactory::newOrleansBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 25;
    int shipHeight = 178;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    CannonFactory cf;
    int antiAir = 12;

    std::unique_ptr<Cruiser> NewOrleans(
            new Cruiser(coordinates.x, coordinates.y, 3, 61, 12663, 476, "Usa", 6, 0, 3, antiAir, shipHeight,
                        shipWidth,
                        true,
                        ShipType::Cruiser, ModelType::NewOrleans, 0));
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
    return NewOrleans;
}

std::unique_ptr<Cruiser>
ShipFactory::tiger59Builder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 19;
    int shipHeight = 169;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    CannonFactory cf;
    int antiAir = 7;

    std::unique_ptr<Cruiser> Tiger59(
            new Cruiser(coordinates.x, coordinates.y, 3, 58, 12080, 191, "Uk", 6, 0, 4, antiAir, shipHeight,
                        shipWidth,
                        true,
                        ShipType::Cruiser, ModelType::Tiger59, 2));
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
    return Tiger59;
}

std::unique_ptr<Cruiser>
ShipFactory::belfastBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 27;
    int shipHeight = 187;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    CannonFactory cf;
    int antiAir = 12;

    std::unique_ptr<Cruiser> Belfast(
            new Cruiser(coordinates.x, coordinates.y, 3, 59, 11550, 228, "Uk", 6, 0, 4, antiAir, shipHeight,
                        shipWidth,
                        true,
                        ShipType::Cruiser, ModelType::Belfast, 1));
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
    return Belfast;
}

std::unique_ptr<Cruiser>
ShipFactory::goriziaBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 22;
    int shipHeight = 183;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    CannonFactory cf;
    int antiAir = 12;

    std::unique_ptr<Cruiser> Gorizia(
            new Cruiser(coordinates.x, coordinates.y, 3, 59, 14330, 370, "Italy", 6, 0, 4, antiAir, shipHeight,
                        shipWidth,
                        true,
                        ShipType::Cruiser, ModelType::Gorizia, 0));
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
    return Gorizia;
}

std::unique_ptr<Cruiser>
ShipFactory::isuzuNagaraBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 14;
    int shipHeight = 159;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    CannonFactory cf;
    int antiAir = 6;

    std::unique_ptr<Cruiser> IsuzuNagara(
            new Cruiser(coordinates.x, coordinates.y, 3, 67, 5700, 90, "Japan", 5, 0, 3, antiAir, shipHeight,
                        shipWidth,
                        true,
                        ShipType::Cruiser, ModelType::IsuzuNagara, 1));
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
    return IsuzuNagara;
}

std::unique_ptr<Cruiser>
ShipFactory::ijnBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 26;
    int shipHeight = 204;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    CannonFactory cf;
    int antiAir = 10;

    std::unique_ptr<Cruiser> Ijn(
            new Cruiser(coordinates.x, coordinates.y, 3, 66, 15500, 230, "Japan", 4, 0, 4, antiAir, shipHeight,
                        shipWidth,
                        true,
                        ShipType::Cruiser, ModelType::Ijn, 2));
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
    return Ijn;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedBattleship(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;
    coordinates.y = coordinates.y + (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::ISE: {
            std::unique_ptr<WarShip> ise = iseBuilder(coordinates);
            repositionAlliedShip(ise);
            return std::move(ise);
        }

        case ModelType::Kongo: {
            std::unique_ptr<WarShip> kongo = kongoBuilder(coordinates);
            repositionAlliedShip(kongo);
            return std::move(kongo);
        }

        case ModelType::Musashi: {
            std::unique_ptr<WarShip> musashi = musashiBuilder(coordinates);
            repositionAlliedShip(musashi);
            return std::move(musashi);
        }

        case ModelType::Yamato: {
            std::unique_ptr<WarShip> yamato = yamatoBuilder(coordinates);
            repositionAlliedShip(yamato);
            return std::move(yamato);
        }

        case ModelType::AndreaDoria: {
            std::unique_ptr<WarShip> andreaDoria = andreaDoriaBuilder(coordinates);
            repositionAlliedShip(andreaDoria);
            return std::move(andreaDoria);
        }

        case ModelType::ImperatoreAugusto: {
            std::unique_ptr<WarShip> imperatoreAugusto = imperatoreAugustoBuilder(coordinates);
            repositionAlliedShip(imperatoreAugusto);
            return std::move(imperatoreAugusto);
        }

        case ModelType::MichelangeloBuonarroti: {
            std::unique_ptr<WarShip> michelangeloBuonarroti = michelangeloBuonarrotiBuilder(coordinates);
            repositionAlliedShip(michelangeloBuonarroti);
            return std::move(michelangeloBuonarroti);
        }

        case ModelType::VittorioVeneto: {
            std::unique_ptr<WarShip> vittorioVeneto = vittorioVenetoBuilder(coordinates);
            repositionAlliedShip(vittorioVeneto);
            return std::move(vittorioVeneto);
        }


        case ModelType::Dreadnought: {
            std::unique_ptr<WarShip> dreadNought = dreadNoughtBuilder(coordinates);
            repositionAlliedShip(dreadNought);
            return std::move(dreadNought);
        }


        case ModelType::Hood: {
            std::unique_ptr<WarShip> hood = hoodBuilder(coordinates);
            repositionAlliedShip(hood);
            return std::move(hood);
        }


        case ModelType::IronDuke: {
            std::unique_ptr<WarShip> ironDuke = ironDukeBuilder(coordinates);
            repositionAlliedShip(ironDuke);
            return std::move(ironDuke);
        }
        case ModelType::Lion: {
            std::unique_ptr<WarShip> lion = lionBuilder(coordinates);
            repositionAlliedShip(lion);
            return std::move(lion);
        }

        case ModelType::Arizona: {
            std::unique_ptr<WarShip> arizona = arizonaBuilder(coordinates);
            repositionAlliedShip(arizona);
            return std::move(arizona);
        }

        case ModelType::Montana: {
            std::unique_ptr<WarShip> montana = montanaBuilder(coordinates);
            repositionAlliedShip(montana);
            return std::move(montana);
        }

        case ModelType::NewYork: {
            std::unique_ptr<WarShip> newYork = newYorkBuilder(coordinates);
            repositionAlliedShip(newYork);
            return std::move(newYork);
        }


        case ModelType::NorthCarolina: {
            std::unique_ptr<WarShip> northCarolina = northCarolinaBuilder(coordinates);
            repositionAlliedShip(northCarolina);
            return std::move(northCarolina);
        }


    }

}

std::unique_ptr<Battleship>
ShipFactory::vittorioVenetoBuilder(sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 33;
    int shipHeight = 238;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 32;

    std::unique_ptr<Battleship> VittorioVeneto(
            new Battleship(coordinates.x, coordinates.y, 1, 56, 45963, 862, "Italy", 12, 4, 4, numAntiAir,
                           shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::VittorioVeneto, 1));
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
    return VittorioVeneto;
}

std::unique_ptr<Battleship>
ShipFactory::newYorkBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int shipWidth = 35;
    int shipHeight = 175;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int antiAir = 6;

    std::unique_ptr<Battleship> NewYork(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 28822, 939,
                           "Usa", 0, 5, 0, antiAir, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::NewYork, 0));
    NewYork->attach(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 19, *NewYork)));
    NewYork->attach(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 39, *NewYork)));
    NewYork->attach(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 84, *NewYork)));
    NewYork->attach(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 109, *NewYork)));
    NewYork->attach(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 134, *NewYork)));
    for (int i = 0; i < antiAir; i++)
        NewYork->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *NewYork)));
    return NewYork;
}

std::unique_ptr<Battleship>
ShipFactory::arizonaBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int shipWidth = 32;
    int shipHeight = 185;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int antiAir = 4;

    std::unique_ptr<Battleship> Arizona(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 32429, 1536,
                           "Usa", 8, 4, 0, antiAir, 185, 32, true,
                           ShipType::Battleship,
                           ModelType::Arizona, 0));
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
    return Arizona;
}

std::unique_ptr<Battleship>
ShipFactory::hoodBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int shipWidth = 34;
    int shipHeight = 262;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int antiAir = 20;

    std::unique_ptr<Battleship> Hood(
            new Battleship(coordinates.x, coordinates.y, 1, 54, 49136, 800, "Uk", 0, 2, 2, antiAir, shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::Hood, 0));
    Hood->attach(std::move(cf.createHeavly(cannonPosX + 9, cannonPosY + 207, *Hood)));
    Hood->attach(std::move(cf.createHeavly(cannonPosX + 9, cannonPosY + 44, *Hood)));
    Hood->attach(std::move(cf.createMedium(cannonPosX + 12, cannonPosY + 190, *Hood)));
    Hood->attach(std::move(cf.createMedium(cannonPosX + 13, cannonPosY + 59, *Hood)));

    for (int i = 0; i < antiAir; i++)
        Hood->attach(std::move(factory.createSpecialWeapon(WeaponType::antiAir, *Hood)));
    return Hood;
}

std::unique_ptr<Battleship>
ShipFactory::michelangeloBuonarrotiBuilder(sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 35;
    int shipHeight = 246;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 14;
    std::unique_ptr<Battleship> MichelangeloBuonarroti(
            new Battleship(coordinates.x, coordinates.y, 1, 61, 42533, 837, "Italy", 12, 3, 6, numAntiAir,
                           shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::MichelangeloBuonarroti, 1));
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
    return MichelangeloBuonarroti;
}

std::unique_ptr<Battleship>
ShipFactory::andreaDoriaBuilder(sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 29;
    int shipHeight = 176;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 13;
    std::unique_ptr<Battleship> AndreaDoria(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 24729, 622, "Italy", 10, 4, 4, numAntiAir,
                           shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::AndreaDoria, 0));
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
    return AndreaDoria;
}

std::unique_ptr<Battleship>
ShipFactory::yamatoBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 40;
    int shipWidth = 41;
    int shipHeight = 263;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;


    std::unique_ptr<Battleship> Yamato(
            new Battleship(coordinates.x, coordinates.y, 1, 50, 71659, 1286, "Japan", 12, 3, 2, antiAir,
                           shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::Yamato, 3));
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
    return Yamato;
}

std::unique_ptr<Battleship>
ShipFactory::iseBuilder(sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 19;
    int shipWidth = 43;
    int shipHeight = 220;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    std::unique_ptr<Battleship> Ise(
            new Battleship(coordinates.x, coordinates.y, 1, 45, 40444, 705, "Japan", 8, 4, 0, antiAir, shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::ISE, 2));
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
    return Ise;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedDestroyer(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;
    coordinates.y = coordinates.y + (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::Akizuki: {
            std::unique_ptr<WarShip> akizuki = akizukiBuilder(coordinates);
            repositionAlliedShip(akizuki);
            return std::move(akizuki);
        }


        case ModelType::Fubuki: {
            std::unique_ptr<WarShip> fubuki = fubukiBuilder(coordinates);
            repositionAlliedShip(fubuki);
            return std::move(fubuki);
        }


        case ModelType::Yukikaze: {
            std::unique_ptr<WarShip> yukikaze = yukikazeBuilder(coordinates);
            repositionAlliedShip(yukikaze);
            return std::move(yukikaze);
        }


        case ModelType::Impavido: {
            std::unique_ptr<WarShip> impavido = impavidoBuilder(coordinates);
            repositionAlliedShip(impavido);
            return std::move(impavido);
        }


        case ModelType::Leone: {
            std::unique_ptr<WarShip> leone = leoneBuilder(coordinates);
            repositionAlliedShip(leone);
            return std::move(leone);
        }
        case ModelType::PaoloEmilio: {
            std::unique_ptr<WarShip> paoloEmilio = paoloEmilioBuilder(coordinates);
            repositionAlliedShip(paoloEmilio);
            return std::move(paoloEmilio);
        }


        case ModelType::Campbelltown: {
            std::unique_ptr<WarShip> campbelltown = campbeltownBuilder(coordinates);
            repositionAlliedShip(campbelltown);
            return std::move(campbelltown);
        }


        case ModelType::Gallant: {
            std::unique_ptr<WarShip> gallant = gallandBuilder(coordinates);
            repositionAlliedShip(gallant);
            return std::move(gallant);
        }


        case ModelType::Jutland: {
            std::unique_ptr<WarShip> jutLand = jutlandBuilder(coordinates);
            repositionAlliedShip(jutLand);
            return std::move(jutLand);
        }


        case ModelType::Fletcher: {
            std::unique_ptr<WarShip> fletcher = fletcherBuilder(coordinates);
            repositionAlliedShip(fletcher);
            return std::move(fletcher);
        }


        case ModelType::Mahan: {
            std::unique_ptr<WarShip> mahan = mahanBuilder(coordinates);
            repositionAlliedShip(mahan);
            return std::move(mahan);
        }


        case ModelType::Sims: {
            std::unique_ptr<WarShip> sims = simsBuilder(coordinates);
            repositionAlliedShip(sims);
            return std::move(sims);
        }


    }

}

std::unique_ptr<Destroyer>
ShipFactory::mahanBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 13;
    int shipHeight = 104;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 8;
    std::unique_ptr<Destroyer> Mahan(
            new Destroyer(coordinates.x, coordinates.y, 4, 69, 2137, 27,
                          "Usa", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Mahan, 12));
    Mahan->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 11, *Mahan)));
    Mahan->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 37, *Mahan)));
    Mahan->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 90, *Mahan)));
    Mahan->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 72, *Mahan)));

    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        Mahan->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *Mahan)));
    }

    return Mahan;
}

std::unique_ptr<Destroyer>
ShipFactory::gallandBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 10;
    int shipHeight = 99;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int numAntiAir = 8;

    std::unique_ptr<Destroyer> Gallant(
            new Destroyer(coordinates.x, coordinates.y, 4, 67, 1913, 22,
                          "Uk", 0, 0, 4, numAntiAir, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Gallant, 8));
    Gallant->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 14, *Gallant)));
    Gallant->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 21, *Gallant)));
    Gallant->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 75, *Gallant)));
    Gallant->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 81, *Gallant)));

    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        Gallant->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *Gallant)));
    }
    return Gallant;
}

std::unique_ptr<Destroyer>
ShipFactory::campbeltownBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 10;
    int shipHeight = 96;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 10;
    std::unique_ptr<Destroyer> Campbelltown(
            new Destroyer(coordinates.x, coordinates.y, 4, 66, 1280, 19,
                          "Uk", 4, 0, 0, numAntiAir, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Campbelltown, 6));
    Campbelltown->attach(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 14, *Campbelltown)));
    Campbelltown->attach(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 40, *Campbelltown)));
    Campbelltown->attach(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 40, *Campbelltown)));
    Campbelltown->attach(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 81, *Campbelltown)));

    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        Campbelltown->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *Campbelltown)));
    }

    return Campbelltown;
}

std::unique_ptr<Destroyer>
ShipFactory::leoneBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 13;
    int shipHeight = 113;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int numAntiAir = 20;
    std::unique_ptr<Destroyer> Leone(
            new Destroyer(coordinates.x, coordinates.y, 4, 61, 2326, 22,
                          "Italy", 0, 0, 3, numAntiAir, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Leone, 6));
    Leone->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 33, *Leone)));
    Leone->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 74, *Leone)));
    Leone->attach(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 100, *Leone)));

    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        Leone->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *Leone)));
    }
    return Leone;
}

std::unique_ptr<Destroyer>
ShipFactory::fubukiBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 14;
    int shipHeight = 118;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 20;
    std::unique_ptr<Destroyer> Fubuki(
            new Destroyer(coordinates.x, coordinates.y, 4, 70, 2080, 26,
                          "Japan", 0, 0, 6, numAntiAir, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Fubuki, 9));
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
    return Fubuki;
}

std::unique_ptr<Destroyer>
ShipFactory::akizukiBuilder(sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 12;
    int shipHeight = 134;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int numAntiAir = 50;
    std::unique_ptr<Destroyer> Akizuki(
            new Destroyer(coordinates.x, coordinates.y, 4, 61, 3759, 33,
                          "Japan", 0, 0, 5, numAntiAir, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Akizuki, 4));
    Akizuki->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 22, *Akizuki)));
    Akizuki->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 29, *Akizuki)));
    Akizuki->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 95, *Akizuki)));
    Akizuki->attach(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 104, *Akizuki)));

    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        Akizuki->attach(std::move(wf.createSpecialWeapon(WeaponType::antiAir, *Akizuki)));
    }
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


std::unique_ptr<WarShip> &ShipFactory::repositionEnemyShip(std::unique_ptr<WarShip> &ship) {
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

std::unique_ptr<WarShip> &ShipFactory::repositionAlliedShip(std::unique_ptr<WarShip> &ship) {
    ship->getSprite().setOrigin(ship->getWidth() / 2, ship->getLength() / 2);
    ship->getSprite().move(0, -ship->getLength() / 2);
    for (auto &it: ship->getArsenalList()) {
        it->getSprite().move(0, -ship->getLength() / 2);
        it->getSprite().rotate(180);
    }
    for (auto &it: ship->getVehicleList()) {
        it->getSprite().move(0, -ship->getLength() / 2);

    }
    return ship;
}