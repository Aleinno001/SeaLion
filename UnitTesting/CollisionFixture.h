//
// Created by pala on 9/28/21.
//

#ifndef SEALION_COLLISIONFIXTURE_H
#define SEALION_COLLISIONFIXTURE_H


#include <gtest/gtest.h>
#include "../GameWorld.h"
#include "../Functions.h"
class CollisionSuite : public ::testing::Test {
protected:
    virtual void SetUp(){}
};
TEST_F(CollisionSuite,Collisions){
    sf::ContextSettings settings;
    int height = 60;
    int width = 60;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 2;
    settings.minorVersion = 1;
    sf::RenderWindow window;
    window.create(sf::VideoMode(height,width),"CollisionTest",sf::Style::Default,settings);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    GameWorld gameWorld(height,width,30);
    while(window.isOpen() /*|| nave.getCol == true*/){
        for (int i = 0; i < (gameWorld.getMapHeight() / gameWorld.getTileDim()); i++) { //disegna la  mappa
            for (int j = 0; j < (gameWorld.getMapWidth() / gameWorld.getTileDim()); j++) {
                window.draw(gameWorld.getTempTile()[i][j]);
            }
        }
    }
}

#endif //SEALION_COLLISIONFIXTURE_H
