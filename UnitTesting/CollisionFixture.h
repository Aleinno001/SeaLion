//
// Created by pala on 9/28/21.
//

#ifndef SEALION_COLLISIONFIXTURE_H
#define SEALION_COLLISIONFIXTURE_H

#include <gtest/gtest.h>
#include "../GameWorld.h"
#include "../Functions.h"
#include <SFML/Graphics.hpp>
#include <thread>

class CollisionSuite : public ::testing::Test {
protected:
    virtual void SetUp(){}
};
TEST_F(CollisionSuite,IslandCollisions){
    sf::ContextSettings settings;
    sf::Clock c;
    int height = 900;
    int width = 900;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 2;
    settings.minorVersion = 1;
    sf::RenderWindow window;
    window.create(sf::VideoMode(height,width),"CollisionTest",sf::Style::Default,settings);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    GameWorld gameWorld(height,width,30,1,"dirt", 0);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    std::thread thread_collision(Functions::f, std::ref(gameWorld.getAlliedFleet()), std::ref(gameWorld),std::ref(window));
    std::thread thread_tiles_effect(Functions::tilesCheckAndDeath, std::ref(window), std::ref(gameWorld),std::ref(gameWorld.getAlliedFleet()));
    std::thread thread_checkHit(Functions::checkHit, std::ref(gameWorld.getAlliedFleet()), std::ref(window));
    thread_collision.detach();
    thread_tiles_effect.detach();
    thread_checkHit.detach();
    sf::Vector2f targetCoords;
    targetCoords.x=gameWorld.getAlliedFleet().front()->getSprite().getPosition().x;
    targetCoords.y=0;
    gameWorld.getAlliedFleet().front()->setTargetCoordinates(targetCoords);
    while(window.isOpen()){
       sf::Event event;
       while (window.pollEvent(event)) {
           if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
               window.close();
           }
       }
       window.clear();
        for (int i = 0; i < (gameWorld.getMapWidth() / gameWorld.getTileDim()); i++) { //disegna la  mappa
            for (int j = 0; j < (gameWorld.getMapHeight() / gameWorld.getTileDim()); j++) {
                window.draw(gameWorld.getTiles()[i][j]->getSprite());
            }
        }
        gameWorld.getAlliedFleet().front()->drawEquipment(window);
        gameWorld.getAlliedFleet().front()->searchTarget(c.restart().asSeconds());
        window.display();
        if(!gameWorld.getAlliedFleet().front()->isCollision()){
            window.close();
        }
    }
    EXPECT_TRUE(gameWorld.getAlliedFleet().front()->isCollision() == false);
}
TEST_F(CollisionSuite,shipCollisions){
    sf::ContextSettings settings;
    sf::Clock c;
    int height = 900;
    int width = 900;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 2;
    settings.minorVersion = 1;
    sf::RenderWindow window;
    window.create(sf::VideoMode(height,width),"CollisionTest",sf::Style::Default,settings);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    GameWorld gameWorld(height,width,30,2,"sea", 0);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    std::thread thread_collision(Functions::f, std::ref(gameWorld.getAlliedFleet()), std::ref(gameWorld),std::ref(window));
    std::thread thread_tiles_effect(Functions::tilesCheckAndDeath, std::ref(window), std::ref(gameWorld),std::ref(gameWorld.getAlliedFleet()));
    std::thread thread_checkHit(Functions::checkHit, std::ref(gameWorld.getAlliedFleet()), std::ref(window));
    thread_collision.detach();
    thread_tiles_effect.detach();
    thread_checkHit.detach();
    sf::Vector2f targetCoords;
    targetCoords.x=gameWorld.getMapWidth();
    targetCoords.y=0;
    gameWorld.getAlliedFleet().front()->setTargetCoordinates(targetCoords);
    targetCoords.x=0;
    targetCoords.y=0;
    gameWorld.getAlliedFleet().back()->setTargetCoordinates(targetCoords);
    float dt = 0;
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }
        window.clear();
        for (int i = 0; i < (gameWorld.getMapWidth() / gameWorld.getTileDim()); i++) { //disegna la  mappa
            for (int j = 0; j < (gameWorld.getMapHeight() / gameWorld.getTileDim()); j++) {
                window.draw(gameWorld.getTiles()[i][j]->getSprite());
            }
        }
        dt=c.restart().asSeconds();
        for(auto &iter : gameWorld.getAlliedFleet()){
            iter->drawEquipment(window);
        }
        for(auto &it:gameWorld.getAlliedFleet()){
            it->searchTarget(dt);
        }
        window.display();
        if(!gameWorld.getAlliedFleet().front()->isCollision()){
            window.close();
        }
    }
    EXPECT_TRUE(gameWorld.getAlliedFleet().front()->isCollision() == false);
    EXPECT_TRUE(gameWorld.getAlliedFleet().back()->isCollision() == false);
}
TEST_F(CollisionSuite,FogCollisions){
    sf::ContextSettings settings;
    sf::Clock c;
    int height = 900;
    int width = 900;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 2;
    settings.minorVersion = 1;
    sf::RenderWindow window;
    window.create(sf::VideoMode(height,width),"CollisionTest",sf::Style::Default,settings);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    GameWorld gameWorld(height,width,30,1,"seaFoggy", 0);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    std::thread thread_collision(Functions::f, std::ref(gameWorld.getAlliedFleet()), std::ref(gameWorld),std::ref(window));
    std::thread thread_tiles_effect(Functions::tilesCheckAndDeath, std::ref(window), std::ref(gameWorld),std::ref(gameWorld.getAlliedFleet()));
    std::thread thread_checkHit(Functions::checkHit, std::ref(gameWorld.getAlliedFleet()), std::ref(window));
    thread_collision.detach();
    thread_tiles_effect.detach();
    thread_checkHit.detach();
    sf::Vector2f targetCoords;
    targetCoords.x=gameWorld.getAlliedFleet().front()->getSprite().getPosition().x;
    targetCoords.y=0;
    gameWorld.getAlliedFleet().front()->setTargetCoordinates(targetCoords);
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }
        window.clear();
        for (int i = 0; i < (gameWorld.getMapWidth() / gameWorld.getTileDim()); i++) { //disegna la  mappa
            for (int j = 0; j < (gameWorld.getMapHeight() / gameWorld.getTileDim()); j++) {
                window.draw(gameWorld.getTiles()[i][j]->getSprite());
            }
        }
        gameWorld.getAlliedFleet().front()->drawEquipment(window);
        gameWorld.getAlliedFleet().front()->searchTarget(c.restart().asSeconds());
        window.display();
        if(gameWorld.getAlliedFleet().front()->isConcealed()){
            window.close();
        }
    }
    EXPECT_TRUE(gameWorld.getAlliedFleet().front()->isConcealed() == true);
}
//FIXME completare il test
/*
TEST_F(CollisionSuite,BulletCollision){
    sf::ContextSettings settings;
    sf::Clock c;
    int height = 900;
    int width = 900;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 2;
    settings.minorVersion = 1;
    sf::RenderWindow window;
    window.create(sf::VideoMode(height,width),"CollisionTest",sf::Style::Default,settings);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    GameWorld gameWorld(height,width,30,1,"sea", 1);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    std::list<std::shared_ptr<WarShip>> fullNavyList;
    fullNavyList.push_back(gameWorld.getAlliedFleet().front());
    fullNavyList.push_back(gameWorld.getEnemyFleet().front());
    std::thread thread_collision(Functions::f, std::ref(fullNavyList), std::ref(gameWorld),std::ref(window));
    std::thread thread_tiles_effect(Functions::tilesCheckAndDeath, std::ref(window), std::ref(gameWorld),std::ref(fullNavyList));
    std::thread thread_checkHit(Functions::checkHit, std::ref(fullNavyList), std::ref(window));
    thread_collision.detach();
    thread_tiles_effect.detach();
    thread_checkHit.detach();
    sf::Vector2f targetCoords;
    targetCoords.x=gameWorld.getAlliedFleet().front()->getSprite().getPosition().x;
    targetCoords.y=gameWorld.getMapHeight() - gameWorld.getMapHeight()/3 - 50;
    gameWorld.getAlliedFleet().front()->setTargetCoordinates(targetCoords);
    targetCoords.x=gameWorld.getEnemyFleet().front()->getSprite().getPosition().x;
    targetCoords.y=gameWorld.getMapHeight()/3 + 50;
    gameWorld.getEnemyFleet().front()->setTargetCoordinates(targetCoords);
    gameWorld.getAlliedFleet().front()->setEnemyList(gameWorld.getEnemyFleet());
    gameWorld.getEnemyFleet().front()->setEnemyList(gameWorld.getAlliedFleet());
    float  alliedMaxHp = gameWorld.getAlliedFleet().front()->getHp();
    float dt = 0;
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }
        window.clear();
        for (int i = 0; i < (gameWorld.getMapWidth() / gameWorld.getTileDim()); i++) { //disegna la mappa
            for (int j = 0; j < (gameWorld.getMapHeight() / gameWorld.getTileDim()); j++) {
                window.draw(gameWorld.getTiles()[i][j]->getSprite());
            }
        }
        dt = c.restart().asSeconds();
        gameWorld.getAlliedFleet().front()->drawEquipment(window);
        gameWorld.getAlliedFleet().front()->searchTarget(dt);
        gameWorld.getEnemyFleet().front()->drawEquipment(window);
        gameWorld.getEnemyFleet().front()->searchTarget(dt);
        window.display();
        if(gameWorld.getAlliedFleet().front()->getHp() != alliedMaxHp){
            window.close();
        }
    }
    EXPECT_TRUE(gameWorld.getAlliedFleet().front()->getHp() != alliedMaxHp);
}
 */
#endif //SEALION_COLLISIONFIXTURE_H
