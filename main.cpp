#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include "GameWorld.h"
#include <thread>
#include "MvcController.h"
#include "MvcView.h"
#include "Functions.h"
#include "ToolBox.h"
int main() {
    std::vector<Fleet> fleet = Functions::alliedDummyFleet();
    sf::RenderWindow window;
    sf::ContextSettings settings;
    sf::Vector2f buttonPos;
    sf::Vector2i exit{0,0};
    int numEnemySub, numEnemyBat, numEnemyCru, numEnemyDes, numEnemyAir;
    int width, height, tileDim=30;
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
    sf::Vector2f pos;
    sf::Clock clock;
    std::shared_ptr<WarShip> selectedShip;
    std::list<std::shared_ptr<WarShip>> fullNavyList;
    std::list<MvcController<Specialty,WarShip>> controllers;
    std::list<MvcView<Specialty,WarShip>> views;
    window.create(sf::VideoMode(width, height), "SeaLion", sf::Style::Fullscreen, settings);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    GameWorld gameWorld = GameWorld(numEnemySub,numEnemyBat,numEnemyCru,numEnemyDes,numEnemyAir,fleet,FactionType::Uk,FactionType::Italy,8,exit,width,height,tileDim);
    Functions::settingTargets(gameWorld);
    pos.x = 1;
    pos.y = 1;
    Functions::prepareFullNavyList(gameWorld,fullNavyList);
    pos.x = window.getSize().x - 15;
    pos.y = window.getSize().y - 15;
    Button button("airplaneButton", 30, 30, buttonPos);
    for (auto & iter : gameWorld.getAlliedFleet()) {
        if (auto *dynamic= dynamic_cast<ConcreteAircraftCarrier *>(iter.get())) {
            MvcController<Specialty,WarShip> controller(*dynamic);
            controllers.push_back(controller);
            MvcView<Specialty,WarShip> view(*dynamic, controllers.back(), window,button);
            views.push_back(view);
        }
    }
    std::thread thread_collision(Functions::f, std::ref(fullNavyList), std::ref(gameWorld),std::ref(window));
    std::thread thread_tiles_effect(Functions::tilesCheckAndDeath, std::ref(window), std::ref(gameWorld),std::ref(fullNavyList));
    std::thread thread_checkHit(Functions::checkHit, std::ref(fullNavyList), std::ref(window));
    thread_collision.detach();
    thread_tiles_effect.detach();
    thread_checkHit.detach();
    Functions::gameLoop(width, height, settings, videoMode,window, gameWorld, fullNavyList, views,selectedShip,clock);
    return 0;
}

