//
// Created by alessandro on 04/07/21.
//

#ifndef SEALION_GAMEWORLD_H
#define SEALION_GAMEWORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameTile.h"
#include "WarShip.h"
#include "ShipFactory.h"
#include <string>
#include <memory>
#include <list>
#include "Dice.h"

#include <stdio.h>
/*
// #define WINDOWS
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
*/
#include <unistd.h>

#define GetCurrentDir getcwd
//#endif

#include<iostream>


enum class FactionType {
    Uk,
    Usa,
    Italy,
    Japan

};



struct Fleet {
    ModelType name;
    int num;
    ShipType type;
};

class GameWorld {
public:
    std::vector<std::vector<std::unique_ptr<GameTile>>> tiles;

private:

    FactionType enemyFaction;
    FactionType alliedFaction;
    sf::Vector2i exitPos;
    std::list<std::unique_ptr<WarShip>> alliedFleet;
    std::list<std::unique_ptr<WarShip>> enemyFleet;

    int gridLength;
    int mapWidth{1920};
    int mapHeight{1080};

public:

    GameWorld(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir,
              std::vector<Fleet> &fleet, FactionType enemyFact, FactionType alliedFact, int grid, sf::Vector2i exit,
              int &width, int &height, int &tileDim);

    GameWorld() = default;

    void setUpInitialState(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir,
                           std::vector<Fleet> &fleet);

    void setUpAlliedFleet(std::vector<Fleet> &fleet);

    void setUpEnemyFleet(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir);

    void setUpTiles(int &tileDim);


private:
    bool isInStrip(int i, int tileDim);

    void submarineRandomizer(int &enemySub, Dice &subDice, std::shared_ptr<ShipFactory> enemyFactory);

    void battleshipRandomizer(int &enemyBat, Dice &batDice, std::shared_ptr<ShipFactory> enemyFactory);

    void cruiserRandomizer(int &enemyCru, Dice &cruDice, std::shared_ptr<ShipFactory> enemyFactory);

    void destroyerRandomizer(int &enemyDes, Dice &desDice, std::shared_ptr<ShipFactory> enemyFactory);

    void aircraftCarrierRandomizer(int &enemyAir, Dice &airDice, std::shared_ptr<ShipFactory> enemyFactory);

    void japanBattleshipInizializer(int &numBat, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void japanCruiserInizializer(int &numCru, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void japanSubmarineInizializer(int &numSub, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void japanDestroyerInizializer(int &numDes, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void japanAircraftCarrierInizializer(int &numAir, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void italianBattleshipInizializer(int &numBat, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void usaBattleshipInizializer(int &numBat, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void ukBattleshipInizializer(int &numBat, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void italianCruiserInizializer(int &numCru, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void usaCruiserInizializer(int &numCru, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void ukCruiserInizializer(int &numCru, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void italianDestroyerInizializer(int &numDes, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void usaDestroyerInizializer(int &numDes, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void ukDestroyerInizializer(int &numDes, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void italianSubmarineInizializer(int &numSub, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void usaSubmarineInizializer(int &numSub, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void ukSubmarineInizializer(int &numSub, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void italianAircraftCarrierInizializer(int &numAir, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void usaAircraftCarrierInizializer(int &numAir, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

    void ukAircraftCarrierInizializer(int &numAir, std::shared_ptr<ShipFactory> enemyFactory, Dice &dice);

public:
    FactionType getEnemyFaction() const;

    FactionType getAlliedFaction() const;

    const sf::Vector2i &getExitPos() const;

    const std::list<std::unique_ptr<WarShip>> &getAlliedFleet() const;

    const std::list<std::unique_ptr<WarShip>> &getEnemyFleet() const;

    const std::vector<std::vector<std::unique_ptr<GameTile>>> &getTiles() const;

    int getGridLength() const;

    int getMapWidth() const;

    int getMapHeight() const;

    void setEnemyFaction(FactionType enemyFaction);

    void setAlliedFaction(FactionType alliedFaction);

    void setExitPos(const sf::Vector2i &exitPos);

    void setGridLength(int gridLength);

    void setMapWidth(int mapWidth);

    void setMapHeight(int mapHeight);

    std::list<std::unique_ptr<WarShip>> &getAlliedFleet() {
        return alliedFleet;
    }

    std::list<std::unique_ptr<WarShip>> &getEnemyFleet() {
        return enemyFleet;
    }

};



#endif //SEALION_GAMEWORLD_H
