//
// Created by alessandro on 04/07/21.
//
#include "GameWorld.h"
GameWorld::GameWorld(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir,std::vector<Fleet> &fleet, FactionType enemyFact, FactionType alliedFact, int grid,sf::Vector2i exit, int &width, int &height, int &tileDim) : tileDim(tileDim) {
    try {
        gridLength = grid;
        enemyFaction = enemyFact;
        exitPos = exit;
        mapHeight = height;
        mapWidth = width;
        alliedFaction = alliedFact;
        setUpTiles(tileDim);
        setUpInitialState(numEnemySub, numEnemyBat, numEnemyCru, numEnemyDes, numEnemyAir, fleet);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Please change Warship type" << std::endl;
    }
}
void GameWorld::setUpInitialState(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir,std::vector<Fleet> &fleet) {
    setUpEnemyFleet(numEnemySub, numEnemyBat, numEnemyCru, numEnemyDes, numEnemyAir);
    setUpAlliedFleet(fleet);
}
void GameWorld::setUpEnemyFleet(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir) {
    std::shared_ptr<ShipFactory> enemyFactory(new ShipFactory(0, 0));
    Dice subDice(2, 23);
    submarineRandomizer(numEnemySub, subDice, enemyFactory);
    Dice batDice(4, 345);
    battleshipRandomizer(numEnemyBat, batDice, enemyFactory);
    Dice tripleDice(3, 52);
    cruiserRandomizer(numEnemyCru, tripleDice, enemyFactory);
    destroyerRandomizer(numEnemyDes, tripleDice, enemyFactory);
    aircraftCarrierRandomizer(numEnemyAir, subDice, enemyFactory);
}
void GameWorld::setUpTiles(int &tileDim) {
    tiles.clear();
    std::vector<std::shared_ptr<GameTile>> row;
    Dice dice(300, 8734);
    std::string path = "seaBlock.png";
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
                    path = "seaFoggyBlock.png";
                    tileType = TileType::Fog;
                    collision = false;
                } else if (isFogCluster && fogTilesInAColumn > 1 &&
                           j >= fogColumn - (resTile % 5) && j <= (fogColumn + fogTilesInARow + (resTile %5))) { //Permette la generazione di cluster di nebbia per ighe
                    path = "seaFoggyBlock.png";
                    tileType = TileType::Fog;
                    collision = false;
                } else if (fogTilesInAColumn == 1 && j >= fogColumn - (resTile % 4) && j <= (fogColumn + 4 +(resTile % 4))) {  //Permette la generazione di cluster di nebbia per colonne
                    path = "seaFoggyBlock.png";
                    tileType = TileType::Fog;
                    collision = false;
                } else if (resTile == 300 && !isWaveCluster && maxWaveCluster != 0 &&isInStrip(i, tileDim)) {      //Wave
                    waveColumn = j;
                    waveTilesInARow = 3;
                    isWaveCluster = true;
                    path = "seaWaveBlock.png";
                    tileType = TileType::Wave;
                    collision = false;
                } else if (isWaveCluster && waveTilesInAColumn > 1 &&j >= waveColumn - (resTile % 3) && j <= (waveColumn + waveTilesInARow + (resTile % 3)) &&isInStrip(i, tileDim)) {  //Permette la generazione di cluster di onde per righe
                    path = "seaWaveBlock.png";
                    tileType = TileType::Wave;
                    collision = false;
                } else if (waveTilesInAColumn == 1 && j >= waveColumn - (resTile % 3) &&j <= (waveColumn + 3 + (resTile % 3)) &&isInStrip(i, tileDim)) {   //Permette la generazione di cluster di onde per colonna
                    path = "seaWaveBlock.png";
                    tileType = TileType::Wave;
                    collision = false;
                } else if (resTile == 298 && !isWhirlpoolCluster && maxWhirlpoolCluster != 0 &&isInStrip(i, tileDim)) {         //Whirlplool
                    whirlpoolColumn = j;
                    whirlpoolTilesInARow = 2;
                    isWhirlpoolCluster = true;
                    path = "seaWhirlpoolBlock.png";
                    tileType = TileType::Whirlpool;
                    collision = false;
                } else if (isWhirlpoolCluster && whirlpoolTilesInAColumn > 1 &&j >= whirlpoolColumn - (resTile % 3) &&j <= (whirlpoolColumn + whirlpoolTilesInARow + (resTile % 3)) &&isInStrip(i, tileDim)) {  //Permette la generazione di cluster di mulinelli per righe
                    path = "seaWhirlpoolBlock.png";
                    tileType = TileType::Whirlpool;
                    collision = false;
                } else if (whirlpoolTilesInAColumn == 1 && j >= whirlpoolColumn - (resTile % 3) &&j <= (whirlpoolColumn + 2 + (resTile % 3)) &&isInStrip(i, tileDim)) {    //Permette la generazione di cluster di mulinelli per colonna
                    path = "seaWhirlpoolBlock.png";
                    tileType = TileType::Whirlpool;
                    collision = false;
                } else if (resTile == 297 && !isDirtCluster && maxDirtCluster != 0 &&isInStrip(i, tileDim)) {         //Dirt
                    dirtColumn = j;
                    dirtTilesInARow = 2;
                    isDirtCluster = true;
                    path = "dirtBlock.png";
                    tileType = TileType::Dirt;
                    collision = true;
                } else if (isDirtCluster && dirtTilesInAColumn > 1 &&j >= dirtColumn - (resTile % 3) && j <= (dirtColumn + dirtTilesInARow + (resTile % 3)) &&isInStrip(i, tileDim)) {  //Permette la generazione di cluster di terra per righe
                    path = "dirtBlock.png";
                    tileType = TileType::Dirt;
                    collision = true;
                } else if (dirtTilesInAColumn == 1 && j >= dirtColumn - (resTile % 3) &&j <= (dirtColumn + 3 + (resTile % 3)) &&isInStrip(i, tileDim)) {  //Permette la generazione di cluster di terra per colonne
                    path = "dirtBlock.png";
                    tileType = TileType::Dirt;
                    collision = true;
                } else {
                    path = "seaBlock.png";
                    tileType = TileType::Sea;
                    collision = false;
                }
                std::unique_ptr<GameTile> tile(new GameTile(path, tileDim * j, tileDim * i, collision, false, tileType));
                row.push_back(std::move(tile));
            }
            //Aggiorna lo stato dei cluster
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
            tiles.push_back(row);
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Please change the directory" << std::endl;
    }
}
void GameWorld::italianBattleshipInizializer(int &numBat, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) { //impartisce l'ordine di inizializzare un certo numero di navi a seconda della fazione
    try {
        for (int i = 0; i < numBat; i++) {
            if (dice.roll(1) == 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::AndreaDoria, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 2) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::ImperatoreAugusto, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
        } else if (dice.roll(1) == 3) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::VittorioVeneto, mapHeight, mapWidth));
            enemyFleet.push_back(std::move(enemy));
        } else {
                std::shared_ptr<WarShip> enemy(
                        enemyFactory->createBattleship(ModelType::MichelangeloBuonarroti, mapHeight, mapWidth));
            enemyFleet.push_back(std::move(enemy));
        }
    }
} catch (std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
}
}
void GameWorld::setUpAlliedFleet(std::vector<Fleet> &fleet) {
    ShipFactory alliedFactory(0, 0);
    for (auto iterator:fleet) {
        switch (iterator.type) {
            case ShipType::Battleship:
                for (int i = 0; i < iterator.num; i++)
                    alliedFleet.push_back(alliedFactory.createAlliedBattleship(iterator.name, mapHeight, mapWidth));
                break;
            case ShipType::Cruiser:
                for (int i = 0; i < iterator.num; i++)
                    alliedFleet.push_back(alliedFactory.createAlliedCruiser(iterator.name, mapHeight, mapWidth));
                break;
            case ShipType::AircraftCarrier:
                for (int i = 0; i < iterator.num; i++)
                    alliedFleet.push_back(alliedFactory.createAlliedAircraftCarrier(iterator.name, mapHeight, mapWidth));
                break;
            case ShipType::Destroyer:
                for (int i = 0; i < iterator.num; i++)
                    alliedFleet.push_back(alliedFactory.createAlliedDestroyer(iterator.name, mapHeight, mapWidth));
                break;
            case ShipType::Submarine:
                for (int i = 0; i < iterator.num; i++)
                    alliedFleet.push_back(alliedFactory.createAlliedSubmarine(iterator.name, mapHeight, mapWidth));
                break;
            default:
                throw std::runtime_error("Invalid Warship type!");
        }
    }
}
void GameWorld::submarineRandomizer(int &enemySub, Dice &subDice,const std::shared_ptr<ShipFactory>& enemyFactory) { //impartisce l'ordine di inizializzare un certo numero di navi a seconda della fazione
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
void GameWorld::battleshipRandomizer(int &enemyBat, Dice &batDice,const std::shared_ptr<ShipFactory>& enemyFactory) { //impartisce l'ordine di inizializzare un certo numero di navi a seconda della fazione
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
void GameWorld::cruiserRandomizer(int &enemyCru, Dice &cruDice,const std::shared_ptr<ShipFactory>& enemyFactory) { //impartisce l'ordine di inizializzare un certo numero di navi a seconda della fazione
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
void GameWorld::destroyerRandomizer(int &enemyDes, Dice &desDice,const std::shared_ptr<ShipFactory>& enemyFactory) { //impartisce l'ordine di inizializzare un certo numero di navi a seconda della fazione
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
void GameWorld::aircraftCarrierRandomizer(int &enemyAir, Dice &airDice,const std::shared_ptr<ShipFactory>& enemyFactory) { //impartisce l'ordine di inizializzare un certo numero di navi a seconda della fazione
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
void GameWorld::japanBattleshipInizializer(int &numBat, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numBat; i++) {
            if (dice.roll(1) == 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::Kongo, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 2) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::Musashi, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 3) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::Yamato, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::ISE, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            }
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
void GameWorld::japanSubmarineInizializer(int &numSub, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) { //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numSub; i++) {
            if (dice.roll(1) > 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createSubmarine(ModelType::I400, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createSubmarine(ModelType::typeb1, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            }
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
void GameWorld::japanDestroyerInizializer(int &numDes, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) { //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numDes; i++) {
            if (dice.roll(1) == 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createDestroyer(ModelType::Akizuki, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 2) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createDestroyer(ModelType::Fubuki, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createDestroyer(ModelType::Yukikaze, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            }
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
void GameWorld::japanAircraftCarrierInizializer(int &numAir, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) { //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numAir; i++) {
            if (dice.roll(1) > 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createAircraftCarrier(ModelType::Hiryu, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createAircraftCarrier(ModelType::Tahio, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            }
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
void GameWorld::japanCruiserInizializer(int &numCru, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) { //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numCru; i++) {
            if (dice.roll(1) == 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createCruiser(ModelType::Takao, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 2) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createCruiser(ModelType::IsuzuNagara, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
        } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createCruiser(ModelType::Ijn, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
        }
    }
} catch (std::runtime_error &e) {
    std::cerr << e.what() << std::endl;

}
}
void GameWorld::usaBattleshipInizializer(int &numBat, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) {   //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numBat; i++) {
            if (dice.roll(1) == 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::NewYork, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 2) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::Arizona, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 3) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::NorthCarolina, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::Montana, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            }
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
void GameWorld::ukBattleshipInizializer(int &numBat, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numBat; i++) {
            if (dice.roll(1) == 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::Dreadnought, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 2) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::IronDuke, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 3) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::Hood, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createBattleship(ModelType::Lion, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            }
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
void GameWorld::italianCruiserInizializer(int &numCru, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numCru; i++) {
            if (dice.roll(1) == 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createCruiser(ModelType::AlbertoDiGiussano, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 2) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createCruiser(ModelType::Trento, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
        } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createCruiser(ModelType::Gorizia, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
        }
    }
} catch (std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
}
}
void GameWorld::usaCruiserInizializer(int &numCru, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numCru; i++) {
            if (dice.roll(1) == 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createCruiser(ModelType::StLouis, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 2) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createCruiser(ModelType::NewOrleans, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createCruiser(ModelType::Alaska, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            }
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
void GameWorld::ukCruiserInizializer(int &numCru, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numCru; i++) {
            if (dice.roll(1) == 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createCruiser(ModelType::Danae, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 2) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createCruiser(ModelType::Belfast, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createCruiser(ModelType::Tiger59, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            }
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
void GameWorld::italianDestroyerInizializer(int &numDes, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numDes; i++) {
            if (dice.roll(1) == 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createDestroyer(ModelType::Impavido, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 2) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createDestroyer(ModelType::Leone, mapHeight, mapWidth));
            enemyFleet.push_back(std::move(enemy));
        } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createDestroyer(ModelType::PaoloEmilio, mapHeight, mapWidth));
            enemyFleet.push_back(std::move(enemy));
        }
    }
} catch (std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
}
}
void GameWorld::usaDestroyerInizializer(int &numDes, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numDes; i++) {
            if (dice.roll(1) == 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createDestroyer(ModelType::Mahan, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 2) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createDestroyer(ModelType::Fletcher, mapHeight, mapWidth));
            enemyFleet.push_back(std::move(enemy));
        } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createDestroyer(ModelType::Sims, mapHeight, mapWidth));
            enemyFleet.push_back(std::move(enemy));
        }
    }
} catch (std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
}
}
void GameWorld::ukDestroyerInizializer(int &numDes, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numDes; i++) {
            if (dice.roll(1) == 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createDestroyer(ModelType::Campbelltown, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else if (dice.roll(1) == 2) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createDestroyer(ModelType::Gallant, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createDestroyer(ModelType::Jutland, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            }
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
void GameWorld::italianSubmarineInizializer(int &numSub, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numSub; i++) {
            if (dice.roll(1) > 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createSubmarine(ModelType::DaVinci, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createSubmarine(ModelType::Papa, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            }
    }
} catch (std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
}
}
void GameWorld::usaSubmarineInizializer(int &numSub, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numSub; i++) {
            if (dice.roll(1) > 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createSubmarine(ModelType::Gato, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createSubmarine(ModelType::Narwhal, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            }
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
void GameWorld::ukSubmarineInizializer(int &numSub, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) {  //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numSub; i++) {
            if (dice.roll(1) > 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createSubmarine(ModelType::Triton, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createSubmarine(ModelType::Trenchant, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            }
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
void GameWorld::italianAircraftCarrierInizializer(int &numAir, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) { //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numAir; i++) {
            if (dice.roll(1) > 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createAircraftCarrier(ModelType::GiuseppeGaribaldi, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createAircraftCarrier(ModelType::Cavour, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            }
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
void GameWorld::usaAircraftCarrierInizializer(int &numAir, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) { //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numAir; i++) {
            if (dice.roll(1) > 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createAircraftCarrier(ModelType::Midway, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createAircraftCarrier(ModelType::FranklinDRoosevelt, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            }
        }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
void GameWorld::ukAircraftCarrierInizializer(int &numAir, std::shared_ptr<ShipFactory> enemyFactory,Dice &dice) { //estrae in maniera casuale un modello navale con ugual probabilità
    try {
        for (int i = 0; i < numAir; i++) {
            if (dice.roll(1) > 1) {
                std::shared_ptr<WarShip> enemy(enemyFactory->createAircraftCarrier(ModelType::ArkRoyal, mapHeight, mapWidth));
                enemyFleet.push_back(std::move(enemy));
            } else {
                std::shared_ptr<WarShip> enemy(enemyFactory->createAircraftCarrier(ModelType::Indomitable, mapHeight, mapWidth));
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
const std::vector<std::vector<std::shared_ptr<GameTile>>> &GameWorld::getTiles() const {
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
bool GameWorld::isInStrip(int i, int tileDim) {
    return i > 0.28 * (mapHeight / tileDim) && i < mapHeight / tileDim - 0.28 * (mapHeight / tileDim);
}
int GameWorld::getTileDim() const {
    return tileDim;
}

GameWorld::GameWorld(int height,int width,int tileDim,int numAlliedShips,std::string specialTile, int numEnemyShips) :mapHeight(height),mapWidth(width){
    try{
        enemyFaction=FactionType::Italy;
        setUpUnitTestingTiles(tileDim,specialTile);
    } catch (std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
    std::cerr << "Please change Warship type" << std::endl;
    }
    ShipFactory factory(mapWidth/2-mapWidth/16,0);
    for(int i=0; i< numAlliedShips; i++) {
        std::shared_ptr<WarShip> ship(factory.createAlliedDestroyer(ModelType::Impavido, mapHeight, mapWidth));
        alliedFleet.push_back(ship);
    }
    for(int i=0; i< numEnemyShips; i++) {
        std::shared_ptr<WarShip> ship(factory.createBattleship(ModelType::MichelangeloBuonarroti, mapHeight, mapWidth));
        enemyFleet.push_back(ship);
    }
    for(auto &it : alliedFleet){
        it->getSprite().move(0, -1);
    }
    if(!enemyFleet.empty())
        enemyFleet.front()->getSprite().move(0, 1);
}
void GameWorld::setUpUnitTestingTiles(int tileDim,std::string specialTile) {
    tiles.clear();
    gridLength = 8;
    enemyFaction = FactionType::Italy;
    alliedFaction = FactionType::Italy;
    std::string seaBlockPath = "seaBlock.png";
    std::string dirtBlockPath = "dirtBlock.png";
    std::vector<std::shared_ptr<GameTile>> row;
    try {
            for(int i = 0; i < mapWidth/tileDim; i++) {
                row.clear();
                for (int j = 0; j < mapHeight / tileDim; j++) {
                    if(!((i >= mapWidth/tileDim/2 - 2 && i <= mapWidth/tileDim/2 + 2)&&(j >= mapHeight/tileDim/2 - 2 && j <= mapHeight/tileDim/2 + 2))){
                        TileType tileType=TileType::Sea;
                        std::unique_ptr<GameTile> tile(new GameTile("seaBlock.png", tileDim * j, tileDim * i, false, false, tileType));
                        row.push_back(std::move(tile));
                    }else {
                        TileType tileType=TileType::Sea;
                        bool collision=false;
                        if(specialTile=="sea"){
                            tileType=TileType::Sea;
                        }else if(specialTile=="dirt"){
                            tileType=TileType::Dirt;
                            collision=true;
                        } else if(specialTile=="seaFoggy"){
                            tileType=TileType::Fog;
                        }
                        std::unique_ptr<GameTile> tile(new GameTile(specialTile+"Block.png", tileDim * j, tileDim * i, collision, false, tileType));
                        row.push_back(std::move(tile));
                    }
                }
                tiles.push_back(row);
            }
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Please change the directory" << std::endl;
    }
}
