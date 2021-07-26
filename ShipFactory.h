//
// Created by alessandro on 7/2/21.
//

#ifndef SEALION_SHIPFACTORY_H
#define SEALION_SHIPFACTORY_H


#include "AbstractShipFactory.h"
#include "Dice.h"
#include "Submarine.h"
#include "Destroyer.h"
#include "AircraftCarrier.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "WeaponFactory.h"
#include "CannonFactory.h"


class ShipFactory : public AbstractShipFactory {

public:
    std::unique_ptr<WarShip> createSubmarine(ModelType type, GameWorld &map) override;

    std::unique_ptr<WarShip> createAircraftCarrier(ModelType type, GameWorld &map) override;

    std::unique_ptr<WarShip> createCruiser(ModelType type, GameWorld &map) override;

    std::unique_ptr<WarShip> createBattleship(ModelType type, GameWorld &map) override;

    std::unique_ptr<WarShip> createDestroyer(ModelType type, GameWorld &map) override;

    std::unique_ptr<WarShip> createAlliedSubmarine(ModelType type, GameWorld &map) override;

    std::unique_ptr<WarShip> createAlliedAircraftCarrier(ModelType type, GameWorld &map) override;

    std::unique_ptr<WarShip> createAlliedCruiser(ModelType type, GameWorld &map) override;

    std::unique_ptr<WarShip> createAlliedBattleship(ModelType type, GameWorld &map) override;

    std::unique_ptr<WarShip> createAlliedDestroyer(ModelType type, GameWorld &map) override;

    ShipFactory(int x, int y) : offset(x, y), offsetAllied(x, y) {};

private:
    sf::Vector2i offset;
    sf::Vector2i offsetAllied;

    sf::Vector2i randomizeEnemyPositions(GameWorld &map);


    std::unique_ptr<Submarine>
    i400Builder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                sf::Vector2i &coordinates) const;

    std::unique_ptr<Submarine>
    typeb1Builder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                  sf::Vector2i &coordinates) const;

    std::unique_ptr<Submarine>
    DaVinciBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                   sf::Vector2i &coordinates) const;

    std::unique_ptr<Submarine> papaBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                           std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Submarine>
    tritonBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                  sf::Vector2i &coordinates) const;

    std::unique_ptr<Submarine>
    trenchantBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                     std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Submarine>
    gatoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                sf::Vector2i &coordinates) const;

    std::unique_ptr<Submarine> narwhalBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                              std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<AircraftCarrier>
    tahioBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                 sf::Vector2i &coordinates) const;

    std::unique_ptr<AircraftCarrier>
    hiryuBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                 std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<AircraftCarrier>
    giuseppeGaribaldiBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                             sf::Vector2i &coordinates) const;

    std::unique_ptr<AircraftCarrier>
    cavourBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                  std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<AircraftCarrier>
    arkRoyalBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                    sf::Vector2i &coordinates) const;

    std::unique_ptr<AircraftCarrier>
    indomitableBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                       std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<AircraftCarrier>
    midwayBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                  sf::Vector2i &coordinates) const;

    std::unique_ptr<AircraftCarrier>
    franklinDelanoRoosveltBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                  std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Cruiser> ijnBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                        std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Cruiser>
    takaoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                 const sf::Vector2i &coordinates) const;

    std::unique_ptr<Cruiser>
    isuzuNagaraBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                       std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Cruiser>
    albertoDiGiussanoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                             const sf::Vector2i &coordinates) const;

    std::unique_ptr<Cruiser> goriziaBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                            std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Cruiser>
    trentoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                  const sf::Vector2i &coordinates) const;

    std::unique_ptr<Cruiser> belfastBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                            std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Cruiser>
    danaeBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                 const sf::Vector2i &coordinates) const;

    std::unique_ptr<Cruiser> tiger59Builder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                            std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Cruiser>
    alaskaBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                  const sf::Vector2i &coordinates) const;

    std::unique_ptr<Cruiser>
    newOrleansBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                      std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Cruiser>
    stLouisBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                   const sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship> iseBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                           std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    musashiBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                   const sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship> yamatoBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                              std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    kongoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                 const sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship>
    andreaDoriaBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                       std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    imperatoreAugustoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                             const sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship>
    michelangeloBuonarrotiBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                  std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    dreadNoughtBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                       const sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship> hoodBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                            std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    lionBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                const sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship>
    arizonaBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                   std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    montanaBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                   const sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship>
    newYorkBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                   std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    northCarolinaBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                         const sf::Vector2i &coordinates) const;

    std::unique_ptr<Destroyer> akizukiBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                              std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Destroyer>
    yukikazeBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                    sf::Vector2i &coordinates) const;

    std::unique_ptr<Destroyer> fubukiBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                             std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Destroyer>
    impavidoBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                    sf::Vector2i &coordinates) const;

    std::unique_ptr<Destroyer> leoneBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                            std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Destroyer>
    paoloEmilioBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                       sf::Vector2i &coordinates) const;

    std::unique_ptr<Destroyer>
    campbeltownBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                       std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Destroyer>
    jutlandBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                   sf::Vector2i &coordinates) const;

    std::unique_ptr<Destroyer> gallandBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                              std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Destroyer>
    fletcherBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                    sf::Vector2i &coordinates) const;

    std::unique_ptr<Destroyer> mahanBuilder(sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                                            std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Destroyer>
    simsBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship>
    vittorioVenetoBuilder(const sf::Vector2i &coordinates, std::list<std::unique_ptr<Arsenal>> &a,
                          std::list<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    ironDukeBuilder(std::list<std::unique_ptr<Arsenal>> &a, std::list<std::unique_ptr<Vehicle>> &v,
                    const sf::Vector2i &coordinates) const;

    sf::Vector2i randomizeAlliedPositions(GameWorld &map);
};


#endif //SEALION_SHIPFACTORY_H
