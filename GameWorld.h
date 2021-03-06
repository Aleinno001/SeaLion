//
// Created by alessandro on 04/07/21.
//
#ifndef SEALION_GAMEWORLD_H
#define SEALION_GAMEWORLD_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameTile.h"
#include "WarShip.h"
#include <string>
#include <memory>
#include <list>
#include "Dice.h"
#include <stdio.h>
#include <unistd.h>
#include<iostream>
#include "ShipFactory.h"

enum class FactionType {
    Uk,Usa,Italy,Japan
};
struct Fleet {
    ModelType name;
    int num;
    ShipType type;
};
class GameWorld {
private:
    int tileDim{30};
    std::vector<std::vector<std::shared_ptr<GameTile>>> tiles;
    FactionType enemyFaction;
    FactionType alliedFaction;
    sf::Vector2i exitPos;
    std::list<std::shared_ptr<WarShip>> alliedFleet;
    std::list<std::shared_ptr<WarShip>> enemyFleet;
    int gridLength;
    int mapWidth{1920};
    int mapHeight{1080};
    //Inizializzatori delle navi
    bool isInStrip(int i, int tileDim);
    void submarineRandomizer(int &enemySub, Dice &subDice, const std::shared_ptr<ShipFactory>& enemyFactory);
    void battleshipRandomizer(int &enemyBat, Dice &batDice, const std::shared_ptr<ShipFactory>& enemyFactory);
    void cruiserRandomizer(int &enemyCru, Dice &cruDice, const std::shared_ptr<ShipFactory>& enemyFactory);
    void destroyerRandomizer(int &enemyDes, Dice &desDice, const std::shared_ptr<ShipFactory>& enemyFactory);
    void aircraftCarrierRandomizer(int &enemyAir, Dice &airDice, const std::shared_ptr<ShipFactory>& enemyFactory);
    void japanBattleshipInizializer(int &numBat, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void japanCruiserInizializer(int &numCru, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void japanSubmarineInizializer(int &numSub, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void japanDestroyerInizializer(int &numDes, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void japanAircraftCarrierInizializer(int &numAir, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void italianBattleshipInizializer(int &numBat, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void usaBattleshipInizializer(int &numBat, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void ukBattleshipInizializer(int &numBat, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void italianCruiserInizializer(int &numCru, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void usaCruiserInizializer(int &numCru, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void ukCruiserInizializer(int &numCru, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void italianDestroyerInizializer(int &numDes, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void usaDestroyerInizializer(int &numDes, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void ukDestroyerInizializer(int &numDes, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void italianSubmarineInizializer(int &numSub, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void usaSubmarineInizializer(int &numSub, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void ukSubmarineInizializer(int &numSub, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void italianAircraftCarrierInizializer(int &numAir, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void usaAircraftCarrierInizializer(int &numAir, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void ukAircraftCarrierInizializer(int &numAir, const std::shared_ptr<ShipFactory>& enemyFactory, Dice &dice);
    void setUpAlliedFleet(std::vector<Fleet> &fleet);  //Crea la flotta alleata
    void setUpEnemyFleet(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes,int &numEnemyAir);  //Crea la flotta nemica
    void setUpUnitTestingTiles(int tileDim,std::string specialTile); //Genera la mappa per Unit Testing
public:
    GameWorld(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir,std::vector<Fleet> &fleet, FactionType enemyFact, FactionType alliedFact, int grid, sf::Vector2i exit,int &width, int &height, int &tileDim);
    GameWorld(int height,int width,int tileDim,int numAlliedShips,std::string specialTile, int numEnemyShips);
    GameWorld() = default;
    FactionType getEnemyFaction() const;
    FactionType getAlliedFaction() const;
    const sf::Vector2i &getExitPos() const;
    const std::vector<std::vector<std::shared_ptr<GameTile>>> &getTiles() const;
    void setUpInitialState(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir,std::vector<Fleet> &fleet);   //Imposta lo stato delle navi ad inizio partita
    void setUpTiles(int &tileDim);  //Genera la mappa
    int getGridLength() const;
    int getMapWidth() const;
    int getMapHeight() const;
    void setEnemyFaction(FactionType enemyFaction);
    void setAlliedFaction(FactionType alliedFaction);
    void setExitPos(const sf::Vector2i &exitPos);
    void setGridLength(int gridLength);
    void setMapWidth(int mapWidth);
    void setMapHeight(int mapHeight);
    std::list<std::shared_ptr<WarShip>> &getAlliedFleet() {return alliedFleet;}
    std::list<std::shared_ptr<WarShip>> &getEnemyFleet() {return enemyFleet;}
    int getTileDim() const;
    ~GameWorld()=default;
};
#endif //SEALION_GAMEWORLD_H
