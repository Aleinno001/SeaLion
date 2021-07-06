//
// Created by davide on 04/07/21.
//

#ifndef SEALION_GAMEWORLD_H
#define SEALION_GAMEWORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameTile.h"



class GameWorld {

private:

    sf::Vector2i exitPos;
    std::vector<sf::Vector2i> alliedPosition;
    std::vector<sf::Vector2i> enemyPositions;
    std::vector<std::vector<std::unique_ptr<GameTile>>> tiles;
    int gridLength;


public:


    void setUpInitialState();

    void setUpAlliedPosition();

    void setUpEnemyPositions();

    void setUpTiles();

    GameWorld();
};


#endif //SEALION_GAMEWORLD_H
