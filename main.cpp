#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include "GameWorld.h"
#include <thread>
#include "Collision.h"
#include "MvcController.h"
#include "MvcView.h"

enum class windowMode {
    Windowed,
    Fullscreen
};
typedef struct navyPositionsForAirAttack {
    std::_List_iterator<std::unique_ptr<WarShip>> itAllied;
    std::_List_iterator<std::unique_ptr<WarShip>> itEnemy;

} navyPositionsForAirAttack;
typedef struct iteratorPositions {
    std::_List_iterator<std::unique_ptr<WarShip>> it;
    sf::Vector2f pos;
};
void
gameLoop(int &width, int &height, int &tileDim, windowMode &videoMode, sf::Color &deathColor, sf::Color &selectedColor,
         sf::Color &concealedColor, sf::Color &removeColor, const sf::ContextSettings &settings, sf::Clock &clock,
         sf::RenderWindow &window, GameWorld &gameWorld, bool &found, bool &clicked,
         std::list<std::unique_ptr<WarShip>>::iterator &itSecondClick, std::list<iteratorPositions> &lst,
         std::list<iteratorPositions> &fullNavyCollision, std::list<MvcView> &views, Button &airplaneButton,
         std::list<navyPositionsForAirAttack> &airTargets);
void prepareFullNavyList(GameWorld &gameWorld, std::list<std::unique_ptr<WarShip>>::iterator &itAllied,
                         std::list<std::unique_ptr<WarShip>>::iterator &itEnemy,
                         std::list<iteratorPositions> &fullNavyCollision);
std::vector<Fleet> alliedDummyFleet() { //nave alleata di testing
    std::vector<Fleet> fleet;
    Fleet alliedFleet;
    alliedFleet.name = ModelType::DaVinci;
    alliedFleet.num = 1;
    alliedFleet.type = ShipType::Submarine;
    fleet.emplace_back(alliedFleet);
    alliedFleet.name = ModelType::Papa;
    alliedFleet.num = 1;
    fleet.emplace_back(alliedFleet);
    alliedFleet.name = ModelType::Impavido;
    alliedFleet.num = 1;
    alliedFleet.type = ShipType::Destroyer;
    fleet.emplace_back(alliedFleet);
    alliedFleet.name = ModelType::PaoloEmilio;
    alliedFleet.num = 1;
    fleet.emplace_back(alliedFleet);
    alliedFleet.name = ModelType::Leone;
    alliedFleet.num = 1;
    fleet.emplace_back(alliedFleet);
    alliedFleet.name = ModelType::AlbertoDiGiussano;
    alliedFleet.num = 1;
    alliedFleet.type = ShipType::Cruiser;
    fleet.emplace_back(alliedFleet);
    alliedFleet.name = ModelType::Gorizia;
    alliedFleet.num = 1;
    fleet.emplace_back(alliedFleet);
    alliedFleet.name = ModelType::Trento;
    alliedFleet.num = 1;
    fleet.emplace_back(alliedFleet);
    alliedFleet.name = ModelType::GiuseppeGaribaldi;
    alliedFleet.num = 1;
    alliedFleet.type = ShipType::AircraftCarrier;
    fleet.emplace_back(alliedFleet);
    alliedFleet.name = ModelType::Cavour;
    alliedFleet.num = 1;
    fleet.emplace_back(alliedFleet);
    alliedFleet.name = ModelType::ImperatoreAugusto;
    alliedFleet.num = 2;
    alliedFleet.type = ShipType::Battleship;
    fleet.emplace_back(alliedFleet);
    alliedFleet.name = ModelType::MichelangeloBuonarroti;
    alliedFleet.num = 1;
    fleet.emplace_back(alliedFleet);
    alliedFleet.name = ModelType::AndreaDoria;
    alliedFleet.num = 1;
    fleet.emplace_back(alliedFleet);
    alliedFleet.name = ModelType::VittorioVeneto;
    alliedFleet.num = 1;
    fleet.emplace_back(alliedFleet);
    return fleet;
}
void manageSelection(sf::RenderWindow &window, sf::Event &event, GameWorld &gameWorld, bool &found, bool &clicked,
                     std::list<iteratorPositions> &lst, std::_List_iterator<std::unique_ptr<WarShip>> &itSecondClick,
                     Button &airplaneButton, std::list<navyPositionsForAirAttack> &airAttackList) {
    bool alreadyMove = false;
    switch (event.key.code) {
        case sf::Mouse::Left: {
            //FIXME le hitbox della selezione sono calcolate in base ai vertici della sprite e non ruota
            sf::Vector2f coords(event.mouseButton.x, event.mouseButton.y);
            auto translated_pos = window.mapPixelToCoords(
                    static_cast <sf::Vector2i> (coords));     /*Gestione della selezione navale e comando di spostamento*/
            if (airplaneButton.getSprite().getGlobalBounds().contains(translated_pos) &&
                itSecondClick->get()->getShipType() == ShipType::AircraftCarrier &&
                itSecondClick->get()->isSelected()) {
                airplaneButton.getSprite().setColor(sf::Color(0, 180, 0));
                airplaneButton.setClicked(true);
            } else {
                airplaneButton.getSprite().setColor(sf::Color(255, 255, 255));
                if (!airplaneButton.isClicked()) {
                    found = false;
                    for (auto it = gameWorld.getAlliedFleet().begin();
                         it != gameWorld.getAlliedFleet().end() && !found; ++it) {
                        if (it->get()->getSprite().getGlobalBounds().contains(translated_pos) &&
                            !it->get()->isDeath()) {
                            itSecondClick->get()->setSelected(false);
                            it->get()->setSelected(true);
                            found = true;
                            clicked = false;
                            itSecondClick = it;
                        }
                    }
                    if (!found && !clicked && !airplaneButton.getSprite().getGlobalBounds().contains(translated_pos)) {
                        bool foundIter = false;
                        for (auto iter = lst.begin(); iter != lst.end() && !foundIter; ++iter) {
                            if (iter->it == itSecondClick) {
                                foundIter = true;
                                lst.erase(iter);
                            }
                        }
                        iteratorPositions itPos;
                        itPos.it = itSecondClick;
                        itPos.pos = coords;
                        lst.push_back(itPos);
                        itPos.it->get()->setSelected(false);
                        clicked = true;
                    }
                } else {
                    for (auto itSearchClickIsValid = gameWorld.getEnemyFleet().begin();
                         itSearchClickIsValid != gameWorld.getEnemyFleet().end(); ++itSearchClickIsValid)
                        if (itSearchClickIsValid->get()->getSprite().getGlobalBounds().contains(
                                translated_pos))//click su nave nemica dopo pulsante mvc premuto
                        {
                            for (auto &itList: airAttackList) {
                                if (itList.itAllied == itSecondClick) {
                                    itList.itEnemy = itSearchClickIsValid;
                                    alreadyMove = true;
                                }
                            }
                            if (!alreadyMove) {
                                navyPositionsForAirAttack element;
                                element.itAllied = itSecondClick;//Portaerei alleata
                                element.itEnemy = itSearchClickIsValid;//Qualsiasi nave nemica
                                element.itAllied->get()->setAir(
                                        true);//Comunica alla move di warship(cioè la move alla propria istanza ) che gli aerei sono partiti e non c'è più bisogno di chiamre la notify nella move per ristracciarli sulla portaerei
                                airAttackList.push_back(element);
                            }
                        }
                }
                airplaneButton.setClicked(false);
            }
        }
            break;
        case sf::Mouse::Right:
            break;
    }
}
void
drawAndManageEnemyShips(sf::RenderWindow &window, GameWorld &gameWorld, sf::Color &deathColor, sf::Color &selectedColor,
                        sf::Color &concealedColor, sf::Color &removeColor) {
    for (auto &it: gameWorld.getEnemyFleet()) { //imposta il colore alle navinemiche per lo spostamento e per gli effetti delle tiles
        if (it.get()->isDeath()) {
            it.get()->getSprite().setColor(deathColor);
        } else if (it.get()->isSelected()) {
            it.get()->getSprite().setColor(selectedColor);
        } else if (it->isConcealed()) {
            it.get()->getSprite().setColor(concealedColor);
        } else {
            it.get()->getSprite().setColor(removeColor);
        }
        window.draw(it->getSprite());
        for (auto const &itArsenal: it->getArsenalList()) // disegna i cannoni e gestisci il colore per la selezione
            if (itArsenal->getTextureName() != "AntiAircraft" && itArsenal->getTextureName() != "TorpedoTube") {
                if (it.get()->isDeath()) {
                    itArsenal.get()->getSprite().setColor(deathColor);
                } else if (it.get()->isSelected()) {
                    itArsenal.get()->getSprite().setColor(selectedColor);
                } else {
                    itArsenal.get()->getSprite().setColor(removeColor);
                }
                window.draw(itArsenal->getSprite());
                if (!itArsenal->getAmmoType()->isArrived()) {
                    window.draw(itArsenal->getAmmoType()->getSprite());
                }
            }
        for (auto const &itBars: it->getBars()) { //disegna le barre di stato e imposta un colore predefinito
            if (it.get()->isDeath()) {
                itBars->getSprite().setColor(sf::Color(255, 0, 0));
            }
            window.draw(itBars->getSprite());
        }
        if (it->getShipType() == ShipType::AircraftCarrier) { //disegna gli aerei e gestisci il colore per la selezione
            for (auto const &itPlanes: it->getVehicleList()) {
                if (it.get()->isDeath()) {
                    itPlanes.get()->getSprite().setColor(deathColor);
                } else if (it.get()->isSelected()) {
                    itPlanes.get()->getSprite().setColor(selectedColor);
                } else {
                    itPlanes.get()->getSprite().setColor(removeColor);
                }
                window.draw(itPlanes->getSprite());
            }
        }
    }
}
void drawAndManageAlliedShips(sf::RenderWindow &window, GameWorld &gameWorld, sf::Color &deathColor,
                              sf::Color &selectedColor, sf::Color &concealedColor, sf::Color &removeColor,
                              std::list<MvcView> &views, Button &airplaneButton) {
    for (auto &it: gameWorld.getAlliedFleet()) { //disegna le navi alleate e gestisci il colore per la selezione
        if (it.get()->isDeath()) {
            it.get()->getSprite().setColor(deathColor);
        } else if (it.get()->isSelected()) {
            it.get()->getSprite().setColor(selectedColor);
        } else if (it->isConcealed()) {
            it.get()->getSprite().setColor(concealedColor);
        } else {
            it.get()->getSprite().setColor(removeColor);
        }
        window.draw(it->getSprite());
        if (it->getShipType() == ShipType::AircraftCarrier && it->isSelected()) {
            airplaneButton.getSprite().setPosition(window.getSize().x - airplaneButton.getWidth() / 2,
                                                   window.getSize().y - airplaneButton.getLength() / 2);
            window.draw(airplaneButton.getSprite());
        }
        for (auto const &itArsenal: it->getArsenalList())
            if (itArsenal->getTextureName() != "AntiAircraft" && itArsenal->getTextureName() != "TorpedoTube") {
                if (it.get()->isDeath()) {
                    itArsenal.get()->getSprite().setColor(deathColor);
                } else if (it.get()->isSelected()) {
                    itArsenal.get()->getSprite().setColor(selectedColor);
                } else {
                    itArsenal.get()->getSprite().setColor(removeColor);
                }
                window.draw(itArsenal->getSprite());
                if (!itArsenal->getAmmoType()->isArrived()) {
                    window.draw(itArsenal->getAmmoType()->getSprite());
                }
            }
        for (auto const &itBars: it->getBars()) { //disegna le barre di stato e impostane un colore predefinito se la nave viene distrutta
            if (it.get()->isDeath()) {
                itBars->getSprite().setColor(sf::Color(255, 0, 0));
            }
            window.draw(itBars->getSprite());
        }
        if (it->getShipType() == ShipType::AircraftCarrier) {
            for (auto const &itPlanes: it->getVehicleList()) {
                if (it.get()->isDeath()) {
                    itPlanes.get()->getSprite().setColor(deathColor);
                } else if (it.get()->isSelected()) {
                    itPlanes.get()->getSprite().setColor(selectedColor);
                } else {
                    itPlanes.get()->getSprite().setColor(removeColor);
                }
                window.draw(itPlanes->getSprite());
            }
        }
    }
}
void fpsManagment(sf::RenderWindow &window, sf::Clock &clock) {
    sf::Time time = clock.getElapsedTime();
    int fps = 1.0f / time.asSeconds();
    std::string currentDir = CurrentDir::GetCurrentWorkingDir();
    sf::Text fpsCount;
    sf::Text fpsText;
    sf::Font arialFont;
    if (!arialFont.loadFromFile(currentDir + "/../Res/Font/arial.ttf")) {
        std::cerr << "Impossibile caricare il font" << std::endl;
    }
    fpsText.setFont(arialFont);
    fpsText.setString("FPS:");
    fpsText.setCharacterSize(20);
    fpsText.setFillColor(sf::Color::Yellow);
    fpsText.setPosition(0, 0);
    fpsCount.setFont(arialFont);
    fpsCount.setString(std::to_string(fps));
    fpsCount.setCharacterSize(20);
    fpsCount.setFillColor(sf::Color::Yellow);
    fpsCount.setPosition(50, 0);
    window.draw(fpsText);
    window.draw(fpsCount);
    window.display();
}
void drawMap(sf::RenderWindow &window, GameWorld &gameWorld) {
    for (int i = 0; i < (gameWorld.getMapHeight() / 30); i++) { //disegna la  mappa
        for (int j = 0; j < (gameWorld.getMapWidth() / 30); j++) {
            window.draw(gameWorld.getTiles()[i][j]->getSprite());
        }
    }
}
void update(std::list<iteratorPositions> &lst, double dt,
            std::list<iteratorPositions> &fullNavyCollision, //funzione di base per gestir el'aggiornamento del gioco durante il game loop
            GameWorld &gameWorld, int tileDim, sf::RenderWindow &window,
            std::list<navyPositionsForAirAttack> &airTargets, std::list<MvcView> &views) {
    if (!lst.empty()) {
        for (auto iter = lst.begin(); iter != lst.end();) {
            if ((iter->it->get()->getSprite().getPosition().x) == iter->pos.x &&
                iter->it->get()->getSprite().getPosition().y == iter->pos.y) {
                iter = lst.erase(iter);
            } else {
                iter->it->get()->move(iter->pos, dt);
                ++iter;
            }
        }
    }
    if (!airTargets.empty()) {
        for (auto &iter: airTargets) {
            if (auto *bend = dynamic_cast<AircraftCarrier *> (iter.itAllied->get())) {
                //TODO cambiare il .front per l'agfgiunta di piu' viste
                for (auto &itViews: views) {
                    if (bend->getSprite().getPosition() == itViews.getAircraftCarrier().getSprite().getPosition()) {
                        itViews.airplaneClick(iter.itEnemy, dt);
                    }
                }
            }
        }
    }
    //collisonControl(fullNavyCollision);
    auto enemyIterStart = gameWorld.getEnemyFleet().begin();
    auto enemyIterEnd = gameWorld.getEnemyFleet().end();
    for (auto iter = gameWorld.getAlliedFleet().begin(); iter != gameWorld.getAlliedFleet().end(); ++iter) {
        iter->get()->searchTarget(enemyIterStart, enemyIterEnd, gameWorld.getTiles(), dt);
    }
    auto alliedIterStart = gameWorld.getAlliedFleet().begin();
    auto alliedIterEnd = gameWorld.getAlliedFleet().end();
    for (auto iter = gameWorld.getEnemyFleet().begin(); iter != gameWorld.getEnemyFleet().end(); ++iter) {
        iter->get()->searchTarget(alliedIterStart, alliedIterEnd, gameWorld.getTiles(), dt);
    }
}
int main() {
    std::vector<Fleet> fleet = alliedDummyFleet();
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
    std::list<MvcController> controllers;
    std::list<MvcView> views;
    prepareFullNavyList(gameWorld, itAllied, itEnemy, fullNavyCollision);
    sf::Vector2f buttonPos;
    pos.x = window.getSize().x - 15;
    pos.y = window.getSize().y - 15;
    Button airplaneButton("airplaneButton", 30, 30, buttonPos);
    for (auto iter = gameWorld.getAlliedFleet().begin(); iter != gameWorld.getAlliedFleet().end(); ++iter) {
        if (iter->get()->getShipType() == ShipType::AircraftCarrier) {
            AircraftCarrier *dinamicAir = dynamic_cast<AircraftCarrier *>(iter->get());
            MvcController controller(dinamicAir->getInstance());
            controllers.push_back(controller);
            MvcView view(dinamicAir->getInstance(), controllers.back(), window);
            views.push_back(view);
        }
    }
    std::thread thread_antiair (searchAirplane, std::ref(window), std::ref(gameWorld));
    std::thread thread_collision(f, std::ref(fullNavyCollision), std::ref(gameWorld), tileDim, std::ref(window));
    std::thread thread_tiles_effect(tilesCheckAndDeath, std::ref(window), std::ref(gameWorld),
                                    std::ref(fullNavyCollision), tileDim);
    std::thread thread_checkHit(checkHit, std::ref(fullNavyCollision), std::ref(window));
    thread_collision.detach();
    thread_tiles_effect.detach();
    thread_checkHit.detach();
    thread_antiair.detach();
    gameLoop(width, height, tileDim, videoMode, deathColor, selectedColor, concealedColor, removeColor, settings, clock,
             window, gameWorld, found, clicked, itSecondClick, lst, fullNavyCollision, views, airplaneButton,
             airTargets);
    return 0;
}
void prepareFullNavyList(GameWorld &gameWorld, std::list<std::unique_ptr<WarShip>>::iterator &itAllied,
                         std::list<std::unique_ptr<WarShip>>::iterator &itEnemy,
                         std::list<iteratorPositions> &fullNavyCollision) {
    for (itAllied = gameWorld.getAlliedFleet().begin(); itAllied !=
                                                        gameWorld.getAlliedFleet().end(); ++itAllied) { //creazione lista contenete tutte le navi di gioco, propedeutica al controllo delle collisoni
        iteratorPositions itPos;
        itPos.it = itAllied;
        fullNavyCollision.push_back(itPos);
    }
    for (itEnemy = gameWorld.getEnemyFleet().begin(); itEnemy != gameWorld.getEnemyFleet().end(); ++itEnemy) {
        iteratorPositions itPos;
        itPos.it = itEnemy;
        fullNavyCollision.push_back(itPos);
    }
}
void
gameLoop(int &width, int &height, int &tileDim, windowMode &videoMode, sf::Color &deathColor, sf::Color &selectedColor,
         sf::Color &concealedColor, sf::Color &removeColor, const sf::ContextSettings &settings, sf::Clock &clock,
         sf::RenderWindow &window, GameWorld &gameWorld, bool &found, bool &clicked,
         std::list<std::unique_ptr<WarShip>>::iterator &itSecondClick, std::list<iteratorPositions> &lst,
         std::list<iteratorPositions> &fullNavyCollision, std::list<MvcView> &views, Button &airplaneButton,
         std::list<navyPositionsForAirAttack> &airTargets) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11 &&
                       videoMode == windowMode::Fullscreen) {
                window.create(sf::VideoMode(width, height), "OpenGL", sf::Style::Default, settings);
                videoMode = windowMode::Windowed;
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11 &&
                       videoMode == windowMode::Windowed) {
                window.create(sf::VideoMode(width, height), "OpenGL", sf::Style::Fullscreen, settings);
                videoMode = windowMode::Fullscreen;
            } else if (event.type == sf::Event::MouseButtonPressed) {
                manageSelection(window, event, gameWorld, found, clicked, lst, itSecondClick, airplaneButton,
                                airTargets);
            } else if (event.type == sf::Event::MouseWheelMoved) {

            } else if (event.type == sf::Event::MouseMoved) {

            }
        }
        window.clear();
        drawMap(window, gameWorld);
        drawAndManageEnemyShips(window, gameWorld, deathColor, selectedColor, concealedColor, removeColor);
        drawAndManageAlliedShips(window, gameWorld, deathColor, selectedColor, concealedColor, removeColor, views,
                                 airplaneButton);
        update(lst, clock.restart().asSeconds(), fullNavyCollision, gameWorld, tileDim, window, airTargets, views);
        fpsManagment(window, clock);//calcola e mostra fps con l'aggiunta dei font
    }
}
