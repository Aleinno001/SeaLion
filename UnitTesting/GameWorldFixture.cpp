//
// Created by pala on 08/07/21.
//

#include "gtest/gtest.h"
#include "../GameWorld.h"
#include <SFML/Graphics.hpp>


class GameWorldSuite : public ::testing::Test {

protected:
    virtual void SetUp() {

        c.setExitPos(sf::Vector2i(1, 0));
        c.setEnemyFaction(FactionType::Japan);
        c.setAlliedFaction(FactionType::Italy);
        c.setGridLength(8);
        c.setMapWidth(1920);
        c.setMapHeight(1080);
        int tileDim = 30;
        int numEnemySub = 2;
        int numEnemyBat = 3;
        int numEnemyCru = 3;
        int numEnemyDes = 4;
        int numEnemyAir = 1;
        std::vector<Fleet> alliedTypeFleet;
        Fleet submarines;
        submarines.type = ShipType::Submarine;
        submarines.name = ModelType::Papa;
        submarines.num = 2;
        alliedTypeFleet.push_back(submarines);
        Fleet destroyers;
        destroyers.type = ShipType::Destroyer;
        destroyers.name = ModelType::PaoloEmilio;
        destroyers.num = 2;
        alliedTypeFleet.push_back(destroyers);
        Fleet secondDestroyers;
        secondDestroyers.type = ShipType::Destroyer;
        secondDestroyers.name = ModelType::Leone;
        secondDestroyers.num = 2;
        alliedTypeFleet.push_back(secondDestroyers);
        Fleet cruisers;
        cruisers.type = ShipType::Cruiser;
        cruisers.name = ModelType::AlbertoDiGiussano;
        cruisers.num = 2;
        alliedTypeFleet.push_back(cruisers);
        Fleet secondCruisers;
        secondCruisers.type = ShipType::Cruiser;
        secondCruisers.name = ModelType::Trento;
        secondCruisers.num = 1;
        alliedTypeFleet.push_back(secondCruisers);
        Fleet battleships;
        battleships.type = ShipType::Battleship;
        battleships.name = ModelType::AndreaDoria;
        battleships.num = 1;
        alliedTypeFleet.push_back(battleships);
        Fleet secondBattleships;
        secondBattleships.type = ShipType::Battleship;
        secondBattleships.name = ModelType::ImperatoreAugusto;
        secondBattleships.num = 1;
        alliedTypeFleet.push_back(secondBattleships);

        Fleet thirdBattleships;
        thirdBattleships.type = ShipType::Battleship;
        thirdBattleships.name = ModelType::MichelangeloBuonarroti;
        thirdBattleships.num = 1;
        alliedTypeFleet.push_back(thirdBattleships);

        Fleet aircraftCarriers;
        aircraftCarriers.type = ShipType::AircraftCarrier;
        aircraftCarriers.name = ModelType::GiuseppeGaribaldi;
        aircraftCarriers.num = 1;
        alliedTypeFleet.push_back(aircraftCarriers);

        c.setUpTiles(tileDim);
        c.setUpInitialState(numEnemySub, numEnemyBat, numEnemyCru, numEnemyDes, numEnemyAir, alliedTypeFleet);
    }

    GameWorld c;
};

TEST_F(GameWorldSuite, Constructor) {

    int enemyNumShip = 0;
    int alliedNumShip = 0;
    int enemyNumBat = 0;
    int enemyNumCru = 0;
    int enemySub = 0;
    int enemyDes = 0;
    int enemyAir = 0;

    int alliedNumBat = 0;
    int alliedNumCru = 0;
    int alliedSub = 0;
    int alliedDes = 0;
    int alliedAir = 0;

    GTEST_ASSERT_EQ(c.getMapHeight(), 1080);
    GTEST_ASSERT_EQ(c.getMapWidth(), 1920);
    GTEST_ASSERT_EQ(c.getGridLength(), 8);
    GTEST_ASSERT_EQ(c.getAlliedFaction(), FactionType::Italy);
    GTEST_ASSERT_EQ(c.getEnemyFaction(), FactionType::Japan);
    GTEST_ASSERT_EQ(c.getExitPos(), sf::Vector2i(1, 0));

    for (auto it = c.getEnemyFleet().begin(); it != c.getEnemyFleet().end(); ++it) {

        //TODO GTEST_ASSERT_EQ(it->get()->getNationality(), "Japan");
        enemyNumShip++;

        if (it->get()->getShipType() == ShipType::Battleship)
            enemyNumBat++;
        else if (it->get()->getShipType() == ShipType::Cruiser)
            enemyNumCru++;
        else if (it->get()->getShipType() == ShipType::Submarine)
            enemySub++;
        else if (it->get()->getShipType() == ShipType::Destroyer)
            enemyDes++;
        else
            enemyAir++;


    }

    GTEST_ASSERT_EQ(enemyNumShip, 13);
    GTEST_ASSERT_EQ(enemyNumBat, 3);
    GTEST_ASSERT_EQ(enemyNumCru, 3);
    GTEST_ASSERT_EQ(enemySub, 2);
    GTEST_ASSERT_EQ(enemyDes, 4);
    GTEST_ASSERT_EQ(enemyAir, 1);


    for (auto it = c.getAlliedFleet().begin(); it != c.getAlliedFleet().end(); ++it) {

        //TODO   GTEST_ASSERT_EQ(it->get()->getNationality(), "Italy");
        alliedNumShip++;

        if (it->get()->getShipType() == ShipType::Battleship)
            alliedNumBat++;
        else if (it->get()->getShipType() == ShipType::Cruiser)
            alliedNumCru++;
        else if (it->get()->getShipType() == ShipType::Submarine)
            alliedSub++;
        else if (it->get()->getShipType() == ShipType::Destroyer)
            alliedDes++;
        else
            alliedAir++;

    }

    GTEST_ASSERT_EQ(alliedNumShip, 13);
    GTEST_ASSERT_EQ(alliedNumBat, 3);
    GTEST_ASSERT_EQ(alliedNumCru, 3);
    GTEST_ASSERT_EQ(alliedSub, 2);
    GTEST_ASSERT_EQ(alliedDes, 4);
    GTEST_ASSERT_EQ(alliedAir, 1);


}

