//
// Created by davide on 08/07/21.
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
    }

    GameWorld c;
};

TEST(GameWorld, Constructor) {


}

TEST(GameWorld, Tiles) {


}