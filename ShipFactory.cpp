//
// Created by alessandro on 7/2/21.
//

#include "ShipFactory.h"
#include "GameWorld.h"


std::unique_ptr<WarShip> ShipFactory::createSubmarine(ModelType type, GameWorld &map) {
    std::list<std::unique_ptr<Arsenal>> a;
    std::list<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::I400: {

            std::unique_ptr<Submarine> i400 = i400Builder(a, v, coordinates);
            i400->getSprite().setOrigin(i400->getWidth() / 2, i400->getLength() / 2);
            i400->getSprite().setRotation(180);


            return std::move(i400);
        }
        case ModelType::typeb1: {
            std::unique_ptr<Submarine> typeb1 = typeb1Builder(a, v, coordinates);
            typeb1->getSprite().setOrigin(typeb1->getWidth() / 2, typeb1->getLength() / 2);
            typeb1->getSprite().setRotation(180);
            return std::move(typeb1);
        }

        case ModelType::DaVinci: {
            std::unique_ptr<Submarine> daVinci = DaVinciBuilder(a, v, coordinates);
            daVinci->getSprite().setOrigin(daVinci->getWidth() / 2, daVinci->getLength() / 2);
            daVinci->getSprite().setRotation(180);
            return std::move(daVinci);
        }
        case ModelType::Papa: {
            std::unique_ptr<Submarine> papa = papaBuilder(coordinates, a, v);
            papa->getSprite().setOrigin(papa->getWidth() / 2, papa->getLength() / 2);
            papa->getSprite().setRotation(180);
            return std::move(papa);
        }
        case ModelType::Triton: {
            std::unique_ptr<Submarine> triton = tritonBuilder(a, v, coordinates);
            triton->getSprite().setOrigin(triton->getWidth() / 2, triton->getLength() / 2);
            triton->getSprite().setRotation(180);
            return std::move(triton);
        }
        case ModelType::Trenchant: {
            std::unique_ptr<Submarine> trenchant = trenchantBuilder(coordinates, a, v);
            trenchant->getSprite().setOrigin(trenchant->getWidth() / 2, trenchant->getLength() / 2);
            trenchant->getSprite().setRotation(180);
            return std::move(trenchant);
        }
        case ModelType::Gato: {
            std::unique_ptr<Submarine> gato = gatoBuilder(a, v, coordinates);
            gato->getSprite().setOrigin(gato->getWidth() / 2, gato->getLength() / 2);
            gato->getSprite().setRotation(180);

            return std::move(gato);
        }
        case ModelType::Narwhal: {
            std::unique_ptr<Submarine> narwhal = narwhalBuilder(coordinates, a, v);
            narwhal->getSprite().setOrigin(narwhal->getWidth() / 2, narwhal->getLength() / 2);
            narwhal->getSprite().setRotation(180);
            return std::move(narwhal);
        }
    }

}

std::unique_ptr<Submarine>
ShipFactory::gatoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                         sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 9;
    int shipHeight = 95;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    for (int i = 0; i < 6; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));

    std::unique_ptr<Submarine> Gato(
            new Submarine(coordinates.x, coordinates.y, 2, 37, 2460, 0, "Usa", 0, 0, 0, 0, a, v, shipHeight, shipWidth, true,
                          ShipType::Submarine, ModelType::Gato, 6, false));
    return Gato;
}

std::unique_ptr<Submarine>
ShipFactory::tritonBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                           sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 8;
    int shipHeight = 84;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    for (int i = 0; i < 6; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));

    std::unique_ptr<Submarine> Triton(
            new Submarine(coordinates.x, coordinates.y, 2, 28, 1576, 0, "Uk", 0, 0, 0, 0, a, v, shipHeight, shipWidth, true,
                          ShipType::Submarine, ModelType::Triton, 6, false));
    return Triton;
}

std::unique_ptr<Submarine>
ShipFactory::DaVinciBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                            sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 9;
    int shipHeight = 77;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    for (int i = 0; i < 8; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));

    std::unique_ptr<Submarine> DaVinci(
            new Submarine(coordinates.x, coordinates.y, 2, 15, 1489, 0, "Italy", 0, 0, 0, 0, a, v, shipHeight, shipWidth, true,
                          ShipType::Submarine, ModelType::DaVinci, 8, false));
    return DaVinci;
}

std::unique_ptr<Submarine>
ShipFactory::typeb1Builder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                           sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 10;
    int shipHeight = 111;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    for (int i = 0; i < 6; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));

    std::unique_ptr<Submarine> typeb1(
            new Submarine(coordinates.x, coordinates.y, 2, 44, 3713, 0, "Japan", 0, 0, 0, 0, a, v, shipHeight, shipWidth,
                          true,
                          ShipType::Submarine, ModelType::typeb1, 6,
                          false));
    return typeb1;
}

std::unique_ptr<Submarine>
ShipFactory::i400Builder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                         sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    int shipWidth = 13;
    int shipHeight = 122;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    for (int i = 0; i < 8; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));

    std::unique_ptr<Submarine> i400(
            new Submarine(coordinates.x, coordinates.y, 2, 35, 6670, 0, "Japan", 0, 0, 0, 0, a, v, shipHeight, shipWidth,
                          true,
                          ShipType::Submarine, ModelType::I400, 8, false));
    return i400;
}

std::unique_ptr<WarShip> ShipFactory::createAircraftCarrier(ModelType type, GameWorld &map) {
    std::list<std::unique_ptr<Arsenal>> a;
    std::list<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {
        case ModelType::Tahio: {
            std::unique_ptr<AircraftCarrier> tahio = tahioBuilder(a, v, coordinates);

            tahio->getSprite().setOrigin(tahio->getWidth() / 2, tahio->getLength() / 2);
            tahio->getSprite().setRotation(180);

            return std::move(tahio);
        }


        case ModelType::Hiryu: {
            std::unique_ptr<AircraftCarrier> hiryu = hiryuBuilder(coordinates, a, v);
            hiryu->getSprite().setOrigin(hiryu->getWidth() / 2, hiryu->getLength() / 2);
            hiryu->getSprite().setRotation(180);

            return std::move(hiryu);
        }

        case ModelType::GiuseppeGaribaldi: {
            std::unique_ptr<AircraftCarrier> giuseppeGaribaldi = giuseppeGaribaldiBuilder(a, v, coordinates);
            giuseppeGaribaldi->getSprite().setOrigin(giuseppeGaribaldi->getWidth() / 2,
                                                     giuseppeGaribaldi->getLength() / 2);
            giuseppeGaribaldi->getSprite().setRotation(180);

            return std::move(giuseppeGaribaldi);
        }

        case ModelType::Cavour: {
            std::unique_ptr<AircraftCarrier> cavour = cavourBuilder(coordinates, a, v);

            cavour->getSprite().setOrigin(cavour->getWidth() / 2, cavour->getLength() / 2);
            cavour->getSprite().setRotation(180);

            return std::move(cavour);
        }
        case ModelType::ArkRoyal: {
            std::unique_ptr<AircraftCarrier> arkRoyal = arkRoyalBuilder(a, v, coordinates);
            arkRoyal->getSprite().setOrigin(arkRoyal->getWidth() / 2, arkRoyal->getLength() / 2);
            arkRoyal->getSprite().setRotation(180);
            return std::move(arkRoyal);
        }

        case ModelType::Indomitable: {

            std::unique_ptr<AircraftCarrier> indomitable = indomitableBuilder(coordinates, a, v);
            indomitable->getSprite().setOrigin(indomitable->getWidth() / 2, indomitable->getLength() / 2);
            indomitable->getSprite().setRotation(180);

            return std::move(indomitable);
        }

        case ModelType::Midway: {
            std::unique_ptr<AircraftCarrier> midway = midwayBuilder(a, v, coordinates);

            midway->getSprite().setOrigin(midway->getWidth() / 2, midway->getLength() / 2);
            midway->getSprite().setRotation(180);

            return std::move(midway);
        }

        case ModelType::FranklinDRoosevelt: {
            std::unique_ptr<AircraftCarrier> franklinDRoosevelt = franklinDelanoRoosveltBuilder(coordinates, a, v);
            franklinDRoosevelt->getSprite().setOrigin(franklinDRoosevelt->getWidth() / 2,
                                                      franklinDRoosevelt->getLength() / 2);
            franklinDRoosevelt->getSprite().setRotation(180);

            return std::move(franklinDRoosevelt);
        }


    }

}

std::unique_ptr<AircraftCarrier>
ShipFactory::midwayBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                           sf::Vector2i &coordinates) const {
    CannonFactory factory;

    int shipWidth = 84;
    int shipHeight = 296;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;


    WeaponFactory specialFactory;
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 72, cannonPosY + 187)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 14, cannonPosY + 230)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 69, cannonPosY + 100)));
    int numAntiAir = 15;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<AircraftCarrier> mid(new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 640000, 520,
                                                             "Usa", 2, 0, 0, numAntiAir, a, v, shipHeight, shipWidth,
                                                             true,
                                                             ShipType::AircraftCarrier, ModelType::Midway, 14));
    return mid;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::arkRoyalBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                             sf::Vector2i &coordinates) const {
    CannonFactory factory;

    int shipWidth = 38;
    int shipHeight = 240;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;


    a.emplace_back(std::move(factory.createLight(cannonPosX + 7, cannonPosY + 85)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 28, cannonPosY + 85)));
    WeaponFactory specialFactory;
    int numAntiAir = 4;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<AircraftCarrier> arkRoyal(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 28160, 20,
                                "Uk", 2, 0, 0, numAntiAir, a, v, shipHeight, shipWidth, true, ShipType::AircraftCarrier,
                                ModelType::ArkRoyal, 7));
    return arkRoyal;
}

std::unique_ptr<AircraftCarrier> ShipFactory::giuseppeGaribaldiBuilder(std::list<std::unique_ptr<Arsenal>> &a,
                                                                       std::list<std::unique_ptr<Vehicle>> &v,
                                                                       sf::Vector2i &coordinates) const {
    CannonFactory factory;

    int shipWidth = 44;
    int shipHeight = 180;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    a.emplace_back(std::move(factory.createLight(cannonPosX + 4, cannonPosY + 41)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 4, cannonPosY + 69)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 4, cannonPosY + 98)));

    std::unique_ptr<AircraftCarrier> GiuseppeGaribaldi(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 14150, 114, "Italy", 3, 0, 0, 0, a, v, shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::GiuseppeGaribaldi, 6));
    return GiuseppeGaribaldi;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::tahioBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                          sf::Vector2i &coordinates) const {
    CannonFactory factory;


    int shipWidth = 46;
    int shipHeight = 260;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    a.emplace_back(std::move(factory.createLight(cannonPosX + 20, cannonPosY + 55)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 20, cannonPosY + 218)));
    WeaponFactory specialFactory;
    int numAntiAir = 20;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<AircraftCarrier> Tahio(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 37866, 304, "Japan", 2, 0, 0, numAntiAir, a, v,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::Tahio, 7));
    return Tahio;
}

std::unique_ptr<WarShip> ShipFactory::createCruiser(ModelType type, GameWorld &map) {
    std::list<std::unique_ptr<Arsenal>> a;
    std::list<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::Takao: {
            std::unique_ptr<Cruiser> takao = takaoBuilder(a, v, coordinates);
            takao->getSprite().setOrigin(takao->getWidth() / 2, takao->getLength() / 2);
            takao->getSprite().setRotation(180);
            return std::move(takao);
        }

        case ModelType::IsuzuNagara: {
            std::unique_ptr<Cruiser> isuzuNagara = isuzuNagaraBuilder(coordinates, a, v);
            isuzuNagara->getSprite().setOrigin(isuzuNagara->getWidth() / 2, isuzuNagara->getLength() / 2);
            isuzuNagara->getSprite().setRotation(180);
            return std::move(isuzuNagara);
        }


        case ModelType::Ijn: {
            std::unique_ptr<Cruiser> ijn = ijnBuilder(coordinates, a, v);
            ijn->getSprite().setOrigin(ijn->getWidth() / 2, ijn->getLength() / 2);
            ijn->getSprite().setRotation(180);
            return std::move(ijn);
        }


        case ModelType::AlbertoDiGiussano: {
            std::unique_ptr<Cruiser> albertoDiGiussano = albertoDiGiussanoBuilder(a, v, coordinates);
            albertoDiGiussano->getSprite().setOrigin(albertoDiGiussano->getWidth() / 2,
                                                     albertoDiGiussano->getLength() / 2);
            albertoDiGiussano->getSprite().setRotation(180);
            return std::move(albertoDiGiussano);
        }

        case ModelType::Gorizia: {
            std::unique_ptr<Cruiser> gorizia = goriziaBuilder(coordinates, a, v);
            gorizia->getSprite().setOrigin(gorizia->getWidth() / 2, gorizia->getLength() / 2);
            gorizia->getSprite().setRotation(180);
            return std::move(gorizia);
        }

        case ModelType::Trento: {
            std::unique_ptr<Cruiser> trento = trentoBuilder(a, v, coordinates);
            trento->getSprite().setOrigin(trento->getWidth() / 2, trento->getLength() / 2);
            trento->getSprite().setRotation(180);
            return std::move(trento);
        }
        case ModelType::Belfast: {
            std::unique_ptr<Cruiser> belfast = belfastBuilder(coordinates, a, v);
            belfast->getSprite().setOrigin(belfast->getWidth() / 2, belfast->getLength() / 2);
            belfast->getSprite().setRotation(180);
            return std::move(belfast);
        }

        case ModelType::Danae: {
            std::unique_ptr<Cruiser> danae = danaeBuilder(a, v, coordinates);
            danae->getSprite().setOrigin(danae->getWidth() / 2, danae->getLength() / 2);
            danae->getSprite().setRotation(180);
            return std::move(danae);
        }

        case ModelType::Tiger59: {
            std::unique_ptr<Cruiser> tiger59 = tiger59Builder(coordinates, a, v);
            tiger59->getSprite().setOrigin(tiger59->getWidth() / 2, tiger59->getLength() / 2);
            tiger59->getSprite().setRotation(180);
            return std::move(tiger59);
        }
        case ModelType::Alaska: {
            std::unique_ptr<Cruiser> alaska = alaskaBuilder(a, v, coordinates);
            alaska->getSprite().setOrigin(alaska->getWidth() / 2, alaska->getLength() / 2);
            alaska->getSprite().setRotation(180);
            return std::move(alaska);
        }
        case ModelType::NewOrleans: {
            std::unique_ptr<Cruiser> newOrleans = newOrleansBuilder(coordinates, a, v);
            newOrleans->getSprite().setOrigin(newOrleans->getWidth() / 2, newOrleans->getLength() / 2);
            newOrleans->getSprite().setRotation(180);
            return std::move(newOrleans);
        }
        case ModelType::StLouis: {
            std::unique_ptr<Cruiser> saintLouis = stLouisBuilder(a, v, coordinates);
            saintLouis->getSprite().setOrigin(saintLouis->getWidth() / 2, saintLouis->getLength() / 2);
            saintLouis->getSprite().setRotation(180);
            return std::move(saintLouis);
        }
    }

}

//TODO aggiungere aerei
std::unique_ptr<Cruiser>
ShipFactory::stLouisBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
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
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createMedium(
                                                                                                                                        cannonPosX +
                                                                                                                                        6,
                                                                                                                                        cannonPosY +
                                                                                                                                        21)));
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createMedium(
                                                                                                                                        cannonPosX +
                                                                                                                                        6,
                                                                                                                                        cannonPosY +
                                                                                                                                        34)));
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createMedium(
                                                                                                                                        cannonPosX +
                                                                                                                                        6,
                                                                                                                                        cannonPosY +
                                                                                                                                        111)));
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createLight(
                                                                                                                                        cannonPosX +
                                                                                                                                        1,
                                                                                                                                        cannonPosY +
                                                                                                                                        71)));
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createLight(
                                                                                                                                        cannonPosX +
                                                                                                                                        15,
                                                                                                                                        cannonPosY +
                                                                                                                                        71)));
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createLight(
                                                                                                                                        cannonPosX +
                                                                                                                                        8,
                                                                                                                                        cannonPosY +
                                                                                                                                        80)));
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createLight(
                                                                                                                                        cannonPosX +
                                                                                                                                        2,
                                                                                                                                        cannonPosY +
                                                                                                                                        41)));
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createLight(
                                                                                                                                        cannonPosX +
                                                                                                                                        16,
                                                                                                                                        cannonPosY +
                                                                                                                                        41)));
                                                                                                                for (int i = 0;
                                                                                                                     i <
                                                                                                                     antiAir; i++)
                                                                                                                    a.emplace_back(
                                                                                                                            std::move(
                                                                                                                                    factory.createSpecialWeapon(
                                                                                                                                            WeaponType::antiAir)));
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
                                                                                                                                a,
                                                                                                                                v,
                                                                                                                                shipHeight,
                                                                                                                                shipWidth,
                                                                                                                                true,
                                                                                                                                ShipType::Cruiser,
                                                                                                                                ModelType::StLouis,
                                                                                                                                0));
                                                                                                                return saintLouis;
                                                                                                            }

std::unique_ptr<Cruiser>
ShipFactory::alaskaBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                           sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 28;
    int shipHeight = 246;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    CannonFactory cf;
    int antiAir = 9;
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 6, cannonPosY + 179)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 10, cannonPosY + 60)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 10, cannonPosY + 77)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 11, cannonPosY + 91)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 105)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 23, cannonPosY + 105)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 149)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 23, cannonPosY + 150)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 11, cannonPosY + 172)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> alaska(new Cruiser(coordinates.x, coordinates.y, 3, 61, 34803, 918,
                                                "Usa", 6, 1, 2, antiAir, a, v, shipHeight, shipWidth, true,
                                                ShipType::Cruiser,
                                                ModelType::Alaska, 4));
    return alaska;
}

std::unique_ptr<Cruiser>
ShipFactory::danaeBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                          sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 14;
    int shipHeight = 136;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    CannonFactory cf;
    int antiAir = 7;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 111)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 102)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 120)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 74)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 45)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 33)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 19)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> danae(new Cruiser(coordinates.x, coordinates.y, 3, 54, 5925, 190,
                                               "Uk", 6, 0, 1, antiAir, a, v, shipHeight, shipWidth, true,
                                               ShipType::Cruiser,
                                               ModelType::Danae, 0));
    return danae;
}

std::unique_ptr<Cruiser>
ShipFactory::trentoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                           sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 25;
    int shipHeight = 197;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    CannonFactory cf;
    int antiAir = 12;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 44)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 52)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 143)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 153)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 68)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 15, cannonPosY + 68)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 84)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 84)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 111)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 111)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> trento(new Cruiser(coordinates.x, coordinates.y, 3, 66, 13548, 120,
                                                "Italy", 6, 0, 4, antiAir, a, v, shipHeight, shipWidth, true,
                                                ShipType::Cruiser,
                                                ModelType::Trento, 2));
    return trento;
}

std::unique_ptr<Cruiser> ShipFactory::albertoDiGiussanoBuilder(std::list<std::unique_ptr<Arsenal>> &a,
                                                               std::list<std::unique_ptr<Vehicle>> &v,
                                                               sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 15;
    int shipHeight = 169;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    CannonFactory cf;
    int antiAir = 12;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 18)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 28)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 121)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 135)));
    a.emplace_back(std::move(cf.createLight(cannonPosX, cannonPosY + 93)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 10, cannonPosY + 93)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 6, cannonPosY + 112)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> albertoDiGiussano(new Cruiser(coordinates.x, coordinates.y, 3, 69, 6950, 84,
                                                           "Italy", 3, 0, 4, antiAir, a, v, shipHeight, shipWidth, true,
                                                           ShipType::Cruiser,
                                                           ModelType::AlbertoDiGiussano, 1));
    return albertoDiGiussano;
}

std::unique_ptr<Cruiser>
ShipFactory::takaoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                          sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    int shipWidth = 25;
    int shipHeight = 193;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    CannonFactory cf;
    int antiAir = 16;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 36)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 44)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 53)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 137)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 145)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 82)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 82)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 96)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 96)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> takao(new Cruiser(coordinates.x, coordinates.y, 3, 66, 15500, 237,
                                               "Japan", 4, 0, 5, antiAir, a, v, shipHeight, shipWidth, true,
                                               ShipType::Cruiser,
                                               ModelType::Takao, 2));
    return takao;
}

std::unique_ptr<WarShip> ShipFactory::createBattleship(ModelType type, GameWorld &map) {
    std::list<std::unique_ptr<Arsenal>> a;
    std::list<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::Yamato: {
            std::unique_ptr<WarShip> yamato = yamatoBuilder(coordinates, a, v);
            yamato->getSprite().setOrigin(yamato->getWidth() / 2, yamato->getLength() / 2);
            yamato->getSprite().setRotation(180);
            repositionEnemyShip(yamato);
            return std::move(yamato);
        }

        case ModelType::Kongo: {
            std::unique_ptr<Battleship> kongo = kongoBuilder(a, v, coordinates);
            kongo->getSprite().setOrigin(kongo->getWidth() / 2, kongo->getLength() / 2);
            kongo->getSprite().setRotation(180);
            return std::move(kongo);
        }

        case ModelType::ISE: {
            std::unique_ptr<Battleship> ise = iseBuilder(coordinates, a, v);
            ise->getSprite().setOrigin(ise->getWidth() / 2, ise->getLength() / 2);
            ise->getSprite().setRotation(180);
            return std::move(ise);
        }

        case ModelType::Musashi: {
            std::unique_ptr<Battleship> musashi = musashiBuilder(a, v, coordinates);
            musashi->getSprite().setOrigin(musashi->getWidth() / 2, musashi->getLength() / 2);
            musashi->getSprite().setRotation(180);
            return std::move(musashi);
        }

        case ModelType::AndreaDoria: {
            std::unique_ptr<Battleship> andreaDoria = andreaDoriaBuilder(coordinates, a, v);
            andreaDoria->getSprite().setOrigin(andreaDoria->getWidth() / 2, andreaDoria->getLength() / 2);
            andreaDoria->getSprite().setRotation(180);
            return std::move(andreaDoria);
        }

        case ModelType::ImperatoreAugusto: {
            std::unique_ptr<Battleship> imperatoreAugusto = imperatoreAugustoBuilder(a, v, coordinates);
            imperatoreAugusto->getSprite().setOrigin(imperatoreAugusto->getWidth() / 2,
                                                     imperatoreAugusto->getLength() / 2);
            imperatoreAugusto->getSprite().setRotation(180);
            return std::move(imperatoreAugusto);
        }
        case ModelType::VittorioVeneto: {
            std::unique_ptr<Battleship> vittorioVeneto = vittorioVenetoBuilder(coordinates, a, v);
            vittorioVeneto->getSprite().setOrigin(vittorioVeneto->getWidth() / 2, vittorioVeneto->getLength() / 2);
            vittorioVeneto->getSprite().setRotation(180);
            return std::move(vittorioVeneto);
        }

        case ModelType::MichelangeloBuonarroti: {
            std::unique_ptr<Battleship> michelangeloBuonarroti = michelangeloBuonarrotiBuilder(coordinates, a, v);
            michelangeloBuonarroti->getSprite().setOrigin(michelangeloBuonarroti->getWidth() / 2,
                                                          michelangeloBuonarroti->getLength() / 2);
            michelangeloBuonarroti->getSprite().setRotation(180);
            return std::move(michelangeloBuonarroti);
        }
        case ModelType::Dreadnought: {
            std::unique_ptr<Battleship> dreadNought = dreadNoughtBuilder(a, v, coordinates);
            dreadNought->getSprite().setOrigin(dreadNought->getWidth() / 2, dreadNought->getLength() / 2);
            dreadNought->getSprite().setRotation(180);
            return std::move(dreadNought);
        }
        case ModelType::IronDuke: {
            std::unique_ptr<Battleship> ironDuke = ironDukeBuilder(a, v, coordinates);
            ironDuke->getSprite().setOrigin(ironDuke->getWidth() / 2, ironDuke->getLength() / 2);
            ironDuke->getSprite().setRotation(180);
            return std::move(ironDuke);
        }
        case ModelType::Lion: {
            std::unique_ptr<Battleship> lion = lionBuilder(a, v, coordinates);
            lion->getSprite().setOrigin(lion->getWidth() / 2, lion->getLength() / 2);
            lion->getSprite().setRotation(180);
            return std::move(lion);
        }
        case ModelType::Hood: {
            std::unique_ptr<Battleship> hood = hoodBuilder(coordinates, a, v);
            hood->getSprite().setOrigin(hood->getWidth() / 2, hood->getLength() / 2);
            hood->getSprite().setRotation(180);
            return std::move(hood);
        }
        case ModelType::Arizona: {
            std::unique_ptr<Battleship> arizona = arizonaBuilder(coordinates, a, v);
            arizona->getSprite().setOrigin(arizona->getWidth() / 2, arizona->getLength() / 2);
            arizona->getSprite().setRotation(180);
            return std::move(arizona);
        }
        case ModelType::Montana: {
            std::unique_ptr<Battleship> montana = montanaBuilder(a, v, coordinates);
            montana->getSprite().setOrigin(montana->getWidth() / 2, montana->getLength() / 2);
            montana->getSprite().setRotation(180);
            return std::move(montana);
        }
        case ModelType::NewYork: {
            std::unique_ptr<Battleship> newYork = newYorkBuilder(coordinates, a, v);
            newYork->getSprite().setOrigin(newYork->getWidth() / 2, newYork->getLength() / 2);
            newYork->getSprite().setRotation(180);
            return std::move(newYork);
        }
        case ModelType::NorthCarolina: {
            std::unique_ptr<Battleship> northCarolina = northCarolinaBuilder(a, v, coordinates);
            northCarolina->getSprite().setOrigin(northCarolina->getWidth() / 2, northCarolina->getLength() / 2);
            northCarolina->getSprite().setRotation(180);
            return std::move(northCarolina);
        }
    }
    return std::unique_ptr<WarShip>(); //TODO implementare tutti i costruttori
}

std::unique_ptr<Battleship>
ShipFactory::ironDukeBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                             sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 190;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 41)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 55)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 107)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 133)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 141)));
    WeaponFactory specialFactory;
    int numAntiAir = 15;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> ironDuke(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 29500, 826,
                           "Uk", 0, 5, 0, numAntiAir, a, v, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::IronDuke, 0));
    return ironDuke;
}

std::unique_ptr<Battleship>
ShipFactory::northCarolinaBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                                  sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 32;
    int shipHeight = 222;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 8, cannonPosY + 56)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 8, cannonPosY + 145)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 8, cannonPosY + 171)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 5, cannonPosY + 81)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 22, cannonPosY + 81)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 5, cannonPosY + 101)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 22, cannonPosY + 101)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 1, cannonPosY + 111)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 111)));
    WeaponFactory specialFactory;
    int numAntiAir = 34;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<Battleship> northCarolina(
            new Battleship(coordinates.x, coordinates.y, 1, 52, 45500, 1224,
                           "Usa", 6, 2, 0, numAntiAir, a, v, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::NorthCarolina, 3));
    return northCarolina;
}

std::unique_ptr<Battleship>
ShipFactory::montanaBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                            sf::Vector2i &coordinates) const {
    //TODO concludere tutte le aggiunte necessarie
    CannonFactory factory;
    int shipWidth = 37;
    int shipHeight = 281;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 11, cannonPosY + 60)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 11, cannonPosY + 88)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 11, cannonPosY + 183)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 11, cannonPosY + 210)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 111)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 30, cannonPosY + 111)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 5, cannonPosY + 125)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 27, cannonPosY + 125)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 138)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 30, cannonPosY + 138)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 4, cannonPosY + 152)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 27, cannonPosY + 152)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 165)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 30, cannonPosY + 165)));
    WeaponFactory specialFactory;
    int numAntiAir = 80;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<Battleship> montana(
            new Battleship(coordinates.x, coordinates.y, 1, 52, 72104, 1810,
                           "Usa", 0, 4, 10, numAntiAir, a, v, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::Montana, 2));
    return montana;
}

std::unique_ptr<Battleship>
ShipFactory::lionBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                         sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 242;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 49)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 64)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 126)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 197)));
    WeaponFactory specialFactory;
    int numAntiAir = 10;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> lion(
            new Battleship(coordinates.x, coordinates.y, 1, 52, 49670, 944,
                           "Uk", 0, 4, 0, numAntiAir, a, v, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::Lion, 0));
    return lion;
}

std::unique_ptr<Battleship>
ShipFactory::dreadNoughtBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                                sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 25;
    int shipHeight = 158;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 5, cannonPosY + 38)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 5, cannonPosY + 93)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 5, cannonPosY + 118)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX - 1, cannonPosY + 64)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 64)));
    WeaponFactory specialFactory;
    int numAntiAir = 20;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> dreadNought(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 21060, 837,
                           "Uk", 0, 5, 0, numAntiAir, a, v, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::Dreadnought, 0));
    return dreadNought;
}

std::unique_ptr<Battleship> ShipFactory::imperatoreAugustoBuilder(std::list<std::unique_ptr<Arsenal>> &a,
                                                                  std::list<std::unique_ptr<Vehicle>> &v,
                                                                  sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 274;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 67)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 86)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 185)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 13, cannonPosY + 205)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 109)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 118)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 161)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 170)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 30, cannonPosY + 109)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 30, cannonPosY + 118)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 30, cannonPosY + 161)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 30, cannonPosY + 170)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 16, cannonPosY + 108)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 16, cannonPosY + 171)));

    a.emplace_back(std::move(factory.createLight(cannonPosX + 2, cannonPosY + 131)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 2, cannonPosY + 138)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 2, cannonPosY + 146)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 2, cannonPosY + 153)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 8, cannonPosY + 128)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 8, cannonPosY + 153)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 8, cannonPosY + 149)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 8, cannonPosY + 156)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 27, cannonPosY + 128)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 27, cannonPosY + 153)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 27, cannonPosY + 149)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 27, cannonPosY + 156)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 33, cannonPosY + 131)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 33, cannonPosY + 138)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 33, cannonPosY + 146)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 33, cannonPosY + 153)));
    WeaponFactory specialFactory;
    int numAntiAir = 12;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<Battleship> imperatoreAugusto(
            new Battleship(coordinates.x, coordinates.y, 1, 57, 65232, 1126,
                           "Italy", 16, 4, 10, numAntiAir, a, v, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::ImperatoreAugusto, 0));
    return imperatoreAugusto;
}

std::unique_ptr<Battleship>
ShipFactory::kongoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                          sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 31;
    int shipHeight = 222;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 43)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 56)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 131)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 169)));

    a.emplace_back(std::move(factory.createLight(cannonPosX + 2, cannonPosY + 81)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 2, cannonPosY + 95)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 2, cannonPosY + 129)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 24, cannonPosY + 81)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 24, cannonPosY + 95)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 24, cannonPosY + 129)));

    WeaponFactory specialFactory;
    int numAntiAir = 18;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> kongo(new Battleship(coordinates.x, coordinates.y, 1, 56, 37187, 592,
                                                     "Japan", 6, 4, 0, numAntiAir, a, v, shipHeight, shipWidth, true,
                                                     ShipType::Battleship,
                                                     ModelType::Kongo, 0));
    return kongo;
}

std::unique_ptr<Battleship>
ShipFactory::musashiBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                            sf::Vector2i &coordinates) const {
    CannonFactory factory;
    int shipWidth = 39;
    int shipHeight = 244;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 67)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 88)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 12, cannonPosY + 173)));

    a.emplace_back(std::move(factory.createMedium(cannonPosX + 8, cannonPosY + 112)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 27, cannonPosY + 112)));

    a.emplace_back(std::move(factory.createLight(cannonPosX, cannonPosY + 125)));
    a.emplace_back(std::move(factory.createLight(cannonPosX, cannonPosY + 146)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 34, cannonPosY + 125)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 34, cannonPosY + 146)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 24, cannonPosY + 95)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 24, cannonPosY + 129)));

    WeaponFactory specialFactory;
    int numAntiAir = 30;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<Battleship> musashi(new Battleship(coordinates.x, coordinates.y, 1, 51, 72809, 1540,
                                                       "Japan", 6, 3, 2, numAntiAir, a, v, shipHeight, shipWidth, true,
                                                       ShipType::Battleship,
                                                       ModelType::Musashi, 2));
    return musashi;
}

std::unique_ptr<WarShip> ShipFactory::createDestroyer(ModelType type, GameWorld &map) {
    std::list<std::unique_ptr<Arsenal>> a;
    std::list<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::Akizuki: {
            std::unique_ptr<Destroyer> akizuki = akizukiBuilder(coordinates, a, v);
            akizuki->getSprite().setOrigin(akizuki->getWidth() / 2, akizuki->getLength() / 2);
            akizuki->getSprite().setRotation(180);
            return std::move(akizuki);
        }

        case ModelType::Yukikaze: {
            std::unique_ptr<Destroyer> yukikaze = yukikazeBuilder(a, v, coordinates);
            yukikaze->getSprite().setOrigin(yukikaze->getWidth() / 2, yukikaze->getLength() / 2);
            yukikaze->getSprite().setRotation(180);
            return std::move(yukikaze);
        }
        case ModelType::Fubuki: {
            std::unique_ptr<Destroyer> fubuki = fubukiBuilder(coordinates, a, v);
            fubuki->getSprite().setOrigin(fubuki->getWidth() / 2, fubuki->getLength() / 2);
            fubuki->getSprite().setRotation(180);
            return std::move(fubuki);
        }
        case ModelType::Impavido: {
            std::unique_ptr<Destroyer> impavido = impavidoBuilder(a, v, coordinates);
            impavido->getSprite().setOrigin(impavido->getWidth() / 2, impavido->getLength() / 2);
            impavido->getSprite().setRotation(180);
            return std::move(impavido);
        }

        case ModelType::Leone: {
            std::unique_ptr<Destroyer> leone = leoneBuilder(coordinates, a, v);
            leone->getSprite().setOrigin(leone->getWidth() / 2, leone->getLength() / 2);
            leone->getSprite().setRotation(180);
            return std::move(leone);
        }

        case ModelType::PaoloEmilio: {
            std::unique_ptr<Destroyer> paoloEmilio = paoloEmilioBuilder(a, v, coordinates);
            paoloEmilio->getSprite().setOrigin(paoloEmilio->getWidth() / 2, paoloEmilio->getLength() / 2);
            paoloEmilio->getSprite().setRotation(180);
            return std::move(paoloEmilio);
        }
        case ModelType::Campbelltown: {
            std::unique_ptr<Destroyer> campbelltown = campbeltownBuilder(coordinates, a, v);
            campbelltown->getSprite().setOrigin(campbelltown->getWidth() / 2, campbelltown->getLength() / 2);
            campbelltown->getSprite().setRotation(180);
            return std::move(campbelltown);
        }

        case ModelType::Jutland: {
            std::unique_ptr<Destroyer> jutLand = jutlandBuilder(a, v, coordinates);
            jutLand->getSprite().setOrigin(jutLand->getWidth() / 2, jutLand->getLength() / 2);
            jutLand->getSprite().setRotation(180);
            return std::move(jutLand);
        }

        case ModelType::Gallant: {
            std::unique_ptr<Destroyer> gallant = gallandBuilder(coordinates, a, v);
            gallant->getSprite().setOrigin(gallant->getWidth() / 2, gallant->getLength() / 2);
            gallant->getSprite().setRotation(180);
            return std::move(gallant);
        }

        case ModelType::Fletcher: {
            std::unique_ptr<Destroyer> fletcher = fletcherBuilder(a, v, coordinates);
            fletcher->getSprite().setOrigin(fletcher->getWidth() / 2, fletcher->getLength() / 2);
            fletcher->getSprite().setRotation(180);
            return std::move(fletcher);
        }

        case ModelType::Mahan: {
            std::unique_ptr<Destroyer> mahan = mahanBuilder(coordinates, a, v);
            mahan->getSprite().setOrigin(mahan->getWidth() / 2, mahan->getLength() / 2);
            mahan->getSprite().setRotation(180);
            return std::move(mahan);


        }
        case ModelType::Sims: {
            std::unique_ptr<Destroyer> sims = simsBuilder(a, v, coordinates);
            sims->getSprite().setOrigin(sims->getWidth() / 2, sims->getLength() / 2);
            sims->getSprite().setRotation(180);
            return std::move(sims);
        }
    }

}

std::unique_ptr<Destroyer>
ShipFactory::simsBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                         sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 16;
    int shipHeight = 106;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 12)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 23)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 78)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 90)));
    int numAntiAir = 16;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }

    std::unique_ptr<Destroyer> sims(
            new Destroyer(coordinates.x, coordinates.y, 4, 69, 2293, 30,
                          "Usa", 0, 0, 4, numAntiAir, a, v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Sims, 8));
    return sims;
}

std::unique_ptr<Destroyer>
ShipFactory::fletcherBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                             sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 12;
    int shipHeight = 114;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 97)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 85)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 73)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 15)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 27)));
    int numAntiAir = 14;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }

    std::unique_ptr<Destroyer> fletcher(
            new Destroyer(coordinates.x, coordinates.y, 4, 68, 2500, 33,
                          "Usa", 0, 0, 5, numAntiAir, a, v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Fletcher, 10));
    return fletcher;
}

std::unique_ptr<Destroyer>
ShipFactory::jutlandBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                            sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 13;
    int shipHeight = 116;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 18)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 28)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 95)));

    std::unique_ptr<Destroyer> jutLand(
            new Destroyer(coordinates.x, coordinates.y, 4, 66, 2480, 26,
                          "Uk", 0, 0, 3, 16, a, v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Jutland, 10));
    return jutLand;
}

std::unique_ptr<Destroyer>
ShipFactory::paoloEmilioBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                                sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 15;
    int shipHeight = 172;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 28)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 36)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 132)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 140)));
    int numAntiAir = 12;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }
    std::unique_ptr<Destroyer> paoloEmilio(
            new Destroyer(coordinates.x, coordinates.y, 4, 76, 5420, 66,
                          "Italy", 0, 0, 4, numAntiAir, a, v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Impavido, 8));
    return paoloEmilio;
}

std::unique_ptr<Destroyer>
ShipFactory::impavidoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                             sf::Vector2i &coordinates) const {

    CannonFactory cf;
    int shipWidth = 15;
    int shipHeight = 131;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 4, cannonPosY + 17)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 67)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 79)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 10, cannonPosY + 67)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 10, cannonPosY + 79)));
    int numAntiAir = 40;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }
    std::unique_ptr<Destroyer> impavido(
            new Destroyer(coordinates.x, coordinates.y, 4, 63, 3941, 36,
                          "Italy", 4, 0, 1, numAntiAir, a, v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Impavido, 6));
    return impavido;
}

std::unique_ptr<Destroyer>
ShipFactory::yukikazeBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                             sf::Vector2i &coordinates) const {
    CannonFactory cf;
    int shipWidth = 12;
    int shipHeight = 119;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 16)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 51)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 70)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 93)));
    int numAntiAir = 32;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }
    std::unique_ptr<Destroyer> yukikaze(
            new Destroyer(coordinates.x, coordinates.y, 4, 65, 2530, 26,
                          "Japan", 0, 0, 4, numAntiAir, a, v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Yukikaze, 8));
    return yukikaze;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedSubmarine(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::list<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::I400: {
            std::unique_ptr<WarShip> i400 = i400Builder(a, v, coordinates);
            i400->getSprite().setOrigin(i400->getWidth() / 2, i400->getLength() / 2);
            repositionAlliedShip(i400);
            return std::move(i400);
        }

        case ModelType::typeb1: {
            std::unique_ptr<WarShip> typeb1 = typeb1Builder(a, v, coordinates);
            typeb1->getSprite().setOrigin(typeb1->getWidth() / 2, typeb1->getLength() / 2);
            repositionAlliedShip(typeb1);
            return std::move(typeb1);
        }

        case ModelType::DaVinci: {
            std::unique_ptr<WarShip> DaVinci = DaVinciBuilder(a, v, coordinates);
            DaVinci->getSprite().setOrigin(DaVinci->getWidth() / 2, DaVinci->getLength() / 2);
            repositionAlliedShip(DaVinci);
            return std::move(DaVinci);
        }

        case ModelType::Papa: {
            std::unique_ptr<WarShip> papa = papaBuilder(coordinates, a, v);
            papa->getSprite().setOrigin(papa->getWidth() / 2, papa->getLength() / 2);
            repositionAlliedShip(papa);
            return std::move(papa);
        }

        case ModelType::Triton: {
            std::unique_ptr<WarShip> triton = tritonBuilder(a, v, coordinates);
            triton->getSprite().setOrigin(triton->getWidth() / 2, triton->getLength() / 2);
            repositionAlliedShip(triton);
            return std::move(triton);
        }

        case ModelType::Trenchant: {
            std::unique_ptr<WarShip> trenchant = trenchantBuilder(coordinates, a, v);
            trenchant->getSprite().setOrigin(trenchant->getWidth() / 2, trenchant->getLength() / 2);
            repositionAlliedShip(trenchant);
            return std::move(trenchant);
        }

        case ModelType::Gato: {
            std::unique_ptr<WarShip> gato = gatoBuilder(a, v, coordinates);
            gato->getSprite().setOrigin(gato->getWidth() / 2, gato->getLength() / 2);
            repositionAlliedShip(gato);
            return std::move(gato);
        }

        case ModelType::Narwhal: {
            std::unique_ptr<WarShip> narwhal = narwhalBuilder(coordinates, a, v);
            narwhal->getSprite().setOrigin(narwhal->getWidth() / 2, narwhal->getLength() / 2);
            repositionAlliedShip(narwhal);
            return std::move(narwhal);
        }
    }

}

std::unique_ptr<Submarine>
ShipFactory::narwhalBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    int shipWidth = 13;
    int shipHeight = 91;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    for (int i = 0; i < 4; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));
    std::unique_ptr<Submarine> Narwhal(
            new Submarine(coordinates.x, coordinates.y, 2, 48, 4600, 0, "Usa", 0, 0, 0, 0, a, v, shipHeight, shipWidth, true,
                          ShipType::Submarine, ModelType::Narwhal, 4, false));
    return Narwhal;
}

std::unique_ptr<Submarine>
ShipFactory::trenchantBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                              std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    int shipWidth = 14;
    int shipHeight = 85;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    for (int i = 0; i < 5; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));
    std::unique_ptr<Submarine> Trenchant(
            new Submarine(coordinates.x, coordinates.y, 2, 56, 5800, 0, "Uk", 0, 0, 0, 0, a, v, shipHeight, shipWidth, true,
                          ShipType::Submarine, ModelType::Trenchant, 5, false));
    return Trenchant;
}

std::unique_ptr<Submarine>
ShipFactory::papaBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                         std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    int shipWidth = 19;
    int shipHeight = 106;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    for (int i = 0; i < 10; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));
    std::unique_ptr<Submarine> Papa(
            new Submarine(coordinates.x, coordinates.y, 2, 82, 7100, 0, "Italy", 0, 0, 0, 0, a, v, shipHeight, shipWidth,
                          true,
                          ShipType::Submarine, ModelType::Papa, 10, false));
    return Papa;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedAircraftCarrier(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::list<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::Tahio: {
            std::unique_ptr<WarShip> tahio = tahioBuilder(a, v, coordinates);
            tahio->getSprite().setOrigin(tahio->getWidth() / 2, tahio->getLength() / 2);
            repositionAlliedShip(tahio);
            return std::move(tahio);
        }



        case ModelType::Hiryu: {
            std::unique_ptr<WarShip> hiryu = hiryuBuilder(coordinates, a, v);
            hiryu->getSprite().setOrigin(hiryu->getWidth() / 2, hiryu->getLength() / 2);
            repositionAlliedShip(hiryu);
            return std::move(hiryu);
        }

        case ModelType::GiuseppeGaribaldi: {
            std::unique_ptr<WarShip> giuseppeGaribaldi = giuseppeGaribaldiBuilder(a, v, coordinates);
            giuseppeGaribaldi->getSprite().setOrigin(giuseppeGaribaldi->getWidth() / 2,
                                                     giuseppeGaribaldi->getLength() / 2);
            repositionAlliedShip(giuseppeGaribaldi);
            return std::move(giuseppeGaribaldi);
        }

        case ModelType::Cavour: {
            std::unique_ptr<WarShip> cavour = cavourBuilder(coordinates, a, v);
            cavour->getSprite().setOrigin(cavour->getWidth() / 2, cavour->getLength() / 2);
            repositionAlliedShip(cavour);
            return std::move(cavour);
        }

        case ModelType::ArkRoyal: {
            std::unique_ptr<WarShip> arkRoyal = arkRoyalBuilder(a, v, coordinates);
            arkRoyal->getSprite().setOrigin(arkRoyal->getWidth() / 2, arkRoyal->getLength() / 2);
            repositionAlliedShip(arkRoyal);
            return std::move(arkRoyal);
        }


        case ModelType::Indomitable: {
            std::unique_ptr<WarShip> indomitable = indomitableBuilder(coordinates, a, v);
            indomitable->getSprite().setOrigin(indomitable->getWidth() / 2, indomitable->getLength() / 2);
            repositionAlliedShip(indomitable);
            return std::move(indomitable);
        }

        case ModelType::Midway: {
            std::unique_ptr<WarShip> midway = midwayBuilder(a, v, coordinates);
            midway->getSprite().setOrigin(midway->getWidth() / 2, midway->getLength() / 2);
            repositionAlliedShip(midway);
            return std::move(midway);
        }

        case ModelType::FranklinDRoosevelt: {
            std::unique_ptr<WarShip> franklinDRoosevelt = franklinDelanoRoosveltBuilder(coordinates, a, v);
            franklinDRoosevelt->getSprite().setOrigin(franklinDRoosevelt->getWidth() / 2,
                                                      franklinDRoosevelt->getLength() / 2);
            repositionAlliedShip(franklinDRoosevelt);
            return std::move(franklinDRoosevelt);
        }

    }

}

std::unique_ptr<AircraftCarrier>
ShipFactory::franklinDelanoRoosveltBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                           std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory factory;
    int shipWidth = 70;
    int shipHeight = 295;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 55, cannonPosY + 92)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 56, cannonPosY + 179)));
    WeaponFactory specialFactory;
    int numAntiAir = 8;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<AircraftCarrier> FranklinDRoosevelt(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 45000, 363, "Usa", 0, 0, 2, numAntiAir, a, v,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::FranklinDRoosevelt, 14));
    return FranklinDRoosevelt;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::indomitableBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory factory;


    int shipWidth = 41;
    int shipHeight = 230;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    a.emplace_back(std::move(factory.createLight(cannonPosX + 6, cannonPosY + 38)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 31, cannonPosY + 38)));
    WeaponFactory specialFactory;
    int numAntiAir = 6;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<AircraftCarrier> Indomitable(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 29730, 240, "Uk", 2, 0, 0, numAntiAir, a, v,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::Indomitable, 5));
    return Indomitable;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::cavourBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                           std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory factory;

    int shipWidth = 50;
    int shipHeight = 244;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    a.emplace_back(std::move(factory.createLight(cannonPosX + 16, cannonPosY + 4)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 31, cannonPosY + 23)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 29, cannonPosY + 78)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 171)));
    WeaponFactory specialFactory;
    int numAntiAir = 3;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<AircraftCarrier> Cavour(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 52, 29900, 241, "Italy", 4, 0, 0, numAntiAir, a, v,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::Cavour, 5));
    return Cavour;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::hiryuBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                          std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory factory;

    int shipWidth = 39;
    int shipHeight = 222;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    a.emplace_back(std::move(factory.createLight(cannonPosX + 18, cannonPosY + 3)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 5, cannonPosY + 61)));
    WeaponFactory specialFactory;
    int numAntiAir = 2;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<AircraftCarrier> Hiryu(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 63, 20570, 70, "Japan", 2, 0, 0, numAntiAir, a, v,
                                shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::Hiryu, 6));
    return Hiryu;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedCruiser(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::list<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::Ijn: {
            std::unique_ptr<WarShip> ijn = ijnBuilder(coordinates, a, v);
            ijn->getSprite().setOrigin(ijn->getWidth() / 2, ijn->getLength() / 2);
            repositionAlliedShip(ijn);
            return std::move(ijn);
        }

        case ModelType::IsuzuNagara: {
            std::unique_ptr<WarShip> isuzuNagara = isuzuNagaraBuilder(coordinates, a, v);
            isuzuNagara->getSprite().setOrigin(isuzuNagara->getWidth() / 2, isuzuNagara->getLength() / 2);
            repositionAlliedShip(isuzuNagara);
            return std::move(isuzuNagara);
        }

        case ModelType::Takao: {
            std::unique_ptr<WarShip> takao = takaoBuilder(a, v, coordinates);
            takao->getSprite().setOrigin(takao->getWidth() / 2, takao->getLength() / 2);
            repositionAlliedShip(takao);
            return std::move(takao);
        }

        case ModelType::AlbertoDiGiussano: {
            std::unique_ptr<WarShip> albertoDiGiussano = albertoDiGiussanoBuilder(a, v, coordinates);
            albertoDiGiussano->getSprite().setOrigin(albertoDiGiussano->getWidth() / 2,
                                                     albertoDiGiussano->getLength() / 2);
            repositionAlliedShip(albertoDiGiussano);
            return std::move(albertoDiGiussano);
        }

        case ModelType::Gorizia: {
            std::unique_ptr<WarShip> gorizia = goriziaBuilder(coordinates, a, v);
            gorizia->getSprite().setOrigin(gorizia->getWidth() / 2, gorizia->getLength() / 2);
            repositionAlliedShip(gorizia);
            return std::move(gorizia);
        }


        case ModelType::Trento: {
            std::unique_ptr<WarShip> trento = trentoBuilder(a, v, coordinates);
            trento->getSprite().setOrigin(trento->getWidth() / 2, trento->getLength() / 2);
            repositionAlliedShip(trento);
            return std::move(trento);
        }


        case ModelType::Belfast: {
            std::unique_ptr<WarShip> belfast = belfastBuilder(coordinates, a, v);
            belfast->getSprite().setOrigin(belfast->getWidth() / 2, belfast->getLength() / 2);
            repositionAlliedShip(belfast);
            return std::move(belfast);
        }

        case ModelType::Danae: {
            std::unique_ptr<WarShip> danae = danaeBuilder(a, v, coordinates);
            danae->getSprite().setOrigin(danae->getWidth() / 2, danae->getLength() / 2);
            repositionAlliedShip(danae);
            return std::move(danae);
        }


        case ModelType::Tiger59: {
            std::unique_ptr<WarShip> tiger59 = tiger59Builder(coordinates, a, v);
            tiger59->getSprite().setOrigin(tiger59->getWidth() / 2, tiger59->getLength() / 2);
            repositionAlliedShip(tiger59);
            return std::move(tiger59);
        }


        case ModelType::Alaska: {
            std::unique_ptr<WarShip> alaska = alaskaBuilder(a, v, coordinates);
            alaska->getSprite().setOrigin(alaska->getWidth() / 2, alaska->getLength() / 2);
            repositionAlliedShip(alaska);
            return std::move(alaska);
        }


        case ModelType::NewOrleans: {
            std::unique_ptr<WarShip> newOrleans = newOrleansBuilder(coordinates, a, v);
            newOrleans->getSprite().setOrigin(newOrleans->getWidth() / 2, newOrleans->getLength() / 2);
            repositionAlliedShip(newOrleans);
            return std::move(newOrleans);
        }


        case ModelType::StLouis: {

            std::unique_ptr<WarShip> saintLouis = stLouisBuilder(a, v, coordinates);
            saintLouis->getSprite().setOrigin(saintLouis->getWidth() / 2, saintLouis->getLength() / 2);
            repositionAlliedShip(saintLouis);
            return std::move(saintLouis);
        }


    }

}


std::unique_ptr<Cruiser>
ShipFactory::newOrleansBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                               std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;

    int shipWidth = 25;
    int shipHeight = 178;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    CannonFactory cf;
    int antiAir = 12;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 121)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 50)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 38)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 73)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 82)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 90)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 17, cannonPosY + 73)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 17, cannonPosY + 82)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 17, cannonPosY + 90)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> NewOrleans(
            new Cruiser(coordinates.x, coordinates.y, 3, 61, 12663, 476, "Usa", 6, 0, 3, antiAir, a, v, shipHeight,
                        shipWidth,
                        true,
                        ShipType::Cruiser, ModelType::NewOrleans, 0));
    return NewOrleans;
}

std::unique_ptr<Cruiser>
ShipFactory::tiger59Builder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;

    int shipWidth = 19;
    int shipHeight = 169;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    CannonFactory cf;
    int antiAir = 7;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 137)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 128)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 32)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 5, cannonPosY + 24)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 117)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 92)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 75)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 13, cannonPosY + 117)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 13, cannonPosY + 92)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 13, cannonPosY + 75)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> Tiger59(
            new Cruiser(coordinates.x, coordinates.y, 3, 58, 12080, 191, "Uk", 6, 0, 4, antiAir, a, v, shipHeight,
                        shipWidth,
                        true,
                        ShipType::Cruiser, ModelType::Tiger59, 2));
    return Tiger59;
}

std::unique_ptr<Cruiser>
ShipFactory::belfastBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;

    int shipWidth = 27;
    int shipHeight = 187;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    CannonFactory cf;
    int antiAir = 12;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 151)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 141)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 34)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 25)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 4, cannonPosY + 121)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 4, cannonPosY + 107)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 4, cannonPosY + 95)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 121)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 107)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 95)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> Belfast(
            new Cruiser(coordinates.x, coordinates.y, 3, 59, 11550, 228, "Uk", 6, 0, 4, antiAir, a, v, shipHeight,
                        shipWidth,
                        true,
                        ShipType::Cruiser, ModelType::Belfast, 1));
    return Belfast;
}

std::unique_ptr<Cruiser>
ShipFactory::goriziaBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;

    int shipWidth = 22;
    int shipHeight = 183;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    CannonFactory cf;
    int antiAir = 12;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 7, cannonPosY + 153)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 7, cannonPosY + 143)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 7, cannonPosY + 59)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 7, cannonPosY + 49)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 78)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 15, cannonPosY + 78)));
    a.emplace_back(std::move(cf.createLight(cannonPosX, cannonPosY + 107)));
    a.emplace_back(std::move(cf.createLight(cannonPosX, cannonPosY + 98)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 107)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 18, cannonPosY + 98)));
    for (int i = 0; i < antiAir; i++) {
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    }
    std::unique_ptr<Cruiser> Gorizia(
            new Cruiser(coordinates.x, coordinates.y, 3, 59, 14330, 370, "Italy", 6, 0, 4, antiAir, a, v, shipHeight,
                        shipWidth,
                        true,
                        ShipType::Cruiser, ModelType::Gorizia, 0));
    return Gorizia;
}

std::unique_ptr<Cruiser>
ShipFactory::isuzuNagaraBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;

    int shipWidth = 14;
    int shipHeight = 159;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;

    CannonFactory cf;
    int antiAir = 6;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 132)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 94)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 18)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 142)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 77)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 6, cannonPosY + 77)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 30)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 6, cannonPosY + 30)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> IsuzuNagara(
            new Cruiser(coordinates.x, coordinates.y, 3, 67, 5700, 90, "Japan", 5, 0, 3, antiAir, a, v, shipHeight,
                        shipWidth,
                        true,
                        ShipType::Cruiser, ModelType::IsuzuNagara, 1));
    return IsuzuNagara;
}

std::unique_ptr<Cruiser>
ShipFactory::ijnBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                        std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;

    int shipWidth = 26;
    int shipHeight = 204;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;

    CannonFactory cf;
    int antiAir = 10;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 31)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 41)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 50)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 9, cannonPosY + 64)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 101)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 115)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 20, cannonPosY + 102)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 20, cannonPosY + 115)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> Ijn(
            new Cruiser(coordinates.x, coordinates.y, 3, 66, 15500, 230, "Japan", 4, 0, 4, antiAir, a, v, shipHeight,
                        shipWidth,
                        true,
                        ShipType::Cruiser, ModelType::Ijn, 2));
    return Ijn;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedBattleship(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::list<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::ISE: {
            std::unique_ptr<WarShip> ise = iseBuilder(coordinates, a, v);
            ise->getSprite().setOrigin(ise->getWidth() / 2, ise->getLength() / 2);
            repositionAlliedShip(ise);
            return std::move(ise);
        }

        case ModelType::Kongo: {
            std::unique_ptr<WarShip> kongo = kongoBuilder(a, v, coordinates);
            kongo->getSprite().setOrigin(kongo->getWidth() / 2, kongo->getLength() / 2);
            repositionAlliedShip(kongo);
            return std::move(kongo);
        }

        case ModelType::Musashi: {
            std::unique_ptr<WarShip> musashi = musashiBuilder(a, v, coordinates);
            musashi->getSprite().setOrigin(musashi->getWidth() / 2, musashi->getLength() / 2);
            repositionAlliedShip(musashi);
            return std::move(musashi);
        }

        case ModelType::Yamato: {
            std::unique_ptr<WarShip> yamato = yamatoBuilder(coordinates, a, v);
            yamato->getSprite().setOrigin(yamato->getWidth() / 2, yamato->getLength() / 2);
            repositionAlliedShip(yamato);
            return std::move(yamato);
        }

        case ModelType::AndreaDoria: {
            std::unique_ptr<WarShip> andreaDoria = andreaDoriaBuilder(coordinates, a, v);
            andreaDoria->getSprite().setOrigin(andreaDoria->getWidth() / 2, andreaDoria->getLength() / 2);
            repositionAlliedShip(andreaDoria);
            return std::move(andreaDoria);
        }

        case ModelType::ImperatoreAugusto: {
            std::unique_ptr<WarShip> imperatoreAugusto = imperatoreAugustoBuilder(a, v, coordinates);
            imperatoreAugusto->getSprite().setOrigin(imperatoreAugusto->getWidth() / 2,
                                                     imperatoreAugusto->getLength() / 2);
            repositionAlliedShip(imperatoreAugusto);
            return std::move(imperatoreAugusto);
        }

        case ModelType::MichelangeloBuonarroti: {
            std::unique_ptr<WarShip> michelangeloBuonarroti = michelangeloBuonarrotiBuilder(coordinates, a, v);
            michelangeloBuonarroti->getSprite().setOrigin(michelangeloBuonarroti->getWidth() / 2,
                                                          michelangeloBuonarroti->getLength() / 2);
            repositionAlliedShip(michelangeloBuonarroti);
            return std::move(michelangeloBuonarroti);
        }

        case ModelType::VittorioVeneto: {
            std::unique_ptr<WarShip> vittorioVeneto = vittorioVenetoBuilder(coordinates, a, v);
            vittorioVeneto->getSprite().setOrigin(vittorioVeneto->getWidth() / 2, vittorioVeneto->getLength() / 2);
            repositionAlliedShip(vittorioVeneto);
            return std::move(vittorioVeneto);
        }


        case ModelType::Dreadnought: {
            std::unique_ptr<WarShip> dreadNought = dreadNoughtBuilder(a, v, coordinates);
            dreadNought->getSprite().setOrigin(dreadNought->getWidth() / 2, dreadNought->getLength() / 2);
            repositionAlliedShip(dreadNought);
            return std::move(dreadNought);
        }


        case ModelType::Hood: {
            std::unique_ptr<WarShip> hood = hoodBuilder(coordinates, a, v);
            hood->getSprite().setOrigin(hood->getWidth() / 2, hood->getLength() / 2);
            repositionAlliedShip(hood);
            return std::move(hood);
        }


        case ModelType::IronDuke: {
            std::unique_ptr<WarShip> ironDuke = ironDukeBuilder(a, v, coordinates);
            ironDuke->getSprite().setOrigin(ironDuke->getWidth() / 2, ironDuke->getLength() / 2);
            repositionAlliedShip(ironDuke);
            return std::move(ironDuke);
        }
        case ModelType::Lion: {
            std::unique_ptr<WarShip> lion = lionBuilder(a, v, coordinates);
            lion->getSprite().setOrigin(lion->getWidth() / 2, lion->getLength() / 2);
            repositionAlliedShip(lion);
            return std::move(lion);
        }

        case ModelType::Arizona: {
            std::unique_ptr<WarShip> arizona = arizonaBuilder(coordinates, a, v);
            arizona->getSprite().setOrigin(arizona->getWidth() / 2, arizona->getLength() / 2);
            repositionAlliedShip(arizona);
            return std::move(arizona);
        }

        case ModelType::Montana: {
            std::unique_ptr<WarShip> montana = montanaBuilder(a, v, coordinates);
            montana->getSprite().setOrigin(montana->getWidth() / 2, montana->getLength() / 2);
            repositionAlliedShip(montana);
            return std::move(montana);
        }

        case ModelType::NewYork: {
            std::unique_ptr<WarShip> newYork = newYorkBuilder(coordinates, a, v);
            newYork->getSprite().setOrigin(newYork->getWidth() / 2, newYork->getLength() / 2);
            repositionAlliedShip(newYork);
            return std::move(newYork);
        }


        case ModelType::NorthCarolina: {
            std::unique_ptr<WarShip> northCarolina = northCarolinaBuilder(a, v, coordinates);
            northCarolina->getSprite().setOrigin(northCarolina->getWidth() / 2, northCarolina->getLength() / 2);
            repositionAlliedShip(northCarolina);
            return std::move(northCarolina);
        }


    }

}

std::unique_ptr<Battleship>
ShipFactory::vittorioVenetoBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                   std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory factory;
    int shipWidth = 33;
    int shipHeight = 238;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 61)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 83)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 83)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 9, cannonPosY + 146)));

    a.emplace_back(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 95)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 165)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 24, cannonPosY + 95)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 24, cannonPosY + 165)));

    a.emplace_back(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 104)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 109)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 115)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 122)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 130)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 136)));

    a.emplace_back(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 104)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 109)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 115)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 122)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 130)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 26, cannonPosY + 136)));


    WeaponFactory specialFactory;
    int numAntiAir = 32;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<Battleship> VittorioVeneto(
            new Battleship(coordinates.x, coordinates.y, 1, 56, 45963, 862, "Italy", 12, 4, 4, numAntiAir, a, v,
                           shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::VittorioVeneto, 1));
    return VittorioVeneto;
}

std::unique_ptr<Battleship>
ShipFactory::newYorkBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int shipWidth = 35;
    int shipHeight = 175;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int antiAir = 6;
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 25)));
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 45)));
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 90)));
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 115)));
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 10, cannonPosY + 140)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> NewYork(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 28822, 939,
                           "Usa", 0, 5, 0, antiAir, a, v, shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::NewYork, 0));
    return NewYork;
}

std::unique_ptr<Battleship>
ShipFactory::arizonaBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int shipWidth = 32;
    int shipHeight = 185;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    int antiAir = 4;
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 8, cannonPosY + 35)));
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 8, cannonPosY + 64)));
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 8, cannonPosY + 126)));
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 8, cannonPosY + 148)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 97)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 2, cannonPosY + 87)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 2, cannonPosY + 78)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 4, cannonPosY + 69)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 23, cannonPosY + 97)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 26, cannonPosY + 87)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 23, cannonPosY + 78)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 21, cannonPosY + 69)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> Arizona(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 32429, 1536,
                           "Usa", 8, 4, 0, antiAir, a, v, 185, 32, true,
                           ShipType::Battleship,
                           ModelType::Arizona, 0));
    return Arizona;
}

std::unique_ptr<Battleship>
ShipFactory::hoodBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                         std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int shipWidth = 34;
    int shipHeight = 262;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    int antiAir = 20;
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 9, cannonPosY + 213)));
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 9, cannonPosY + 50)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 12, cannonPosY + 196)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 13, cannonPosY + 65)));

    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> Hood(
            new Battleship(coordinates.x, coordinates.y, 1, 54, 49136, 800, "Uk", 0, 2, 2, antiAir, a, v, shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::Hood, 0));
    return Hood;
}

std::unique_ptr<Battleship>
ShipFactory::michelangeloBuonarrotiBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                           std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory factory;
    int shipWidth = 35;
    int shipHeight = 246;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 10, cannonPosY + 62)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 10, cannonPosY + 83)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 10, cannonPosY + 172)));


    a.emplace_back(std::move(factory.createMedium(cannonPosX + 1, cannonPosY + 120)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 1, cannonPosY + 141)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 2, cannonPosY + 96)));

    a.emplace_back(std::move(factory.createMedium(cannonPosX + 27, cannonPosY + 120)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 27, cannonPosY + 141)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 27, cannonPosY + 96)));

    a.emplace_back(std::move(factory.createLight(cannonPosX + 5, cannonPosY + 106)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 5, cannonPosY + 112)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 5, cannonPosY + 132)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 5, cannonPosY + 153)));


    a.emplace_back(std::move(factory.createLight(cannonPosX + 24, cannonPosY + 106)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 24, cannonPosY + 112)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 24, cannonPosY + 132)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 24, cannonPosY + 154)));

    a.emplace_back(std::move(factory.createLight(cannonPosX + 4, cannonPosY + 166)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 4, cannonPosY + 172)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 25, cannonPosY + 166)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 25, cannonPosY + 172)));


    WeaponFactory specialFactory;
    int numAntiAir = 14;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> MichelangeloBuonarroti(
            new Battleship(coordinates.x, coordinates.y, 1, 61, 42533, 837, "Italy", 12, 3, 6, numAntiAir, a, v,
                           shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::MichelangeloBuonarroti, 1));
    return MichelangeloBuonarroti;
}

std::unique_ptr<Battleship>
ShipFactory::andreaDoriaBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory factory;
    int shipWidth = 29;
    int shipHeight = 176;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 7, cannonPosY + 46)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 7, cannonPosY + 60)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 7, cannonPosY + 124)));
    a.emplace_back(std::move(factory.createHeavly(cannonPosX + 7, cannonPosY + 138)));

    a.emplace_back(std::move(factory.createMedium(cannonPosX + 4, cannonPosY + 70)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 20, cannonPosY + 70)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 3, cannonPosY + 77)));
    a.emplace_back(std::move(factory.createMedium(cannonPosX + 21, cannonPosY + 77)));

    a.emplace_back(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 85)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 91)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 97)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 103)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 3, cannonPosY + 109)));

    a.emplace_back(std::move(factory.createLight(cannonPosX + 22, cannonPosY + 85)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 22, cannonPosY + 91)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 22, cannonPosY + 97)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 22, cannonPosY + 103)));
    a.emplace_back(std::move(factory.createLight(cannonPosX + 22, cannonPosY + 109)));

    WeaponFactory specialFactory;
    int numAntiAir = 13;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> AndreaDoria(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 24729, 622, "Italy", 10, 4, 4, numAntiAir, a, v,
                           shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::AndreaDoria, 0));
    return AndreaDoria;
}

std::unique_ptr<Battleship>
ShipFactory::yamatoBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                           std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 40;
    int shipWidth = 41;
    int shipHeight = 263;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 13, cannonPosY + 71)));
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 13, cannonPosY + 93)));
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 14, cannonPosY + 184)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 16, cannonPosY + 176)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 16, cannonPosY + 118)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 13, cannonPosY + 161)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 13, cannonPosY + 150)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 13, cannonPosY + 138)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 157)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 146)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 4, cannonPosY + 130)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 25, cannonPosY + 161)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 25, cannonPosY + 150)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 26, cannonPosY + 138)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 29, cannonPosY + 157)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 29, cannonPosY + 146)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 32, cannonPosY + 130)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<Battleship> Yamato(
            new Battleship(coordinates.x, coordinates.y, 1, 50, 71659, 1286, "Japan", 12, 3, 2, antiAir, a, v,
                           shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::Yamato, 3));
    return Yamato;
}

std::unique_ptr<Battleship>
ShipFactory::iseBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                        std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 19;
    int shipWidth = 43;
    int shipHeight = 220;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 14, cannonPosY + 37)));
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 14, cannonPosY + 51)));
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 14, cannonPosY + 113)));
    a.emplace_back(std::move(cf.createHeavly(cannonPosX + 14, cannonPosY + 125)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 9, cannonPosY + 102)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 9, cannonPosY + 80)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 12, cannonPosY + 71)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 12, cannonPosY + 62)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 30, cannonPosY + 102)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 32, cannonPosY + 80)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 28, cannonPosY + 71)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 27, cannonPosY + 62)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> Ise(
            new Battleship(coordinates.x, coordinates.y, 1, 45, 40444, 705, "Japan", 8, 4, 0, antiAir, a, v, shipHeight,
                           shipWidth,
                           true,
                           ShipType::Battleship, ModelType::ISE, 2));
    return Ise;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedDestroyer(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::list<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;
    coordinates.y = coordinates.y - (0.14 * map.getMapHeight());
    switch (type) {

        case ModelType::Akizuki: {
            std::unique_ptr<WarShip> akizuki = akizukiBuilder(coordinates, a, v);
            akizuki->getSprite().setOrigin(akizuki->getWidth() / 2, akizuki->getLength() / 2);
            repositionAlliedShip(akizuki);
            return std::move(akizuki);
        }


        case ModelType::Fubuki: {
            std::unique_ptr<WarShip> fubuki = fubukiBuilder(coordinates, a, v);
            fubuki->getSprite().setOrigin(fubuki->getWidth() / 2, fubuki->getLength() / 2);
            repositionAlliedShip(fubuki);
            return std::move(fubuki);
        }


        case ModelType::Yukikaze: {
            std::unique_ptr<WarShip> yukikaze = yukikazeBuilder(a, v, coordinates);
            yukikaze->getSprite().setOrigin(yukikaze->getWidth() / 2, yukikaze->getLength() / 2);
            repositionAlliedShip(yukikaze);
            return std::move(yukikaze);
        }


        case ModelType::Impavido: {
            std::unique_ptr<WarShip> impavido = impavidoBuilder(a, v, coordinates);
            impavido->getSprite().setOrigin(impavido->getWidth() / 2, impavido->getLength() / 2);
            repositionAlliedShip(impavido);
            return std::move(impavido);
        }


        case ModelType::Leone: {
            std::unique_ptr<WarShip> leone = leoneBuilder(coordinates, a, v);
            leone->getSprite().setOrigin(leone->getWidth() / 2, leone->getLength() / 2);
            repositionAlliedShip(leone);
            return std::move(leone);
        }
        case ModelType::PaoloEmilio: {
            std::unique_ptr<WarShip> paoloEmilio = paoloEmilioBuilder(a, v, coordinates);
            paoloEmilio->getSprite().setOrigin(paoloEmilio->getWidth() / 2, paoloEmilio->getLength() / 2);
            repositionAlliedShip(paoloEmilio);
            return std::move(paoloEmilio);
        }


        case ModelType::Campbelltown: {
            std::unique_ptr<WarShip> campbelltown = campbeltownBuilder(coordinates, a, v);
            campbelltown->getSprite().setOrigin(campbelltown->getWidth() / 2, campbelltown->getLength() / 2);
            repositionAlliedShip(campbelltown);
            return std::move(campbelltown);
        }


        case ModelType::Gallant: {
            std::unique_ptr<WarShip> gallant = gallandBuilder(coordinates, a, v);
            gallant->getSprite().setOrigin(gallant->getWidth() / 2, gallant->getLength() / 2);
            repositionAlliedShip(gallant);
            return std::move(gallant);
        }


        case ModelType::Jutland: {
            std::unique_ptr<WarShip> jutLand = jutlandBuilder(a, v, coordinates);
            jutLand->getSprite().setOrigin(jutLand->getWidth() / 2, jutLand->getLength() / 2);
            repositionAlliedShip(jutLand);
            return std::move(jutLand);
        }


        case ModelType::Fletcher: {
            std::unique_ptr<WarShip> fletcher = fletcherBuilder(a, v, coordinates);
            fletcher->getSprite().setOrigin(fletcher->getWidth() / 2, fletcher->getLength() / 2);
            repositionAlliedShip(fletcher);
            return std::move(fletcher);
        }


        case ModelType::Mahan: {
            std::unique_ptr<WarShip> mahan = mahanBuilder(coordinates, a, v);
            mahan->getSprite().setOrigin(mahan->getWidth() / 2, mahan->getLength() / 2);
            repositionAlliedShip(mahan);
            return std::move(mahan);
        }


        case ModelType::Sims: {
            std::unique_ptr<WarShip> sims = simsBuilder(a, v, coordinates);
            sims->getSprite().setOrigin(sims->getWidth() / 2, sims->getLength() / 2);
            repositionAlliedShip(sims);
            return std::move(sims);
        }


    }

}

std::unique_ptr<Destroyer>
ShipFactory::mahanBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                          std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory cf;
    int shipWidth = 13;
    int shipHeight = 104;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 11)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 37)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 90)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 72)));
    int numAntiAir = 8;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }

    std::unique_ptr<Destroyer> Mahan(
            new Destroyer(coordinates.x, coordinates.y, 4, 69, 2137, 27,
                          "Usa", 0, 0, 4, numAntiAir, a, v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Mahan, 12));
    return Mahan;
}

std::unique_ptr<Destroyer>
ShipFactory::gallandBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory cf;
    int shipWidth = 10;
    int shipHeight = 99;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 14)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 21)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 75)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 81)));
    int numAntiAir = 8;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }

    std::unique_ptr<Destroyer> Gallant(
            new Destroyer(coordinates.x, coordinates.y, 4, 67, 1913, 22,
                          "Uk", 0, 0, 4, numAntiAir, a, v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Gallant, 8));
    return Gallant;
}

std::unique_ptr<Destroyer>
ShipFactory::campbeltownBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory cf;
    int shipWidth = 10;
    int shipHeight = 96;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 14)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 1, cannonPosY + 40)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 5, cannonPosY + 40)));
    a.emplace_back(std::move(cf.createLight(cannonPosX + 3, cannonPosY + 81)));
    int numAntiAir = 10;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }

    std::unique_ptr<Destroyer> Campbelltown(
            new Destroyer(coordinates.x, coordinates.y, 4, 66, 1280, 19,
                          "Uk", 4, 0, 0, numAntiAir, a, v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Campbelltown, 6));
    return Campbelltown;
}

std::unique_ptr<Destroyer>
ShipFactory::leoneBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                          std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory cf;
    int shipWidth = 13;
    int shipHeight = 113;

    int cannonPosX = coordinates.x - (shipWidth - 1) / 2;
    int cannonPosY = coordinates.y - (shipHeight - 1) / 2;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 31)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 72)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 98)));
    int numAntiAir = 20;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }
    std::unique_ptr<Destroyer> Leone(
            new Destroyer(coordinates.x, coordinates.y, 4, 61, 2326, 22,
                          "Italy", 0, 0, 3, numAntiAir, a, v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Leone, 6));
    return Leone;
}

std::unique_ptr<Destroyer>
ShipFactory::fubukiBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                           std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory cf;
    int shipWidth = 14;
    int shipHeight = 118;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 15)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 47)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 67)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 78)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 90)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 3, cannonPosY + 98)));
    int numAntiAir = 20;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }
    std::unique_ptr<Destroyer> Fubuki(
            new Destroyer(coordinates.x, coordinates.y, 4, 70, 2080, 26,
                          "Japan", 0, 0, 6, numAntiAir, a, v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Fubuki, 9));
    return Fubuki;
}

std::unique_ptr<Destroyer>
ShipFactory::akizukiBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory cf;
    int shipWidth = 12;
    int shipHeight = 134;

    int cannonPosX = coordinates.x - (shipWidth) / 2;
    int cannonPosY = coordinates.y - (shipHeight) / 2;
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 22)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 29)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 95)));
    a.emplace_back(std::move(cf.createMedium(cannonPosX + 2, cannonPosY + 104)));
    int numAntiAir = 50;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }
    std::unique_ptr<Destroyer> Akizuki(
            new Destroyer(coordinates.x, coordinates.y, 4, 61, 3759, 33,
                          "Japan", 0, 0, 5, numAntiAir, a, v, shipHeight, shipWidth, true,
                          ShipType::Destroyer,
                          ModelType::Akizuki, 4));
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
    //sposta la nave in giu di lunghezza mezzi
    ship->getSprite().move(0, ship->getLength() / 2);
    for (auto &it:ship->getArsenalList()) {
        it->getSprite().move(0, ship->getLength() / 2);
    }
    return ship;
}

std::unique_ptr<WarShip> &ShipFactory::repositionAlliedShip(std::unique_ptr<WarShip> &ship) {
    //sposta la nave in giu di lunghezza mezzi
    ship->getSprite().move(0, -ship->getLength() / 2);
    for (auto &it:ship->getArsenalList()) {
        it->getSprite().move(0, -ship->getLength() / 2);
    }
    return ship;
}
