//
// Created by alessandro on 7/2/21.
//

#ifndef SEALION_SHIPFACTORY_H
#define SEALION_SHIPFACTORY_H


#include "AbstractShipFactory.h"
#include "Dice.h"
#include "AircraftCarrier.h"
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
    i400Builder( 
                sf::Vector2i &coordinates) const;
    std::unique_ptr<Submarine>
    typeb1Builder( 
                  sf::Vector2i &coordinates) const;
    std::unique_ptr<Submarine>
    DaVinciBuilder( 
                   sf::Vector2i &coordinates) const;
    std::unique_ptr<Submarine> papaBuilder(sf::Vector2i &coordinates 
                                           ) const;
    std::unique_ptr<Submarine>
    tritonBuilder( 
                  sf::Vector2i &coordinates) const;
    std::unique_ptr<Submarine>
    trenchantBuilder(sf::Vector2i &coordinates 
                     ) const;
    std::unique_ptr<Submarine>
    gatoBuilder(
                sf::Vector2i &coordinates) const;
    std::unique_ptr<Submarine> narwhalBuilder(sf::Vector2i &coordinates 
                                              ) const;
    std::unique_ptr<AircraftCarrier>
    tahioBuilder( 
                 sf::Vector2i &coordinates) const;
    std::unique_ptr<AircraftCarrier>
    hiryuBuilder(sf::Vector2i &coordinates 
                 ) const;
    std::unique_ptr<AircraftCarrier>
    giuseppeGaribaldiBuilder( 
                             sf::Vector2i &coordinates) const;
    std::unique_ptr<AircraftCarrier>
    cavourBuilder(sf::Vector2i &coordinates 
                  ) const;
    std::unique_ptr<AircraftCarrier>
    arkRoyalBuilder( 
                    sf::Vector2i &coordinates) const;
    std::unique_ptr<AircraftCarrier>
    indomitableBuilder(sf::Vector2i &coordinates 
                       ) const;
    std::unique_ptr<AircraftCarrier>
    midwayBuilder( 
                  sf::Vector2i &coordinates) const;
    std::unique_ptr<AircraftCarrier>
    franklinDelanoRoosveltBuilder(sf::Vector2i &coordinates 
                                  ) const;

    std::unique_ptr<Cruiser> ijnBuilder(sf::Vector2i &coordinates 
                                        ) const;
    std::unique_ptr<Cruiser>
    takaoBuilder( 
                 sf::Vector2i &coordinates) const;
    std::unique_ptr<Cruiser>
    isuzuNagaraBuilder(sf::Vector2i &coordinates 
                       ) const;
    std::unique_ptr<Cruiser>
    albertoDiGiussanoBuilder( 
                             sf::Vector2i &coordinates) const;
    std::unique_ptr<Cruiser> goriziaBuilder(sf::Vector2i &coordinates 
                                            ) const;
    std::unique_ptr<Cruiser>
    trentoBuilder( 
                  sf::Vector2i &coordinates) const;
    std::unique_ptr<Cruiser> belfastBuilder(sf::Vector2i &coordinates 
                                            ) const;
    std::unique_ptr<Cruiser>
    danaeBuilder( 
                 sf::Vector2i &coordinates) const;
    std::unique_ptr<Cruiser> tiger59Builder(sf::Vector2i &coordinates 
                                            ) const;
    std::unique_ptr<Cruiser>
    alaskaBuilder( 
                  sf::Vector2i &coordinates) const;
    std::unique_ptr<Cruiser>
    newOrleansBuilder(sf::Vector2i &coordinates 
                      ) const;
    std::unique_ptr<Cruiser>
    stLouisBuilder( 
                   sf::Vector2i &coordinates) const;
    std::unique_ptr<Battleship> iseBuilder(sf::Vector2i &coordinates 
                                           ) const;
    std::unique_ptr<Battleship>
    musashiBuilder( 
                   sf::Vector2i &coordinates) const;
    std::unique_ptr<Battleship> yamatoBuilder(sf::Vector2i &coordinates 
                                              ) const;
    std::unique_ptr<Battleship>
    kongoBuilder( 
                 sf::Vector2i &coordinates) const;
    std::unique_ptr<Battleship>
    andreaDoriaBuilder(sf::Vector2i &coordinates 
                       ) const;
    std::unique_ptr<Battleship>
    imperatoreAugustoBuilder( 
                             sf::Vector2i &coordinates) const;
    std::unique_ptr<Battleship>
    michelangeloBuonarrotiBuilder(sf::Vector2i &coordinates 
                                  ) const;
    std::unique_ptr<Battleship>
    dreadNoughtBuilder( 
                       sf::Vector2i &coordinates) const;
    std::unique_ptr<Battleship> hoodBuilder(sf::Vector2i &coordinates 
                                            ) const;
    std::unique_ptr<Battleship>
    lionBuilder( 
                sf::Vector2i &coordinates) const;

    std::unique_ptr<Battleship>
    arizonaBuilder(sf::Vector2i &coordinates 
                   ) const;
    std::unique_ptr<Battleship>
    montanaBuilder( 
                   sf::Vector2i &coordinates) const;
    std::unique_ptr<Battleship>
    newYorkBuilder(sf::Vector2i &coordinates 
                   ) const;
    std::unique_ptr<Battleship>
    northCarolinaBuilder( 
                         sf::Vector2i &coordinates) const;
    std::unique_ptr<Destroyer> akizukiBuilder(sf::Vector2i &coordinates 
                                              ) const;
    std::unique_ptr<Destroyer>
    yukikazeBuilder( 
                    sf::Vector2i &coordinates) const;

    std::unique_ptr<Destroyer> fubukiBuilder(sf::Vector2i &coordinates 
                                             ) const;
    std::unique_ptr<Destroyer>
    impavidoBuilder( 
                    sf::Vector2i &coordinates) const;
    std::unique_ptr<Destroyer> leoneBuilder(sf::Vector2i &coordinates 
                                            ) const;
    std::unique_ptr<Destroyer>
    paoloEmilioBuilder( 
                       sf::Vector2i &coordinates) const;
    std::unique_ptr<Destroyer>
    campbeltownBuilder(sf::Vector2i &coordinates 
                       ) const;
    std::unique_ptr<Destroyer>
    jutlandBuilder( 
                   sf::Vector2i &coordinates) const;
    std::unique_ptr<Destroyer> gallandBuilder(sf::Vector2i &coordinates 
                                              ) const;
    std::unique_ptr<Destroyer>
    fletcherBuilder( 
                    sf::Vector2i &coordinates) const;
    std::unique_ptr<Destroyer> mahanBuilder(sf::Vector2i &coordinates 
                                            ) const;
    std::unique_ptr<Destroyer>
    simsBuilder( 
                sf::Vector2i &coordinates) const;
    std::unique_ptr<Battleship>
    vittorioVenetoBuilder(sf::Vector2i &coordinates 
                          ) const;
    std::unique_ptr<Battleship>
    ironDukeBuilder( 
                    sf::Vector2i &coordinates) const;
    sf::Vector2i randomizeAlliedPositions(GameWorld &map);
    std::unique_ptr<WarShip> &repositionEnemyShip(std::unique_ptr<WarShip> &ship);
    std::unique_ptr<WarShip> &repositionAlliedShip(std::unique_ptr<WarShip> &ship);
};


#endif //SEALION_SHIPFACTORY_H
