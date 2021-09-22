//
// Created by pala on 9/20/21.
//

#ifndef SEALION_FUNCTIONS_H
#define SEALION_FUNCTIONS_H

#include <vector>
#include "GameWorld.h"
#include "Button.h"
#include "MvcView.h"
#include "Specialty.h"

enum class windowMode {
    Windowed,
    Fullscreen
};

namespace Functions {
    void searchAirplane(sf::RenderWindow &window, GameWorld &gameWorld);
    void f (std::list<std::shared_ptr<WarShip>> &fullNavy, GameWorld &gameWorld,  sf::RenderWindow &window);
    std::vector<Fleet> alliedDummyFleet();
    void fpsManagment(sf::RenderWindow &window,float elapsedTime);
    void update(std::list<std::shared_ptr<WarShip>> &fullNavyList,float elapsedTime);
    void manageSelection(sf::RenderWindow &window, sf::Event &event, GameWorld &gameWorld, std::shared_ptr<WarShip> &selectedShip,std::list<MvcView<Specialty,WarShip>>& views);
    void drawMap(sf::RenderWindow &window, GameWorld &gameWorld);
    void prepareFullNavyList(GameWorld &gameWorld,std::list<std::shared_ptr<WarShip>> &fullNavyList);
    void gameLoop(int &width, int &height, sf::ContextSettings settings, windowMode &videoMode,sf::RenderWindow &window, GameWorld &gameWorld,std::list<std::shared_ptr<WarShip>> &fullNavyList, std::list<MvcView<Specialty,WarShip>> &views,std::shared_ptr<WarShip> selectedShip,sf::Clock &clock);
    void checkHit(std::list<std::shared_ptr<WarShip>> &fullNavy, sf::Window &window);
    void tilesCheckAndDeath(sf::RenderWindow &window, GameWorld &gameWorld,std::list<std::shared_ptr<WarShip>> &fullNavyCollision);
    void drawAll(GameWorld &gameWorld,std::list<std::shared_ptr<WarShip>> &fullNavyCollision,sf::RenderWindow &window);
}

#endif //SEALION_FUNCTIONS_H
