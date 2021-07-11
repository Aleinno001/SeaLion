//
// Created by pala on 08/07/21.
//

#include "gtest/gtest.h"
#include "../GameWorld.h"


class GameWorldTest : public ::testing::Test {

protected:
    virtual void SetUp() {                                   //TODO aggiungere setAlliedFleet, setEnemyFleet e setTiles

        c.setExitPos(sf::Vector2i(1, 0));
        c.setEnemyFaction(FactionType::Japan);
        c.setAlliedFaction(FactionType::Italy);
        c.setGridLength(8);
        c.setMapWidth(1920);
        c.setMapHeight(1080);
        int tileDim = 60;
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


        c.setUpTiles(tileDim);
        c.setUpInitialState();
    }

    GameWorld c;
};

TEST(GameWorld, Constructor) {


}

TEST(GameWorld, Tiles) {


}