//
// Created by pala on 9/20/21.
//

#ifndef SEALION_FUNCTIONS_H
#define SEALION_FUNCTIONS_H

#include <vector>
#include "GameWorld.h"
#include "Button.h"
#include "MvcView.h"
#include "CustomColors.h"

enum class windowMode {
    Windowed,
    Fullscreen
};
typedef struct navyPositionsForAirAttack {
    std::_List_iterator<std::unique_ptr<WarShip>> itAllied;
    std::_List_iterator<std::unique_ptr<WarShip>> itEnemy;

} navyPositionsForAirAttack;
typedef struct iteratorPositions {
    std::shared_ptr<WarShip> it;
    sf::Vector2f pos;
};
namespace Functions {
    void searchAirplane(sf::RenderWindow &window, GameWorld &gameWorld);
    void f (std::list<iteratorPositions> fullNavyCollision, GameWorld &gameWorld,  sf::RenderWindow &window);
    std::vector<Fleet> alliedDummyFleet();
    void drawAndManageAlliedShips(sf::RenderWindow &window, GameWorld &gameWorld,std::list<MvcView<Specialty>> &views);
    void fpsManagment(sf::RenderWindow &window, sf::Clock &clock);
    void update(std::list<iteratorPositions> &lst, double dt,std::list<iteratorPositions> &fullNavyCollision, sf::RenderWindow &window,std::list<MvcView<Specialty>> &views);
    void drawAndManageEnemyShips(sf::RenderWindow &window, GameWorld &gameWorld);
    void manageSelection(sf::RenderWindow &window, sf::Event &event, GameWorld &gameWorld,std::list<iteratorPositions> &lst, std::shared_ptr<WarShip> selectedShip,const std::list<MvcView<Specialty>>& views);
    void drawMap(sf::RenderWindow &window, GameWorld &gameWorld);
    void prepareFullNavyList(GameWorld &gameWorld,std::list<iteratorPositions> &fullNavyCollision);
    void gameLoop(int &width, int &height,  windowMode &videoMode, sf::Color &deathColor,sf::Color &selectedColor,sf::Color &concealedColor, sf::Color &removeColor, const sf::ContextSettings &settings,sf::Clock &clock,sf::RenderWindow &window, GameWorld &gameWorld, std::list<iteratorPositions> &lst,std::list<iteratorPositions> &fullNavyCollision, std::list<MvcView<Specialty>> &views,std::shared_ptr<WarShip> selectedShip);
    void checkHit(std::list<iteratorPositions> &fullNavy, sf::Window &window);
    void tilesCheckAndDeath(sf::RenderWindow &window, GameWorld &gameWorld,std::list<iteratorPositions> &fullNavyCollision);

}

#endif //SEALION_FUNCTIONS_H
