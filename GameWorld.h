//
// Created by davide on 04/07/21.
//

#ifndef SEALION_GAMEWORLD_H
#define SEALION_GAMEWORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameTile.h"


class GameWorld {

    sf::Vector2i exitPos;
    sf::Vector2i playerPos;
    std::vector<sf::Vector2i> enemyPositions;

    void setUpInitialState();

    void setUpEnemyPositions();

    void setUpTiles();

public:
    std::vector<std::vector<GameTile *>> tiles;
    int gridLength;

    GameWorld();
};


#endif //SEALION_GAMEWORLD_H
