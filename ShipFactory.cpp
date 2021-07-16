//
// Created by pala on 7/2/21.
//

#include "ShipFactory.h"
#include "GameWorld.h"
#include "Submarine.h"
#include "AircraftCarrier.h"
#include "Cruiser.h"
#include "Battleship.h"


std::unique_ptr<WarShip> ShipFactory::createSubmarine(ModelType type, GameWorld &map) {
    std::vector<std::unique_ptr<Arsenal>> a;
    std::vector<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    switch (type) {

        case ModelType::I400: {
            std::unique_ptr<Submarine> i400(
                    new Submarine(coordinates.x, coordinates.y, 2, 35, 6670, 0, "Japan", 0, 0, 0, 0, a, v, 122, 12,
                                  true,
                                  ShipType::Submarine, ModelType::I400, 8, false));


            return std::move(i400);
        }
        case ModelType::typeb1: {
            std::unique_ptr<Submarine> typeb1(
                    new Submarine(coordinates.x, coordinates.y, 2, 44, 3713, 0, "Japan", 0, 0, 0, 0, a, v, 111, 10,
                                  true,
                                  ShipType::Submarine, ModelType::typeb1, 6,
                                  false));
            return std::move(typeb1);
        }

        case ModelType::DaVinci: {
            std::unique_ptr<Submarine> DaVinci(
                    new Submarine(coordinates.x, coordinates.y, 2, 15, 1489, 0, "Italy", 0, 0, 0, 0, a, v, 77, 9, true,
                                  ShipType::Submarine, ModelType::DaVinci, 8, false));

            return std::move(DaVinci);
        }
        case ModelType::Papa: {
            std::unique_ptr<Submarine> Papa(
                    new Submarine(coordinates.x, coordinates.y, 2, 82, 7100, 0, "Italy", 0, 0, 0, 0, a, v, 107, 12,
                                  true,
                                  ShipType::Submarine, ModelType::Papa, 10, false));

            return std::move(Papa);
        }
        case ModelType::Triton: {
            std::unique_ptr<Submarine> Triton(
                    new Submarine(coordinates.x, coordinates.y, 2, 28, 1576, 0, "Uk", 0, 0, 0, 0, a, v, 84, 8, true,
                                  ShipType::Submarine, ModelType::Triton, 6, false));

            return std::move(Triton);
        }
        case ModelType::Trenchant: {
            std::unique_ptr<Submarine> Trenchant(
                    new Submarine(coordinates.x, coordinates.y, 2, 56, 5800, 0, "Uk", 0, 0, 0, 0, a, v, 85, 10, true,
                                  ShipType::Submarine, ModelType::Trenchant, 5, false));
            return std::move(Trenchant);
        }
        case ModelType::Gato: {
            std::unique_ptr<Submarine> Gato(
                    new Submarine(coordinates.x, coordinates.y, 2, 37, 2460, 0, "Usa", 0, 0, 0, 0, a, v, 95, 8, true,
                                  ShipType::Submarine, ModelType::Gato, 6, false));


            return std::move(Gato);
        }
        case ModelType::Narwhal: {
            std::unique_ptr<Submarine> Narwhal(
                    new Submarine(coordinates.x, coordinates.y, 2, 48, 4600, 0, "Usa", 0, 0, 0, 0, a, v, 91, 10, true,
                                  ShipType::Submarine, ModelType::Narwhal, 4, false));

            return std::move(Narwhal);
        }
    }

}

std::unique_ptr<WarShip> ShipFactory::createAircraftCarrier(ModelType type, GameWorld &map) {
    std::vector<std::unique_ptr<Arsenal>> a;
    std::vector<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);


    switch (type) {

        case ModelType::Tahio: {
            std::unique_ptr<AircraftCarrier> Tahio(
                    new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 37866, 304, "Japan", 2, 0, 0, 2, a, v, 260,
                                        27,
                                        true,
                                        ShipType::AircraftCarrier, ModelType::Tahio, 7));


            return std::move(Tahio);
        }


        case ModelType::Hiryu: {
            std::unique_ptr<AircraftCarrier> Hiryu(
                    new AircraftCarrier(coordinates.x, coordinates.y, 1, 63, 20570, 70, "Japan", 2, 0, 0, 2, a, v, 222,
                                        22,
                                        true,
                                        ShipType::AircraftCarrier, ModelType::Hiryu, 6));

            return std::move(Hiryu);
        }

        case ModelType::GiuseppeGaribaldi: {
            std::unique_ptr<AircraftCarrier> GiuseppeGaribaldi(
                    new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 14150, 114, "Italy", 3, 0, 0, 0, a, v, 180,
                                        33,
                                        true,
                                        ShipType::AircraftCarrier, ModelType::GiuseppeGaribaldi, 6));


            return std::move(GiuseppeGaribaldi);
        }

        case ModelType::Cavour: {
            std::unique_ptr<AircraftCarrier> cavour(new AircraftCarrier(coordinates.x, coordinates.y, 1, 52, 29900, 241,
                                                                        "Italy", 4, 0, 0, 3, a, v, 244, 29, true,
                                                                        ShipType::AircraftCarrier, ModelType::Cavour,
                                                                        5));

            return std::move(cavour);
        }
        case ModelType::ArkRoyal: {
            std::unique_ptr<AircraftCarrier> arkRoyal(
                    new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 28160, 20,
                                        "Uk", 2, 0, 0, 4, a, v, 240, 29, true, ShipType::AircraftCarrier,
                                        ModelType::ArkRoyal, 7));

            return std::move(arkRoyal);
        }

        case ModelType::Indomitable: {

            std::unique_ptr<AircraftCarrier> indom(new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 29730, 240,
                                                                       "Uk", 2, 0, 0, 6, a, v, 230, 29, true,
                                                                       ShipType::AircraftCarrier,
                                                                       ModelType::Indomitable, 5));

            return std::move(indom);
        }

        case ModelType::Midway: {
            std::unique_ptr<AircraftCarrier> mid(new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 640000, 520,
                                                                     "Usa", 2, 0, 0, 15, a, v, 305, 74, true,
                                                                     ShipType::AircraftCarrier, ModelType::Midway, 14));
            return std::move(mid);
        }

        case ModelType::FranklinDRoosevelt: {
            std::unique_ptr<AircraftCarrier> frank(new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 45000, 363,
                                                                       "Usa", 0, 0, 2, 8, a, v, 295, 34, true,
                                                                       ShipType::AircraftCarrier,
                                                                       ModelType::FranklinDRoosevelt, 14));
            return std::move(frank);
        }


    }

}

std::unique_ptr<WarShip> ShipFactory::createCruiser(ModelType type, GameWorld &map) {
    std::vector<std::unique_ptr<Arsenal>> a;
    std::vector<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);

    switch (type) {

        case ModelType::Takao: {
            std::unique_ptr<Cruiser> takao(new Cruiser(coordinates.x, coordinates.y, 3, 66, 15500, 237,
                                                       "Japan", 4, 0, 5, 16, a, v, 193, 19, true,
                                                       ShipType::Cruiser,
                                                       ModelType::Takao, 2));

            return std::move(takao);
        }

        case ModelType::IsuzuNagara: {
            std::unique_ptr<Cruiser> isuzuNagara(new Cruiser(coordinates.x, coordinates.y, 3, 67, 5700, 90,
                                                             "Japan", 5, 0, 3, 6, a, v, 159, 14, true,
                                                             ShipType::Cruiser,
                                                             ModelType::IsuzuNagara, 1));

            return std::move(isuzuNagara);
        }


        case ModelType::Ijn: {
            std::unique_ptr<Cruiser> ijn(new Cruiser(coordinates.x, coordinates.y, 3, 66, 15500, 230,
                                                     "Japan", 4, 0, 4, 10, a, v, 204, 20, true,
                                                     ShipType::Cruiser,
                                                     ModelType::Ijn, 2));

            return std::move(ijn);
        }


        case ModelType::AlbertoDiGiussano: {
            std::unique_ptr<Cruiser> albertoDiGiussano(new Cruiser(coordinates.x, coordinates.y, 3, 69, 6950, 84,
                                                                   "Italy", 3, 0, 4, 2, a, v, 169, 16, true,
                                                                   ShipType::Cruiser,
                                                                   ModelType::AlbertoDiGiussano, 1));

            return std::move(albertoDiGiussano);
        }

        case ModelType::Gorizia: {
            std::unique_ptr<Cruiser> gorizia(new Cruiser(coordinates.x, coordinates.y, 3, 59, 14330, 370,
                                                         "Italy", 6, 0, 4, 2, a, v, 183, 21, true,
                                                         ShipType::Cruiser,
                                                         ModelType::Gorizia, 0));

            return std::move(gorizia);
        }

        case ModelType::Trento: {
            std::unique_ptr<Cruiser> trento(new Cruiser(coordinates.x, coordinates.y, 3, 66, 13548, 120,
                                                        "Italy", 6, 0, 4, 2, a, v, 197, 21, true,
                                                        ShipType::Cruiser,
                                                        ModelType::Trento, 2));

            return std::move(trento);
        }
        case ModelType::Belfast: {
            std::unique_ptr<Cruiser> belfast(new Cruiser(coordinates.x, coordinates.y, 3, 59, 11550, 228,
                                                         "Uk", 6, 0, 4, 2, a, v, 187, 19, true,
                                                         ShipType::Cruiser,
                                                         ModelType::Belfast, 1));

            return std::move(belfast);
        }

        case ModelType::Danae: {
            std::unique_ptr<Cruiser> danae(new Cruiser(coordinates.x, coordinates.y, 3, 54, 5925, 190,
                                                       "Uk", 6, 0, 1, 1, a, v, 136, 14, true,
                                                       ShipType::Cruiser,
                                                       ModelType::Danae, 0));

            return std::move(danae);
        }

        case ModelType::Tiger59: {
            std::unique_ptr<Cruiser> tiger59(new Cruiser(coordinates.x, coordinates.y, 3, 58, 12080, 191,
                                                         "Uk", 2, 0, 2, 1, a, v, 169, 20, true,
                                                         ShipType::Cruiser,
                                                         ModelType::Tiger59, 2));

            return std::move(tiger59);
        }
        case ModelType::Alaska: {
            std::unique_ptr<Cruiser> alaska(new Cruiser(coordinates.x, coordinates.y, 3, 61, 34803, 918,
                                                        "Usa", 6, 1, 2, 9, a, v, 246, 28, true,
                                                        ShipType::Cruiser,
                                                        ModelType::Alaska, 4));

            return std::move(alaska);
        }
        case ModelType::NewOrleans: {
            std::unique_ptr<Cruiser> newOrleans(new Cruiser(coordinates.x, coordinates.y, 3, 61, 12663, 476,
                                                            "Usa", 6, 0, 3, 1, a, v, 179, 19, true,
                                                            ShipType::Cruiser,
                                                            ModelType::NewOrleans, 0));

            return std::move(newOrleans);
        }
        case ModelType::StLouis: {
            std::unique_ptr<Cruiser> saintLouis(new Cruiser(coordinates.x, coordinates.y, 3, 41, 11013, 280,
                                                            "Usa", 5, 0, 3, 2, a, v, 130, 20, true,
                                                            ShipType::Cruiser,
                                                            ModelType::StLouis, 0));

            return std::move(saintLouis);
        }
    }

}

std::unique_ptr<WarShip> ShipFactory::createBattleship(ModelType type, GameWorld &map) {
    std::vector<std::unique_ptr<Arsenal>> a;
    std::vector<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    switch (type) {

        case ModelType::Yamato: {
            std::unique_ptr<Battleship> yamato(new Battleship(coordinates.x, coordinates.y, 1, 50, 71659, 1286,
                                                              "Japan", 12, 3, 2, 40, a, v, 263, 39, true,
                                                              ShipType::Battleship,
                                                              ModelType::Yamato, 3));

            return std::move(yamato);
        }

        case ModelType::Kongo: {
            std::unique_ptr<Battleship> kongo(new Battleship(coordinates.x, coordinates.y, 1, 56, 37187, 592,
                                                             "Japan", 6, 4, 0, 18, a, v, 222, 31, true,
                                                             ShipType::Battleship,
                                                             ModelType::Kongo, 0));

            return std::move(kongo);
        }

        case ModelType::ISE: {
            std::unique_ptr<Battleship> ise(new Battleship(coordinates.x, coordinates.y, 1, 45, 40444, 705,
                                                           "Japan", 8, 4, 0, 19, a, v, 220, 32, true,
                                                           ShipType::Battleship,
                                                           ModelType::ISE, 2));

            return std::move(ise);
        }

        case ModelType::Musashi: {
            std::unique_ptr<Battleship> musashi(new Battleship(coordinates.x, coordinates.y, 1, 51, 72809, 1540,
                                                               "Japan", 6, 3, 2, 30, a, v, 244, 37, true,
                                                               ShipType::Battleship,
                                                               ModelType::Musashi, 2));

            return std::move(musashi);
        }

        case ModelType::AndreaDoria: {
            std::unique_ptr<Battleship> andreaDoria(new Battleship(coordinates.x, coordinates.y, 1, 39, 24729, 622,
                                                                   "Italy", 10, 2, 2, 13, a, v, 176, 28, true,
                                                                   ShipType::Battleship,
                                                                   ModelType::AndreaDoria, 0));

            return std::move(andreaDoria);
        }

        case ModelType::ImperatoreAugusto: {
            std::unique_ptr<Battleship> imperatoreAugusto(
                    new Battleship(coordinates.x, coordinates.y, 1, 57, 65232, 1126,
                                   "Italy", 16, 4, 10, 12, a, v, 274, 40, true,
                                   ShipType::Battleship,
                                   ModelType::ImperatoreAugusto, 0));

            return std::move(imperatoreAugusto);
        }
        case ModelType::VittorioVeneto: {
            std::unique_ptr<Battleship> vittorioVeneto(
                    new Battleship(coordinates.x, coordinates.y, 1, 56, 45963, 862,
                                   "Italy", 14, 3, 4, 32, a, v, 238, 33, true,
                                   ShipType::Battleship,
                                   ModelType::VittorioVeneto, 1));

            return std::move(vittorioVeneto);
        }

        case ModelType::MichelangeloBuonarroti: {
            std::unique_ptr<Battleship> michelangeloBuonarroti(
                    new Battleship(coordinates.x, coordinates.y, 1, 61, 42533, 837,
                                   "Italy", 12, 3, 6, 14, a, v, 246, 29, true,
                                   ShipType::Battleship,
                                   ModelType::MichelangeloBuonarroti, 1));

            return std::move(michelangeloBuonarroti);
        }
        case ModelType::Dreadnought: {
            std::unique_ptr<Battleship> dreadNought(
                    new Battleship(coordinates.x, coordinates.y, 1, 39, 21060, 837,
                                   "Uk", 0, 0, 5, 20, a, v, 161, 25, true,
                                   ShipType::Battleship,
                                   ModelType::Dreadnought, 0));

            return std::move(dreadNought);
        }
        case ModelType::IronDuke: {
            std::unique_ptr<Battleship> ironDuke(
                    new Battleship(coordinates.x, coordinates.y, 1, 39, 29500, 826,
                                   "Uk", 0, 5, 0, 15, a, v, 190, 27, true,
                                   ShipType::Battleship,
                                   ModelType::IronDuke, 0));

            return std::move(ironDuke);
        }
        case ModelType::Lion: {
            std::unique_ptr<Battleship> lion(
                    new Battleship(coordinates.x, coordinates.y, 1, 52, 49670, 944,
                                   "Uk", 0, 4, 0, 10, a, v, 242, 33, true,
                                   ShipType::Battleship,
                                   ModelType::Lion, 0));

            return std::move(lion);
        }
        case ModelType::Hood: {
            std::unique_ptr<Battleship> hood(
                    new Battleship(coordinates.x, coordinates.y, 1, 54, 49136, 800,
                                   "Uk", 0, 2, 2, 20, a, v, 262, 32, true,
                                   ShipType::Battleship,
                                   ModelType::Hood, 0));

            return std::move(hood);
        }
        case ModelType::Arizona: {
            std::unique_ptr<Battleship> arizona(
                    new Battleship(coordinates.x, coordinates.y, 1, 39, 32429, 1536,
                                   "Usa", 8, 4, 0, 4, a, v, 185, 30, true,
                                   ShipType::Battleship,
                                   ModelType::Arizona, 0));

            return std::move(arizona);
        }
        case ModelType::Montana: {
            std::unique_ptr<Battleship> montana(
                    new Battleship(coordinates.x, coordinates.y, 1, 52, 72104, 1810,
                                   "Usa", 0, 4, 10, 80, a, v, 281, 37, true,
                                   ShipType::Battleship,
                                   ModelType::Montana, 2));

            return std::move(montana);
        }
        case ModelType::NewYork: {
            std::unique_ptr<Battleship> newYork(
                    new Battleship(coordinates.x, coordinates.y, 1, 39, 28822, 939,
                                   "Usa", 0, 5, 0, 6, a, v, 175, 29, true,
                                   ShipType::Battleship,
                                   ModelType::NewYork, 0));

            return std::move(newYork);
        }
        case ModelType::NorthCarolina: {
            std::unique_ptr<Battleship> northCarolina(
                    new Battleship(coordinates.x, coordinates.y, 1, 52, 45500, 1224,
                                   "Usa", 6, 2, 0, 34, a, v, 222, 33, true,
                                   ShipType::Battleship,
                                   ModelType::NorthCarolina, 3));

            return std::move(northCarolina);
        }
    }
    return std::unique_ptr<WarShip>(); //TODO implementare tutti i costruttori
}

std::unique_ptr<WarShip> ShipFactory::createDestroyer(ModelType type, GameWorld &map) {
    switch (type) {

        case ModelType::Akizuki:


            break;

        case ModelType::Yukikaze:

            break;

        case ModelType::Fubuki:

            break;

        case ModelType::Impavido:

            break;

        case ModelType::Leone:

            break;

        case ModelType::PaoloEmilio:

            break;

        case ModelType::Campbelltown:

            break;

        case ModelType::Jutland:

            break;
        case ModelType::Gallant:

            break;
        case ModelType::Fletcher:

            break;
        case ModelType::Mahan:

            break;
        case ModelType::Sims:

            break;//TODO add exception
    }
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedSubmarine(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::vector<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::vector<std::unique_ptr<Vehicle>> v;
    switch (type) {

        case ModelType::I400: {
            std::unique_ptr<Submarine> I400(
                    new Submarine(coordinates.x, coordinates.y, 2, 35, 6670, 0, "Japan", 0, 0, 0, 0, a, v, 122, 12,
                                  true,
                                  ShipType::Submarine, ModelType::I400, 8,
                                  false));
            return std::move(I400);
        }

        case ModelType::typeb1: {
            std::unique_ptr<Submarine> Typeb1(
                    new Submarine(coordinates.x, coordinates.y, 2, 44, 3713, 0, "Japan", 0, 0, 0, 0, a, v, 111, 10,
                                  true,
                                  ShipType::Submarine, ModelType::typeb1, 6,
                                  false));
            return std::move(Typeb1);
        }

        case ModelType::DaVinci: {
            std::unique_ptr<Submarine> DaVinci(
                    new Submarine(coordinates.x, coordinates.y, 2, 15, 1489, 0, "Italy", 0, 0, 0, 0, a, v, 77, 9, true,
                                  ShipType::Submarine, ModelType::DaVinci, 8, false));
            return std::move(DaVinci);
        }

        case ModelType::Papa: {
            std::unique_ptr<Submarine> Papa(
                    new Submarine(coordinates.x, coordinates.y, 2, 82, 7100, 0, "Italy", 0, 0, 0, 0, a, v, 107, 12,
                                  true,
                                  ShipType::Submarine, ModelType::Papa, 10, false));
            return std::move(Papa);
        }

        case ModelType::Triton: {
            std::unique_ptr<Submarine> Triton(
                    new Submarine(coordinates.x, coordinates.y, 2, 28, 1576, 0, "Uk", 0, 0, 0, 0, a, v, 84, 8, true,
                                  ShipType::Submarine, ModelType::Triton, 6, false));
            return std::move(Triton);
        }

        case ModelType::Trenchant: {
            std::unique_ptr<Submarine> Trenchant(
                    new Submarine(coordinates.x, coordinates.y, 2, 56, 5800, 0, "Uk", 0, 0, 0, 0, a, v, 85, 10, true,
                                  ShipType::Submarine, ModelType::Trenchant, 5, false));
            return std::move(Trenchant);
        }

        case ModelType::Gato: {
            std::unique_ptr<Submarine> Gato(
                    new Submarine(coordinates.x, coordinates.y, 2, 37, 2460, 0, "Usa", 0, 0, 0, 0, a, v, 95, 8, true,
                                  ShipType::Submarine, ModelType::Gato, 6, false));
            return std::move(Gato);
        }

        case ModelType::Narwhal: {
            std::unique_ptr<Submarine> Narwhal(
                    new Submarine(coordinates.x, coordinates.y, 2, 48, 4600, 0, "Usa", 0, 0, 0, 0, a, v, 91, 10, true,
                                  ShipType::Submarine, ModelType::Narwhal, 4, false));
            return std::move(Narwhal);
        }
    }
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedAircraftCarrier(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::vector<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::vector<std::unique_ptr<Vehicle>> v;
    switch (type) {

        case ModelType::Tahio: {
            std::unique_ptr<AircraftCarrier> Tahio(
                    new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 37866, 304, "Japan", 2, 0, 0, 2, a, v, 260,
                                        27,
                                        true,
                                        ShipType::AircraftCarrier, ModelType::Tahio, 7));
            return std::move(Tahio);
        }



        case ModelType::Hiryu: {
            std::unique_ptr<AircraftCarrier> Hiryu(
                    new AircraftCarrier(coordinates.x, coordinates.y, 1, 63, 20570, 70, "Japan", 2, 0, 0, 2, a, v, 222,
                                        22,
                                        true,
                                        ShipType::AircraftCarrier, ModelType::Hiryu, 6));
            return std::move(Hiryu);
        }

        case ModelType::GiuseppeGaribaldi: {
            std::unique_ptr<AircraftCarrier> GiuseppeGaribaldi(
                    new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 14150, 114, "Italy", 3, 0, 0, 0, a, v, 180,
                                        33,
                                        true,
                                        ShipType::AircraftCarrier, ModelType::GiuseppeGaribaldi, 6));
            return std::move(GiuseppeGaribaldi);
        }

        case ModelType::Cavour: {
            std::unique_ptr<AircraftCarrier> Cavour(
                    new AircraftCarrier(coordinates.x, coordinates.y, 1, 52, 29900, 241, "Italy", 4, 0, 0, 3, a, v, 244,
                                        29,
                                        true,
                                        ShipType::AircraftCarrier, ModelType::Cavour, 5));
            return std::move(Cavour);
        }

        case ModelType::ArkRoyal: {
            std::unique_ptr<AircraftCarrier> ArkRoyal(
                    new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 28160, 20, "Uk", 2, 0, 0, 4, a, v, 240, 29,
                                        true,
                                        ShipType::AircraftCarrier, ModelType::ArkRoyal, 7));
            return std::move(ArkRoyal);
        }


        case ModelType::Indomitable: {
            std::unique_ptr<AircraftCarrier> Indomitable(
                    new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 29730, 240, "Uk", 2, 0, 0, 6, a, v, 230,
                                        29,
                                        true,
                                        ShipType::AircraftCarrier, ModelType::Indomitable, 5));
            return std::move(Indomitable);
        }

        case ModelType::Midway: {
            std::unique_ptr<AircraftCarrier> Midway(
                    new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 64000, 520, "Usa", 2, 0, 0, 15, a, v, 305,
                                        73,
                                        true,
                                        ShipType::AircraftCarrier, ModelType::Midway, 14));
            return std::move(Midway);
        }

        case ModelType::FranklinDRoosevelt: {
            std::unique_ptr<AircraftCarrier> FranklinDRoosevelt(
                    new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 45000, 363, "Usa", 0, 0, 2, 8, a, v, 295,
                                        34,
                                        true,
                                        ShipType::AircraftCarrier, ModelType::FranklinDRoosevelt, 14));
            return std::move(FranklinDRoosevelt);
        }

        default:                        //TODO aggiungere eccezione
            break;
    }
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedCruiser(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::vector<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::vector<std::unique_ptr<Vehicle>> v;
    switch (type) {

        case ModelType::Ijn: {
            std::unique_ptr<Cruiser> Ijn(
                    new Cruiser(coordinates.x, coordinates.y, 3, 66, 15500, 230, "Japan", 4, 0, 4, 10, a, v, 204,
                                20,
                                true,
                                ShipType::Cruiser, ModelType::Ijn, 2));
            return std::move(Ijn);
        }

        case ModelType::IsuzuNagara: {
            std::unique_ptr<Cruiser> IsuzuNagara(
                    new Cruiser(coordinates.x, coordinates.y, 3, 67, 5700, 90, "Japan", 5, 0, 3, 6, a, v, 159,
                                14,
                                true,
                                ShipType::Cruiser, ModelType::IsuzuNagara, 1));
            return std::move(IsuzuNagara);
        }

        case ModelType::Takao: {
            std::unique_ptr<Cruiser> Takao(
                    new Cruiser(coordinates.x, coordinates.y, 3, 66, 15500, 237, "Japan", 4, 0, 5, 16, a, v, 193,
                                19,
                                true,
                                ShipType::Cruiser, ModelType::Takao, 2));
            return std::move(Takao);
        }

        case ModelType::AlbertoDiGiussano: {
            std::unique_ptr<Cruiser> AlbertoDiGiussano(
                    new Cruiser(coordinates.x, coordinates.y, 3, 69, 6950, 84, "Italy", 3, 0, 4, 2, a, v, 169,
                                16,
                                true,
                                ShipType::Cruiser, ModelType::AlbertoDiGiussano, 1));
            return std::move(AlbertoDiGiussano);
        }

        case ModelType::Gorizia: {
            std::unique_ptr<Cruiser> Gorizia(
                    new Cruiser(coordinates.x, coordinates.y, 3, 59, 14330, 370, "Italy", 6, 0, 4, 2, a, v, 183,
                                21,
                                true,
                                ShipType::Cruiser, ModelType::Gorizia, 0));
            return std::move(Gorizia);
        }


        case ModelType::Trento: {
            std::unique_ptr<Cruiser> Trento(
                    new Cruiser(coordinates.x, coordinates.y, 3, 66, 13548, 120, "Italy", 6, 0, 4, 2, a, v, 197,
                                21,
                                true,
                                ShipType::Cruiser, ModelType::Trento, 2));
            return std::move(Trento);
        }


        case ModelType::Belfast: {
            std::unique_ptr<Cruiser> Belfast(
                    new Cruiser(coordinates.x, coordinates.y, 3, 59, 11550, 228, "Uk", 6, 0, 4, 2, a, v, 187,
                                19,
                                true,
                                ShipType::Cruiser, ModelType::Belfast, 1));
            return std::move(Belfast);
        }

        case ModelType::Danae: {
            std::unique_ptr<Cruiser> Danae(
                    new Cruiser(coordinates.x, coordinates.y, 3, 54, 5925, 190, "Uk", 6, 0, 1, 1, a, v, 136,
                                14,
                                true,
                                ShipType::Cruiser, ModelType::Danae, 0));
            return std::move(Danae);
        }


        case ModelType::Tiger59: {
            std::unique_ptr<Cruiser> Tiger59(
                    new Cruiser(coordinates.x, coordinates.y, 3, 58, 12080, 191, "Uk", 2, 0, 2, 1, a, v, 169,
                                20,
                                true,
                                ShipType::Cruiser, ModelType::Tiger59, 2));
            return std::move(Tiger59);
        }


        case ModelType::Alaska: {
            std::unique_ptr<Cruiser> Alaska(
                    new Cruiser(coordinates.x, coordinates.y, 3, 61, 34803, 918, "Usa", 6, 1, 2, 9, a, v, 246,
                                28,
                                true,
                                ShipType::Cruiser, ModelType::Alaska, 4));
            return std::move(Alaska);
        }


        case ModelType::NewOrleans: {
            std::unique_ptr<Cruiser> NewOrleans(
                    new Cruiser(coordinates.x, coordinates.y, 3, 61, 12663, 476, "Usa", 6, 0, 3, 2, a, v, 179,
                                19,
                                true,
                                ShipType::Cruiser, ModelType::NewOrleans, 0));
            return std::move(NewOrleans);
        }


        case ModelType::StLouis: {
            std::unique_ptr<Cruiser> StLouis(
                    new Cruiser(coordinates.x, coordinates.y, 3, 41, 11013, 280, "Usa", 5, 0, 3, 2, a, v, 130,
                                20,
                                true,
                                ShipType::Cruiser, ModelType::StLouis, 0));
            return std::move(StLouis);
        }

        default:                    //TODO aggiungere eccezione
            break;;
    }
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedBattleship(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::vector<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::vector<std::unique_ptr<Vehicle>> v;
    switch (type) {

        case ModelType::ISE: {
            std::unique_ptr<Battleship> Ise(
                    new Battleship(coordinates.x, coordinates.y, 1, 45, 40444, 705, "Japan", 8, 4, 0, 19, a, v, 220, 32,
                                   true,
                                   ShipType::Battleship, ModelType::ISE, 2));
            return std::move(Ise);
        }

        case ModelType::Kongo: {
            std::unique_ptr<Battleship> Kongo(
                    new Battleship(coordinates.x, coordinates.y, 1, 56, 37187, 592, "Japan", 6, 4, 0, 18, a, v, 222, 31,
                                   true,
                                   ShipType::Battleship, ModelType::Kongo, 0));
            return std::move(Kongo);
        }

        case ModelType::Musashi: {
            std::unique_ptr<Battleship> Musashi(
                    new Battleship(coordinates.x, coordinates.y, 1, 51, 72809, 1540, "Japan", 6, 3, 2, 30, a, v, 244,
                                   37,
                                   true,
                                   ShipType::Battleship, ModelType::Musashi, 2));
            return std::move(Musashi);
        }

        case ModelType::Yamato: {
            std::unique_ptr<Battleship> Yamato(
                    new Battleship(coordinates.x, coordinates.y, 1, 50, 71659, 1286, "Japan", 12, 3, 2, 40, a, v, 263,
                                   39,
                                   true,
                                   ShipType::Battleship, ModelType::Yamato, 3));
            return std::move(Yamato);
        }

        case ModelType::AndreaDoria: {
            std::unique_ptr<Battleship> AndreaDoria(
                    new Battleship(coordinates.x, coordinates.y, 1, 39, 24729, 622, "Italy", 10, 2, 2, 13, a, v, 176,
                                   28,
                                   true,
                                   ShipType::Battleship, ModelType::AndreaDoria, 0));
            return std::move(AndreaDoria);
        }

        case ModelType::ImperatoreAugusto: {
            std::unique_ptr<Battleship> ImperatoreAugusto(
                    new Battleship(coordinates.x, coordinates.y, 1, 57, 65232, 1126, "Italy", 16, 4, 10, 12, a, v, 274,
                                   40,
                                   true,
                                   ShipType::Battleship, ModelType::ImperatoreAugusto, 0));
            return std::move(ImperatoreAugusto);
        }

        case ModelType::MichelangeloBuonarroti: {
            std::unique_ptr<Battleship> MichelangeloBuonarroti(
                    new Battleship(coordinates.x, coordinates.y, 1, 61, 42533, 837, "Italy", 12, 3, 6, 14, a, v, 246,
                                   29,
                                   true,
                                   ShipType::Battleship, ModelType::MichelangeloBuonarroti, 1));
            return std::move(MichelangeloBuonarroti);
        }

        case ModelType::VittorioVeneto: {
            std::unique_ptr<Battleship> VittorioVeneto(
                    new Battleship(coordinates.x, coordinates.y, 1, 56, 45963, 862, "Italy", 14, 3, 4, 32, a, v, 238,
                                   33,
                                   true,
                                   ShipType::Battleship, ModelType::VittorioVeneto, 1));
            return std::move(VittorioVeneto);
        }


        case ModelType::Dreadnought: {
            std::unique_ptr<Battleship> Dreadnought(
                    new Battleship(coordinates.x, coordinates.y, 1, 39, 21060, 837, "Uk", 0, 0, 5, 20, a, v, 161, 25,
                                   true,
                                   ShipType::Battleship, ModelType::Dreadnought, 0));
            return std::move(Dreadnought);
        }


        case ModelType::Hood: {
            std::unique_ptr<Battleship> Hood(
                    new Battleship(coordinates.x, coordinates.y, 1, 54, 49136, 800, "Uk", 0, 2, 2, 20, a, v, 262, 32,
                                   true,
                                   ShipType::Battleship, ModelType::Hood, 0));
            return std::move(Hood);
        }


        case ModelType::IronDuke:

            break;

        case ModelType::Lion:

            break;

        case ModelType::Arizona:

            break;

        case ModelType::Montana:

            break;

        case ModelType::NewYork:

            break;

        case ModelType::NorthCarolina:

            break;

        default:                        //TODO aggiungere eccezione
            break;
    }
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedDestroyer(ModelType type, GameWorld &map) {
    switch (type) {

        case ModelType::Akizuki:
            //std::unique_ptr<Submarine> i400(new Submarine()); //TODO da concludere
            break;

        case ModelType::Fubuki:

            break;

        case ModelType::Yukikaze:

            break;

        case ModelType::Impavido:

            break;

        case ModelType::Leone:

            break;

        case ModelType::PaoloEmilio:

            break;

        case ModelType::Campbelltown:

            break;

        case ModelType::Gallant:

            break;

        case ModelType::Jutland:

            break;

        case ModelType::Fletcher:

            break;

        case ModelType::Mahan:

            break;

        case ModelType::Sims:

            break;

        default:                        //TODO aggiungere eccezione
            break;
    }
    return std::unique_ptr<WarShip>();
}

sf::Vector2i ShipFactory::randomizeEnemyPositions(GameWorld &map) {


    Dice percentage(3);
    int xMap = map.getMapWidth();
    int yMap = map.getMapHeight();

    if (offset.x >= xMap - (xMap * 0.03)) {

        offset.x = ((percentage.roll(1) + 1) / 100) * xMap;
        offset.y = offset.y + (yMap * 0.24);

    } else {

        offset.x = offset.x + ((percentage.roll(1) + 1) / 100) * xMap;

    }

    return offset;

}

sf::Vector2i ShipFactory::randomizeAlliedPositions(GameWorld &map) {


    Dice percentage(3);
    int xMap = map.getMapWidth();
    int yMap = map.getMapHeight();
    if (offsetAllied.y == 0) {
        offsetAllied.y = yMap - yMap * 0.24;
    }
    if (offsetAllied.x >= xMap - (xMap * 0.03)) {

        offsetAllied.x = ((percentage.roll(1) + 1) / 100) * xMap;
        offsetAllied.y -= yMap * 0.24;

    } else {

        offsetAllied.x = offsetAllied.x + ((percentage.roll(1) + 1) / 100) * xMap;

    }

    return offsetAllied;

}

