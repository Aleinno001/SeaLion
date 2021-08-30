//
// Created by davide on 08/07/21.
//
#include "gtest/gtest.h"
#include "../GameTile.h"


TEST(GameTile, Constructor) {

    GameTile c("seaWhirlpoolBlock.png", 1, 2, true, true, TileType::Whirlpool);
    ASSERT_EQ(c.isPassable, !true);
    ASSERT_EQ(c.isExit, true);
    ASSERT_EQ(c.getPos(), sf::Vector2f(1, 2));
    ASSERT_EQ(c.getTileType(), TileType::Whirlpool);
}
