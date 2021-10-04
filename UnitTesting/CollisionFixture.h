//
// Created by pala on 9/28/21.
//

#ifndef SEALION_COLLISIONFIXTURE_H
#define SEALION_COLLISIONFIXTURE_H

#include <gtest/gtest.h>
#include "../GameWorld.h"
#include "../Functions.h"
#include <SFML/Graphics.hpp>

class CollisionSuite : public ::testing::Test {
protected:
    virtual void SetUp(){}
};
TEST_F(CollisionSuite,Collisions){
    sf::ContextSettings settings;
    int height = 1200;
    int width = 1200;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 2;
    settings.minorVersion = 1;
    sf::RenderWindow window;
    windowMode videoMode = windowMode::Windowed;
    window.create(sf::VideoMode(height,width),"CollisionTest",sf::Style::Default,settings);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    GameWorld gameWorld(height,width,30);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);

    while(window.isOpen() /*|| nave.getCol == true*/){
       sf::Event event;
       while (window.pollEvent(event)) {
           if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
               window.close();
           }
       }
       window.clear();
        for (int i = 1; i < (gameWorld.getMapWidth() / gameWorld.getTileDim())-1; i++) { //disegna la  mappa
            for (int j = 1; j < (gameWorld.getMapHeight() / gameWorld.getTileDim())-1; j++) {
                window.draw(gameWorld.getUTiles()[i][j].getSprite());
            }
        }
        gameWorld.getAlliedFleet().front()->drawEquipment(window);
        window.display();
    }
}

#endif //SEALION_COLLISIONFIXTURE_H
