//
// Created by davide on 04/07/21.
//

#include "GameWorld.h"

GameWorld::GameWorld(int &numEnemySub, int &numEnemyBat, int &numEnemyCru, int &numEnemyDes, int &numEnemyAir)
        : gridLength(8) {
    setUpInitialState(numEnemySub, numEnemyBat, numEnemyCru, numEnemyDes, numEnemyAir);
}


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

void GameWorld::submarineRandomizer(int &enemySub, Dice &subDice, ShipFactory &enemyFactory) {

    for (int i = 0; i < enemySub; i++) {

        switch (enemyFaction) {
            case FactionType::Japan:

                if (subDice.roll(1) > 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::I400));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::typeb1));
                    enemyFleet.push_back(std::move(enemy));
                }

                break;

            case FactionType::Italy:

                if (subDice.roll(1) > 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::DaVinci));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Papa));
                    enemyFleet.push_back(std::move(enemy));
                }


                break;

            case FactionType::Usa:

                if (subDice.roll(1) > 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Gato));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createSubmarine(ModelType::Narwhal));
                    enemyFleet.push_back(std::move(enemy));
                }
                break;

            case FactionType::Uk:

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

void GameWorld::battleshipRandomizer(int &enemyBat, Dice &batDice, ShipFactory &enemyFactory) {

    for (int i = 0; i < enemyBat; i++) {

        switch (enemyFaction) {
            case FactionType::Japan:

                if (batDice.roll(1) == 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Kongo));
                    enemyFleet.push_back(std::move(enemy));
                } else if (batDice.roll(1) == 2) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Musashi));
                    enemyFleet.push_back(std::move(enemy));
                } else if (batDice.roll(1) == 3) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Yamato));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::ISE));
                    enemyFleet.push_back(std::move(enemy));
                }

                break;

            case FactionType::Italy:

                if (batDice.roll(1) == 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::AndreaDoria));
                    enemyFleet.push_back(std::move(enemy));
                } else if (batDice.roll(1) == 2) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::ImperatoreAugusto));
                    enemyFleet.push_back(std::move(enemy));
                } else if (batDice.roll(1) == 3) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::VittorioVeneto));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::MichelangeloBuonarroti));
                    enemyFleet.push_back(std::move(enemy));
                }


                break;

            case FactionType::Usa:

                if (batDice.roll(1) == 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::NewYork));
                    enemyFleet.push_back(std::move(enemy));
                } else if (batDice.roll(1) == 2) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Arizona));
                    enemyFleet.push_back(std::move(enemy));
                } else if (batDice.roll(1) == 3) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::NorthCarolina));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Montana));
                    enemyFleet.push_back(std::move(enemy));
                }
                break;

            case FactionType::Uk:

                if (batDice.roll(1) == 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Dreadnought));
                    enemyFleet.push_back(std::move(enemy));
                } else if (batDice.roll(1) == 2) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::IronDuke));
                    enemyFleet.push_back(std::move(enemy));
                } else if (batDice.roll(1) == 3) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Hood));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createBattleship(ModelType::Lion));
                    enemyFleet.push_back(std::move(enemy));
                }

                break;
            default:
                //TODO lancia eccezione
                break;

        }


    }


}

void GameWorld::cruiserRandomizer(int &enemyCru, Dice &cruDice, ShipFactory &enemyFactory) {

    for (int i = 0; i < enemyCru; i++) {

        switch (enemyFaction) {
            case FactionType::Japan:

                if (cruDice.roll(1) == 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Takao));
                    enemyFleet.push_back(std::move(enemy));
                } else if (cruDice.roll(1) == 2) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::IsuzuNagara));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Ijn));
                    enemyFleet.push_back(std::move(enemy));
                }

                break;

            case FactionType::Italy:

                if (cruDice.roll(1) == 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::AlbertoDiGiussano));
                    enemyFleet.push_back(std::move(enemy));
                } else if (cruDice.roll(1) == 2) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Trento));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Gorizia));
                    enemyFleet.push_back(std::move(enemy));
                }


                break;

            case FactionType::Usa:

                if (cruDice.roll(1) == 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::StLouis));
                    enemyFleet.push_back(std::move(enemy));
                } else if (cruDice.roll(1) == 2) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::NewOrleans));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Alaska));
                    enemyFleet.push_back(std::move(enemy));
                }
                break;

            case FactionType::Uk:

                if (cruDice.roll(1) == 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Danae));
                    enemyFleet.push_back(std::move(enemy));
                } else if (cruDice.roll(1) == 2) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Belfast));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createCruiser(ModelType::Tiger59));
                    enemyFleet.push_back(std::move(enemy));
                }

                break;
            default:
                //TODO lancia eccezione
                break;

        }


    }


}

void GameWorld::destroyerRandomizer(int &enemyDes, Dice &desDice, ShipFactory &enemyFactory) {

    for (int i = 0; i < enemyDes; i++) {

        switch (enemyFaction) {
            case FactionType::Japan:

                if (desDice.roll(1) == 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Akizuki));
                    enemyFleet.push_back(std::move(enemy));
                } else if (desDice.roll(1) == 2) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Fubuki));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Yukikaze));
                    enemyFleet.push_back(std::move(enemy));
                }

                break;

            case FactionType::Italy:

                if (desDice.roll(1) == 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Impavido));
                    enemyFleet.push_back(std::move(enemy));
                } else if (desDice.roll(1) == 2) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Leone));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::PaoloEmilio));
                    enemyFleet.push_back(std::move(enemy));
                }


                break;

            case FactionType::Usa:

                if (desDice.roll(1) == 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Mahan));
                    enemyFleet.push_back(std::move(enemy));
                } else if (desDice.roll(1) == 2) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Fletcher));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Sims));
                    enemyFleet.push_back(std::move(enemy));
                }
                break;

            case FactionType::Uk:

                if (desDice.roll(1) == 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Campbelltown));
                    enemyFleet.push_back(std::move(enemy));
                } else if (desDice.roll(1) == 2) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Gallant));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createDestroyer(ModelType::Jutland));
                    enemyFleet.push_back(std::move(enemy));
                }

                break;
            default:
                //TODO lancia eccezione
                break;

        }


    }
}

void GameWorld::aircraftCarrierRandomizer(int &enemyAir, Dice &airDice, ShipFactory &enemyFactory) {

    for (int i = 0; i < enemyAir; i++) {

        switch (enemyFaction) {
            case FactionType::Japan:

                if (airDice.roll(1) > 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::Hiryu));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::Tahio));
                    enemyFleet.push_back(std::move(enemy));
                }

                break;

            case FactionType::Italy:

                if (airDice.roll(1) > 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::GiuseppeGaribaldi));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::GiuseppeGaribaldi));
                    enemyFleet.push_back(std::move(enemy));
                }

                break;

            case FactionType::Usa:

                if (airDice.roll(1) > 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::Midway));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::Ranger));
                    enemyFleet.push_back(std::move(enemy));
                }
                break;

            case FactionType::Uk:

                if (airDice.roll(1) > 1) {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::ArkRoyal));
                    enemyFleet.push_back(std::move(enemy));
                } else {
                    std::unique_ptr<WarShip> enemy(enemyFactory.createAircraftCarrier(ModelType::Indomitable));
                    enemyFleet.push_back(std::move(enemy));
                }

                break;

            default:
                //TODO lancia eccezione
                break;

        }


    }


}


