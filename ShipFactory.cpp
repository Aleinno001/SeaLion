//
// Created by alessandro on 7/2/21.
//

#include "ShipFactory.h"
#include "GameWorld.h"


std::unique_ptr<WarShip> ShipFactory::createSubmarine(ModelType type, GameWorld &map) {
    std::list<std::unique_ptr<Arsenal>> a;
    std::list<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    switch (type) {

        case ModelType::I400: {

            std::unique_ptr<Submarine> i400 = i400Builder(a, v, coordinates);


            return std::move(i400);
        }
        case ModelType::typeb1: {
            std::unique_ptr<Submarine> typeb1 = typeb1Builder(a, v, coordinates);
            return std::move(typeb1);
        }

        case ModelType::DaVinci: {
            std::unique_ptr<Submarine> daVinci = DaVinciBuilder(a, v, coordinates);

            return std::move(daVinci);
        }
        case ModelType::Papa: {
            std::unique_ptr<Submarine> papa = papaBuilder(coordinates, a, v);
            return std::move(papa);
        }
        case ModelType::Triton: {
            std::unique_ptr<Submarine> triton = tritonBuilder(a, v, coordinates);

            return std::move(triton);
        }
        case ModelType::Trenchant: {
            std::unique_ptr<Submarine> trenchant = trenchantBuilder(coordinates, a, v);
            return std::move(trenchant);
        }
        case ModelType::Gato: {
            std::unique_ptr<Submarine> gato = gatoBuilder(a, v, coordinates);


            return std::move(gato);
        }
        case ModelType::Narwhal: {
            std::unique_ptr<Submarine> narwhal = narwhalBuilder(coordinates, a, v);
            return std::move(narwhal);
        }
    }

}

std::unique_ptr<Submarine>
ShipFactory::gatoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                         const sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    for (int i = 0; i < 6; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));

    std::unique_ptr<Submarine> Gato(
            new Submarine(coordinates.x, coordinates.y, 2, 37, 2460, 0, "Usa", 0, 0, 0, 0, a, v, 95, 9, true,
                          ShipType::Submarine, ModelType::Gato, 6, false));
    return Gato;
}

std::unique_ptr<Submarine>
ShipFactory::tritonBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                           const sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    for (int i = 0; i < 6; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));

    std::unique_ptr<Submarine> Triton(
            new Submarine(coordinates.x, coordinates.y, 2, 28, 1576, 0, "Uk", 0, 0, 0, 0, a, v, 84, 8, true,
                          ShipType::Submarine, ModelType::Triton, 6, false));
    return Triton;
}

std::unique_ptr<Submarine>
ShipFactory::DaVinciBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                            const sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    for (int i = 0; i < 8; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));

    std::unique_ptr<Submarine> DaVinci(
            new Submarine(coordinates.x, coordinates.y, 2, 15, 1489, 0, "Italy", 0, 0, 0, 0, a, v, 77, 9, true,
                          ShipType::Submarine, ModelType::DaVinci, 8, false));
    return DaVinci;
}

std::unique_ptr<Submarine>
ShipFactory::typeb1Builder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                           const sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    for (int i = 0; i < 6; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));

    std::unique_ptr<Submarine> typeb1(
            new Submarine(coordinates.x, coordinates.y, 2, 44, 3713, 0, "Japan", 0, 0, 0, 0, a, v, 111, 10,
                          true,
                          ShipType::Submarine, ModelType::typeb1, 6,
                          false));
    return typeb1;
}

std::unique_ptr<Submarine>
ShipFactory::i400Builder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                         const sf::Vector2i &coordinates) const {
    WeaponFactory factory;

    for (int i = 0; i < 8; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));

    std::unique_ptr<Submarine> i400(
            new Submarine(coordinates.x, coordinates.y, 2, 35, 6670, 0, "Japan", 0, 0, 0, 0, a, v, 122, 13,
                          true,
                          ShipType::Submarine, ModelType::I400, 8, false));
    return i400;
}

std::unique_ptr<WarShip> ShipFactory::createAircraftCarrier(ModelType type, GameWorld &map) {
    std::list<std::unique_ptr<Arsenal>> a;
    std::list<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);


    switch (type) {
        case ModelType::Tahio: {
            std::unique_ptr<AircraftCarrier> tahio = tahioBuilder(a, v, coordinates);


            return std::move(tahio);
        }


        case ModelType::Hiryu: {
            std::unique_ptr<AircraftCarrier> hiryu = hiryuBuilder(coordinates, a, v);
            return std::move(hiryu);
        }

        case ModelType::GiuseppeGaribaldi: {
            std::unique_ptr<AircraftCarrier> giuseppeGaribaldi = giuseppeGaribaldiBuilder(a, v, coordinates);


            return std::move(giuseppeGaribaldi);
        }

        case ModelType::Cavour: {
            std::unique_ptr<AircraftCarrier> cavour = cavourBuilder(coordinates, a, v);
            return std::move(cavour);
        }
        case ModelType::ArkRoyal: {
            std::unique_ptr<AircraftCarrier> arkRoyal = arkRoyalBuilder(a, v, coordinates);

            return std::move(arkRoyal);
        }

        case ModelType::Indomitable: {

            std::unique_ptr<AircraftCarrier> indomitable = indomitableBuilder(coordinates, a, v);
            return std::move(indomitable);
        }

        case ModelType::Midway: {
            std::unique_ptr<AircraftCarrier> midway = midwayBuilder(a, v, coordinates);
            return std::move(midway);
        }

        case ModelType::FranklinDRoosevelt: {
            std::unique_ptr<AircraftCarrier> franklinDRoosevelt = franklinDelanoRoosveltBuilder(coordinates, a, v);
            return std::move(franklinDRoosevelt);
        }


    }

}

std::unique_ptr<AircraftCarrier>
ShipFactory::midwayBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                           const sf::Vector2i &coordinates) const {
    CannonFactory factory;
    WeaponFactory specialFactory;
    a.emplace_back(std::move(factory.createLight(coordinates.x + 35, coordinates.y + 79)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 14, coordinates.y + 230)));
    int numAntiAir = 15;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<AircraftCarrier> mid(new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 640000, 520,
                                                             "Usa", 2, 0, 0, numAntiAir, a, v, 296, 84, true,
                                                             ShipType::AircraftCarrier, ModelType::Midway, 14));
    return mid;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::arkRoyalBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                             const sf::Vector2i &coordinates) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createLight(coordinates.x + 7, coordinates.y + 85)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 28, coordinates.y + 85)));
    WeaponFactory specialFactory;
    int numAntiAir = 4;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<AircraftCarrier> arkRoyal(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 28160, 20,
                                "Uk", 2, 0, 0, numAntiAir, a, v, 240, 38, true, ShipType::AircraftCarrier,
                                ModelType::ArkRoyal, 7));
    return arkRoyal;
}

std::unique_ptr<AircraftCarrier> ShipFactory::giuseppeGaribaldiBuilder(std::list<std::unique_ptr<Arsenal>> &a,
                                                                       std::list<std::unique_ptr<Vehicle>> &v,
                                                                       const sf::Vector2i &coordinates) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createLight(coordinates.x + 4, coordinates.y + 41)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 4, coordinates.y + 69)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 4, coordinates.y + 98)));

    std::unique_ptr<AircraftCarrier> GiuseppeGaribaldi(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 14150, 114, "Italy", 3, 0, 0, 0, a, v, 180,
                                44,
                                true,
                                ShipType::AircraftCarrier, ModelType::GiuseppeGaribaldi, 6));
    return GiuseppeGaribaldi;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::tahioBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                          const sf::Vector2i &coordinates) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createLight(coordinates.x + 20, coordinates.y + 55)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 20, coordinates.y + 218)));
    WeaponFactory specialFactory;
    int numAntiAir = 20;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<AircraftCarrier> Tahio(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 37866, 304, "Japan", 2, 0, 0, numAntiAir, a, v,
                                260,
                                46,
                                true,
                                ShipType::AircraftCarrier, ModelType::Tahio, 7));
    return Tahio;
}

std::unique_ptr<WarShip> ShipFactory::createCruiser(ModelType type, GameWorld &map) {
    std::list<std::unique_ptr<Arsenal>> a;
    std::list<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);

    switch (type) {

        case ModelType::Takao: {
            std::unique_ptr<Cruiser> takao = takaoBuilder(a, v, coordinates);

            return std::move(takao);
        }

        case ModelType::IsuzuNagara: {
            std::unique_ptr<Cruiser> isuzuNagara = isuzuNagaraBuilder(coordinates, a, v);
            return std::move(isuzuNagara);
        }


        case ModelType::Ijn: {
            std::unique_ptr<Cruiser> ijn = ijnBuilder(coordinates, a, v);
            return std::move(ijn);
        }


        case ModelType::AlbertoDiGiussano: {
            std::unique_ptr<Cruiser> albertoDiGiussano = albertoDiGiussanoBuilder(a, v, coordinates);

            return std::move(albertoDiGiussano);
        }

        case ModelType::Gorizia: {
            std::unique_ptr<Cruiser> gorizia = goriziaBuilder(coordinates, a, v);
            return std::move(gorizia);
        }

        case ModelType::Trento: {
            std::unique_ptr<Cruiser> trento = trentoBuilder(a, v, coordinates);

            return std::move(trento);
        }
        case ModelType::Belfast: {
            std::unique_ptr<Cruiser> belfast = belfastBuilder(coordinates, a, v);
            return std::move(belfast);
        }

        case ModelType::Danae: {
            std::unique_ptr<Cruiser> danae = danaeBuilder(a, v, coordinates);

            return std::move(danae);
        }

        case ModelType::Tiger59: {
            std::unique_ptr<Cruiser> tiger59 = tiger59Builder(coordinates, a, v);
            return std::move(tiger59);
        }
        case ModelType::Alaska: {
            std::unique_ptr<Cruiser> alaska = alaskaBuilder(a, v, coordinates);

            return std::move(alaska);
        }
        case ModelType::NewOrleans: {
            std::unique_ptr<Cruiser> newOrleans = newOrleansBuilder(coordinates, a, v);
            return std::move(newOrleans);
        }
        case ModelType::StLouis: {
            std::unique_ptr<Cruiser> saintLouis = stLouisBuilder(a, v, coordinates);

            return std::move(saintLouis);
        }
    }

}
                                                                                                            //TODO aggiungere aerei
std::unique_ptr<Cruiser>
ShipFactory::stLouisBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                            const sf::Vector2i &coordinates) const {
                                                                                                                WeaponFactory factory;
                                                                                                                CannonFactory cf;
                                                                                                                int antiAir = 8;
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createMedium(
                                                                                                                                        coordinates.x +
                                                                                                                                        7,
                                                                                                                                        coordinates.y +
                                                                                                                                        29)));
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createMedium(
                                                                                                                                        coordinates.x +
                                                                                                                                        7,
                                                                                                                                        coordinates.y +
                                                                                                                                        37)));
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createMedium(
                                                                                                                                        coordinates.x +
                                                                                                                                        6,
                                                                                                                                        coordinates.y +
                                                                                                                                        98)));
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createLight(
                                                                                                                                        coordinates.x +
                                                                                                                                        1,
                                                                                                                                        coordinates.y +
                                                                                                                                        71)));
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createLight(
                                                                                                                                        coordinates.x +
                                                                                                                                        15,
                                                                                                                                        coordinates.y +
                                                                                                                                        71)));
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createLight(
                                                                                                                                        coordinates.x +
                                                                                                                                        8,
                                                                                                                                        coordinates.y +
                                                                                                                                        80)));
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createLight(
                                                                                                                                        coordinates.x +
                                                                                                                                        2,
                                                                                                                                        coordinates.y +
                                                                                                                                        41)));
                                                                                                                a.emplace_back(
                                                                                                                        std::move(
                                                                                                                                cf.createLight(
                                                                                                                                        coordinates.x +
                                                                                                                                        16,
                                                                                                                                        coordinates.y +
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
                                                                                                                                130,
                                                                                                                                20,
                                                                                                                                true,
                                                                                                                                ShipType::Cruiser,
                                                                                                                                ModelType::StLouis,
                                                                                                                                0));
                                                                                                                return saintLouis;
                                                                                                            }

std::unique_ptr<Cruiser>
ShipFactory::alaskaBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                           const sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 9;
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 9, coordinates.y + 179)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 9, coordinates.y + 60)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 6, coordinates.y + 77)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 11, coordinates.y + 91)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 1, coordinates.y + 105)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 23, coordinates.y + 105)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 1, coordinates.y + 149)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 23, coordinates.y + 150)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 11, coordinates.y + 172)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> alaska(new Cruiser(coordinates.x, coordinates.y, 3, 61, 34803, 918,
                                                "Usa", 6, 1, 2, antiAir, a, v, 246, 28, true,
                                                ShipType::Cruiser,
                                                ModelType::Alaska, 4));
    return alaska;
}

std::unique_ptr<Cruiser>
ShipFactory::danaeBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                          const sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 7;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 111)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 102)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 120)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 74)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 45)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 33)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 19)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> danae(new Cruiser(coordinates.x, coordinates.y, 3, 54, 5925, 190,
                                               "Uk", 6, 0, 1, antiAir, a, v, 136, 14, true,
                                               ShipType::Cruiser,
                                               ModelType::Danae, 0));
    return danae;
}

std::unique_ptr<Cruiser>
ShipFactory::trentoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                           const sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 12;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 9, coordinates.y + 44)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 9, coordinates.y + 52)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 9, coordinates.y + 143)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 9, coordinates.y + 153)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 68)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 15, coordinates.y + 68)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 3, coordinates.y + 84)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 18, coordinates.y + 84)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 3, coordinates.y + 111)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 18, coordinates.y + 111)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> trento(new Cruiser(coordinates.x, coordinates.y, 3, 66, 13548, 120,
                                                "Italy", 6, 0, 4, antiAir, a, v, 197, 25, true,
                                                ShipType::Cruiser,
                                                ModelType::Trento, 2));
    return trento;
}

std::unique_ptr<Cruiser> ShipFactory::albertoDiGiussanoBuilder(std::list<std::unique_ptr<Arsenal>> &a,
                                                               std::list<std::unique_ptr<Vehicle>> &v,
                                                               const sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 12;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 18)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 28)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 5, coordinates.y + 121)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 5, coordinates.y + 135)));
    a.emplace_back(std::move(cf.createLight(coordinates.x, coordinates.y + 93)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 10, coordinates.y + 93)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 6, coordinates.y + 112)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> albertoDiGiussano(new Cruiser(coordinates.x, coordinates.y, 3, 69, 6950, 84,
                                                           "Italy", 3, 0, 4, antiAir, a, v, 169, 15, true,
                                                           ShipType::Cruiser,
                                                           ModelType::AlbertoDiGiussano, 1));
    return albertoDiGiussano;
}

std::unique_ptr<Cruiser>
ShipFactory::takaoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                          const sf::Vector2i &coordinates) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 16;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 10, coordinates.y + 36)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 10, coordinates.y + 44)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 10, coordinates.y + 53)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 10, coordinates.y + 137)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 10, coordinates.y + 145)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 3, coordinates.y + 82)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 18, coordinates.y + 82)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 3, coordinates.y + 96)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 18, coordinates.y + 96)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> takao(new Cruiser(coordinates.x, coordinates.y, 3, 66, 15500, 237,
                                               "Japan", 4, 0, 5, antiAir, a, v, 193, 25, true,
                                               ShipType::Cruiser,
                                               ModelType::Takao, 2));
    return takao;
}

std::unique_ptr<WarShip> ShipFactory::createBattleship(ModelType type, GameWorld &map) {
    std::list<std::unique_ptr<Arsenal>> a;
    std::list<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    switch (type) {

        case ModelType::Yamato: {
            std::unique_ptr<Battleship> yamato = yamatoBuilder(coordinates, a, v);
            return std::move(yamato);
        }

        case ModelType::Kongo: {
            std::unique_ptr<Battleship> kongo = kongoBuilder(a, v, coordinates);

            return std::move(kongo);
        }

        case ModelType::ISE: {
            std::unique_ptr<Battleship> ise = iseBuilder(coordinates, a, v);
            return std::move(ise);
        }

        case ModelType::Musashi: {
            std::unique_ptr<Battleship> musashi = musashiBuilder(a, v, coordinates);

            return std::move(musashi);
        }

        case ModelType::AndreaDoria: {
            std::unique_ptr<Battleship> andreaDoria = andreaDoriaBuilder(coordinates, a, v);
            return std::move(andreaDoria);
        }

        case ModelType::ImperatoreAugusto: {
            std::unique_ptr<Battleship> imperatoreAugusto = imperatoreAugustoBuilder(a, v, coordinates);

            return std::move(imperatoreAugusto);
        }
        case ModelType::VittorioVeneto: {
            std::unique_ptr<Battleship> vittorioVeneto = vittorioVenetoBuilder(coordinates, a, v);
            return std::move(vittorioVeneto);
        }

        case ModelType::MichelangeloBuonarroti: {
            std::unique_ptr<Battleship> michelangeloBuonarroti = michelangeloBuonarrotiBuilder(coordinates, a, v);
            return std::move(michelangeloBuonarroti);
        }
        case ModelType::Dreadnought: {
            std::unique_ptr<Battleship> dreadNought = dreadNoughtBuilder(a, v, coordinates);

            return std::move(dreadNought);
        }
        case ModelType::IronDuke: {
            std::unique_ptr<Battleship> ironDuke = ironDukeBuilder(a, v, coordinates);

            return std::move(ironDuke);
        }
        case ModelType::Lion: {
            std::unique_ptr<Battleship> lion = lionBuilder(a, v, coordinates);

            return std::move(lion);
        }
        case ModelType::Hood: {
            std::unique_ptr<Battleship> hood = hoodBuilder(coordinates, a, v);
            return std::move(hood);
        }
        case ModelType::Arizona: {
            std::unique_ptr<Battleship> arizona = arizonaBuilder(coordinates, a, v);

            return std::move(arizona);
        }
        case ModelType::Montana: {
            std::unique_ptr<Battleship> montana = montanaBuilder(a, v, coordinates);

            return std::move(montana);
        }
        case ModelType::NewYork: {
            std::unique_ptr<Battleship> newYork = newYorkBuilder(coordinates, a, v);

            return std::move(newYork);
        }
        case ModelType::NorthCarolina: {
            std::unique_ptr<Battleship> northCarolina = northCarolinaBuilder(a, v, coordinates);

            return std::move(northCarolina);
        }
    }
    return std::unique_ptr<WarShip>(); //TODO implementare tutti i costruttori
}

std::unique_ptr<Battleship>
ShipFactory::ironDukeBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                             const sf::Vector2i &coordinates) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 16, coordinates.y + 41)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 16, coordinates.y + 55)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 16, coordinates.y + 107)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 16, coordinates.y + 133)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 16, coordinates.y + 141)));
    WeaponFactory specialFactory;
    int numAntiAir = 15;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> ironDuke(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 29500, 826,
                           "Uk", 0, 5, 0, numAntiAir, a, v, 190, 39, true,
                           ShipType::Battleship,
                           ModelType::IronDuke, 0));
    return ironDuke;
}

std::unique_ptr<Battleship>
ShipFactory::northCarolinaBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                                  const sf::Vector2i &coordinates) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 12, coordinates.y + 147)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 12, coordinates.y + 173)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 5, coordinates.y + 81)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 22, coordinates.y + 81)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 5, coordinates.y + 101)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 22, coordinates.y + 101)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 1, coordinates.y + 111)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 26, coordinates.y + 111)));
    WeaponFactory specialFactory;
    int numAntiAir = 34;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<Battleship> northCarolina(
            new Battleship(coordinates.x, coordinates.y, 1, 52, 45500, 1224,
                           "Usa", 6, 2, 0, numAntiAir, a, v, 222, 32, true,
                           ShipType::Battleship,
                           ModelType::NorthCarolina, 3));
    return northCarolina;
}

std::unique_ptr<Battleship>
ShipFactory::montanaBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                            const sf::Vector2i &coordinates) const {
    //TODO concludere tutte le aggiunte necessarie
    CannonFactory factory;
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 13, coordinates.y + 68)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 13, coordinates.y + 88)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 13, coordinates.y + 183)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 13, coordinates.y + 203)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 2, coordinates.y + 111)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 30, coordinates.y + 111)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 5, coordinates.y + 125)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 27, coordinates.y + 125)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 2, coordinates.y + 138)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 30, coordinates.y + 138)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 4, coordinates.y + 152)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 27, coordinates.y + 152)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 2, coordinates.y + 165)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 30, coordinates.y + 165)));
    WeaponFactory specialFactory;
    int numAntiAir = 80;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<Battleship> montana(
            new Battleship(coordinates.x, coordinates.y, 1, 52, 72104, 1810,
                           "Usa", 0, 4, 10, numAntiAir, a, v, 281, 37, true,
                           ShipType::Battleship,
                           ModelType::Montana, 2));
    return montana;
}

std::unique_ptr<Battleship>
ShipFactory::lionBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                         const sf::Vector2i &coordinates) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 15, coordinates.y + 49)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 15, coordinates.y + 64)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 15, coordinates.y + 126)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 15, coordinates.y + 197)));
    WeaponFactory specialFactory;
    int numAntiAir = 10;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> lion(
            new Battleship(coordinates.x, coordinates.y, 1, 52, 49670, 944,
                           "Uk", 0, 4, 0, numAntiAir, a, v, 242, 39, true,
                           ShipType::Battleship,
                           ModelType::Lion, 0));
    return lion;
}

std::unique_ptr<Battleship>
ShipFactory::dreadNoughtBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                                const sf::Vector2i &coordinates) const {
    CannonFactory factory;

    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 8, coordinates.y + 38)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 8, coordinates.y + 93)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 8, coordinates.y + 118)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x, coordinates.y + 64)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 17, coordinates.y + 64)));
    WeaponFactory specialFactory;
    int numAntiAir = 20;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> dreadNought(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 21060, 837,
                           "Uk", 0, 5, 0, numAntiAir, a, v, 158, 25, true,
                           ShipType::Battleship,
                           ModelType::Dreadnought, 0));
    return dreadNought;
}

std::unique_ptr<Battleship> ShipFactory::imperatoreAugustoBuilder(std::list<std::unique_ptr<Arsenal>> &a,
                                                                  std::list<std::unique_ptr<Vehicle>> &v,
                                                                  const sf::Vector2i &coordinates) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 16, coordinates.y + 70)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 16, coordinates.y + 89)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 16, coordinates.y + 188)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 16, coordinates.y + 208)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 3, coordinates.y + 111)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 3, coordinates.y + 120)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 3, coordinates.y + 163)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 3, coordinates.y + 172)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 31, coordinates.y + 111)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 31, coordinates.y + 120)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 31, coordinates.y + 163)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 31, coordinates.y + 172)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 17, coordinates.y + 110)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 17, coordinates.y + 173)));

    a.emplace_back(std::move(factory.createLight(coordinates.x + 2, coordinates.y + 131)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 2, coordinates.y + 138)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 2, coordinates.y + 146)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 2, coordinates.y + 153)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 8, coordinates.y + 128)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 8, coordinates.y + 153)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 8, coordinates.y + 149)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 8, coordinates.y + 156)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 27, coordinates.y + 128)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 27, coordinates.y + 153)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 27, coordinates.y + 149)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 27, coordinates.y + 156)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 33, coordinates.y + 131)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 33, coordinates.y + 138)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 33, coordinates.y + 146)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 33, coordinates.y + 153)));
    WeaponFactory specialFactory;
    int numAntiAir = 12;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<Battleship> imperatoreAugusto(
            new Battleship(coordinates.x, coordinates.y, 1, 57, 65232, 1126,
                           "Italy", 16, 4, 10, numAntiAir, a, v, 274, 39, true,
                           ShipType::Battleship,
                           ModelType::ImperatoreAugusto, 0));
    return imperatoreAugusto;
}

std::unique_ptr<Battleship>
ShipFactory::kongoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                          const sf::Vector2i &coordinates) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 11, coordinates.y + 43)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 11, coordinates.y + 56)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 11, coordinates.y + 131)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 11, coordinates.y + 169)));

    a.emplace_back(std::move(factory.createLight(coordinates.x + 2, coordinates.y + 81)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 2, coordinates.y + 95)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 2, coordinates.y + 129)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 24, coordinates.y + 81)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 24, coordinates.y + 95)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 24, coordinates.y + 129)));

    WeaponFactory specialFactory;
    int numAntiAir = 18;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> kongo(new Battleship(coordinates.x, coordinates.y, 1, 56, 37187, 592,
                                                     "Japan", 6, 4, 0, numAntiAir, a, v, 222, 31, true,
                                                     ShipType::Battleship,
                                                     ModelType::Kongo, 0));
    return kongo;
}

std::unique_ptr<Battleship>
ShipFactory::musashiBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                            const sf::Vector2i &coordinates) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 12, coordinates.y + 67)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 12, coordinates.y + 88)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 12, coordinates.y + 173)));

    a.emplace_back(std::move(factory.createMedium(coordinates.x + 8, coordinates.y + 112)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 27, coordinates.y + 112)));

    a.emplace_back(std::move(factory.createLight(coordinates.x, coordinates.y + 125)));
    a.emplace_back(std::move(factory.createLight(coordinates.x, coordinates.y + 146)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 34, coordinates.y + 125)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 34, coordinates.y + 146)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 24, coordinates.y + 95)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 24, coordinates.y + 129)));

    WeaponFactory specialFactory;
    int numAntiAir = 30;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<Battleship> musashi(new Battleship(coordinates.x, coordinates.y, 1, 51, 72809, 1540,
                                                       "Japan", 6, 3, 2, numAntiAir, a, v, 244, 39, true,
                                                       ShipType::Battleship,
                                                       ModelType::Musashi, 2));
    return musashi;
}

std::unique_ptr<WarShip> ShipFactory::createDestroyer(ModelType type, GameWorld &map) {
    std::list<std::unique_ptr<Arsenal>> a;
    std::list<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    switch (type) {

        case ModelType::Akizuki: {
            std::unique_ptr<Destroyer> akizuki = akizukiBuilder(coordinates, a, v);

            return std::move(akizuki);
        }

        case ModelType::Yukikaze: {
            std::unique_ptr<Destroyer> yukikaze = yukikazeBuilder(a, v, coordinates);

            return std::move(yukikaze);
        }
        case ModelType::Fubuki: {
            std::unique_ptr<Destroyer> fubuki = fubukiBuilder(coordinates, a, v);

            return std::move(fubuki);
        }
        case ModelType::Impavido: {
            std::unique_ptr<Destroyer> impavido = impavidoBuilder(a, v, coordinates);

            return std::move(impavido);
        }

        case ModelType::Leone: {
            std::unique_ptr<Destroyer> leone = leoneBuilder(coordinates, a, v);

            return std::move(leone);
        }

        case ModelType::PaoloEmilio: {
            std::unique_ptr<Destroyer> paoloEmilio = paoloEmilioBuilder(a, v, coordinates);

            return std::move(paoloEmilio);
        }
        case ModelType::Campbelltown: {
            std::unique_ptr<Destroyer> campbelltown = campbeltownBuilder(coordinates, a, v);

            return std::move(campbelltown);
        }

        case ModelType::Jutland: {
            std::unique_ptr<Destroyer> jutLand = jutlandBuilder(a, v, coordinates);

            return std::move(jutLand);
        }

        case ModelType::Gallant: {
            std::unique_ptr<Destroyer> gallant = gallandBuilder(coordinates, a, v);

            return std::move(gallant);
        }

        case ModelType::Fletcher: {
            std::unique_ptr<Destroyer> fletcher = fletcherBuilder(a, v, coordinates);

            return std::move(fletcher);
        }

        case ModelType::Mahan: {
            std::unique_ptr<Destroyer> mahan = mahanBuilder(coordinates, a, v);

            return std::move(mahan);


        }
        case ModelType::Sims: {
            std::unique_ptr<Destroyer> sims = simsBuilder(a, v, coordinates);

            return std::move(sims);
        }
    }

}

std::unique_ptr<Destroyer>
ShipFactory::simsBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                         const sf::Vector2i &coordinates) const {
    CannonFactory cf;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 5, coordinates.y + 16)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 5, coordinates.y + 23)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 5, coordinates.y + 81)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 5, coordinates.y + 89)));
    int numAntiAir = 16;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }

    std::unique_ptr<Destroyer> sims(
            new Destroyer(coordinates.x, coordinates.y, 4, 69, 2293, 30,
                          "Usa", 0, 0, 4, numAntiAir, a, v, 106, 16, true,
                          ShipType::Destroyer,
                          ModelType::Sims, 8));
    return sims;
}

std::unique_ptr<Destroyer>
ShipFactory::fletcherBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                             const sf::Vector2i &coordinates) const {
    CannonFactory cf;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 93)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 87)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 73)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 17)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 24)));
    int numAntiAir = 14;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }

    std::unique_ptr<Destroyer> fletcher(
            new Destroyer(coordinates.x, coordinates.y, 4, 68, 2500, 33,
                          "Usa", 0, 0, 5, numAntiAir, a, v, 114, 12, true,
                          ShipType::Destroyer,
                          ModelType::Fletcher, 10));
    return fletcher;
}

std::unique_ptr<Destroyer>
ShipFactory::jutlandBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                            const sf::Vector2i &coordinates) const {
    CannonFactory cf;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 18)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 28)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 95)));

    std::unique_ptr<Destroyer> jutLand(
            new Destroyer(coordinates.x, coordinates.y, 4, 66, 2480, 26,
                          "Uk", 0, 0, 3, 16, a, v, 116, 13, true,
                          ShipType::Destroyer,
                          ModelType::Jutland, 10));
    return jutLand;
}

std::unique_ptr<Destroyer>
ShipFactory::paoloEmilioBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                                const sf::Vector2i &coordinates) const {
    CannonFactory cf;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 28)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 36)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 132)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 140)));
    int numAntiAir = 12;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }
    std::unique_ptr<Destroyer> paoloEmilio(
            new Destroyer(coordinates.x, coordinates.y, 4, 76, 5420, 66,
                          "Italy", 0, 0, 4, numAntiAir, a, v, 172, 15, true,
                          ShipType::Destroyer,
                          ModelType::Impavido, 8));
    return paoloEmilio;
}

std::unique_ptr<Destroyer>
ShipFactory::impavidoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                             const sf::Vector2i &coordinates) const {
    CannonFactory cf;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 17)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 1, coordinates.y + 67)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 1, coordinates.y + 79)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 10, coordinates.y + 67)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 10, coordinates.y + 79)));
    int numAntiAir = 40;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }
    std::unique_ptr<Destroyer> impavido(
            new Destroyer(coordinates.x, coordinates.y, 4, 63, 3941, 36,
                          "Italy", 4, 0, 1, numAntiAir, a, v, 131, 15, true,
                          ShipType::Destroyer,
                          ModelType::Impavido, 6));
    return impavido;
}

std::unique_ptr<Destroyer>
ShipFactory::yukikazeBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                             const sf::Vector2i &coordinates) const {
    CannonFactory cf;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 16)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 51)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 70)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 93)));
    int numAntiAir = 32;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }
    std::unique_ptr<Destroyer> yukikaze(
            new Destroyer(coordinates.x, coordinates.y, 4, 65, 2530, 26,
                          "Japan", 0, 0, 4, numAntiAir, a, v, 119, 12, true,
                          ShipType::Destroyer,
                          ModelType::Yukikaze, 8));
    return yukikaze;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedSubmarine(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::list<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;
    switch (type) {

        case ModelType::I400: {
            std::unique_ptr<Submarine> i400 = i400Builder(a, v, coordinates);
            return std::move(i400);
        }

        case ModelType::typeb1: {
            std::unique_ptr<Submarine> typeb1 = typeb1Builder(a, v, coordinates);
            return std::move(typeb1);
        }

        case ModelType::DaVinci: {
            std::unique_ptr<Submarine> DaVinci = DaVinciBuilder(a, v, coordinates);

            return std::move(DaVinci);
        }

        case ModelType::Papa: {
            std::unique_ptr<Submarine> papa = papaBuilder(coordinates, a, v);
            return std::move(papa);
        }

        case ModelType::Triton: {
            std::unique_ptr<Submarine> triton = tritonBuilder(a, v, coordinates);

            return std::move(triton);
        }

        case ModelType::Trenchant: {
            std::unique_ptr<Submarine> trenchant = trenchantBuilder(coordinates, a, v);
            return std::move(trenchant);
        }

        case ModelType::Gato: {
            std::unique_ptr<Submarine> gato = gatoBuilder(a, v, coordinates);


            return std::move(gato);
        }

        case ModelType::Narwhal: {
            std::unique_ptr<Submarine> narwhal = narwhalBuilder(coordinates, a, v);
            return std::move(narwhal);
        }
    }

}

std::unique_ptr<Submarine>
ShipFactory::narwhalBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    for (int i = 0; i < 4; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));
    std::unique_ptr<Submarine> Narwhal(
            new Submarine(coordinates.x, coordinates.y, 2, 48, 4600, 0, "Usa", 0, 0, 0, 0, a, v, 91, 13, true,
                          ShipType::Submarine, ModelType::Narwhal, 4, false));
    return Narwhal;
}

std::unique_ptr<Submarine>
ShipFactory::trenchantBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                              std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    for (int i = 0; i < 5; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));
    std::unique_ptr<Submarine> Trenchant(
            new Submarine(coordinates.x, coordinates.y, 2, 56, 5800, 0, "Uk", 0, 0, 0, 0, a, v, 85, 14, true,
                          ShipType::Submarine, ModelType::Trenchant, 5, false));
    return Trenchant;
}

std::unique_ptr<Submarine>
ShipFactory::papaBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                         std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    for (int i = 0; i < 10; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::torpedo)));
    std::unique_ptr<Submarine> Papa(
            new Submarine(coordinates.x, coordinates.y, 2, 82, 7100, 0, "Italy", 0, 0, 0, 0, a, v, 106, 19,
                          true,
                          ShipType::Submarine, ModelType::Papa, 10, false));
    return Papa;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedAircraftCarrier(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::list<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;
    switch (type) {

        case ModelType::Tahio: {
            std::unique_ptr<AircraftCarrier> tahio = tahioBuilder(a, v, coordinates);


            return std::move(tahio);
        }



        case ModelType::Hiryu: {
            std::unique_ptr<AircraftCarrier> hiryu = hiryuBuilder(coordinates, a, v);
            return std::move(hiryu);
        }

        case ModelType::GiuseppeGaribaldi: {
            std::unique_ptr<AircraftCarrier> giuseppeGaribaldi = giuseppeGaribaldiBuilder(a, v, coordinates);


            return std::move(giuseppeGaribaldi);
        }

        case ModelType::Cavour: {
            std::unique_ptr<AircraftCarrier> cavour = cavourBuilder(coordinates, a, v);
            return std::move(cavour);
        }

        case ModelType::ArkRoyal: {
            std::unique_ptr<AircraftCarrier> arkRoyal = arkRoyalBuilder(a, v, coordinates);

            return std::move(arkRoyal);
        }


        case ModelType::Indomitable: {
            std::unique_ptr<AircraftCarrier> indomitable = indomitableBuilder(coordinates, a, v);
            return std::move(indomitable);
        }

        case ModelType::Midway: {
            std::unique_ptr<AircraftCarrier> midway = midwayBuilder(a, v, coordinates);
            return std::move(midway);
        }

        case ModelType::FranklinDRoosevelt: {
            std::unique_ptr<AircraftCarrier> franklinDRoosevelt = franklinDelanoRoosveltBuilder(coordinates, a, v);
            return std::move(franklinDRoosevelt);
        }

    }

}

std::unique_ptr<AircraftCarrier>
ShipFactory::franklinDelanoRoosveltBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                           std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 55, coordinates.y + 92)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 56, coordinates.y + 179)));
    WeaponFactory specialFactory;
    int numAntiAir = 8;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<AircraftCarrier> FranklinDRoosevelt(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 45000, 363, "Usa", 0, 0, 2, numAntiAir, a, v, 295,
                                70,
                                true,
                                ShipType::AircraftCarrier, ModelType::FranklinDRoosevelt, 14));
    return FranklinDRoosevelt;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::indomitableBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createLight(coordinates.x + 6, coordinates.y + 38)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 31, coordinates.y + 38)));
    WeaponFactory specialFactory;
    int numAntiAir = 6;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<AircraftCarrier> Indomitable(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 29730, 240, "Uk", 2, 0, 0, numAntiAir, a, v, 230,
                                41,
                                true,
                                ShipType::AircraftCarrier, ModelType::Indomitable, 5));
    return Indomitable;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::cavourBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                           std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createLight(coordinates.x + 16, coordinates.y + 4)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 31, coordinates.y + 23)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 29, coordinates.y + 78)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 26, coordinates.y + 171)));
    WeaponFactory specialFactory;
    int numAntiAir = 3;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<AircraftCarrier> Cavour(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 52, 29900, 241, "Italy", 4, 0, 0, numAntiAir, a, v,
                                244,
                                50,
                                true,
                                ShipType::AircraftCarrier, ModelType::Cavour, 5));
    return Cavour;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::hiryuBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                          std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createLight(coordinates.x + 18, coordinates.y + 3)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 5, coordinates.y + 61)));
    WeaponFactory specialFactory;
    int numAntiAir = 2;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<AircraftCarrier> Hiryu(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 63, 20570, 70, "Japan", 2, 0, 0, numAntiAir, a, v, 222,
                                39,
                                true,
                                ShipType::AircraftCarrier, ModelType::Hiryu, 6));
    return Hiryu;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedCruiser(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::list<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;
    switch (type) {

        case ModelType::Ijn: {
            std::unique_ptr<Cruiser> ijn = ijnBuilder(coordinates, a, v);
            return std::move(ijn);
        }

        case ModelType::IsuzuNagara: {
            std::unique_ptr<Cruiser> isuzuNagara = isuzuNagaraBuilder(coordinates, a, v);
            return std::move(isuzuNagara);
        }

        case ModelType::Takao: {
            std::unique_ptr<Cruiser> takao = takaoBuilder(a, v, coordinates);

            return std::move(takao);
        }

        case ModelType::AlbertoDiGiussano: {
            std::unique_ptr<Cruiser> albertoDiGiussano = albertoDiGiussanoBuilder(a, v, coordinates);

            return std::move(albertoDiGiussano);
        }

        case ModelType::Gorizia: {
            std::unique_ptr<Cruiser> gorizia = goriziaBuilder(coordinates, a, v);
            return std::move(gorizia);
        }


        case ModelType::Trento: {
            std::unique_ptr<Cruiser> trento = trentoBuilder(a, v, coordinates);

            return std::move(trento);
        }


        case ModelType::Belfast: {
            std::unique_ptr<Cruiser> belfast = belfastBuilder(coordinates, a, v);
            return std::move(belfast);
        }

        case ModelType::Danae: {
            std::unique_ptr<Cruiser> danae = danaeBuilder(a, v, coordinates);

            return std::move(danae);
        }


        case ModelType::Tiger59: {
            std::unique_ptr<Cruiser> tiger59 = tiger59Builder(coordinates, a, v);
            return std::move(tiger59);
        }


        case ModelType::Alaska: {
            std::unique_ptr<Cruiser> alaska = alaskaBuilder(a, v, coordinates);

            return std::move(alaska);
        }


        case ModelType::NewOrleans: {
            std::unique_ptr<Cruiser> newOrleans = newOrleansBuilder(coordinates, a, v);
            return std::move(newOrleans);
        }


        case ModelType::StLouis: {
            std::unique_ptr<Cruiser> saintLouis = stLouisBuilder(a, v, coordinates);

            return std::move(saintLouis);
        }


    }

}


std::unique_ptr<Cruiser>
ShipFactory::newOrleansBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                               std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 12;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 8, coordinates.y + 121)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 8, coordinates.y + 50)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 8, coordinates.y + 41)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 73)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 82)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 90)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 17, coordinates.y + 73)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 17, coordinates.y + 82)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 17, coordinates.y + 90)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> NewOrleans(
            new Cruiser(coordinates.x, coordinates.y, 3, 61, 12663, 476, "Usa", 6, 0, 3, antiAir, a, v, 178,
                        25,
                        true,
                        ShipType::Cruiser, ModelType::NewOrleans, 0));
    return NewOrleans;
}

std::unique_ptr<Cruiser>
ShipFactory::tiger59Builder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 7;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 6, coordinates.y + 137)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 6, coordinates.y + 128)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 6, coordinates.y + 32)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 6, coordinates.y + 24)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 1, coordinates.y + 117)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 1, coordinates.y + 92)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 1, coordinates.y + 75)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 13, coordinates.y + 117)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 13, coordinates.y + 92)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 13, coordinates.y + 75)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> Tiger59(
            new Cruiser(coordinates.x, coordinates.y, 3, 58, 12080, 191, "Uk", 6, 0, 4, antiAir, a, v, 169,
                        19,
                        true,
                        ShipType::Cruiser, ModelType::Tiger59, 2));
    return Tiger59;
}

std::unique_ptr<Cruiser>
ShipFactory::belfastBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 12;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 10, coordinates.y + 151)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 10, coordinates.y + 141)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 10, coordinates.y + 34)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 10, coordinates.y + 25)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 4, coordinates.y + 121)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 4, coordinates.y + 107)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 4, coordinates.y + 95)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 18, coordinates.y + 121)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 18, coordinates.y + 107)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 18, coordinates.y + 95)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> Belfast(
            new Cruiser(coordinates.x, coordinates.y, 3, 59, 11550, 228, "Uk", 6, 0, 4, antiAir, a, v, 187,
                        27,
                        true,
                        ShipType::Cruiser, ModelType::Belfast, 1));
    return Belfast;
}

std::unique_ptr<Cruiser>
ShipFactory::goriziaBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 12;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 7, coordinates.y + 153)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 7, coordinates.y + 143)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 7, coordinates.y + 59)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 7, coordinates.y + 49)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 3, coordinates.y + 78)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 15, coordinates.y + 78)));
    a.emplace_back(std::move(cf.createLight(coordinates.x, coordinates.y + 107)));
    a.emplace_back(std::move(cf.createLight(coordinates.x, coordinates.y + 98)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 18, coordinates.y + 107)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 18, coordinates.y + 98)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> Gorizia(
            new Cruiser(coordinates.x, coordinates.y, 3, 59, 14330, 370, "Italy", 6, 0, 4, antiAir, a, v, 183,
                        22,
                        true,
                        ShipType::Cruiser, ModelType::Gorizia, 0));
    return Gorizia;
}

std::unique_ptr<Cruiser>
ShipFactory::isuzuNagaraBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 6;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 132)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 94)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 18)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 142)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 3, coordinates.y + 77)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 6, coordinates.y + 77)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 3, coordinates.y + 30)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 6, coordinates.y + 30)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> IsuzuNagara(
            new Cruiser(coordinates.x, coordinates.y, 3, 67, 5700, 90, "Japan", 5, 0, 3, antiAir, a, v, 159,
                        14,
                        true,
                        ShipType::Cruiser, ModelType::IsuzuNagara, 1));
    return IsuzuNagara;
}

std::unique_ptr<Cruiser>
ShipFactory::ijnBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                        std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 10;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 10, coordinates.y + 31)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 10, coordinates.y + 41)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 10, coordinates.y + 50)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 10, coordinates.y + 64)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 1, coordinates.y + 101)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 1, coordinates.y + 115)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 20, coordinates.y + 102)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 20, coordinates.y + 115)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Cruiser> Ijn(
            new Cruiser(coordinates.x, coordinates.y, 3, 66, 15500, 230, "Japan", 4, 0, 4, antiAir, a, v, 204,
                        26,
                        true,
                        ShipType::Cruiser, ModelType::Ijn, 2));
    return Ijn;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedBattleship(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::list<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;
    switch (type) {

        case ModelType::ISE: {
            std::unique_ptr<Battleship> ise = iseBuilder(coordinates, a, v);
            return std::move(ise);
        }

        case ModelType::Kongo: {
            std::unique_ptr<Battleship> kongo = kongoBuilder(a, v, coordinates);

            return std::move(kongo);
        }

        case ModelType::Musashi: {
            std::unique_ptr<Battleship> musashi = musashiBuilder(a, v, coordinates);

            return std::move(musashi);
        }

        case ModelType::Yamato: {
            std::unique_ptr<Battleship> yamato = yamatoBuilder(coordinates, a, v);
            return std::move(yamato);
        }

        case ModelType::AndreaDoria: {
            std::unique_ptr<Battleship> andreaDoria = andreaDoriaBuilder(coordinates, a, v);
            return std::move(andreaDoria);
        }

        case ModelType::ImperatoreAugusto: {
            std::unique_ptr<Battleship> imperatoreAugusto = imperatoreAugustoBuilder(a, v, coordinates);

            return std::move(imperatoreAugusto);
        }

        case ModelType::MichelangeloBuonarroti: {
            std::unique_ptr<Battleship> michelangeloBuonarroti = michelangeloBuonarrotiBuilder(coordinates, a, v);
            return std::move(michelangeloBuonarroti);
        }

        case ModelType::VittorioVeneto: {
            std::unique_ptr<Battleship> vittorioVeneto = vittorioVenetoBuilder(coordinates, a, v);
            return std::move(vittorioVeneto);
        }


        case ModelType::Dreadnought: {
            std::unique_ptr<Battleship> dreadNought = dreadNoughtBuilder(a, v, coordinates);

            return std::move(dreadNought);
        }


        case ModelType::Hood: {
            std::unique_ptr<Battleship> hood = hoodBuilder(coordinates, a, v);
            return std::move(hood);
        }


        case ModelType::IronDuke: {
            std::unique_ptr<Battleship> ironDuke = ironDukeBuilder(a, v, coordinates);

            return std::move(ironDuke);
        }
        case ModelType::Lion: {
            std::unique_ptr<Battleship> lion = lionBuilder(a, v, coordinates);

            return std::move(lion);
        }

        case ModelType::Arizona: {
            std::unique_ptr<Battleship> arizona = arizonaBuilder(coordinates, a, v);

            return std::move(arizona);
        }

        case ModelType::Montana: {
            std::unique_ptr<Battleship> montana = montanaBuilder(a, v, coordinates);

            return std::move(montana);
        }

        case ModelType::NewYork: {
            std::unique_ptr<Battleship> newYork = newYorkBuilder(coordinates, a, v);

            return std::move(newYork);
        }


        case ModelType::NorthCarolina: {
            std::unique_ptr<Battleship> northCarolina = northCarolinaBuilder(a, v, coordinates);

            return std::move(northCarolina);
        }


    }

}

std::unique_ptr<Battleship>
ShipFactory::vittorioVenetoBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                   std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 10, coordinates.y + 61)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 10, coordinates.y + 83)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 10, coordinates.y + 83)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 10, coordinates.y + 146)));

    a.emplace_back(std::move(factory.createMedium(coordinates.x + 2, coordinates.y + 95)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 2, coordinates.y + 165)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 24, coordinates.y + 95)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 24, coordinates.y + 165)));

    a.emplace_back(std::move(factory.createLight(coordinates.x + 3, coordinates.y + 104)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 3, coordinates.y + 109)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 3, coordinates.y + 115)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 3, coordinates.y + 122)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 3, coordinates.y + 130)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 3, coordinates.y + 136)));

    a.emplace_back(std::move(factory.createLight(coordinates.x + 26, coordinates.y + 104)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 26, coordinates.y + 109)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 26, coordinates.y + 115)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 26, coordinates.y + 122)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 26, coordinates.y + 130)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 26, coordinates.y + 136)));


    WeaponFactory specialFactory;
    int numAntiAir = 32;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<Battleship> VittorioVeneto(
            new Battleship(coordinates.x, coordinates.y, 1, 56, 45963, 862, "Italy", 12, 4, 4, numAntiAir, a, v, 238,
                           33,
                           true,
                           ShipType::Battleship, ModelType::VittorioVeneto, 1));
    return VittorioVeneto;
}

std::unique_ptr<Battleship>
ShipFactory::newYorkBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 6;
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 13, coordinates.y + 32)));
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 13, coordinates.y + 45)));
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 14, coordinates.y + 100)));
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 14, coordinates.y + 125)));
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 14, coordinates.y + 139)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> NewYork(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 28822, 939,
                           "Usa", 0, 5, 0, antiAir, a, v, 175, 35, true,
                           ShipType::Battleship,
                           ModelType::NewYork, 0));
    return NewYork;
}

std::unique_ptr<Battleship>
ShipFactory::arizonaBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 4;
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 13, coordinates.y + 42)));
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 13, coordinates.y + 56)));
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 13, coordinates.y + 126)));
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 13, coordinates.y + 137)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 97)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 2, coordinates.y + 87)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 2, coordinates.y + 78)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 4, coordinates.y + 69)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 23, coordinates.y + 97)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 26, coordinates.y + 87)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 23, coordinates.y + 78)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 21, coordinates.y + 69)));
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
ShipFactory::hoodBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                         std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 20;
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 12, coordinates.y + 213)));
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 13, coordinates.y + 50)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 12, coordinates.y + 196)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 13, coordinates.y + 65)));

    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> Hood(
            new Battleship(coordinates.x, coordinates.y, 1, 54, 49136, 800, "Uk", 0, 2, 2, antiAir, a, v, 262, 34,
                           true,
                           ShipType::Battleship, ModelType::Hood, 0));
    return Hood;
}

std::unique_ptr<Battleship>
ShipFactory::michelangeloBuonarrotiBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                           std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 13, coordinates.y + 64)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 13, coordinates.y + 85)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 13, coordinates.y + 175)));


    a.emplace_back(std::move(factory.createMedium(coordinates.x + 2, coordinates.y + 122)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 2, coordinates.y + 143)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 3, coordinates.y + 98)));

    a.emplace_back(std::move(factory.createMedium(coordinates.x + 28, coordinates.y + 122)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 28, coordinates.y + 143)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 27, coordinates.y + 98)));

    a.emplace_back(std::move(factory.createLight(coordinates.x + 6, coordinates.y + 108)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 6, coordinates.y + 114)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 6, coordinates.y + 134)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 6, coordinates.y + 155)));


    a.emplace_back(std::move(factory.createLight(coordinates.x + 25, coordinates.y + 108)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 25, coordinates.y + 114)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 25, coordinates.y + 134)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 25, coordinates.y + 155)));

    a.emplace_back(std::move(factory.createLight(coordinates.x + 5, coordinates.y + 168)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 5, coordinates.y + 174)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 26, coordinates.y + 168)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 26, coordinates.y + 174)));


    WeaponFactory specialFactory;
    int numAntiAir = 14;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> MichelangeloBuonarroti(
            new Battleship(coordinates.x, coordinates.y, 1, 61, 42533, 837, "Italy", 12, 3, 6, numAntiAir, a, v, 246,
                           35,
                           true,
                           ShipType::Battleship, ModelType::MichelangeloBuonarroti, 1));
    return MichelangeloBuonarroti;
}

std::unique_ptr<Battleship>
ShipFactory::andreaDoriaBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory factory;
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 10, coordinates.y + 48))); //TODO PROSEGUI BATTLESHIP
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 10, coordinates.y + 62)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 10, coordinates.y + 126)));
    a.emplace_back(std::move(factory.createHeavly(coordinates.x + 10, coordinates.y + 140)));

    a.emplace_back(std::move(factory.createMedium(coordinates.x + 4, coordinates.y + 70)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 20, coordinates.y + 70)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 3, coordinates.y + 77)));
    a.emplace_back(std::move(factory.createMedium(coordinates.x + 21, coordinates.y + 77)));

    a.emplace_back(std::move(factory.createLight(coordinates.x + 3, coordinates.y + 85)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 3, coordinates.y + 91)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 3, coordinates.y + 97)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 3, coordinates.y + 103)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 3, coordinates.y + 109)));

    a.emplace_back(std::move(factory.createLight(coordinates.x + 22, coordinates.y + 85)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 22, coordinates.y + 91)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 22, coordinates.y + 97)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 22, coordinates.y + 103)));
    a.emplace_back(std::move(factory.createLight(coordinates.x + 22, coordinates.y + 109)));

    WeaponFactory specialFactory;
    int numAntiAir = 13;
    for (int i = 0; i < numAntiAir; i++)
        a.emplace_back(std::move(specialFactory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> AndreaDoria(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 24729, 622, "Italy", 10, 4, 4, numAntiAir, a, v, 176,
                           29,
                           true,
                           ShipType::Battleship, ModelType::AndreaDoria, 0));
    return AndreaDoria;
}

std::unique_ptr<Battleship>
ShipFactory::yamatoBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                           std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 40;
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 13, coordinates.y + 71)));
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 13, coordinates.y + 93)));
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 14, coordinates.y + 184)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 16, coordinates.y + 176)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 16, coordinates.y + 118)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 13, coordinates.y + 161)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 13, coordinates.y + 150)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 13, coordinates.y + 138)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 157)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 146)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 4, coordinates.y + 130)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 25, coordinates.y + 161)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 25, coordinates.y + 150)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 26, coordinates.y + 138)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 29, coordinates.y + 157)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 29, coordinates.y + 146)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 32, coordinates.y + 130)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));

    std::unique_ptr<Battleship> Yamato(
            new Battleship(coordinates.x, coordinates.y, 1, 50, 71659, 1286, "Japan", 12, 3, 2, antiAir, a, v, 263,
                           41,
                           true,
                           ShipType::Battleship, ModelType::Yamato, 3));
    return Yamato;
}

std::unique_ptr<Battleship>
ShipFactory::iseBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                        std::list<std::unique_ptr<Vehicle>> &v) const {
    WeaponFactory factory;
    CannonFactory cf;
    int antiAir = 19;
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 17, coordinates.y + 37)));
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 17, coordinates.y + 51)));
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 17, coordinates.y + 113)));
    a.emplace_back(std::move(cf.createHeavly(coordinates.x + 17, coordinates.y + 125)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 9, coordinates.y + 102)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 9, coordinates.y + 80)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 12, coordinates.y + 71)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 12, coordinates.y + 62)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 30, coordinates.y + 102)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 32, coordinates.y + 80)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 28, coordinates.y + 71)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 27, coordinates.y + 62)));
    for (int i = 0; i < antiAir; i++)
        a.emplace_back(std::move(factory.createSpecialWeapon(WeaponType::antiAir)));
    std::unique_ptr<Battleship> Ise(
            new Battleship(coordinates.x, coordinates.y, 1, 45, 40444, 705, "Japan", 8, 4, 0, antiAir, a, v, 220, 43,
                           true,
                           ShipType::Battleship, ModelType::ISE, 2));
    return Ise;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedDestroyer(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::list<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::list<std::unique_ptr<Vehicle>> v;

    switch (type) {

        case ModelType::Akizuki: {
            std::unique_ptr<Destroyer> akizuki = akizukiBuilder(coordinates, a, v);

            return std::move(akizuki);
        }


        case ModelType::Fubuki: {
            std::unique_ptr<Destroyer> fubuki = fubukiBuilder(coordinates, a, v);

            return std::move(fubuki);
        }


        case ModelType::Yukikaze: {
            std::unique_ptr<Destroyer> yukikaze = yukikazeBuilder(a, v, coordinates);

            return std::move(yukikaze);
        }


        case ModelType::Impavido: {
            std::unique_ptr<Destroyer> impavido = impavidoBuilder(a, v, coordinates);

            return std::move(impavido);
        }


        case ModelType::Leone: {
            std::unique_ptr<Destroyer> leone = leoneBuilder(coordinates, a, v);

            return std::move(leone);
        }
        case ModelType::PaoloEmilio: {
            std::unique_ptr<Destroyer> paoloEmilio = paoloEmilioBuilder(a, v, coordinates);

            return std::move(paoloEmilio);
        }


        case ModelType::Campbelltown: {
            std::unique_ptr<Destroyer> campbelltown = campbeltownBuilder(coordinates, a, v);

            return std::move(campbelltown);
        }


        case ModelType::Gallant: {
            std::unique_ptr<Destroyer> gallant = gallandBuilder(coordinates, a, v);

            return std::move(gallant);
        }


        case ModelType::Jutland: {
            std::unique_ptr<Destroyer> jutLand = jutlandBuilder(a, v, coordinates);

            return std::move(jutLand);
        }


        case ModelType::Fletcher: {
            std::unique_ptr<Destroyer> fletcher = fletcherBuilder(a, v, coordinates);

            return std::move(fletcher);
        }


        case ModelType::Mahan: {
            std::unique_ptr<Destroyer> mahan = mahanBuilder(coordinates, a, v);

            return std::move(mahan);
        }


        case ModelType::Sims: {
            std::unique_ptr<Destroyer> sims = simsBuilder(a, v, coordinates);

            return std::move(sims);
        }


    }

}

std::unique_ptr<Destroyer>
ShipFactory::mahanBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                          std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory cf;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 11)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 20)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 85)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 76)));
    int numAntiAir = 8;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }

    std::unique_ptr<Destroyer> Mahan(
            new Destroyer(coordinates.x, coordinates.y, 4, 69, 2137, 27,
                          "Usa", 0, 0, 4, numAntiAir, a, v, 104, 13, true,
                          ShipType::Destroyer,
                          ModelType::Mahan, 12));
    return Mahan;
}

std::unique_ptr<Destroyer>
ShipFactory::gallandBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory cf;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 14)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 21)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 75)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 81)));
    int numAntiAir = 8;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }

    std::unique_ptr<Destroyer> Gallant(
            new Destroyer(coordinates.x, coordinates.y, 4, 67, 1913, 22,
                          "Uk", 0, 0, 4, numAntiAir, a, v, 99, 10, true,
                          ShipType::Destroyer,
                          ModelType::Gallant, 8));
    return Gallant;
}

std::unique_ptr<Destroyer>
ShipFactory::campbeltownBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory cf;
    a.emplace_back(std::move(cf.createLight(coordinates.x + 3, coordinates.y + 14)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 1, coordinates.y + 40)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 5, coordinates.y + 40)));
    a.emplace_back(std::move(cf.createLight(coordinates.x + 3, coordinates.y + 81)));
    int numAntiAir = 10;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }

    std::unique_ptr<Destroyer> Campbelltown(
            new Destroyer(coordinates.x, coordinates.y, 4, 66, 1280, 19,
                          "Uk", 4, 0, 0, numAntiAir, a, v, 96, 10, true,
                          ShipType::Destroyer,
                          ModelType::Campbelltown, 6));
    return Campbelltown;
}

std::unique_ptr<Destroyer>
ShipFactory::leoneBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                          std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory cf;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 31)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 72)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 98)));
    int numAntiAir = 20;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }
    std::unique_ptr<Destroyer> Leone(
            new Destroyer(coordinates.x, coordinates.y, 4, 61, 2326, 22,
                          "Italy", 0, 0, 3, numAntiAir, a, v, 113, 13, true,
                          ShipType::Destroyer,
                          ModelType::Leone, 6));
    return Leone;
}

std::unique_ptr<Destroyer>
ShipFactory::fubukiBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                           std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory cf;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 15)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 47)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 67)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 78)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 90)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 4, coordinates.y + 98)));
    int numAntiAir = 20;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }
    std::unique_ptr<Destroyer> Fubuki(
            new Destroyer(coordinates.x, coordinates.y, 4, 70, 2080, 26,
                          "Japan", 0, 0, 6, numAntiAir, a, v, 118, 14, true,
                          ShipType::Destroyer,
                          ModelType::Fubuki, 9));
    return Fubuki;
}

std::unique_ptr<Destroyer>
ShipFactory::akizukiBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                            std::list<std::unique_ptr<Vehicle>> &v) const {
    CannonFactory cf;
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 22)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 29)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 95)));
    a.emplace_back(std::move(cf.createMedium(coordinates.x + 3, coordinates.y + 104)));
    int numAntiAir = 50;
    WeaponFactory wf;
    for (int i = 0; i < numAntiAir; i++) {
        a.emplace_back(std::move(wf.createSpecialWeapon(WeaponType::antiAir)));
    }
    std::unique_ptr<Destroyer> Akizuki(
            new Destroyer(coordinates.x, coordinates.y, 4, 61, 3759, 33,
                          "Japan", 0, 0, 5, numAntiAir, a, v, 134, 12, true,
                          ShipType::Destroyer,
                          ModelType::Akizuki, 4));
    return Akizuki;
}

sf::Vector2i ShipFactory::randomizeEnemyPositions(GameWorld &map) {


    Dice percentage(3, offset.x + 1);
    int xMap = map.getMapWidth();
    int yMap = map.getMapHeight();

    if (offset.x >= xMap - (xMap * 0.03)) {

        offset.x = ((percentage.roll(1) + 1) / 100) * xMap;
        offset.y = offset.y + (yMap * 0.24);

    } else {

        offset.x = offset.x + ((percentage.roll(1) + 1) * xMap / 100);
        std::cerr << ((percentage.roll(1) + 1) * xMap / 100) << std::endl;

    }

    return offset;

}

sf::Vector2i ShipFactory::randomizeAlliedPositions(GameWorld &map) {


    Dice percentage(3, offset.x + 1);
    int xMap = map.getMapWidth();
    int yMap = map.getMapHeight();
    if (offsetAllied.y == 0) {
        offsetAllied.y = yMap - yMap * 0.24;
    }
    if (offsetAllied.x >= xMap - (xMap * 0.03)) {

        offsetAllied.x = ((percentage.roll(1) + 1) * xMap / 100);
        offsetAllied.y -= yMap * 0.24;

    } else {

        offsetAllied.x = offsetAllied.x + ((percentage.roll(1) + 1) * xMap / 100);

    }

    return offsetAllied;

}



