//
// Created by pala on 7/2/21.
//

#include "ShipFactory.h"
#include "GameWorld.h"
#include "Submarine.h"
#include "AircraftCarrier.h"
#include "Cruiser.h"


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
    switch (type) {

        case ModelType::Yamato:
            //std::unique_ptr<Submarine> i400(new Submarine()); //TODO da concludere


            break;

        case ModelType::Kongo:

            break;

        case ModelType::ISE:

            break;

        case ModelType::Musashi:

            break;

        case ModelType::AndreaDoria:

            break;

        case ModelType::ImperatoreAugusto:

            break;

        case ModelType::VittorioVeneto:

            break;

        case ModelType::MichelangeloBuonarroti:

            break;
        case ModelType::Dreadnought:

            break;
        case ModelType::IronDuke:

            break;
        case ModelType::Lion:

            break;
        case ModelType::Hood:

            break;
        case ModelType::Arizona:

            break;
        case ModelType::Montana:

            break;
        case ModelType::NewYork:

            break;
        case ModelType::NorthCarolina:

            break;
            //TODO add exception
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
            std::unique_ptr<Submarine> i400(
                    new Submarine(coordinates.x, coordinates.y, 2, 35, 6670, 0, "Japan", 0, 0, 0, 0, a, v, 122, 12,
                                  true,
                                  ShipType::Submarine, ModelType::I400, 8,
                                  false));
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
    switch (type) {

        case ModelType::Ijn:
            //std::unique_ptr<Submarine> i400(new Submarine()); //TODO da concludere
            break;

        case ModelType::IsuzuNagara:

            break;

        case ModelType::Takao:

            break;

        case ModelType::AlbertoDiGiussano:

            break;

        case ModelType::Gorizia:

            break;

        case ModelType::Trento:

            break;

        case ModelType::Belfast:

            break;

        case ModelType::Danae:

            break;

        case ModelType::Tiger59:

            break;

        case ModelType::Alaska:

            break;

        case ModelType::NewOrleans:

            break;

        case ModelType::StLouis:

            break;

        default:                    //TODO aggiungere eccezione
            break;;
    }
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedBattleship(ModelType type, GameWorld &map) {

    switch (type) {

        case ModelType::ISE:

            break;

        case ModelType::Kongo:

            break;

        case ModelType::Musashi:

            break;

        case ModelType::Yamato:

            break;

        case ModelType::AndreaDoria:

            break;

        case ModelType::ImperatoreAugusto:

            break;

        case ModelType::MichelangeloBuonarroti:

            break;

        case ModelType::VittorioVeneto:

            break;

        case ModelType::Dreadnought:

            break;

        case ModelType::Hood:

            break;

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

