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
};


#endif //SEALION_SHIPFACTORY_H
