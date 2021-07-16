//
// Created by pala on 7/2/21.
//

#ifndef SEALION_SHIPFACTORY_H
#define SEALION_SHIPFACTORY_H


#include "AbstractShipFactory.h"
#include "Dice.h"


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

    ShipFactory() = default;

private:
    sf::Vector2i offset{0, 0};
    sf::Vector2i offsetAllied{0, 0};

    sf::Vector2i randomizeEnemyPositions(GameWorld &map);

    sf::Vector2i randomizeAlliedPositions(GameWorld &map);

    std::unique_ptr<Submarine>
    i400Builder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                const sf::Vector2i &coordinates) const;

    std::unique_ptr<Submarine>
    typeb1Builder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                  const sf::Vector2i &coordinates) const;

    std::unique_ptr<Submarine>
    DaVinciBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                   const sf::Vector2i &coordinates) const;

    std::unique_ptr<Submarine> papaBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                           std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Submarine>
    tritonBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                  const sf::Vector2i &coordinates) const;

    std::unique_ptr<Submarine>
    trenchantBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                     std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Submarine>
    gatoBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                const sf::Vector2i &coordinates) const;

    std::unique_ptr<Submarine> narwhalBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                              std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<AircraftCarrier>
    tahioBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                 const sf::Vector2i &coordinates) const;

    std::unique_ptr<AircraftCarrier>
    hiryuBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                 std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<AircraftCarrier>
    giuseppeGaribaldiBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                             const sf::Vector2i &coordinates) const;

    std::unique_ptr<AircraftCarrier>
    cavourBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                  std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<AircraftCarrier>
    arkRoyalBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                    const sf::Vector2i &coordinates) const;

    std::unique_ptr<AircraftCarrier>
    indomitableBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                       std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<AircraftCarrier>
    midwayBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                  const sf::Vector2i &coordinates) const;

    std::unique_ptr<AircraftCarrier>
    franklinDelanoRoosveltBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                  std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Cruiser> ijnBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                        std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Cruiser>
    takaoBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                 const sf::Vector2i &coordinates) const;

    std::unique_ptr<Cruiser>
    isuzuNagaraBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                       std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Cruiser>
    albertoDiGiussanoBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                             const sf::Vector2i &coordinates) const;

    std::unique_ptr<Cruiser> goriziaBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                            std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Cruiser>
    trentoBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                  const sf::Vector2i &coordinates) const;

    std::unique_ptr<Cruiser> belfastBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                            std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Cruiser>
    danaeBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                 const sf::Vector2i &coordinates) const;

    std::unique_ptr<Cruiser> tiger59Builder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                            std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Cruiser>
    alaskaBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                  const sf::Vector2i &coordinates) const;

    std::unique_ptr<Cruiser>
    newOrleansBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                      std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Cruiser>
    stLouisBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                   const sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship> iseBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                           std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    musashiBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                   const sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship> yamatoBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                              std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    kongoBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                 const sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship>
    andreaDoriaBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                       std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    imperatoreAugustoBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                             const sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship>
    michelangeloBuonarrotiBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                  std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    dreadNoughtBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                       const sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship> hoodBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                            std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    lionBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                const sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship>
    arizonaBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                   std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    montanaBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                   const sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship>
    newYorkBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                   std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Battleship>
    northCarolinaBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                         const sf::Vector2i &coordinates) const;

    std::unique_ptr<Destroyer> akizukiBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                              std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Destroyer>
    yukikazeBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                    const sf::Vector2i &coordinates) const;

    std::unique_ptr<Destroyer> fubukiBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                             std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Destroyer>
    impavidoBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                    const sf::Vector2i &coordinates) const;

    std::unique_ptr<Destroyer> leoneBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                            std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Destroyer>
    paoloEmilioBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                       const sf::Vector2i &coordinates) const;

    std::unique_ptr<Destroyer>
    campbeltownBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                       std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Destroyer>
    jutlandBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                   const sf::Vector2i &coordinates) const;

    std::unique_ptr<Destroyer> gallandBuilder(const sf::Vector2i &coordinates, std::vector<std::unique_ptr<Arsenal>> &a,
                                              std::vector<std::unique_ptr<Vehicle>> &v) const;

    std::unique_ptr<Destroyer>
    fletcherBuilder(std::vector<std::unique_ptr<Arsenal>> &a, std::vector<std::unique_ptr<Vehicle>> &v,
                    const sf::Vector2i &coordinates) const;
};


#endif //SEALION_SHIPFACTORY_H
