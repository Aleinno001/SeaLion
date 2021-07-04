//
// Created by davide on 04/07/21.
//

#include "GameWorld.h"

GameWorld::GameWorld() {
    gridLength = 8;
    setUpInitialState();
}

void GameWorld::setUpInitialState() {
    exitPos = sf::Vector2i(1, 0);
    playerPos = sf::Vector2i(gridLength - 1, gridLength - 1);
    setUpEnemyPositions();
}

void GameWorld::setUpEnemyPositions() {
    enemyPositions.clear();
    enemyPositions.push_back(sf::Vector2i(0, 2));
    enemyPositions.push_back(sf::Vector2i(6, 0));
    enemyPositions.push_back(sf::Vector2i(2, 7));
}

void GameWorld::setUpTiles() {
    tiles.clear();
    std::vector<GameTile *> firstRow;
    firstRow.push_back(new GameTile("", 0, 0, false, false)); //TODO aggiungere tile
    firstRow.push_back(new GameTile("", 50, 0, false, false)); //TODO aggiungere tile
    firstRow.push_back(new GameTile("", 100, 0, false, false)); //TODO aggiungere tile
    firstRow.push_back(new GameTile("", 150, 0, false, false)); //TODO aggiungere tile
    firstRow.push_back(new GameTile("", 200, 0, false, false)); //TODO aggiungere tile
    firstRow.push_back(new GameTile("", 250, 0, false, false)); //TODO aggiungere tile
    firstRow.push_back(new GameTile("", 300, 0, false, false)); //TODO aggiungere tile
    firstRow.push_back(new GameTile("", 350, 0, false, false)); //TODO aggiungere tile
    tiles.push_back(firstRow);
    std::vector<GameTile *> secondRow;
    secondRow.push_back(new GameTile("", 0, 0, false, false)); //TODO aggiungere tile
    secondRow.push_back(new GameTile("", 50, 0, false, false)); //TODO aggiungere tile
    secondRow.push_back(new GameTile("", 100, 0, false, false)); //TODO aggiungere tile
    secondRow.push_back(new GameTile("", 150, 0, false, false)); //TODO aggiungere tile
    secondRow.push_back(new GameTile("", 200, 0, false, false)); //TODO aggiungere tile
    secondRow.push_back(new GameTile("", 250, 0, false, false)); //TODO aggiungere tile
    secondRow.push_back(new GameTile("", 300, 0, false, false)); //TODO aggiungere tile
    secondRow.push_back(new GameTile("", 350, 0, false, false)); //TODO aggiungere tile
    tiles.push_back(secondRow);

}
