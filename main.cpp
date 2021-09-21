#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include "GameWorld.h"
#include <thread>
#include "Collision.h"
#include "MvcController.h"
#include "MvcView.h"
#include "Functions.h"
enum class windowMode {
    Windowed,
    Fullscreen
};
int main() {
    std::vector<Fleet> fleet = Functions::alliedDummyFleet();
    sf::Color deathColor(100, 100, 100, 120);
    sf::Color selectedColor(196, 255, 168, 255);
    sf::Color concealedColor(250, 250, 250, 180);
    sf::Color removeColor(255, 255, 255, 255);
    sf::RenderWindow window;
    sf::ContextSettings settings;
    sf::Vector2f buttonPos;
    sf::Vector2i exit{0,0};
    ToolBox::dt.restart().asSeconds();
    int numEnemySub, numEnemyBat, numEnemyCru, numEnemyDes, numEnemyAir;
    int width, height, tileDim;
    numEnemySub = 3;
    numEnemyBat = 3;
    numEnemyCru = 3;
    numEnemyDes = 3;
    numEnemyAir = 2;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 2;
    settings.minorVersion = 1;
    windowMode videoMode = windowMode::Windowed;
    auto desktop = sf::VideoMode::getDesktopMode();
    width = desktop.width;
    height = desktop.height;
    tileDim = 30;
    window.create(sf::VideoMode(width, height), "SeaLion", sf::Style::Fullscreen, settings);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    GameWorld gameWorld = GameWorld(numEnemySub,numEnemyBat,numEnemyCru,numEnemyDes,numEnemyAir,fleet,FactionType::Italy,FactionType::Italy,8,exit,width,height,tileDim);
    bool found = false;
    bool clicked = true;
    auto itSecondClick = gameWorld.getAlliedFleet().begin();
    auto itAllied = gameWorld.getAlliedFleet().begin();
    auto itEnemy = gameWorld.getEnemyFleet().begin();
    auto itTiles = gameWorld.getTiles().begin();
    sf::Vector2f pos;
    pos.x = 1;
    pos.y = 1;
    std::list<iteratorPositions> lst;
    std::list<iteratorPositions> fullNavyList;
    std::list<MvcController<ConcreteAircraftCarrier>> controllers;
    std::list<MvcView<ConcreteAircraftCarrier>> views;
    Functions::prepareFullNavyList(gameWorld,fullNavyList);
    pos.x = window.getSize().x - 15;
    pos.y = window.getSize().y - 15;
    Button airplaneButton("airplaneButton", 30, 30, buttonPos);
    for (auto & iter : gameWorld.getAlliedFleet()) {
        if (ConcreteAircraftCarrier *dynamic= dynamic_cast<ConcreteAircraftCarrier *>(iter.get())) {
            MvcController<ConcreteAircraftCarrier> controller(*dynamic);
            controllers.push_back(controller);
            MvcView<ConcreteAircraftCarrier> view(*dynamic, controllers.back(), window);
            views.push_back(view);
        }
    }
    std::thread thread_collision(Functions::f, std::ref(fullNavyList), std::ref(gameWorld),std::ref(window));
    std::thread thread_tiles_effect(Functions::tilesCheckAndDeath, std::ref(window), std::ref(gameWorld),std::ref(fullNavyList));
    std::thread thread_checkHit(Functions::checkHit, std::ref(fullNavyList), std::ref(window));
    thread_collision.detach();
    thread_tiles_effect.detach();
    thread_checkHit.detach();
    Functions::gameLoop(width, height, tileDim, videoMode, deathColor, selectedColor, concealedColor, removeColor, settings, clock,window, gameWorld, found, clicked, itSecondClick, lst, fullNavyList, views, airplaneButton);
    return 0;
}

