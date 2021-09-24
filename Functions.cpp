//
// Created by alessandro on 20/09/21.
//
#include "Functions.h"
void Functions::f (std::list<std::shared_ptr<WarShip>> &fullNavyCollision, GameWorld &gameWorld, sf::RenderWindow &window){
    while (window.isOpen()) {
        for (auto &iter:fullNavyCollision) {
            for (auto &iterSecond:fullNavyCollision) {
                if (iter != iterSecond) {
                    if (Collision::PixelPerfectTest(iter->getSprite(), iterSecond->getSprite()) &&
                        !(iter->isDeath() || iterSecond->isDeath())) {
                        iter->setCollision(false);
                        iterSecond->setCollision(false);
                    }
                }
            }
            //controlla le eventuali collisioni ai bordi della finestra di gioco
            if (((iter->getSprite().getPosition().x -
                  iter->getSprite().getLocalBounds().width / 2) < 0) ||
                ((iter->getSprite().getPosition().y -
                  iter->getSprite().getLocalBounds().height / 2) < 0) ||
                ((iter->getSprite().getPosition().x +
                  iter->getSprite().getLocalBounds().width / 2) > window.getSize().x) ||
                ((iter->getSprite().getPosition().y +
                  iter->getSprite().getLocalBounds().height / 2) > window.getSize().y)) {
                iter->setCollision(false);
            }
        }
        //controllo cllisioni con blocchi di terra
        for (auto &iterNavy: fullNavyCollision) {
            for (int row = 0; row < (gameWorld.getMapHeight() / gameWorld.getTileDim()); row++) {
                for (int column = 0; column < (gameWorld.getMapWidth() / gameWorld.getTileDim()); column++) {
                    if (gameWorld.getTiles()[row][column]->getTileType() == TileType::Dirt &&
                        Collision::PixelPerfectTest(iterNavy->getSprite(),gameWorld.getTiles()[row][column]->getSprite())) {//Se il blocco è di terra e se avviene la collisione
                        iterNavy->setCollision(false);
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

void Functions::fpsManagment(sf::RenderWindow &window,float elapsedTime) {
    int fps = 1.0f / elapsedTime;
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
    for (int i = 0; i < (gameWorld.getMapHeight() / gameWorld.getTileDim()); i++) { //disegna la  mappa
        for (int j = 0; j < (gameWorld.getMapWidth() / gameWorld.getTileDim()); j++) {
            window.draw(gameWorld.getTiles()[i][j]->getSprite());
        }
    }
}
void Functions::update(std::list<std::shared_ptr<WarShip>> &fullNavyList,float elapsedTime) { //funzione di base per gestire l'aggiornamento del gioco durante il game loopGameWorld &gameWorld
    for(auto &itShips : fullNavyList){
        itShips->searchTarget(elapsedTime);
    }
}
void Functions::manageSelection(sf::RenderWindow &window, sf::Event &event, GameWorld &gameWorld, std::shared_ptr<WarShip> &selectedShip,std::list<MvcView<Specialty,WarShip>>& views) {
    switch (event.key.code) {
        case sf::Mouse::Left: {
            sf::Vector2f coords(event.mouseButton.x, event.mouseButton.y);
            auto translated_pos = window.mapPixelToCoords(static_cast <sf::Vector2i> (coords));     /*Gestione della selezione navale e comando di spostamento*/
            for (auto &it : gameWorld.getAlliedFleet()) {                                               //
                if (it->getSprite().getGlobalBounds().contains(translated_pos) && !it->isDeath()) {
                    if(selectedShip)
                        selectedShip->setSelected(false);                                                                                    //
                    selectedShip=it;                                                                    //  Fase di selezionamento della nave da parte dell'utente
                    it->setSelected(true);                                                      //
                    return;                                                                             //
                }                                                                                       //
            }                                                                                           //
            for (auto &itView: views) {
                if(!itView.getButton().isClicked()) {                                                               //
                    itView.getButton().getSprite().setColor(sf::Color(255,255,255));         //
                    if (itView.getButton().getSprite().getGlobalBounds().contains(translated_pos)) {                //  Caso bottone del Mvc non è stato ancora cliccato
                        itView.getButton().getSprite().setColor(sf::Color(0, 180,0));         //
                        itView.getButton().setClicked(true);                                               //   Individua il click e imposta lo stato di cliccato
                        return;                                                                                     //
                    }                                                                                               //
                }else{
                    for (auto &it : gameWorld.getEnemyFleet()) {                                                    //
                        if (it->getSprite().getGlobalBounds().contains(translated_pos) && !it->isDeath()) {         // Caso bottone del Mvc cliccato
                            itView.click(it);
                            selectedShip->setSelected(false);                                               //
                            return;                                                                                 //  Imposta i bersagli delle classi che implementano Mvc
                        }                                                                                           //
                    }
                }
            }
            if(selectedShip) {
                selectedShip->setTargetCoordinates(coords);
                selectedShip->setSelected(false);
            }
        }
            break;
        case sf::Mouse::Right:
            break;
    }
}
void Functions::prepareFullNavyList(GameWorld &gameWorld,std::list<std::shared_ptr<WarShip>> &fullNavyList) {
    for (auto & itAllied : gameWorld.getAlliedFleet()) { //creazione lista contenete tutte le navi di gioco, propedeutica al controllo delle collisoni
        std::shared_ptr<WarShip>ele(itAllied.get());
        fullNavyList.push_back(ele);
    }
    for (auto & itEnemy : gameWorld.getEnemyFleet()) {
        std::shared_ptr<WarShip> ele (itEnemy.get());
        fullNavyList.push_back(ele);
    }
}
void Functions::gameLoop(int &width, int &height,  sf::ContextSettings settings, windowMode &videoMode,sf::RenderWindow &window, GameWorld &gameWorld,std::list<std::shared_ptr<WarShip>> &fullNavyList, std::list<MvcView<Specialty,WarShip>> &views,std::shared_ptr<WarShip> selectedShip,sf::Clock &clock) {
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
                manageSelection(window, event, gameWorld,selectedShip,views);
            }
        }
        window.clear();
        drawAll(gameWorld,fullNavyList,window);
        update(fullNavyList,clock.restart().asSeconds());
        fpsManagment(window,clock.restart().asSeconds());//calcola e mostra fps con l'aggiunta dei font
    }
}
void Functions::drawAll(GameWorld &gameWorld,std::list<std::shared_ptr<WarShip>> &fullNavyList,sf::RenderWindow &window){
    drawMap(window, gameWorld);

    for(auto &itShips : fullNavyList){
        itShips->drawEquipment(window);
    }
}
void Functions::checkHit(std::list<std::shared_ptr<WarShip>> &fullNavy, sf::Window &window) {
    while (window.isOpen()) {
        for (auto &iteratorNavy: fullNavy) {
            for (auto &iteratorTarget: fullNavy) {
                if (iteratorNavy != iteratorTarget) {
                    if(iteratorNavy->getShipType()!=ShipType::Submarine) {
                        for (auto &iteratorCannons: iteratorNavy->getArsenalList()) {// controlla le collisoni tra i proiettili e tutte le navi permettendo il fuoco amico
                            if (iteratorCannons->getTextureName() != "AntiAircraft" &&
                                iteratorCannons->getTextureName() != "TorpedoTube" &&
                                !iteratorCannons->getAmmoType()->isArrived()) {
                                if (Collision::PixelPerfectTest(iteratorCannons->getAmmoType()->getSprite(),
                                                                iteratorTarget->getSprite()) &&
                                    !iteratorTarget->isDeath()) {
                                    double directDamage = 0;
                                    Dice critical(3, iteratorCannons->getAmmoType()->getSprite().getPosition().y);
                                    if (iteratorCannons->getTextureName() ==
                                        "HeavlyCannon") {        //Applica gli effetti del cannone pesante se la nave spara col cannone pesante
                                        if (((critical.roll(1) - 1) *
                                             //calcolo del livello di prenetrazione armatura e dinamica casualità con tiro di dado
                                             ((800 * iteratorCannons->getAmmoType()->getPenetrationMult()) *
                                              ((iteratorCannons->getAmmoType()->getCurrentSpeed()) /
                                               (iteratorCannons->getAmmoType()->getSpeed() *
                                                iteratorCannons->getAmmoType()->getSpeedMult())))) >
                                            iteratorTarget->getArmour()) {

                                            directDamage = (critical.roll(1) - 1) *
                                                           iteratorCannons->getAmmoType()->getDmgMult() *
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
                                            iteratorTarget->getArmour()) {
                                            directDamage =
                                                    (critical.roll(1) - 1) *
                                                    iteratorCannons->getAmmoType()->getDmgMult() *
                                                    iteratorCannons->getFirepower();
                                        }
                                    } else {  //Applica gli effetti del cannone pesante se la nave spara col cannone leggero
                                        if (((critical.roll(1) - 1) *
                                             ((200 * iteratorCannons->getAmmoType()->getPenetrationMult()) *
                                              //calcolo del livello di prenetrazione armatura e dinamica casualità con tiro di dado
                                              ((iteratorCannons->getAmmoType()->getCurrentSpeed()) /
                                               (iteratorCannons->getAmmoType()->getSpeed() *
                                                iteratorCannons->getAmmoType()->getSpeedMult())))) >
                                            iteratorTarget->getArmour()) {
                                            directDamage =
                                                    (critical.roll(1) - 1) *
                                                    iteratorCannons->getAmmoType()->getDmgMult() *
                                                    iteratorCannons->getFirepower();
                                        }
                                    }
                                    iteratorCannons->getAmmoType()->hit();
                                    iteratorTarget->setDamage(directDamage);
                                    iteratorTarget->notifyBarsDamage();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void Functions::tilesCheckAndDeath(sf::RenderWindow &window, GameWorld &gameWorld,std::list<std::shared_ptr<WarShip>> &fullNavyCollision) {
    bool enteredFog = false;
    while (window.isOpen()) {
        for (auto &itNaval: fullNavyCollision) {
            enteredFog = false;
            if (itNaval->getHp() > 0) {
                for (int row = 0; row < (gameWorld.getMapHeight() / gameWorld.getTileDim()); row++)
                    for (int column = 0; column < (gameWorld.getMapWidth() / gameWorld.getTileDim()); column++) {
                        if (gameWorld.getTiles()[row][column]->getTileType() == TileType::Wave &&
                            //applica i relativi effetti se la tile è di mare mosso
                            Collision::PixelPerfectTest(itNaval->getSprite(),
                                                        gameWorld.getTiles()[row][column]->getSprite())) {
                            itNaval->setConcealed(false);
                            itNaval->setCurrentSpeed(itNaval->getMaxSpeed() * 0.80);
                        } else if (gameWorld.getTiles()[row][column]->getTileType() == TileType::Whirlpool &&
                                   //applica i seguenti effetti se la tile è di tipo muninello
                                   Collision::PixelPerfectTest(itNaval->getSprite(),gameWorld.getTiles()[row][column]->getSprite())) {
                            itNaval->setConcealed(false);
                            itNaval->setDamage(itNaval->getHp() * 0.00003);
                            itNaval->notifyBarsDamage();
                        } else if (gameWorld.getTiles()[row][column]->getTileType() == TileType::Fog &&
                                   //applica i seguenti effetti se la tile è di nebbia
                                   Collision::PixelPerfectTest(itNaval->getSprite(),gameWorld.getTiles()[row][column]->getSprite())) {
                            itNaval->setConcealed(true);
                            enteredFog = true;
                        }
                    }
            } else {//controlla se la nave è distrutta e applica i relativi effetti
                itNaval->setCollision(true);
                itNaval->setDeath(true);
                for (auto &itCannons: itNaval->getArsenalList()) {
                    itCannons->getAmmoType()->setArrived(true);
                }
            }
            if (!enteredFog) {
                itNaval->setConcealed(false); //effetti contrari alla nebbia applicati se la nave non si trova sulla nebbia
            }
        }
    }
}
void Functions::settingTargets(GameWorld &gameWorld){
    for(auto &itAllied : gameWorld.getAlliedFleet()){
        itAllied->setEnemyList(gameWorld.getEnemyFleet());
    }
    for(auto &itEnemy : gameWorld.getEnemyFleet()){
        itEnemy->setEnemyList(gameWorld.getAlliedFleet());
    }
}