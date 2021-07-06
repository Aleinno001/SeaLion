//
// Created by davide on 04/07/21.
//

#include "GameWorld.h"

GameWorld::GameWorld(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir)
        : gridLength(8) {
    setUpInitialState(numEnemySub, numEnemyBat, numEnemyCru, numEnemyDes, numEnemyAir);
}
//TODO Rimuovere i row pointer e sistemare l'implementazione di Game Word

void
GameWorld::setUpInitialState(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir) {
    exitPos = sf::Vector2i(1, 0);
    //TODO iniziallizare la lista di navi alleate e nemiche
    setUpAlliedFleet();
    setUpEnemyFleet(numEnemySub, numEnemyBat, numEnemyCru, numEnemyDes, numEnemyAir);
}

void
GameWorld::setUpEnemyFleet(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir) {

    ShipFactory enemyFactory;

    Dice subDice(2);


    for (int i = 0; i < numEnemySub; i++) {

        switch (enemyFaction) {
            case "Japan":

                if (subDice.roll(1) > 1)
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::I400));
                else
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::typeb1));
                enemyFleet.push_back(std::move(enemy));

                break;

            case "Italy":

                if (subDice.roll(1) > 1)
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::DaVinci));
                else

                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Papa));
                enemyFleet.push_back(std::move(enemy));

                break;

            case "Usa":

                if (subDice.roll(1) > 1)
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Gato));
                else
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Narwhal));
                enemyFleet.push_back(std::move(enemy));
                break;

            case "Uk":

                if (subDice.roll(1) > 1)
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Triton));
                else
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Trenchant));
                enemyFleet.push_back(std::move(enemy));

                break;
            default:
                //TODO lancia eccezione
                break;

        }


    }


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

    std::vector<std::unique_ptr<GameTile>> row;
    Dice dice(6);
    std::string path;
    bool collision = false;
    for (int i = 1; i < (mapHeight / 30); i++) {
        row.clear();
        for (int j = 1; j < (mapWidth / 30); j++) {
            int resTile = dice.roll(1);
            if (resTile >= 1 && resTile < 5) {
                path = "/Res/Tiles/seaBlock";
            } else if (resTile == 5) {
                path = "/Res/Tiles/seaFoggyBlock";
                collision = true;
            } else {
                path = "/Res/Tiles/seaWaveBlock";
            }
            std::unique_ptr<GameTile> tile(new GameTile(path, 30 * (i - 1), 30 * (j - 1), collision, false));
            row.push_back(std::move(tile));
        }
        tiles.push_back(row);
    }

}

void
GameWorld::setUpAlliedFleet() {                     //FIXME da rifare tutto

    ShipFactory alliedFactory;
    for (int i = 0; i < numAlliedSub; i++) {
        alliedFleet.push_back(alliedFactory.createSubmarine());
    }
    for (int i = 0; i < numAlliedBat; i++) {
        alliedFleet.push_back(alliedFactory.createBattleship());
    }
    for (int i = 0; i < numAlliedCru; i++) {
        alliedFleet.push_back(alliedFactory.createCruiser());
    }
    for (int i = 0; i < numAlliedDes; i++) {
        alliedFleet.push_back(alliedFactory.createDestroyer());
    }
    for (int i = 0; i < numAlliedAir; i++) {
        alliedFleet.push_back(alliedFactory.createAircraftCarrier());
    }
}


