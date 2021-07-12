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

    GTEST_ASSERT_EQ(c.getMapHeight(), 1080);
    GTEST_ASSERT_EQ(c.getMapWidth(), 1920);
    GTEST_ASSERT_EQ(c.getGridLength(), 8);
    GTEST_ASSERT_EQ(c.getAlliedFaction(), "Italy");
    GTEST_ASSERT_EQ(c.getEnemyFaction(), "Japan");
    GTEST_ASSERT_EQ(c.getExitPos(), sf::Vector2i(1, 0));

}

