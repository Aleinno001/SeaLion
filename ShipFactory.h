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
    std::shared_ptr<ConcreteWarShip>i400Builder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>typeb1Builder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>DaVinciBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip> papaBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>tritonBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>trenchantBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>gatoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip> narwhalBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>tahioBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>hiryuBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>giuseppeGaribaldiBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>cavourBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>arkRoyalBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>indomitableBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>midwayBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>franklinDelanoRoosveltBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip> ijnBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>takaoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>isuzuNagaraBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>albertoDiGiussanoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip> goriziaBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>trentoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip> belfastBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>danaeBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip> tiger59Builder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>alaskaBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>newOrleansBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>stLouisBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip> iseBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>musashiBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip> yamatoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>kongoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>andreaDoriaBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>imperatoreAugustoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>michelangeloBuonarrotiBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>dreadNoughtBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip> hoodBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>lionBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>arizonaBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>montanaBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>newYorkBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>northCarolinaBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip> akizukiBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>yukikazeBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip> fubukiBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>impavidoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip> leoneBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>paoloEmilioBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>campbeltownBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>jutlandBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip> gallandBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>fletcherBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip> mahanBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>simsBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>vittorioVenetoBuilder(sf::Vector2i &coordinates) const;
    std::shared_ptr<ConcreteWarShip>ironDukeBuilder(sf::Vector2i &coordinates) const;
    sf::Vector2i randomizeAlliedPositions(GameWorld &map);
    std::shared_ptr<WarShip> &repositionEnemyShip(std::shared_ptr<WarShip> &ship);
    std::shared_ptr<WarShip> &repositionAlliedShip(std::shared_ptr<WarShip> &ship);
};
#endif //SEALION_SHIPFACTORY_H
