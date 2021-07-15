//
// Created by pala on 7/2/21.
//

#include "ShipFactory.h"
#include "GameWorld.h"
#include "Submarine.h"
#include "AircraftCarrier.h"


std::unique_ptr<WarShip> ShipFactory::createSubmarine(ModelType type, GameWorld &map) {
    std::vector<std::unique_ptr<Arsenal>> a;
    std::vector<std::unique_ptr<Vehicle>> v;
    sf::Vector2i coordinates = randomizeEnemyPositions(map);
    switch (type) {

        case ModelType::I400: {
            std::unique_ptr<Submarine> i400(
                    new Submarine(coordinates.x, coordinates.y, 2, 35, 6670, 0, "Japan", 0, 0, 0, a, v, 122, 12, true,
                                  ShipType::Submarine, ModelType::I400, 8, false));


            return std::move(i400);
        }
        case ModelType::typeb1: {
            std::unique_ptr<Submarine> typeb1(
                    new Submarine(coordinates.x, coordinates.y, 2, 44, 3713, 0, "Japan", 0, 0, 0, a, v, 111, 10, true,
                                  ShipType::Submarine, ModelType::typeb1, 6,
                                  false));
            return std::move(typeb1);
        }

        case ModelType::DaVinci: {
            std::unique_ptr<Submarine> DaVinci(
                    new Submarine(coordinates.x, coordinates.y, 2, 15, 1489, 0, "Italy", 0, 0, 0, a, v, 77, 9, true,
                                  ShipType::Submarine, ModelType::DaVinci, 8, false));

            return std::move(DaVinci);
        }
        case ModelType::Papa: {
            std::unique_ptr<Submarine> Papa(
                    new Submarine(coordinates.x, coordinates.y, 2, 82, 7100, 0, "Italy", 0, 0, 0, a, v, 107, 12, true,
                                  ShipType::Submarine, ModelType::Papa, 10, false));

            return std::move(Papa);
        }
        case ModelType::Triton: {
            std::unique_ptr<Submarine> Triton(
                    new Submarine(coordinates.x, coordinates.y, 2, 28, 1576, 0, "Uk", 0, 0, 0, a, v, 84, 8, true,
                                  ShipType::Submarine, ModelType::Triton, 6, false));

            return std::move(Triton);
        }
        case ModelType::Trenchant: {
            std::unique_ptr<Submarine> Trenchant(
                    new Submarine(coordinates.x, coordinates.y, 2, 56, 5800, 0, "Uk", 0, 0, 0, a, v, 85, 10, true,
                                  ShipType::Submarine, ModelType::Trenchant, 5, false));
            return std::move(Trenchant);
        }
        case ModelType::Gato: {
            std::unique_ptr<Submarine> Gato(
                    new Submarine(coordinates.x, coordinates.y, 2, 37, 2460, 0, "Usa", 0, 0, 0, a, v, 95, 8, true,
                                  ShipType::Submarine, ModelType::Gato, 6, false));


            return std::move(Gato);
        }
        case ModelType::Narwhal: {
            std::unique_ptr<Submarine> Narwhal(
                    new Submarine(coordinates.x, coordinates.y, 2, 48, 4600, 0, "Usa", 0, 0, 0, a, v, 91, 10, true,
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

        case ModelType::Hiryu: {


            return std::move();
        }


        case ModelType::Tahio: {

            return std::move();
        }

        case ModelType::GiuseppeGaribaldi: {


            return std::move();
        }

        case ModelType::Cavour: {
            std::unique_ptr<AircraftCarrier> cavour(new AircraftCarrier(coordinates.x, coordinates.y, 1, 52, 29900, 241,
                                                                        "Italy", 0, 0, 0, a, v, 244, 29, true,
                                                                        ShipType::AircraftCarrier, ModelType::Cavour,
                                                                        5));

            return std::move(cavour);
        }
        case ModelType::ArkRoyal: {
            std::unique_ptr<AircraftCarrier> arkRoyal(
                    new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 28160, 20,
                                        "Uk", 0, 0, 0, a, v, 240, 29, true, ShipType::AircraftCarrier,
                                        ModelType::ArkRoyal, 7));

            return std::move(arkRoyal);
        }

        case ModelType::Indomitable: {

            std::unique_ptr<AircraftCarrier> indom(new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 29730, 240,
                                                                       "Uk", 0, 0, 0, a, v, 230, 29, true,
                                                                       ShipType::AircraftCarrier,
                                                                       ModelType::Indomitable, 5));

            return std::move(indom);
        }

        case ModelType::Midway: {
            std::unique_ptr<AircraftCarrier> mid(new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 640000, 520,
                                                                     "Usa", 0, 0, 0, a, v, 305, 74, true,
                                                                     ShipType::AircraftCarrier, ModelType::Midway, 14));
            return std::move(mid);
        }

        case ModelType::FranklinDRoosevelt: {
            std::unique_ptr<AircraftCarrier> frank(new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 45000, 363,
                                                                       "Usa", 0, 0, 0, a, v, 295, 34, true,
                                                                       ShipType::AircraftCarrier,
                                                                       ModelType::FranklinDRoosevelt, 14));
            return std::move(frank);
        }


    }

}

std::unique_ptr<WarShip> ShipFactory::createCruiser(ModelType type, GameWorld &map) {
    switch (type) {

        case ModelType::Takao:


            break;

        case ModelType::IsuzuNagara:

            break;

        case ModelType::Ijn:

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

            break;//TODO add exception
    }
    return std::unique_ptr<WarShip>();
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
                    new Submarine(coordinates.x, coordinates.y, 2, 35, 6670, 0, "Japan", 0, 0, 0, a, v, 122, 12, true,
                                  ShipType::Submarine, ModelType::I400, 8,
                                  false));
        }
            break;

        case ModelType::typeb1: {
            std::unique_ptr<Submarine> typeb1(
                    new Submarine(coordinates.x, coordinates.y, 2, 44, 3713, 0, "Japan", 0, 0, 0, a, v, 111, 10, true,
                                  ShipType::Submarine, ModelType::typeb1, 6,
                                  false));
        }
            break;

        case ModelType::DaVinci: {
            std::unique_ptr<Submarine> DaVinci(
                    new Submarine(coordinates.x, coordinates.y, 2, 15, 1489, 0, "Italy", 0, 0, 0, a, v, 77, 9, true,
                                  ShipType::Submarine, ModelType::DaVinci, 8, false));
        }
            break;

        case ModelType::Papa: {
            std::unique_ptr<Submarine> Papa(
                    new Submarine(coordinates.x, coordinates.y, 2, 82, 7100, 0, "Italy", 0, 0, 0, a, v, 107, 12, true,
                                  ShipType::Submarine, ModelType::Papa, 10, false));
        }
            break;

        case ModelType::Triton: {
            std::unique_ptr<Submarine> Triton(
                    new Submarine(coordinates.x, coordinates.y, 2, 28, 1576, 0, "Uk", 0, 0, 0, a, v, 84, 8, true,
                                  ShipType::Submarine, ModelType::Triton, 6, false));
        }
            break;

        case ModelType::Trenchant: {
            std::unique_ptr<Submarine> Trenchant(
                    new Submarine(coordinates.x, coordinates.y, 2, 56, 5800, 0, "Uk", 0, 0, 0, a, v, 85, 10, true,
                                  ShipType::Submarine, ModelType::Trenchant, 5, false));
        }
            break;

        case ModelType::Gato: {
            std::unique_ptr<Submarine> Gato(
                    new Submarine(coordinates.x, coordinates.y, 2, 37, 2460, 0, "Usa", 0, 0, 0, a, v, 95, 8, true,
                                  ShipType::Submarine, ModelType::Gato, 6, false));
        }
            break;

        case ModelType::Narwhal: {
            std::unique_ptr<Submarine> Narwhal(
                    new Submarine(coordinates.x, coordinates.y, 2, 48, 4600, 0, "Usa", 0, 0, 0, a, v, 91, 10, true,
                                  ShipType::Submarine, ModelType::Narwhal, 4, false));
        }
            break;
    }
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedAircraftCarrier(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::vector<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::vector<std::unique_ptr<Vehicle>> v;
    switch (type) {

        case ModelType::Tahio:
            std::unique_ptr<AircraftCarrier> Tahio(
                    new AircraftCarrier(coordinates.x, coordinates.y, 1, 48, 4600, 0, "Japan", 0, 0, 0, a, v, 91, 10,
                                        true,
                                        ShipType::AircraftCarrier, ModelType::Tahio));

            break;

        case ModelType::Hiryu:

            break;

        case ModelType::GiuseppeGaribaldi:

            break;

        case ModelType::Cavour:

            break;

        case ModelType::ArkRoyal:

            break;

        case ModelType::Indomitable:

            break;

        case ModelType::Midway:

            break;
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

