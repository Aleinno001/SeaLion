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
#include "Dice.h"

class enum FactionType {
    Uk,
    Usa,
    Italy,
    Japan

};

class GameWorld {

private:

    FactioType enemyFaction{"Japan"};
    FactionType alliedFaction{"Italy"};
    sf::Vector2i exitPos;
    std::list<std::unique_ptr<WarShip>> alliedFleet;
    std::list<std::unique_ptr<WarShip>> enemyFleet;
    std::vector<std::vector<std::unique_ptr<GameTile>>> tiles;
    int gridLength;
    int mapWidth{1920};
    int mapHeight{1080};


public:
    GameWorld(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir);

    void setUpInitialState(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir);

    void
    setUpAlliedFleet(int &numAlliedSub, int &numAlliedBat, int &numAlliedCru, int &numAlliedDes, int &numAlliedAir);

    void setUpEnemyFleet(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir);

    void setUpTiles();


};


#endif //SEALION_GAMEWORLD_H
