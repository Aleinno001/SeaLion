//
// Created by davide on 04/07/21.
//

#include "GameWorld.h"

GameWorld::GameWorld() : gridLength(8) {
    setUpInitialState();
}
//TODO Rimuovere i row pointer e sistemare l'implementazione di Game Word

void GameWorld::setUpInitialState() {
    exitPos = sf::Vector2i(1, 0);
    //TODO iniziallizare la lista di navi alleate e nemiche
    setUpAlliedFleet();
    setUpEnemyFleet();
}

void GameWorld::setUpEnemyFleet() {

}

void
GameWorld::setUpTiles() { //FIXME Trovare un metodo migliore per inizializzare la mappa , più randomica e più automatizzata
    tiles.clear();
    /*
    std::string pathSea = "/Res/Tiles/seaBlock"; //TODO Inserire un eccezione e forse passare tra i parametri di ingresso al metodo il path (potrebbe lanciare un eccezione se non trova la risorsa)
    std::vector<std::unique_ptr<GameTile>> firstRow;
    std::unique_ptr<GameTile> firstTile(
            new GameTile(pathSea, 0, 0, false, false));  //TODO cercare un modo di non usare costanti codeSmell
    firstRow.push_back(std::move(firstTile));
    std::unique_ptr<GameTile> secondTile(
            new GameTile(pathSea, 50, 0, false, false));   //TODO le misure della singola tile non è 50 ma 30
    firstRow.push_back(std::move(secondTile));
    std::unique_ptr<GameTile> thirdTile(new GameTile(pathSea, 100, 0, false, false));
    firstRow.push_back(std::move(thirdTile));
    std::unique_ptr<GameTile> fourthTile(new GameTile(pathSea, 150, 0, false, false));
    firstRow.push_back(std::move(fourthTile));
    std::unique_ptr<GameTile> fifthTile(new GameTile(pathSea, 200, 0, false, false));
    firstRow.push_back(std::move(fifthTile));
    std::unique_ptr<GameTile> sixtyTile(new GameTile(pathSea, 250, 0, false, false));
    firstRow.push_back(std::move(sixtyTile));
    std::unique_ptr<GameTile> seventhTile(new GameTile(pathSea, 300, 0, false, false));
    firstRow.push_back(std::move(seventhTile));
    std::unique_ptr<GameTile> eightyTile(new GameTile(pathSea, 350, 0, false, false));
    firstRow.push_back(std::move(eightyTile));
    tiles.push_back(firstRow);
    std::vector<std::unique_ptr<GameTile>> secondRow;

    secondRow.push_back(new GameTile("", 0, 0, false, false));
    secondRow.push_back(new GameTile("", 50, 0, false, false));
    secondRow.push_back(new GameTile("", 100, 0, false, false));
    secondRow.push_back(new GameTile("", 150, 0, false, false));
    secondRow.push_back(new GameTile("", 200, 0, false, false));
    secondRow.push_back(new GameTile("", 250, 0, false, false));
    secondRow.push_back(new GameTile("", 300, 0, false, false));
    secondRow.push_back(new GameTile("", 350, 0, false, false));
    tiles.push_back(secondRow);
*/

    for (int i = 1; i < (mapHegith / 30); i++) {
        for (int j = 1; j < (mapWidth / 30); j++) {
            worldMap.emplace();
        }
    }

}

void GameWorld::setUpAlliedFleet() {

}


