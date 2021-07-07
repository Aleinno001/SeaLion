//
// Created by davide on 04/07/21.
//

#ifndef SEALION_GAMEWORLD_H
#define SEALION_GAMEWORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameTile.h"
#include "WarShip.h"
#include "ShipFactory.h"
#include <string>
#include "AbstractShipFactory.h"
#include <memory>
#include <list>
#include "Dice.h"

enum class FactionType {
    Uk,
    Usa,
    Italy,
    Japan

};

enum class ShipType {
    Battleship,
    Cruiser,
    AircraftCarrier,
    Destroyer,
    Submarine
};


struct Fleet {
    ModelType name;
    int num;
    ShipType type;
};

class GameWorld {

private:

    FactionType enemyFaction;
    FactionType alliedFaction;
    sf::Vector2i exitPos;
    std::list<std::unique_ptr<WarShip>> alliedFleet;
    std::list<std::unique_ptr<WarShip>> enemyFleet;
    std::vector<std::vector<std::unique_ptr<GameTile>>> tiles;
    int gridLength;
    int mapWidth{1920};
    int mapHeight{1080};


public:
    GameWorld(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir,
              std::vector<Fleet> &fleet);



    void setUpInitialState(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir,
                           std::vector<Fleet> &fleet);

    void setUpAlliedFleet(std::vector<Fleet> &fleet);

    void setUpEnemyFleet(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir);

    void setUpTiles();

    void submarineRandomizer(int &enemySub, Dice &subDice, ShipFactory &enemyFactory);

    void battleshipRandomizer(int &enemyBat, Dice &batDice, ShipFactory &enemyFactory);

    void cruiserRandomizer(int &enemyCru, Dice &cruDice, ShipFactory &enemyFactory);

    void destroyerRandomizer(int &enemyDes, Dice &desDice, ShipFactory &enemyFactory);

    void aircraftCarrierRandomizer(int &enemyAir, Dice &airDice, ShipFactory &enemyFactory);

    void japanBattleshipInizializer(int &numBat, ShipFactory &enemyFactory, Dice &dice);

    void japanCruiserInizializer(int &numCru, ShipFactory &enemyFactory, Dice &dice);

    void japanSubmarineInizializer(int &numSub, ShipFactory &enemyFactory, Dice &dice);

    void japanDestroyerInizializer(int &numDes, ShipFactory &enemyFactory, Dice &dice);

    void japanAircraftCarrierInizializer(int &numAir, ShipFactory &enemyFactory, Dice &dice);

    void italianBattleshipInizializer(int &numBat, ShipFactory &enemyFactory, Dice &dice);

    void usaBattleshipInizializer(int &numBat, ShipFactory &enemyFactory, Dice &dice);

};



#endif //SEALION_GAMEWORLD_H
