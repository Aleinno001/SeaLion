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
    //TODO iniziallizare la lista di navi alleate e nemiche
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

void
GameWorld::setUpTiles(
        int &tileDim) { //FIXME Finire di aggiungere le tiles per poi migliorare l'uniformità della generazione
    tiles.clear();
    std::vector<std::unique_ptr<GameTile>> row;
    Dice dice(6);
    std::string currentDir = GetCurrentWorkingDir();
    std::string path = currentDir + "/../Res/Tiles/seaBlock.png";
    bool collision = false;
    int resTile;
    int firstChangeTileValue;
    int secondChangeTileValue;
    for (int i = 1; i < (mapHeight / tileDim); i++) {
        row.clear();
        for (int j = 1; j < (mapWidth / tileDim); j++) {
            resTile = dice.roll(1);
            std::cerr << resTile << std::endl;
            firstChangeTileValue = 5;
            secondChangeTileValue = 6;
            if (path == (currentDir + "/../Res/Tiles/seaFoggyBlock.png")) {
                firstChangeTileValue = 3;
                secondChangeTileValue = 6;
            } else if (path == (currentDir + "/../Res/Tiles/seaWaveBlock.png")) {
                firstChangeTileValue = 3;
                secondChangeTileValue = 4;
            }
            if (resTile >= 1 && resTile < firstChangeTileValue) {
                path = currentDir + "/../Res/Tiles/seaBlock.png";   //TODO gestire eccezioni per il path dei file
            } else if (resTile >= firstChangeTileValue && resTile < secondChangeTileValue) {
                path = currentDir + "/../Res/Tiles/seaFoggyBlock.png";
                collision = true;  //FIXME da cambiare la collisione della nebbia(tenere solo per testare)
            } else {
                path = currentDir + "/../Res/Tiles/seaWaveBlock.png";
            }
            std::unique_ptr<GameTile> tile(new GameTile(path, tileDim * (i - 1), tileDim * (j - 1), collision, false));
            row.push_back(std::move(tile));
        }
        tiles.push_back(std::move(row));
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
    for (int i = 0; i < numAir; i++) {

        if (dice.roll(1) > 1) {
            std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::ArkRoyal));
            enemyFleet.push_back(std::move(enemy));
        } else {
            std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::Indomitable));
            enemyFleet.push_back(std::move(enemy));
        }
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