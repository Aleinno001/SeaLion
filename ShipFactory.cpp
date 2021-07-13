//
// Created by pala on 7/2/21.
//

#include "ShipFactory.h"
#include "GameWorld.h"
#include "Submarine.h"


std::unique_ptr<WarShip> ShipFactory::createSubmarine(ModelType type, GameWorld &map) {

    switch (type) {

        case ModelType::I400:
            sf::Vector2i coord = randomizeEnemyPositions(map);
            std::unique_ptr<WarShip> sub(new Submarine(coord.x, coord.y,))//TODO Concludere
            return;
            break;

        case ModelType::typeb1:

            break;

        case ModelType::DaVinci:

            break;

        case ModelType::Papa:

            break;

        case ModelType::Triton:

            break;

        case ModelType::Trenchant:

            break;

        case ModelType::Gato:

            break;

        case ModelType::Narwhal:

            break;      //TODO add exception
    }

}

std::unique_ptr<WarShip> ShipFactory::createAircraftCarrier(ModelType type, GameWorld &map) {
    switch (type) {

        case ModelType::Hiryu:
            break;

        case ModelType::Tahio:

            break;

        case ModelType::GiuseppeGaribaldi:

            break;

        case ModelType::ArkRoyal:

            break;

        case ModelType::Indomitable:

            break;

        case ModelType::Midway:

            break;    //TODO add exception


    }
    return std::unique_ptr<WarShip>();
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
    switch (type) {

        case ModelType::I400:
            //std::unique_ptr<Submarine> i400(new Submarine()); //TODO da concludere
            break;

        case ModelType::typeb1:

            break;

        case ModelType::DaVinci:

            break;

        case ModelType::Papa:

            break;

        case ModelType::Triton:

            break;

        case ModelType::Trenchant:

            break;

        case ModelType::Gato:

            break;

        case ModelType::Narwhal:

            break;
    }
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedAircraftCarrier(ModelType type, GameWorld &map) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedCruiser(ModelType type, GameWorld &map) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedBattleship(ModelType type, GameWorld &map) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createAlliedDestroyer(ModelType type, GameWorld &map) {
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

