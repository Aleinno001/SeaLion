//
// Created by pala on 7/12/21.
//

#include "gtest/gtest.h"
#include "../GameTile.h"
#include <SFML/Graphics.hpp>

class GameTileSuite : public ::testing::Test {
protected:
    virtual void SetUp() {

        c.setPos(sf::Vector2f(1, 0));
        c.sprite.setTexture(c.texture);
        c.sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
        c.sprite.setPosition(c.pos);
        c.setTileType(TileType::Fog);

    }

    GameTile c;


};



