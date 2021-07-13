//
// Created by pala on 7/2/21.
//

#include "ShipFactory.h"



std::unique_ptr<WarShip> ShipFactory::createSubmarine(ModelType type, GameWorld &map) {

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

}

std::unique_ptr<WarShip> ShipFactory::createAircraftCarrier(ModelType type, GameWorld &map) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createCruiser(ModelType type, GameWorld &map) {
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<WarShip> ShipFactory::createBattleship(ModelType type, GameWorld &map) {
    return std::unique_ptr<WarShip>(); //TODO implementare tutti i costruttori
}

std::unique_ptr<WarShip> ShipFactory::createDestroyer(ModelType type, GameWorld &map) {
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
    switch (type) {

        case ModelType::Tahio:
            //std::unique_ptr<Submarine> i400(new Submarine()); //TODO da concludere
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
            //std::unique_ptr<Submarine> i400(new Submarine()); //TODO da concludere
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
