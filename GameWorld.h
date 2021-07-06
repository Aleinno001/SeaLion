//
// Created by davide on 04/07/21.
//

#ifndef SEALION_GAMEWORLD_H
#define SEALION_GAMEWORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameTile.h"
#include "WarShip.h"
#include <string>

class GameWorld {

private:

    sf::Vector2i exitPos;
    std::list<std::unique_ptr<WarShip>> alliedFleet;
    std::list<std::unique_ptr<WarShip>> enemyFleet;
    std::vector<std::vector<std::unique_ptr<GameTile>>> tiles;
    int gridLength;
    std::map<std::string, std::unique_ptr<GameTile>> worldMap;
    int mapWidth{1920};
    int mapHeight{1080};

public:


    void setUpInitialState();

    void setUpAlliedFleet();

    void setUpEnemyFleet();

    void setUpTiles();

    GameWorld();
};


#endif //SEALION_GAMEWORLD_H
