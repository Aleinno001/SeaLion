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
    submarineRandomizer(numEnemySub, subDice, enemyFactory);
    Dice batDice(4);
    battleshipRandomizer(numEnemyBat, batDice, enemyFactory);
    Dice tripleDice(3);
    cruiserRandomizer(numEnemyCru, tripleDice, enemyFactory);

    destroyerRandomizer(numEnemyDes, tripleDice, enemyFactory);

    aircraftCarrierRandomizer(numEnemyAir, subDice, enemyFactory);


}

void
GameWorld::setUpTiles() { //FIXME Finire di aggiungere le tiles per poi migliorare l'uniformità della generazione
    tiles.clear();
    std::vector<std::unique_ptr<GameTile>> row;
    Dice dice(6);
    std::string path = "";
    bool collision = false;
    int resTile;
    int firstChangeTileValue;
    int secondChangeTileValue;
    for (int i = 1; i < (mapHeight / 30); i++) {
        row.clear();
        for (int j = 1; j < (mapWidth / 30); j++) {
            resTile = dice.roll(1);
            firstChangeTileValue = 5;
            secondChangeTileValue = 6;
            if (path == "/Res/Tiles/seaFoggyBlock") {
                firstChangeTileValue = 3;
                secondChangeTileValue = 6;
            } else if (path == "/Res/Tiles/seaWaveBlock") {
                firstChangeTileValue = 3;
                secondChangeTileValue = 4;
            }
            if (resTile >= 1 && resTile < firstChangeTileValue) {
                path = "/Res/Tiles/seaBlock";   //TODO gestire eccezioni per il path dei file
            } else if (resTile >= firstChangeTileValue && resTile < secondChangeTileValue) {
                path = "/Res/Tiles/seaFoggyBlock";
                collision = true;  //FIXME da cambiare la collisione della nebbia(tenere solo per testare)
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
GameWorld::setUpAlliedFleet() {    //FIXME da rifare tutto

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

void GameWorld::submarineRandomizer(int &enemySub, Dice &subDice, ShipFactory &enemyFactory) {

    for (int i = 0; i < enemySub; i++) {

        switch (enemyFaction) {
            case "Japan":

                if (subDice.roll(1) > 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::I400));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::typeb1));
                    enemyFleet.push_back(std::move(enemy));
                }

                break;

            case "Italy":

                if (subDice.roll(1) > 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::DaVinci));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Papa));
                    enemyFleet.push_back(std::move(enemy));
                }


                break;

            case "Usa":

                if (subDice.roll(1) > 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Gato));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Narwhal));
                    enemyFleet.push_back(std::move(enemy));
                }
                break;

            case "Uk":

                if (subDice.roll(1) > 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Triton));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Trenchant));
                    enemyFleet.push_back(std::move(enemy));
                }

                break;
            default:
                //TODO lancia eccezione
                break;

        }


    }
}

void GameWorld::battleshipRandomizer(int &enemyBat, Dice &batDice, ShipFactory &enemyFaction) {

}

void GameWorld::cruiserRandomizer(int &enemyCru, Dice &cruDice, ShipFactory &enemyFaction) {

}

void GameWorld::destroyerRandomizer(int &enemyDes, Dice &desDice, ShipFactory &enemyFaction) {

}

void GameWorld::aircraftCarrierRandomizer(int &enemyAir, Dice &airDice, ShipFactory &enemyFaction) {

}


