//
// Created by alessandro on 7/2/21.
//
#ifndef SEALION_SHIPFACTORY_H
#define SEALION_SHIPFACTORY_H
#include "AbstractShipFactory.h"
#include "Dice.h"
#include "WeaponFactory.h"
#include "CannonFactory.h"
#include "ConcreteWarShip.h"

class ShipFactory : public AbstractShipFactory {
public:
    std::shared_ptr<WarShip> createSubmarine(ModelType type, GameWorld &map) override;
    std::shared_ptr<WarShip> createAircraftCarrier(ModelType type, GameWorld &map) override;
    std::shared_ptr<WarShip> createCruiser(ModelType type, GameWorld &map) override;
    std::shared_ptr<WarShip> createBattleship(ModelType type, GameWorld &map) override;
    std::shared_ptr<WarShip> createDestroyer(ModelType type, GameWorld &map) override;
    std::shared_ptr<WarShip> createAlliedSubmarine(ModelType type, GameWorld &map) override;
    std::shared_ptr<WarShip> createAlliedAircraftCarrier(ModelType type, GameWorld &map) override;
    std::shared_ptr<WarShip> createAlliedCruiser(ModelType type, GameWorld &map) override;
    std::shared_ptr<WarShip> createAlliedBattleship(ModelType type, GameWorld &map) override;
    std::shared_ptr<WarShip> createAlliedDestroyer(ModelType type, GameWorld &map) override;
    ShipFactory(int x, int y) : offset(x, y), offsetAllied(x, y) {};
private:
    sf::Vector2i offset;
    sf::Vector2i offsetAllied;
    sf::Vector2i randomizeEnemyPositions(GameWorld &map);
    std::shared_ptr<WarShip>i400Builder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>typeb1Builder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>DaVinciBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip> papaBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>tritonBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>trenchantBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>gatoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip> narwhalBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>tahioBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>hiryuBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>giuseppeGaribaldiBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>cavourBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>arkRoyalBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>indomitableBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>midwayBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>franklinDelanoRoosveltBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip> ijnBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>takaoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>isuzuNagaraBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>albertoDiGiussanoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip> goriziaBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>trentoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip> belfastBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>danaeBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip> tiger59Builder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>alaskaBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>newOrleansBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>stLouisBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip> iseBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>musashiBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip> yamatoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>kongoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>andreaDoriaBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>imperatoreAugustoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>michelangeloBuonarrotiBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>dreadNoughtBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip> hoodBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>lionBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>arizonaBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>montanaBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>newYorkBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>northCarolinaBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip> akizukiBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>yukikazeBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip> fubukiBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>impavidoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip> leoneBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>paoloEmilioBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>campbeltownBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>jutlandBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip> gallandBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>fletcherBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip> mahanBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>simsBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>vittorioVenetoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<WarShip>ironDukeBuilder(sf::Vector2i &coordinates) const;
    sf::Vector2i randomizeAlliedPositions(GameWorld &map);
    std::shared_ptr<WarShip> &repositionEnemyShip(std::shared_ptr<WarShip> &ship);
    std::shared_ptr<WarShip> &repositionAlliedShip(std::shared_ptr<WarShip> &ship);
};
#endif //SEALION_SHIPFACTORY_H
