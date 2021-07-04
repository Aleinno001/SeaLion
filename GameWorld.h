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
    std::vector<sf::Vector2i> navyElementsPosition;
    std::vector<sf::Vector2i> enemyPositions;

    void setUpInitialState();

    void setUpEnemyPositions();

    void setUpTiles();

public:
    std::vector<std::vector<std::unique_ptr<GameTile>>> tiles;
    int gridLength;

    GameWorld();
};


#endif //SEALION_GAMEWORLD_H
