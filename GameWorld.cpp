//
// Created by davide on 04/07/21.
//

#include "GameWorld.h"

std::string GetCurrentWorkingDir() {
    char buff[FILENAME_MAX];
    GetCurrentDir(buff, FILENAME_MAX);
    std::string current_working_dir(buff);
    return current_working_dir;
}

GameWorld::GameWorld(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir,
                     std::vector<Fleet> &fleet, FactionType enemyFact, FactionType alliedFact, int grid,
                     sf::Vector2i exit, int &width, int &height, int &tileDim) : gridLength(grid),
                                                                                 enemyFaction(enemyFact),
                                                                                 alliedFaction(alliedFact),
                                                                                 exitPos(exit), mapHeight(height),
                                                                                 mapWidth(width) {
    setUpTiles(tileDim);
    setUpInitialState(numEnemySub, numEnemyBat, numEnemyCru, numEnemyDes, numEnemyAir, fleet);
}


void
GameWorld::setUpInitialState(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir,
                             std::vector<Fleet> &fleet) {
    exitPos = sf::Vector2i(1, 0);

    setUpAlliedFleet(fleet);
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

void GameWorld::setUpTiles(
        int &tileDim) { //FIXME Finire di aggiungere le tiles per poi migliorare l'uniformità della generazione
    tiles.clear();
    std::vector <std::unique_ptr<GameTile>> row;
    Dice dice(300);
    std::string currentDir = GetCurrentWorkingDir();
    std::string path = currentDir + "/../Res/Tiles/seaBlock.png";
    bool collision = false;
    int resTile;
    resTile = dice.roll(1);
    int fogTilesInARow = 0;
    int waveTilesInARow = 0;
    int whirlpoolTilesInARow = 0;
    int fogTilesInAColumn = resTile % 10 + 6;
    int whirlpoolTilesInAColumn = resTile % 5 + 2;
    int waveTilesInAColumn = resTile % 8 + 3;
    bool isFogCluster = false;
    bool isWaveCluster = false;
    bool isWhirlpoolCluster = false;
    int fogColumn;
    int waveColumn;
    int whirlpoolColumn;
    int maxFogCluster = resTile % 3 - 1;
    int maxWhirlpoolCluster = resTile % 4 - 1;
    int maxWaveCluster = resTile % 7 - 1;
    TileType tileType = TileType::Sea;
    bool isDirtCluster = false;
    int maxDirtCluster = resTile % 3 - 1;
    int dirtColumn;
    int dirtTilesInARow;
    int dirtTilesInAColumn = resTile % 5 + 4;
    try {
        for (int i = 0; i < (mapHeight / tileDim); i++) {
            row.clear();
            for (int j = 0; j < (mapWidth / tileDim); j++) {
                resTile = dice.roll(1);
                if (resTile == 299 && !isFogCluster && maxFogCluster != 0) {         //Nebbia
                    fogColumn = j;
                    fogTilesInARow = 4;
                    isFogCluster = true;
                    path = currentDir + "/../Res/Tiles/seaFoggyBlock.png";
                    tileType = TileType::Fog;
                    collision = false;
                } else if (isFogCluster && fogTilesInAColumn > 1 &&
                           j >= fogColumn - (resTile % 5) && j <= (fogColumn + fogTilesInARow + (resTile % 5))) {
                    path = currentDir + "/../Res/Tiles/seaFoggyBlock.png";
                    tileType = TileType::Fog;
                    collision = false;
                } else if (fogTilesInAColumn == 1 && j >= fogColumn - (resTile % 4) &&
                           j <= (fogColumn + 4 + (resTile % 4))) {
                    path = currentDir + "/../Res/Tiles/seaFoggyBlock.png";
                    tileType = TileType::Fog;
                    collision = false;
                } else if (resTile == 300 && !isWaveCluster && maxWaveCluster != 0) {      //Wave
                    waveColumn = j;
                    waveTilesInARow = 3;
                    isWaveCluster = true;
                    path = currentDir + "/../Res/Tiles/seaWaveBlock.png";
                    tileType = TileType::Wave;
                    collision = false;
                } else if (isWaveCluster && waveTilesInAColumn > 1 &&
                           j >= waveColumn - (resTile % 3) && j <= (waveColumn + waveTilesInARow + (resTile % 3))) {
                    path = currentDir + "/../Res/Tiles/seaWaveBlock.png";
                tileType = TileType::Wave;
                collision = false;
            } else if (waveTilesInAColumn == 1 && j >= waveColumn - (resTile % 3) &&
                       j <= (waveColumn + 3 + (resTile % 3))) {
                path = currentDir + "/../Res/Tiles/seaWaveBlock.png";
                tileType = TileType::Wave;
                collision = false;
            } else if (resTile == 298 && !isWhirlpoolCluster && maxWhirlpoolCluster != 0) {         //Whirlplool
                whirlpoolColumn = j;
                whirlpoolTilesInARow = 2;
                isWhirlpoolCluster = true;
                path = currentDir + "/../Res/Tiles/seaWhirlpoolBlock.png";
                tileType = TileType::Whirlpool;
                collision = false;
            } else if (isWhirlpoolCluster && whirlpoolTilesInAColumn > 1 &&
                       j >= whirlpoolColumn - (resTile % 3) &&
                       j <= (whirlpoolColumn + whirlpoolTilesInARow + (resTile % 3))) {
                path = currentDir + "/../Res/Tiles/seaWhirlpoolBlock.png";
                tileType = TileType::Whirlpool;
                collision = false;
            } else if (whirlpoolTilesInAColumn == 1 && j >= whirlpoolColumn - (resTile % 3) &&
                       j <= (whirlpoolColumn + 2 + (resTile % 3))) {
                path = currentDir + "/../Res/Tiles/seaWhirlpoolBlock.png";
                tileType = TileType::Whirlpool;
                collision = false;
            } else if (resTile == 297 && !isDirtCluster && maxDirtCluster != 0) {         //Dirt
                dirtColumn = j;
                dirtTilesInARow = 2;
                isDirtCluster = true;
                path = currentDir + "/../Res/Tiles/dirtBlock.png";
                tileType = TileType::Dirt;
                collision = true;
            } else if (isDirtCluster && dirtTilesInAColumn > 1 &&
                       j >= dirtColumn - (resTile % 3) && j <= (dirtColumn + dirtTilesInARow + (resTile % 3))) {

                path = currentDir + "/../Res/Tiles/dirtBlock.png";
                tileType = TileType::Dirt;
                collision = true;

                } else if (dirtTilesInAColumn == 1 && j >= dirtColumn - (resTile % 3) &&
                           j <= (dirtColumn + 3 + (resTile % 3))) {
                    path = currentDir + "/../Res/Tiles/dirtBlock.png";
                    tileType = TileType::Dirt;
                    collision = true;
                } else {
                    path = currentDir + "/../Res/Tiles/seaBlock.png";
                    tileType = TileType::Sea;
                    collision = false;
                }


                std::unique_ptr<GameTile> tile(
                        new GameTile(path, tileDim * j, tileDim * i, collision, false, tileType));
                row.push_back(std::move(tile));


            }
        if (isFogCluster) {
            fogTilesInARow = 8;
            fogTilesInAColumn -= 1;
        }
        if (fogTilesInAColumn == 0) {
            isFogCluster = false;
            maxFogCluster -= 1;
            fogTilesInAColumn = resTile % 10 + 5;
        }
        if (isWaveCluster) {
            waveTilesInARow = 6;
            waveTilesInAColumn -= 1;
        }
        if (waveTilesInAColumn == 0) {
            isWaveCluster = false;
            maxWaveCluster -= 1;
            waveTilesInAColumn = resTile % 8 + 3;
        }
        if (isWhirlpoolCluster) {
            whirlpoolTilesInARow = 6;
            whirlpoolTilesInAColumn -= 1;
        }
        if (whirlpoolTilesInAColumn == 0) {
            isWhirlpoolCluster = false;
            maxWhirlpoolCluster -= 1;
            whirlpoolTilesInAColumn = resTile % 5 + 2;
        }


        if (isDirtCluster) {
            dirtTilesInARow = 5;
            dirtTilesInAColumn -= 1;
        }
            if (dirtTilesInAColumn == 0) {
                isDirtCluster = false;
                maxDirtCluster -= 1;
                dirtTilesInAColumn = resTile % 5 + 4;
            }
            tiles.push_back(std::move(row));
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Please change the directory" << std::endl;

    }

}






void GameWorld::italianBattleshipInizializer(int &numBat, ShipFactory &enemyFactory,
                                             Dice &dice) { //impartisce l'ordine di inizializzare un certo numero di navi a seconda della fazione

    for (int i = 0; i < numBat; i++) {

        if (dice.roll(1) == 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::AndreaDoria));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 2) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::ImperatoreAugusto));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 3) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::VittorioVeneto));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::MichelangeloBuonarroti));
            enemyFleet.push_back(std::move(enemy));
        }
    }

}

void
GameWorld::setUpAlliedFleet(std::vector<Fleet> &fleet) {

    ShipFactory alliedFactory;

    for (auto iterator:fleet) {
        switch (iterator.type) {
            case ShipType::Battleship:
                for (int i = 0; i < iterator.num; i++)
                    alliedFleet.push_back(alliedFactory.createBattleship(iterator.name));
                break;
            case ShipType::Cruiser:
                for (int i = 0; i < iterator.num; i++)
                    alliedFleet.push_back(alliedFactory.createCruiser(iterator.name));
                break;
            case ShipType::AircraftCarrier:
                for (int i = 0; i < iterator.num; i++)
                    alliedFleet.push_back(alliedFactory.createAircraftCarrier(iterator.name));
                break;
            case ShipType::Destroyer:
                for (int i = 0; i < iterator.num; i++)
                    alliedFleet.push_back(alliedFactory.createDestroyer(iterator.name));
                break;
            case ShipType::Submarine:
                for (int i = 0; i < iterator.num; i++)
                    alliedFleet.push_back(alliedFactory.createSubmarine(iterator.name));
                break;
            default:                                                                //FIXME add exceptions
                break;
        }
    }

}

void GameWorld::submarineRandomizer(int &enemySub, Dice &subDice,
                                    ShipFactory &enemyFactory) { //impartisce l'ordine di inizializzare un certo numero di navi a seconda della fazione

    if (enemyFaction == FactionType::Japan) {

        japanSubmarineInizializer(enemySub, enemyFactory, subDice);

    } else if (enemyFaction == FactionType::Italy) {

        italianSubmarineInizializer(enemySub, enemyFactory, subDice);

    } else if (enemyFaction == FactionType::Usa) {

        usaSubmarineInizializer(enemySub, enemyFactory, subDice);

    } else {

        ukSubmarineInizializer(enemySub, enemyFactory, subDice);
    }


}

void GameWorld::battleshipRandomizer(int &enemyBat, Dice &batDice,
                                     ShipFactory &enemyFactory) { //impartisce l'ordine di inizializzare un certo numero di navi a seconda della fazione

    if (enemyFaction == FactionType::Japan) {

        japanBattleshipInizializer(enemyBat, enemyFactory, batDice);

    } else if (enemyFaction == FactionType::Italy) {

        italianBattleshipInizializer(enemyBat, enemyFactory, batDice);

    } else if (enemyFaction == FactionType::Usa) {

        usaBattleshipInizializer(enemyBat, enemyFactory, batDice);

    } else {

        ukBattleshipInizializer(enemyBat, enemyFactory, batDice);
    }



}

void GameWorld::cruiserRandomizer(int &enemyCru, Dice &cruDice,
                                  ShipFactory &enemyFactory) { //impartisce l'ordine di inizializzare un certo numero di navi a seconda della fazione

    if (enemyFaction == FactionType::Japan) {

        japanCruiserInizializer(enemyCru, enemyFactory, cruDice);

    } else if (enemyFaction == FactionType::Italy) {

        italianCruiserInizializer(enemyCru, enemyFactory, cruDice);

    } else if (enemyFaction == FactionType::Usa) {

        usaCruiserInizializer(enemyCru, enemyFactory, cruDice);

    } else {

        ukCruiserInizializer(enemyCru, enemyFactory, cruDice);
    }




}

void GameWorld::destroyerRandomizer(int &enemyDes, Dice &desDice,
                                    ShipFactory &enemyFactory) { //impartisce l'ordine di inizializzare un certo numero di navi a seconda della fazione

    if (enemyFaction == FactionType::Japan) {

        japanDestroyerInizializer(enemyDes, enemyFactory, desDice);

    } else if (enemyFaction == FactionType::Italy) {

        italianDestroyerInizializer(enemyDes, enemyFactory, desDice);

    } else if (enemyFaction == FactionType::Usa) {

        usaDestroyerInizializer(enemyDes, enemyFactory, desDice);

    } else {

        ukDestroyerInizializer(enemyDes, enemyFactory, desDice);
    }


}

void GameWorld::aircraftCarrierRandomizer(int &enemyAir, Dice &airDice,
                                          ShipFactory &enemyFactory) { //impartisce l'ordine di inizializzare un certo numero di navi a seconda della fazione

    if (enemyFaction == FactionType::Japan) {

        japanAircraftCarrierInizializer(enemyAir, enemyFactory, airDice);

    } else if (enemyFaction == FactionType::Italy) {

        italianAircraftCarrierInizializer(enemyAir, enemyFactory, airDice);

    } else if (enemyFaction == FactionType::Usa) {

        usaAircraftCarrierInizializer(enemyAir, enemyFactory, airDice);

    } else {

        ukAircraftCarrierInizializer(enemyAir, enemyFactory, airDice);
    }




}

void GameWorld::japanBattleshipInizializer(int &numBat, ShipFactory &enemyFactory,
                                           Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità



    for (int i = 0; i < numBat; i++) {
        if (dice.roll(1) == 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Kongo));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 2) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Musashi));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 3) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Yamato));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::ISE));
            enemyFleet.push_back(std::move(enemy));
        }
    }








}


void GameWorld::japanSubmarineInizializer(int &numSub, ShipFactory &enemyFactory,
                                          Dice &dice) { //estrae in maniera casuale un modello navale con ugual probabilità

    for (int i = 0; i < numSub; i++) {
        if (dice.roll(1) > 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::I400));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::typeb1));
            enemyFleet.push_back(std::move(enemy));
        }
    }


}


void GameWorld::japanDestroyerInizializer(int &numDes, ShipFactory &enemyFactory,
                                          Dice &dice) { //estrae in maniera casuale un modello navale con ugual probabilità


    for (int i = 0; i < numDes; i++) {
        if (dice.roll(1) == 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Akizuki));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 2) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Fubuki));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Yukikaze));
            enemyFleet.push_back(std::move(enemy));
        }
    }


}


void GameWorld::japanAircraftCarrierInizializer(int &numAir, ShipFactory &enemyFactory,
                                                Dice &dice) { //estrae in maniera casuale un modello navale con ugual probabilità


    for (int i = 0; i < numAir; i++) {
        if (dice.roll(1) > 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::Hiryu));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::Tahio));
            enemyFleet.push_back(std::move(enemy));
        }
    }






}


void GameWorld::japanCruiserInizializer(int &numCru, ShipFactory &enemyFactory,
                                        Dice &dice) { //estrae in maniera casuale un modello navale con ugual probabilità


    for (int i = 0; i < numCru; i++) {
        if (dice.roll(1) == 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Takao));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 2) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::IsuzuNagara));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Ijn));
            enemyFleet.push_back(std::move(enemy));
        }
    }









}

void GameWorld::usaBattleshipInizializer(int &numBat, ShipFactory &enemyFactory,
                                         Dice &dice) {   //estrae in maniera casuale un modello navale con ugual probabilità

    for (int i = 0; i < numBat; i++) {


        if (dice.roll(1) == 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::NewYork));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 2) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Arizona));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 3) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::NorthCarolina));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Montana));
            enemyFleet.push_back(std::move(enemy));
        }
    }

}

void GameWorld::ukBattleshipInizializer(int &numBat, ShipFactory &enemyFactory,
                                        Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità

    for (int i = 0; i < numBat; i++) {

        if (dice.roll(1) == 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Dreadnought));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 2) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::IronDuke));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 3) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Hood));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Lion));
            enemyFleet.push_back(std::move(enemy));
        }
    }

}

void GameWorld::italianCruiserInizializer(int &numCru, ShipFactory &enemyFactory,
                                          Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità

    for (int i = 0; i < numCru; i++) {

        if (dice.roll(1) == 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::AlbertoDiGiussano));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 2) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Trento));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Gorizia));
            enemyFleet.push_back(std::move(enemy));
        }
    }

}

void GameWorld::usaCruiserInizializer(int &numCru, ShipFactory &enemyFactory,
                                      Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità

    for (int i = 0; i < numCru; i++) {


        if (dice.roll(1) == 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::StLouis));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 2) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::NewOrleans));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Alaska));
            enemyFleet.push_back(std::move(enemy));
        }
    }

}

void GameWorld::ukCruiserInizializer(int &numCru, ShipFactory &enemyFactory,
                                     Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità

    for (int i = 0; i < numCru; i++) {
        if (dice.roll(1) == 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Danae));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 2) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Belfast));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Tiger59));
            enemyFleet.push_back(std::move(enemy));
        }
    }

}

void GameWorld::italianDestroyerInizializer(int &numDes, ShipFactory &enemyFactory,
                                            Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità

    for (int i = 0; i < numDes; i++) {


        if (dice.roll(1) == 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Impavido));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 2) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Leone));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::PaoloEmilio));
            enemyFleet.push_back(std::move(enemy));
        }
    }

}

void GameWorld::usaDestroyerInizializer(int &numDes, ShipFactory &enemyFactory,
                                        Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità

    for (int i = 0; i < numDes; i++) {


        if (dice.roll(1) == 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Mahan));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 2) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Fletcher));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Sims));
            enemyFleet.push_back(std::move(enemy));
        }
    }

}

void GameWorld::ukDestroyerInizializer(int &numDes, ShipFactory &enemyFactory,
                                       Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità

    for (int i = 0; i < numDes; i++) {

        if (dice.roll(1) == 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Campbelltown));
            enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 2) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Gallant));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Jutland));
            enemyFleet.push_back(std::move(enemy));
        }
    }

}

void GameWorld::italianSubmarineInizializer(int &numSub, ShipFactory &enemyFactory,
                                            Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità

    for (int i = 0; i < numSub; i++) {
        if (dice.roll(1) > 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::DaVinci));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Papa));
            enemyFleet.push_back(std::move(enemy));
        }
    }

}

void GameWorld::usaSubmarineInizializer(int &numSub, ShipFactory &enemyFactory,
                                        Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità
    for (int i = 0; i < numSub; i++) {
        if (dice.roll(1) > 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Gato));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Narwhal));
            enemyFleet.push_back(std::move(enemy));
        }
    }

}

void GameWorld::ukSubmarineInizializer(int &numSub, ShipFactory &enemyFactory,
                                       Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità
    for (int i = 0; i < numSub; i++) {
        if (dice.roll(1) > 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Triton));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Trenchant));
            enemyFleet.push_back(std::move(enemy));
        }
    }

}

void GameWorld::italianAircraftCarrierInizializer(int &numAir, ShipFactory &enemyFactory,
                                                  Dice &dice) { //estrae in maniera casuale un modello navale con ugual probabilità
    for (int i = 0; i < numAir; i++) {


        if (dice.roll(1) > 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::GiuseppeGaribaldi));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::GiuseppeGaribaldi));
            enemyFleet.push_back(std::move(enemy));
        }
    }

}

void GameWorld::usaAircraftCarrierInizializer(int &numAir, ShipFactory &enemyFactory,
                                              Dice &dice) { //estrae in maniera casuale un modello navale con ugual probabilità

    for (int i = 0; i < numAir; i++) {

        if (dice.roll(1) > 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::Midway));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::Ranger));
            enemyFleet.push_back(std::move(enemy));
        }
    }

}

void GameWorld::ukAircraftCarrierInizializer(int &numAir, ShipFactory &enemyFactory,
                                             Dice &dice) { //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numAir; i++) {

            if (dice.roll(1) > 1) {
                std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::ArkRoyal));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::Indomitable));
                enemyFleet.push_back(std::move(enemy));
            }
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;

    }

}

FactionType GameWorld::getEnemyFaction() const {
    return enemyFaction;
}

FactionType GameWorld::getAlliedFaction() const {
    return alliedFaction;
}

const sf::Vector2i &GameWorld::getExitPos() const {
    return exitPos;
}

const std::list<std::unique_ptr<WarShip>> &GameWorld::getAlliedFleet() const {
    return alliedFleet;
}

const std::list<std::unique_ptr<WarShip>> &GameWorld::getEnemyFleet() const {
    return enemyFleet;
}

const std::vector<std::vector<std::unique_ptr<GameTile>>> &GameWorld::getTiles() const {
    return tiles;
}

int GameWorld::getGridLength() const {
    return gridLength;
}

int GameWorld::getMapWidth() const {
    return mapWidth;
}

int GameWorld::getMapHeight() const {
    return mapHeight;
}

void GameWorld::setEnemyFaction(FactionType enemyFaction) {
    GameWorld::enemyFaction = enemyFaction;
}

void GameWorld::setAlliedFaction(FactionType alliedFaction) {
    GameWorld::alliedFaction = alliedFaction;
}

void GameWorld::setExitPos(const sf::Vector2i &exitPos) {
    GameWorld::exitPos = exitPos;
}

void GameWorld::setGridLength(int gridLength) {
    GameWorld::gridLength = gridLength;
}

void GameWorld::setMapWidth(int mapWidth) {
    GameWorld::mapWidth = mapWidth;
}

void GameWorld::setMapHeight(int mapHeight) {
    GameWorld::mapHeight = mapHeight;
}





