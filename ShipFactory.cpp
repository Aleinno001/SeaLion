//
// Created by pala on 7/2/21.
//

#include "ShipFactory.h"
#include "GameWorld.h"
#include "Submarine.h"
#include "AircraftCarrier.h"
#include "Cruiser.h"
#include "Battleship.h"
#include "Destroyer.h"


std::unique_ptr<WarShip> ShipFactory::createSubmarine(ModelType type, GameWorld &map) {
    std::vector<std::unique_ptr<Arsenal>> a;
    std::vector<std::unique_ptr<Vehicle>> v;
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
ShipFactory::gatoBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                         const sf::Vector2i &coordinates) const {
    std::unique_ptr<Submarine> Gato(
            new Submarine(coordinates.x, coordinates.y, 2, 37, 2460, 0, "Usa", 0, 0, 0, 0, a, v, 95, 8, true,
                          ShipType::Submarine, ModelType::Gato, 6, false));
    return Gato;
}

std::unique_ptr<Submarine>
ShipFactory::tritonBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                           const sf::Vector2i &coordinates) const {
    std::unique_ptr<Submarine> Triton(
            new Submarine(coordinates.x, coordinates.y, 2, 28, 1576, 0, "Uk", 0, 0, 0, 0, a, v, 84, 8, true,
                          ShipType::Submarine, ModelType::Triton, 6, false));
    return Triton;
}

std::unique_ptr<Submarine>
ShipFactory::DaVinciBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                            const sf::Vector2i &coordinates) const {
    std::unique_ptr<Submarine> DaVinci(
            new Submarine(coordinates.x, coordinates.y, 2, 15, 1489, 0, "Italy", 0, 0, 0, 0, a, v, 77, 9, true,
                          ShipType::Submarine, ModelType::DaVinci, 8, false));
    return DaVinci;
}

std::unique_ptr<Submarine>
ShipFactory::typeb1Builder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                           const sf::Vector2i &coordinates) const {
    std::unique_ptr<Submarine> typeb1(
            new Submarine(coordinates.x, coordinates.y, 2, 44, 3713, 0, "Japan", 0, 0, 0, 0, a, v, 111, 10,
                          true,
                          ShipType::Submarine, ModelType::typeb1, 6,
                          false));
    return typeb1;
}

std::unique_ptr<Submarine>
ShipFactory::i400Builder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                         const sf::Vector2i &coordinates) const {
    std::unique_ptr<Submarine> i400(
            new Submarine(coordinates.x, coordinates.y, 2, 35, 6670, 0, "Japan", 0, 0, 0, 0, a, v, 122, 12,
                          true,
                          ShipType::Submarine, ModelType::I400, 8, false));
    return i400;
}

std::unique_ptr<WarShip> ShipFactory::createAircraftCarrier(ModelType type, GameWorld &map) {
    std::vector<std::unique_ptr<Arsenal>> a;
    std::vector<std::unique_ptr<Vehicle>> v;
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
            std::unique_ptr<AircraftCarrier> frank(new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 45000, 363,
                                                                       "Usa", 0, 0, 2, 8, a, v, 295, 34, true,
                                                                       ShipType::AircraftCarrier,
                                                                       ModelType::FranklinDRoosevelt, 14));
            return std::move(frank);
        }


    }

}

std::unique_ptr<AircraftCarrier>
ShipFactory::midwayBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                           const sf::Vector2i &coordinates) const {
    std::unique_ptr<AircraftCarrier> mid(new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 640000, 520,
                                                             "Usa", 2, 0, 0, 15, a, v, 305, 74, true,
                                                             ShipType::AircraftCarrier, ModelType::Midway, 14));
    return mid;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::arkRoyalBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                             const sf::Vector2i &coordinates) const {
    std::unique_ptr<AircraftCarrier> arkRoyal(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 28160, 20,
                                "Uk", 2, 0, 0, 4, a, v, 240, 29, true, ShipType::AircraftCarrier,
                                ModelType::ArkRoyal, 7));
    return arkRoyal;
}

std::unique_ptr<AircraftCarrier> ShipFactory::giuseppeGaribaldiBuilder(std::vector<std::unique_ptr<Arsenal>> &a,
                                                                       std::vector<std::unique_ptr<Vehicle>> &v,
                                                                       const sf::Vector2i &coordinates) const {
    std::unique_ptr<AircraftCarrier> GiuseppeGaribaldi(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 14150, 114, "Italy", 3, 0, 0, 0, a, v, 180,
                                33,
                                true,
                                ShipType::AircraftCarrier, ModelType::GiuseppeGaribaldi, 6));
    return GiuseppeGaribaldi;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::tahioBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                          const sf::Vector2i &coordinates) const {
    std::unique_ptr<AircraftCarrier> Tahio(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 37866, 304, "Japan", 2, 0, 0, 2, a, v, 260,
                                27,
                                true,
                                ShipType::AircraftCarrier, ModelType::Tahio, 7));
    return Tahio;
}

std::unique_ptr<WarShip> ShipFactory::createCruiser(ModelType type, GameWorld &map) {
    std::vector<std::unique_ptr<Arsenal>> a;
    std::vector<std::unique_ptr<Vehicle>> v;
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
            std::unique_ptr<AircraftCarrier> midway = midwayBuilder(a, v, coordinates);
            return std::move(midway);
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
ShipFactory::stLouisBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                            const sf::Vector2i &coordinates) const {
    std::unique_ptr<Cruiser> saintLouis(new Cruiser(coordinates.x, coordinates.y, 3, 41, 11013, 280,
                                                    "Usa", 5, 0, 3, 2, a, v, 130, 20, true,
                                                    ShipType::Cruiser,
                                                    ModelType::StLouis, 0));
    return saintLouis;
}

std::unique_ptr<Cruiser>
ShipFactory::alaskaBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                           const sf::Vector2i &coordinates) const {
    std::unique_ptr<Cruiser> alaska(new Cruiser(coordinates.x, coordinates.y, 3, 61, 34803, 918,
                                                "Usa", 6, 1, 2, 9, a, v, 246, 28, true,
                                                ShipType::Cruiser,
                                                ModelType::Alaska, 4));
    return alaska;
}

std::unique_ptr<Cruiser>
ShipFactory::danaeBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                          const sf::Vector2i &coordinates) const {
    std::unique_ptr<Cruiser> danae(new Cruiser(coordinates.x, coordinates.y, 3, 54, 5925, 190,
                                               "Uk", 6, 0, 1, 1, a, v, 136, 14, true,
                                               ShipType::Cruiser,
                                               ModelType::Danae, 0));
    return danae;
}

std::unique_ptr<Cruiser>
ShipFactory::trentoBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                           const sf::Vector2i &coordinates) const {
    std::unique_ptr<Cruiser> trento(new Cruiser(coordinates.x, coordinates.y, 3, 66, 13548, 120,
                                                "Italy", 6, 0, 4, 2, a, v, 197, 21, true,
                                                ShipType::Cruiser,
                                                ModelType::Trento, 2));
    return trento;
}

std::unique_ptr<Cruiser> ShipFactory::albertoDiGiussanoBuilder(std::vector<std::unique_ptr<Arsenal>> &a,
                                                               std::vector<std::unique_ptr<Vehicle>> &v,
                                                               const sf::Vector2i &coordinates) const {
    std::unique_ptr<Cruiser> albertoDiGiussano(new Cruiser(coordinates.x, coordinates.y, 3, 69, 6950, 84,
                                                           "Italy", 3, 0, 4, 2, a, v, 169, 16, true,
                                                           ShipType::Cruiser,
                                                           ModelType::AlbertoDiGiussano, 1));
    return albertoDiGiussano;
}

std::unique_ptr<Cruiser>
ShipFactory::takaoBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                          const sf::Vector2i &coordinates) const {
    std::unique_ptr<Cruiser> takao(new Cruiser(coordinates.x, coordinates.y, 3, 66, 15500, 237,
                                               "Japan", 4, 0, 5, 16, a, v, 193, 19, true,
                                               ShipType::Cruiser,
                                               ModelType::Takao, 2));
    return takao;
}

std::unique_ptr<WarShip> ShipFactory::createBattleship(ModelType type, GameWorld &map) {
    std::vector<std::unique_ptr<Arsenal>> a;
    std::vector<std::unique_ptr<Vehicle>> v;
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
            std::unique_ptr<Battleship> vittorioVeneto(
                    new Battleship(coordinates.x, coordinates.y, 1, 56, 45963, 862,
                                   "Italy", 14, 3, 4, 32, a, v, 238, 33, true,
                                   ShipType::Battleship,
                                   ModelType::VittorioVeneto, 1));

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
            std::unique_ptr<Battleship> ironDuke(
                    new Battleship(coordinates.x, coordinates.y, 1, 39, 29500, 826,
                                   "Uk", 0, 5, 0, 15, a, v, 190, 27, true,
                                   ShipType::Battleship,
                                   ModelType::IronDuke, 0));

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
ShipFactory::northCarolinaBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                                  const sf::Vector2i &coordinates) const {
    std::unique_ptr<Battleship> northCarolina(
            new Battleship(coordinates.x, coordinates.y, 1, 52, 45500, 1224,
                           "Usa", 6, 2, 0, 34, a, v, 222, 33, true,
                           ShipType::Battleship,
                           ModelType::NorthCarolina, 3));
    return northCarolina;
}

std::unique_ptr<Battleship>
ShipFactory::montanaBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                            const sf::Vector2i &coordinates) const {
    std::unique_ptr<Battleship> montana(
            new Battleship(coordinates.x, coordinates.y, 1, 52, 72104, 1810,
                           "Usa", 0, 4, 10, 80, a, v, 281, 37, true,
                           ShipType::Battleship,
                           ModelType::Montana, 2));
    return montana;
}

std::unique_ptr<Battleship>
ShipFactory::lionBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                         const sf::Vector2i &coordinates) const {
    std::unique_ptr<Battleship> lion(
            new Battleship(coordinates.x, coordinates.y, 1, 52, 49670, 944,
                           "Uk", 0, 4, 0, 10, a, v, 242, 33, true,
                           ShipType::Battleship,
                           ModelType::Lion, 0));
    return lion;
}

std::unique_ptr<Battleship>
ShipFactory::dreadNoughtBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                                const sf::Vector2i &coordinates) const {
    std::unique_ptr<Battleship> dreadNought(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 21060, 837,
                           "Uk", 0, 0, 5, 20, a, v, 161, 25, true,
                           ShipType::Battleship,
                           ModelType::Dreadnought, 0));
    return dreadNought;
}

std::unique_ptr<Battleship> ShipFactory::imperatoreAugustoBuilder(std::vector<std::unique_ptr<Arsenal>> &a,
                                                                  std::vector<std::unique_ptr<Vehicle>> &v,
                                                                  const sf::Vector2i &coordinates) const {
    std::unique_ptr<Battleship> imperatoreAugusto(
            new Battleship(coordinates.x, coordinates.y, 1, 57, 65232, 1126,
                           "Italy", 16, 4, 10, 12, a, v, 274, 40, true,
                           ShipType::Battleship,
                           ModelType::ImperatoreAugusto, 0));
    return imperatoreAugusto;
}

std::unique_ptr<Battleship>
ShipFactory::kongoBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                          const sf::Vector2i &coordinates) const {
    std::unique_ptr<Battleship> kongo(new Battleship(coordinates.x, coordinates.y, 1, 56, 37187, 592,
                                                     "Japan", 6, 4, 0, 18, a, v, 222, 31, true,
                                                     ShipType::Battleship,
                                                     ModelType::Kongo, 0));
    return kongo;
}

std::unique_ptr<Battleship>
ShipFactory::musashiBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                            const sf::Vector2i &coordinates) const {
    std::unique_ptr<Battleship> musashi(new Battleship(coordinates.x, coordinates.y, 1, 51, 72809, 1540,
                                                       "Japan", 6, 3, 2, 30, a, v, 244, 37, true,
                                                       ShipType::Battleship,
                                                       ModelType::Musashi, 2));
    return musashi;
}

std::unique_ptr<WarShip> ShipFactory::createDestroyer(ModelType type, GameWorld &map) {
    std::vector<std::unique_ptr<Arsenal>> a;
    std::vector<std::unique_ptr<Vehicle>> v;
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
            std::unique_ptr<Destroyer> campBelltown(
                    new Destroyer(coordinates.x, coordinates.y, 4, 66, 1280, 19,
                                  "Uk", 4, 0, 0, 10, a, v, 96, 9, true,
                                  ShipType::Destroyer,
                                  ModelType::Campbelltown, 6));

            return std::move(campBelltown);
        }

        case ModelType::Jutland: {
            std::unique_ptr<Destroyer> jutLand(
                    new Destroyer(coordinates.x, coordinates.y, 4, 66, 2480, 26,
                                  "Uk", 0, 0, 3, 16, a, v, 116, 12, true,
                                  ShipType::Destroyer,
                                  ModelType::Jutland, 10));

            return std::move(jutLand);
        }

        case ModelType::Gallant: {
            std::unique_ptr<Destroyer> gallant(
                    new Destroyer(coordinates.x, coordinates.y, 4, 67, 1913, 22,
                                  "Uk", 0, 0, 4, 8, a, v, 99, 10, true,
                                  ShipType::Destroyer,
                                  ModelType::Gallant, 8));

            return std::move(gallant);
        }

        case ModelType::Fletcher: {
            std::unique_ptr<Destroyer> fletcher(
                    new Destroyer(coordinates.x, coordinates.y, 4, 68, 2500, 33,
                                  "Usa", 0, 0, 5, 14, a, v, 115, 12, true,
                                  ShipType::Destroyer,
                                  ModelType::Fletcher, 10));

            return std::move(fletcher);
        }

        case ModelType::Mahan: {
            std::unique_ptr<Destroyer> mahan(
                    new Destroyer(coordinates.x, coordinates.y, 4, 69, 2137, 27,
                                  "Usa", 0, 0, 4, 8, a, v, 104, 11, true,
                                  ShipType::Destroyer,
                                  ModelType::Mahan, 12));

            return std::move(mahan);
        }
        case ModelType::Sims: {
            std::unique_ptr<Destroyer> sims(
                    new Destroyer(coordinates.x, coordinates.y, 4, 69, 2293, 30,
                                  "Usa", 0, 0, 4, 16, a, v, 106, 11, true,
                                  ShipType::Destroyer,
                                  ModelType::Sims, 8));

            return std::move(sims);
        }
    }

}

std::unique_ptr<Destroyer>
ShipFactory::paoloEmilioBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                                const sf::Vector2i &coordinates) const {
    std::unique_ptr<Destroyer> paoloEmilio(
            new Destroyer(coordinates.x, coordinates.y, 4, 76, 5420, 66,
                          "Italy", 0, 0, 4, 12, a, v, 142, 14, true,
                          ShipType::Destroyer,
                          ModelType::Impavido, 8));
    return paoloEmilio;
}

std::unique_ptr<Destroyer>
ShipFactory::impavidoBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                             const sf::Vector2i &coordinates) const {
    std::unique_ptr<Destroyer> impavido(
            new Destroyer(coordinates.x, coordinates.y, 4, 63, 3941, 36,
                          "Italy", 4, 0, 1, 40, a, v, 131, 14, true,
                          ShipType::Destroyer,
                          ModelType::Impavido, 6));
    return impavido;
}

std::unique_ptr<Destroyer>
ShipFactory::yukikazeBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                             const sf::Vector2i &coordinates) const {
    std::unique_ptr<Destroyer> yukikaze(
            new Destroyer(coordinates.x, coordinates.y, 4, 65, 2530, 26,
                          "Japan", 0, 0, 4, 32, a, v, 119, 11, true,
                          ShipType::Destroyer,
                          ModelType::Yukikaze, 8));
    return yukikaze;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedSubmarine(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::vector<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::vector<std::unique_ptr<Vehicle>> v;
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
ShipFactory::narwhalBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                            std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Submarine> Narwhal(
            new Submarine(coordinates.x, coordinates.y, 2, 48, 4600, 0, "Usa", 0, 0, 0, 0, a, v, 91, 10, true,
                          ShipType::Submarine, ModelType::Narwhal, 4, false));
    return Narwhal;
}

std::unique_ptr<Submarine>
ShipFactory::trenchantBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                              std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Submarine> Trenchant(
            new Submarine(coordinates.x, coordinates.y, 2, 56, 5800, 0, "Uk", 0, 0, 0, 0, a, v, 85, 10, true,
                          ShipType::Submarine, ModelType::Trenchant, 5, false));
    return Trenchant;
}

std::unique_ptr<Submarine>
ShipFactory::papaBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                         std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Submarine> Papa(
            new Submarine(coordinates.x, coordinates.y, 2, 82, 7100, 0, "Italy", 0, 0, 0, 0, a, v, 107, 12,
                          true,
                          ShipType::Submarine, ModelType::Papa, 10, false));
    return Papa;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedAircraftCarrier(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::vector<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::vector<std::unique_ptr<Vehicle>> v;
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
ShipFactory::franklinDelanoRoosveltBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                           std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<AircraftCarrier> FranklinDRoosevelt(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 61, 45000, 363, "Usa", 0, 0, 2, 8, a, v, 295,
                                34,
                                true,
                                ShipType::AircraftCarrier, ModelType::FranklinDRoosevelt, 14));
    return FranklinDRoosevelt;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::indomitableBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<AircraftCarrier> Indomitable(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 29730, 240, "Uk", 2, 0, 0, 6, a, v, 230,
                                29,
                                true,
                                ShipType::AircraftCarrier, ModelType::Indomitable, 5));
    return Indomitable;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::cavourBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                           std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<AircraftCarrier> Cavour(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 52, 29900, 241, "Italy", 4, 0, 0, 3, a, v, 244,
                                29,
                                true,
                                ShipType::AircraftCarrier, ModelType::Cavour, 5));
    return Cavour;
}

std::unique_ptr<AircraftCarrier>
ShipFactory::hiryuBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                          std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<AircraftCarrier> Hiryu(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 63, 20570, 70, "Japan", 2, 0, 0, 2, a, v, 222,
                                22,
                                true,
                                ShipType::AircraftCarrier, ModelType::Hiryu, 6));
    return Hiryu;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedCruiser(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::vector<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::vector<std::unique_ptr<Vehicle>> v;
    switch (type) {

        case ModelType::Ijn: {
            std::unique_ptr<AircraftCarrier> midway = midwayBuilder(a, v, coordinates);
            return std::move(midway);
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
ShipFactory::newOrleansBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                               std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Cruiser> NewOrleans(
            new Cruiser(coordinates.x, coordinates.y, 3, 61, 12663, 476, "Usa", 6, 0, 3, 2, a, v, 179,
                        19,
                        true,
                        ShipType::Cruiser, ModelType::NewOrleans, 0));
    return NewOrleans;
}

std::unique_ptr<Cruiser>
ShipFactory::tiger59Builder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                            std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Cruiser> Tiger59(
            new Cruiser(coordinates.x, coordinates.y, 3, 58, 12080, 191, "Uk", 2, 0, 2, 1, a, v, 169,
                        20,
                        true,
                        ShipType::Cruiser, ModelType::Tiger59, 2));
    return Tiger59;
}

std::unique_ptr<Cruiser>
ShipFactory::belfastBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                            std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Cruiser> Belfast(
            new Cruiser(coordinates.x, coordinates.y, 3, 59, 11550, 228, "Uk", 6, 0, 4, 2, a, v, 187,
                        19,
                        true,
                        ShipType::Cruiser, ModelType::Belfast, 1));
    return Belfast;
}

std::unique_ptr<Cruiser>
ShipFactory::goriziaBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                            std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Cruiser> Gorizia(
            new Cruiser(coordinates.x, coordinates.y, 3, 59, 14330, 370, "Italy", 6, 0, 4, 2, a, v, 183,
                        21,
                        true,
                        ShipType::Cruiser, ModelType::Gorizia, 0));
    return Gorizia;
}

std::unique_ptr<Cruiser>
ShipFactory::isuzuNagaraBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Cruiser> IsuzuNagara(
            new Cruiser(coordinates.x, coordinates.y, 3, 67, 5700, 90, "Japan", 5, 0, 3, 6, a, v, 159,
                        14,
                        true,
                        ShipType::Cruiser, ModelType::IsuzuNagara, 1));
    return IsuzuNagara;
}

std::unique_ptr<Cruiser>
ShipFactory::ijnBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                        std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Cruiser> Ijn(
            new Cruiser(coordinates.x, coordinates.y, 3, 66, 15500, 230, "Japan", 4, 0, 4, 10, a, v, 204,
                        20,
                        true,
                        ShipType::Cruiser, ModelType::Ijn, 2));
    return Ijn;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedBattleship(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::vector<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::vector<std::unique_ptr<Vehicle>> v;
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
            std::unique_ptr<Battleship> VittorioVeneto(
                    new Battleship(coordinates.x, coordinates.y, 1, 56, 45963, 862, "Italy", 14, 3, 4, 32, a, v, 238,
                                   33,
                                   true,
                                   ShipType::Battleship, ModelType::VittorioVeneto, 1));
            return std::move(VittorioVeneto);
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
            std::unique_ptr<Battleship> ironDuke(
                    new Battleship(coordinates.x, coordinates.y, 1, 39, 29500, 826,
                                   "Uk", 0, 5, 0, 15, a, v, 190, 27, true,
                                   ShipType::Battleship,
                                   ModelType::IronDuke, 0));

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
ShipFactory::newYorkBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                            std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Battleship> NewYork(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 28822, 939,
                           "Usa", 0, 5, 0, 6, a, v, 175, 29, true,
                           ShipType::Battleship,
                           ModelType::NewYork, 0));
    return NewYork;
}

std::unique_ptr<Battleship>
ShipFactory::arizonaBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                            std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Battleship> Arizona(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 32429, 1536,
                           "Usa", 8, 4, 0, 4, a, v, 185, 30, true,
                           ShipType::Battleship,
                           ModelType::Arizona, 0));
    return Arizona;
}

std::unique_ptr<Battleship>
ShipFactory::hoodBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                         std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Battleship> Hood(
            new Battleship(coordinates.x, coordinates.y, 1, 54, 49136, 800, "Uk", 0, 2, 2, 20, a, v, 262, 32,
                           true,
                           ShipType::Battleship, ModelType::Hood, 0));
    return Hood;
}

std::unique_ptr<Battleship>
ShipFactory::michelangeloBuonarrotiBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                           std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Battleship> MichelangeloBuonarroti(
            new Battleship(coordinates.x, coordinates.y, 1, 61, 42533, 837, "Italy", 12, 3, 6, 14, a, v, 246,
                           29,
                           true,
                           ShipType::Battleship, ModelType::MichelangeloBuonarroti, 1));
    return MichelangeloBuonarroti;
}

std::unique_ptr<Battleship>
ShipFactory::andreaDoriaBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Battleship> AndreaDoria(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 24729, 622, "Italy", 10, 2, 2, 13, a, v, 176,
                           28,
                           true,
                           ShipType::Battleship, ModelType::AndreaDoria, 0));
    return AndreaDoria;
}

std::unique_ptr<Battleship>
ShipFactory::yamatoBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                           std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Battleship> Yamato(
            new Battleship(coordinates.x, coordinates.y, 1, 50, 71659, 1286, "Japan", 12, 3, 2, 40, a, v, 263,
                           39,
                           true,
                           ShipType::Battleship, ModelType::Yamato, 3));
    return Yamato;
}

std::unique_ptr<Battleship>
ShipFactory::iseBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                        std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Battleship> Ise(
            new Battleship(coordinates.x, coordinates.y, 1, 45, 40444, 705, "Japan", 8, 4, 0, 19, a, v, 220, 32,
                           true,
                           ShipType::Battleship, ModelType::ISE, 2));
    return Ise;
}

std::unique_ptr<WarShip> ShipFactory::createAlliedDestroyer(ModelType type, GameWorld &map) {
    sf::Vector2i coordinates = randomizeAlliedPositions(map);
    std::vector<std::unique_ptr<Arsenal>> a; //TODO da sistemare con factory
    std::vector<std::unique_ptr<Vehicle>> v;

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
            std::unique_ptr<Destroyer> Campbelltown(
                    new Destroyer(coordinates.x, coordinates.y, 4, 66, 1280, 19,
                                  "Uk", 4, 0, 0, 10, a, v, 96, 9, true,
                                  ShipType::Destroyer,
                                  ModelType::Campbelltown, 6));

            return std::move(Campbelltown);
        }


        case ModelType::Gallant: {
            std::unique_ptr<Destroyer> Gallant(
                    new Destroyer(coordinates.x, coordinates.y, 4, 67, 1913, 22,
                                  "Uk", 0, 0, 4, 8, a, v, 99, 10, true,
                                  ShipType::Destroyer,
                                  ModelType::Gallant, 8));

            return std::move(Gallant);
        }


        case ModelType::Jutland: {
            std::unique_ptr<Destroyer> Jutland(
                    new Destroyer(coordinates.x, coordinates.y, 4, 66, 2480, 26,
                                  "Uk", 0, 0, 3, 16, a, v, 116, 12, true,
                                  ShipType::Destroyer,
                                  ModelType::Jutland, 10));

            return std::move(Jutland);
        }


        case ModelType::Fletcher: {
            std::unique_ptr<Destroyer> Fletcher(
                    new Destroyer(coordinates.x, coordinates.y, 4, 68, 2500, 33,
                                  "Usa", 0, 0, 5, 14, a, v, 115, 12, true,
                                  ShipType::Destroyer,
                                  ModelType::Fletcher, 610));

            return std::move(Fletcher);
        }


        case ModelType::Mahan: {
            std::unique_ptr<Destroyer> Mahan(
                    new Destroyer(coordinates.x, coordinates.y, 4, 69, 2137, 27,
                                  "Usa", 0, 0, 4, 8, a, v, 104, 11, true,
                                  ShipType::Destroyer,
                                  ModelType::Mahan, 12));

            return std::move(Mahan);
        }


        case ModelType::Sims: {
            std::unique_ptr<Destroyer> Sims(
                    new Destroyer(coordinates.x, coordinates.y, 4, 69, 2293, 30,
                                  "Usa", 0, 0, 4, 16, a, v, 106, 11, true,
                                  ShipType::Destroyer,
                                  ModelType::Sims, 8));

            return std::move(Sims);
        }


        default:                        //TODO aggiungere eccezione
            break;
    }
    return std::unique_ptr<WarShip>();
}

std::unique_ptr<Destroyer>
ShipFactory::leoneBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                          std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Destroyer> Leone(
            new Destroyer(coordinates.x, coordinates.y, 4, 61, 2326, 22,
                          "Italy", 0, 0, 3, 20, a, v, 113, 10, true,
                          ShipType::Destroyer,
                          ModelType::Leone, 6));
    return Leone;
}

std::unique_ptr<Destroyer>
ShipFactory::fubukiBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                           std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Destroyer> Fubuki(
            new Destroyer(coordinates.x, coordinates.y, 4, 70, 2080, 26,
                          "Japan", 0, 0, 6, 20, a, v, 118, 10, true,
                          ShipType::Destroyer,
                          ModelType::Fubuki, 9));
    return Fubuki;
}

std::unique_ptr<Destroyer>
ShipFactory::akizukiBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                            std::vector<std::unique_ptr<Vehicle>> &v) const {
    std::unique_ptr<Destroyer> Akizuki(
            new Destroyer(coordinates.x, coordinates.y, 4, 61, 3759, 33,
                          "Japan", 0, 0, 5, 50, a, v, 134, 12, true,
                          ShipType::Destroyer,
                          ModelType::Akizuki, 4));
    return Akizuki;
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

