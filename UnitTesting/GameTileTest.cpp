//
// Created by pala on 08/07/21.
//
#include "gtest/gtest.h"
#include "../GameTile.h"


TEST(GameTile, Constructor) {

    GameTile c("ciao", 1, 2, true, true, TileType::Whirlpool);
}
