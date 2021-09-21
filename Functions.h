//
// Created by pala on 9/20/21.
//

#ifndef SEALION_FUNCTIONS_H
#define SEALION_FUNCTIONS_H

#include <vector>
#include "GameWorld.h"
#include "Button.h"
#include "MvcView.h"
namespace Functions {
    void searchAirplane(sf::RenderWindow &window, GameWorld &gameWorld);
    void f (std::list<std::shared_ptr<WarShip>> &fullNavy, GameWorld &gameWorld,  sf::RenderWindow &window);
    std::vector<Fleet> alliedDummyFleet();
    void drawAndManageAlliedShips(sf::RenderWindow &window, GameWorld &gameWorld, sf::Color &deathColor,sf::Color &selectedColor, sf::Color &concealedColor, sf::Color &removeColor,std::list<MvcView<WarShip>> &views, Button &airplaneButton);
    void fpsManagment(sf::RenderWindow &window, sf::Clock &clock);
    void update(std::list<std::shared_ptr<WarShip>> &fullNavyCollision, GameWorld &gameWorld,  sf::RenderWindow &window,std::list<navyPositionsForAirAttack> &airTargets, std::list<MvcView<WarShip>> &views);
    void drawAndManageEnemyShips(sf::RenderWindow &window, GameWorld &gameWorld, sf::Color &deathColor,sf::Color &selectedColor,sf::Color &concealedColor, sf::Color &removeColor);
    void manageSelection(sf::RenderWindow &window, sf::Event &event, GameWorld &gameWorld, bool &found, bool &clicked,std::list<iteratorPositions> &lst,std::_List_iterator<std::unique_ptr<WarShip>> &itSecondClick,Button &airplaneButton, std::list<navyPositionsForAirAttack> &airAttackList);
    void drawMap(sf::RenderWindow &window, GameWorld &gameWorld);
    void prepareFullNavyList(GameWorld &gameWorld,std::list<iteratorPositions> &fullNavyCollision);
    void gameLoop(int &width, int &height,  windowMode &videoMode, sf::Color &deathColor,sf::Color &selectedColor,sf::Color &concealedColor, sf::Color &removeColor, const sf::ContextSettings &settings,sf::Clock &clock,sf::RenderWindow &window, GameWorld &gameWorld, bool &found, bool &clicked,std::list<std::unique_ptr<WarShip>>::iterator &itSecondClick, std::list<iteratorPositions> &lst,std::list<iteratorPositions> &fullNavyCollision, std::list<MvcView<WarShip>> &views, Button &airplaneButton,std::list<navyPositionsForAirAttack> &airTargets);
    void checkHit(std::list<std::shared_ptr<WarShip>> &fullNavy, sf::Window &window);
    void tilesCheckAndDeath(sf::RenderWindow &window, GameWorld &gameWorld,std::list<std::shared_ptr<WarShip>> &fullNavyCollision);

}

#endif //SEALION_FUNCTIONS_H
