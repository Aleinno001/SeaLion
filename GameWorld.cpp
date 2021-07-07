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


