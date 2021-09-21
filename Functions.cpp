//
// Created by alessandro on 20/09/21.
//
#include "Functions.h"
void Functions::searchAirplane(sf::RenderWindow &window, GameWorld &gameWorld){
    while (window.isOpen()) {
        float distance;
        for (auto &iter: gameWorld.getAlliedFleet()) {
            for (auto &iterEnemy: gameWorld.getEnemyFleet()) {
                if (iter->getShipType() == ShipType::AircraftCarrier) {
                    for (auto &iterPlane: iterEnemy->getVehicleList()) {
                        distance = sqrt(
                                pow(iterPlane->getSprite().getPosition().x - iter->getSprite().getPosition().x, 2) +
                                pow(iterPlane->getSprite().getPosition().y - iter->getSprite().getPosition().y, 2));
                        for (auto &iterAntiAir: iter.get()->getArsenalList()) {
                            std::cerr << distance << std::endl;
                            if (iterAntiAir->getTextureName() == "AntiAircraft" &&
                                distance <= iterAntiAir->getRangeOfFire()) {
                                iter.get()->antiAirAttack(iterPlane, iterAntiAir);
                            }
                        }
                        if (iterPlane.get()->getHp() <= 0) {
                            iterPlane.get()->setDeath(true);
                            iter.get()->detachPlanes(iterPlane);
                        }
                    }
                }
            }
        }
    }
}

void Functions::f (std::list<iteratorPositions> fullNavyCollision, GameWorld &gameWorld, sf::RenderWindow &window){
    while (window.isOpen()) {
        for (auto iter = fullNavyCollision.begin(); iter != fullNavyCollision.end(); ++iter) {
            for (auto &iterSecond: fullNavyCollision) {
                if (iter->it->get() != iterSecond.it->get()) {
                    if (Collision::PixelPerfectTest(iter->it->get()->getSprite(), iterSecond.it->get()->getSprite()) &&
                        !(iter->it->get()->isDeath() || iterSecond.it->get()->isDeath())) {
                        iter->it->get()->setCollision(false);
                        iterSecond.it->get()->setCollision(false);
                    }
                }
            }
            //controlla le eventuali collisioni ai bordi della finestra di gioco
            if (((iter->it->get()->getSprite().getPosition().x -
                  iter->it->get()->getSprite().getLocalBounds().width / 2) < 0) ||
                ((iter->it->get()->getSprite().getPosition().y -
                  iter->it->get()->getSprite().getLocalBounds().height / 2) < 0) ||
                ((iter->it->get()->getSprite().getPosition().x +
                  iter->it->get()->getSprite().getLocalBounds().width / 2) > window.getSize().x) ||
                ((iter->it->get()->getSprite().getPosition().y +
                  iter->it->get()->getSprite().getLocalBounds().height / 2) > window.getSize().y)) {
                iter->it->get()->setCollision(false);
            }
        }
        //controllo cllisioni con blocchi di terra
        for (auto &iterNavy: fullNavyCollision) {
            for (int row = 0; row < (gameWorld.getMapHeight() / gameWorld.getTileDim()); row++) {
                for (int column = 0; column < (gameWorld.getMapWidth() / gameWorld.getTileDim()); column++) {
                    if (gameWorld.getTiles()[row][column]->getTileType() == TileType::Dirt &&
                        Collision::PixelPerfectTest(iterNavy.it->get()->getSprite(),
                                                    gameWorld.getTiles()[row][column]->getSprite())) {//Se il blocco è di terra e se avviene la collisione
                        iterNavy.it->get()->setCollision(false);
                        gameWorld.getTiles()[row][column]->setIsPassable(false);
                    }
                }
            }
        }
    }
}
std::vector <Fleet> Functions::alliedDummyFleet() { //nave alleata di testing
    std::vector <Fleet> fleet;
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
void Functions::drawAndManageAlliedShips(sf::RenderWindow &window, GameWorld &gameWorld, sf::Color &deathColor,
                              sf::Color &selectedColor, sf::Color &concealedColor, sf::Color &removeColor,
                              std::list<MvcView<WarShip>> &views, Button &airplaneButton) {
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

void Functions::fpsManagment(sf::RenderWindow &window, sf::Clock &clock) {
    sf::Time time = clock.getElapsedTime();
    int fps = 1.0f / time.asSeconds();
    std::string currentDir = ToolBox::GetCurrentWorkingDir();
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

void Functions::drawMap(sf::RenderWindow &window, GameWorld &gameWorld) {
    for (int i = 0; i < (gameWorld.getMapHeight() / 30); i++) { //disegna la  mappa
        for (int j = 0; j < (gameWorld.getMapWidth() / 30); j++) {
            window.draw(gameWorld.getTiles()[i][j]->getSprite());
        }
    }
}

void Functions::update(std::list<iteratorPositions> &lst, double dt,std::list<iteratorPositions> &fullNavyCollision, GameWorld &gameWorld, sf::RenderWindow &window,std::list<navyPositionsForAirAttack> &airTargets, std::list<MvcView<WarShip>> &views) { //funzione di base per gestir el'aggiornamento del gioco durante il game loopGameWorld &gameWorld, sf::RenderWindow &window,
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
            if (auto *bend = dynamic_cast<ConcreteAircraftCarrier *> (iter.itAllied->get())) {
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

void Functions::drawAndManageEnemyShips(sf::RenderWindow &window, GameWorld &gameWorld, sf::Color &deathColor,
                        sf::Color &selectedColor,
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
        if (it->getShipType() ==
            ShipType::AircraftCarrier) { //disegna gli aerei e gestisci il colore per la selezione
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
void Functions::manageSelection(sf::RenderWindow &window, sf::Event &event, GameWorld &gameWorld, bool &found, bool &clicked,
                     std::list<iteratorPositions> &lst,
                     std::_List_iterator<std::unique_ptr<WarShip>> &itSecondClick,
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
                    if (!found && !clicked &&
                        !airplaneButton.getSprite().getGlobalBounds().contains(translated_pos)) {
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
void Functions::prepareFullNavyList(GameWorld &gameWorld, std::list<std::unique_ptr<WarShip>>::iterator &itAllied,
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
void Functions::gameLoop(int &width, int &height, windowMode &videoMode, sf::Color &deathColor,
              sf::Color &selectedColor,
              sf::Color &concealedColor, sf::Color &removeColor, const sf::ContextSettings &settings,
              sf::Clock &clock,
              sf::RenderWindow &window, GameWorld &gameWorld, bool &found, bool &clicked,
              std::list<std::unique_ptr<WarShip>>::iterator &itSecondClick, std::list<iteratorPositions> &lst,
              std::list<iteratorPositions> &fullNavyCollision, std::list<MvcView<WarShip>> &views, Button &airplaneButton,
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
        update(lst, clock.restart().asSeconds(), fullNavyCollision, gameWorld, window, airTargets, views);
        fpsManagment(window, clock);//calcola e mostra fps con l'aggiunta dei font
    }
}
void Functions::checkHit(std::list<iteratorPositions> &fullNavy, sf::Window &window) {
    while (window.isOpen()) {
        for (auto &iteratorNavy: fullNavy) {
            for (auto &iteratorTarget: fullNavy) {
                if (iteratorNavy.it != iteratorTarget.it) {
                    for (auto &iteratorCannons: iteratorNavy.it->get()->getArsenalList()) { // controlla le collisoni tra i proiettili e tutte le navi permettendo il fuoco amico
                        if (iteratorCannons->getTextureName() != "AntiAircraft" &&
                            iteratorCannons->getTextureName() != "TorpedoTube" &&
                            !iteratorCannons->getAmmoType()->isArrived()) {
                            if (Collision::PixelPerfectTest(iteratorCannons->getAmmoType()->getSprite(),
                                                            iteratorTarget.it->get()->getSprite()) &&
                                !iteratorTarget.it->get()->isDeath()) {
                                double directDamage = 0;
                                Dice critical(3, iteratorCannons->getAmmoType()->getSprite().getPosition().y);
                                if (iteratorCannons->getTextureName() ==
                                    "HeavlyCannon") {        //Applica gli effetti del cannone pesante se la nave spara col cannone pesante
                                    if (((critical.roll(1) - 1) *
                                         ((800 * iteratorCannons->getAmmoType()->getPenetrationMult()) *
                                          //calcolo del livello di prenetrazione armatura e dinamica casualità con tiro di dado
                                          ((iteratorCannons->getAmmoType()->getCurrentSpeed()) /
                                           (iteratorCannons->getAmmoType()->getSpeed() *
                                            iteratorCannons->getAmmoType()->getSpeedMult())))) >
                                        iteratorTarget.it->get()->getArmour()) {
                                        directDamage =
                                                (critical.roll(1) - 1) * iteratorCannons->getAmmoType()->getDmgMult() *
                                                iteratorCannons->getFirepower();
                                    }
                                } else if (iteratorCannons->getTextureName() ==
                                           "MediumCannon") { //Applica gli effetti del cannone pesante se la nave spara col cannone medio
                                    if (((critical.roll(1) - 1) *
                                         ((400 * iteratorCannons->getAmmoType()->getPenetrationMult()) *
                                          //calcolo del livello di prenetrazione armatura e dinamica casualità con tiro di dado
                                          ((iteratorCannons->getAmmoType()->getCurrentSpeed()) /
                                           (iteratorCannons->getAmmoType()->getSpeed() *
                                            iteratorCannons->getAmmoType()->getSpeedMult())))) >
                                        iteratorTarget.it->get()->getArmour()) {
                                        directDamage =
                                                (critical.roll(1) - 1) * iteratorCannons->getAmmoType()->getDmgMult() *
                                                iteratorCannons->getFirepower();
                                    }
                                } else {  //Applica gli effetti del cannone pesante se la nave spara col cannone leggero
                                    if (((critical.roll(1) - 1) *
                                         ((200 * iteratorCannons->getAmmoType()->getPenetrationMult()) *
                                          //calcolo del livello di prenetrazione armatura e dinamica casualità con tiro di dado
                                          ((iteratorCannons->getAmmoType()->getCurrentSpeed()) /
                                           (iteratorCannons->getAmmoType()->getSpeed() *
                                            iteratorCannons->getAmmoType()->getSpeedMult())))) >
                                        iteratorTarget.it->get()->getArmour()) {
                                        directDamage =
                                                (critical.roll(1) - 1) * iteratorCannons->getAmmoType()->getDmgMult() *
                                                iteratorCannons->getFirepower();
                                    }
                                }
                                iteratorCannons->getAmmoType()->hit();
                                iteratorTarget.it->get()->setDamage(directDamage);
                                iteratorTarget.it->get()->notifyBarsDamage();
                            }
                        }
                    }
                }
            }
        }
    }
}
void Functions::tilesCheckAndDeath(sf::RenderWindow &window, GameWorld &gameWorld,std::list<iteratorPositions> &fullNavyCollision) {
    bool enteredFog = false;
    while (window.isOpen()) {
        for (auto &itNaval: fullNavyCollision) {
            enteredFog = false;
            if (itNaval.it->get()->getHp() > 0) {
                for (int row = 0; row < (gameWorld.getMapHeight() / gameWorld.getTileDim()); row++)
                    for (int column = 0; column < (gameWorld.getMapWidth() / gameWorld.getTileDim()); column++) {
                        if (gameWorld.getTiles()[row][column]->getTileType() == TileType::Wave &&
                            //applica i relativi effetti se la tile è di mare mosso
                            Collision::PixelPerfectTest(itNaval.it->get()->getSprite(),
                                                        gameWorld.getTiles()[row][column]->getSprite())) {
                            itNaval.it->get()->setConcealed(false);
                            itNaval.it->get()->setCurrentSpeed(itNaval.it->get()->getMaxSpeed() * 0.80);
                        } else if (gameWorld.getTiles()[row][column]->getTileType() == TileType::Whirlpool &&
                                   //applica i seguenti effetti se la tile è di tipo muninello
                                   Collision::PixelPerfectTest(itNaval.it->get()->getSprite(),gameWorld.getTiles()[row][column]->getSprite())) {
                            itNaval.it->get()->setConcealed(false);
                            itNaval.it->get()->setDamage(itNaval.it->get()->getHp() * 0.00003);
                            itNaval.it->get()->notifyBarsDamage();
                        } else if (gameWorld.getTiles()[row][column]->getTileType() == TileType::Fog &&
                                   //applica i seguenti effetti se la tile è di nebbia
                                   Collision::PixelPerfectTest(itNaval.it->get()->getSprite(),gameWorld.getTiles()[row][column]->getSprite())) {
                            itNaval.it->get()->setConcealed(true);
                            enteredFog = true;
                        }
                    }
            } else {                                                //controlla se la nave è distrutta e applica i relativi effetti
                itNaval.it->get()->setCollision(true);
                itNaval.it->get()->setDeath(true);
                for (auto &itCannons: itNaval.it->get()->getArsenalList()) {
                    itCannons->getAmmoType()->setArrived(true);
                    //FIXME itCannons->removeMeFromTheList();
                }
            }
            if (!enteredFog) {
                itNaval.it->get()->setConcealed(false); //effetti contrari alla nebbia applicati se la nave non si trova sulla nebbia
            }
        }
    }
}
