#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include "GameWorld.h"
#include <thread>
#include "Collision.h"
#include "MvcController.h"
#include "MvcView.h"
#include "LambdaFunction.h"
#include "Functions.h"
enum class windowMode {
    Windowed,
    Fullscreen
};

int main() {
    std::vector<Fleet> fleet = Functions::alliedDummyFleet();
    sf::Vector2i boundaries(1920, 1080);
    sf::Color deathColor(100, 100, 100, 120);
    sf::Color selectedColor(196, 255, 168, 255);
    sf::Color concealedColor(250, 250, 250, 180);
    sf::Color removeColor(255, 255, 255, 255);
    sf::Clock clock;
    sf::RenderWindow window;
    sf::ContextSettings settings;
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
    tileDim = 30;  //FIXME adattabile a tutte le risoluzioni
    window.create(sf::VideoMode(width, height), "SeaLion", sf::Style::Fullscreen, settings);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    GameWorld gameWorld = GameWorld(numEnemySub, numEnemyBat, numEnemyCru, numEnemyDes, numEnemyAir, fleet,
                                    FactionType::Uk, FactionType::Japan, 8, boundaries, width,
                                    height, tileDim);
    bool found = false;
    bool clicked = true;
    auto itSecondClick = gameWorld.getAlliedFleet().begin();
    auto itAllied = gameWorld.getAlliedFleet().begin();
    auto itEnemy = gameWorld.getEnemyFleet().begin();
    auto itTiles = gameWorld.getTiles().begin();
    sf::Vector2f pos;
    pos.x = 1;
    pos.y = 1;
    //FIXME da rifare le esplosioni
    //Explosion explosion(pos);
    std::list<iteratorPositions> lst;
    std::list<iteratorPositions> fullNavyCollision;
    std::list<navyPositionsForAirAttack> airTargets;
    std::list<MvcController<WarShip>> controllers;
    std::list<MvcView<WarShip>> views;
    prepareFullNavyList(gameWorld, itAllied, itEnemy, fullNavyCollision);
    sf::Vector2f buttonPos;
    pos.x = window.getSize().x - 15;
    pos.y = window.getSize().y - 15;
    Button airplaneButton("airplaneButton", 30, 30, buttonPos);
    for (auto iter = gameWorld.getAlliedFleet().begin(); iter != gameWorld.getAlliedFleet().end(); ++iter) {
        if (iter->get()->getShipType() == ShipType::AircraftCarrier) {
            ConcreteAircraftCarrier *dinamicAir = dynamic_cast<ConcreteAircraftCarrier *>(iter->get());
            MvcController<WarShip> controller(dinamicAir->getInstance());
            controllers.push_back(controller);
            MvcView<WarShip> view(dinamicAir->getInstance(), controllers.back(), window);
            views.push_back(view);
        }
    }
    std::thread thread_antiair (LambdaFunction::searchAirplane, std::ref(window), std::ref(gameWorld));
    std::thread thread_collision(LambdaFunction::f, std::ref(fullNavyCollision), std::ref(gameWorld), tileDim, std::ref(window));
    std::thread thread_tiles_effect(LambdaFunction::tilesCheckAndDeath, std::ref(window), std::ref(gameWorld),std::ref(fullNavyCollision), tileDim);
    std::thread thread_checkHit(LambdaFunction::checkHit, std::ref(fullNavyCollision), std::ref(window));
    thread_collision.detach();
    thread_tiles_effect.detach();
    thread_checkHit.detach();
    thread_antiair.detach();
    Functions::gameWord(width, height, tileDim, videoMode, deathColor, selectedColor, concealedColor, removeColor, settings, clock,
             window, gameWorld, found, clicked, itSecondClick, lst, fullNavyCollision, views, airplaneButton,
             airTargets);
    return 0;
}

