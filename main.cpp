#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include "GameWorld.h"
#include <thread>
#include "Collision.h"
#include "Explosion.h"

enum class windowMode {
    Windowed,
    Fullscreen
};

typedef struct iteratorPositions {
    std::_List_iterator<std::unique_ptr<WarShip>> it;
    sf::Vector2<double> pos;
};
//FIXME da sistemare il sistema di incaglio delle navi e il danno da speronamento + se una barca muore l'altra non si può muovere
auto f = [](std::list<iteratorPositions> fullNavyCollision, GameWorld &gameWorld, int tileDim,
            sf::RenderWindow &window) { //Scorre la lista di iteratori che puntano ad ogni nave di gioco e ogni sprite di ogni nave verrà controllata con ogni sprite di nave tranne se stessa per verificare l'avvenuta collisione
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

            for (int row = 0; row < (gameWorld.getMapHeight() / tileDim); row++) {

                for (int column = 0; column < (gameWorld.getMapWidth() / tileDim); column++) {

                    if (gameWorld.tiles[row][column]->getTileType() == TileType::Dirt &&
                        Collision::PixelPerfectTest(iterNavy.it->get()->getSprite(),
                                                    gameWorld.tiles[row][column]->getSprite())) {//Se il blocco è di terra e se avviene la collisione
                        iterNavy.it->get()->setCollision(false);
                        gameWorld.tiles[row][column]->setIsPassable(false);
                    }

                }

            }

        }


    }
};

auto tilesCheckAndDeath = [](sf::RenderWindow &window, GameWorld &gameWorld,
                             std::list<iteratorPositions> &fullNavyCollision, int tileDim) { //thread per il controllo e l'applicazione degli effetti tiles
    bool enteredFog = false;
    while (window.isOpen()) {

        for (auto &itNaval: fullNavyCollision) {
            enteredFog = false;
            if (itNaval.it->get()->getHp() > 0) {

                for (int row = 0; row < (gameWorld.getMapHeight() / tileDim); row++)

                    for (int column = 0; column < (gameWorld.getMapWidth() / tileDim); column++) {

                        if (gameWorld.tiles[row][column]->getTileType() == TileType::Wave &&        //Applica i relativi effetti se la tile è di mare mosso
                            Collision::PixelPerfectTest(itNaval.it->get()->getSprite(),
                                                        gameWorld.tiles[row][column]->getSprite())) {
                            itNaval.it->get()->setConcealed(false);
                            itNaval.it->get()->setCurrentSpeed(itNaval.it->get()->getMaxSpeed() * 0.80);


                        } else if (gameWorld.tiles[row][column]->getTileType() == TileType::Whirlpool &&  //Apllica i seguenti effetti se la tile è di tipo muninello
                                   Collision::PixelPerfectTest(itNaval.it->get()->getSprite(),
                                                               gameWorld.tiles[row][column]->getSprite())) {
                            itNaval.it->get()->setConcealed(false);
                            itNaval.it->get()->setDamage(itNaval.it->get()->getHp() * 0.00003);
                            itNaval.it->get()->notifyBarsDamage();


                        } else if (gameWorld.tiles[row][column]->getTileType() == TileType::Fog &&  //applica i seguenti effetti se la tile è di nebbia
                                   Collision::PixelPerfectTest(itNaval.it->get()->getSprite(),
                                                               gameWorld.tiles[row][column]->getSprite())) {

                            itNaval.it->get()->setConcealed(true);
                            enteredFog = true;

                        }
                    }
            } else { //controla se la nave è distrutta e applioca i relativi effetti
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

};

auto checkHit = [](std::list<iteratorPositions> &fullNavy, sf::Window &window) {
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
                                if (iteratorCannons->getTextureName() == "HeavlyCannon") {        //Applica gli effetti del cannone pesante se la nave spara col cannone pesante

                                    if (((critical.roll(1) - 1) *
                                         ((800 * iteratorCannons->getAmmoType()->getPenetrationMult()) * //calcolo del livello di prenetrazione armatura e dinamica casualità con tiro di dado
                                          ((iteratorCannons->getAmmoType()->getCurrentSpeed()) /
                                           (iteratorCannons->getAmmoType()->getSpeed() *
                                            iteratorCannons->getAmmoType()->getSpeedMult())))) >
                                        iteratorTarget.it->get()->getArmour()) {
                                        directDamage =
                                                (critical.roll(1) - 1) * iteratorCannons->getAmmoType()->getDmgMult() *
                                                iteratorCannons->getFirepower();
                                    }

                                } else if (iteratorCannons->getTextureName() == "MediumCannon") { //Applica gli effetti del cannone pesante se la nave spara col cannone medio
                                    if (((critical.roll(1) - 1) *
                                         ((400 * iteratorCannons->getAmmoType()->getPenetrationMult()) *  //calcolo del livello di prenetrazione armatura e dinamica casualità con tiro di dado
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
                                         ((200 * iteratorCannons->getAmmoType()->getPenetrationMult()) * //calcolo del livello di prenetrazione armatura e dinamica casualità con tiro di dado
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

};


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









void update(std::list<iteratorPositions> &lst, double dt, std::list<iteratorPositions> &fullNavyCollision, //funzione di base per gestir el'aggiornamento del gioco durante il game loop
            GameWorld &gameWorld, int tileDim, sf::RenderWindow &window) {
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
    int a, b, c, d, e;
    int width, height, tileDim;
    windowMode videoMode = windowMode::Windowed;
    a = 3;
    b = 3;
    c = 3;
    d = 3;
    e = 2;

    sf::Color deathColor(100, 100, 100, 120);
    sf::Color selectedColor(196, 255, 168, 255);
    sf::Color concealedColor(250, 250, 250, 180);
    sf::Color removeColor(255, 255, 255, 255);
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 2;
    settings.minorVersion = 1;
    sf::Clock clock;
    sf::RenderWindow window;
    auto desktop = sf::VideoMode::getDesktopMode();
    width = desktop.width;
    height = desktop.height;
    tileDim = 30;  //FIXME adattabile a tutte le risoluzioni
    window.create(sf::VideoMode(width, height), "SeaLion", sf::Style::Fullscreen, settings);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    GameWorld gameWorld = GameWorld(a, b, c, d, e, fleet, FactionType::Uk, FactionType::Japan, 8, boundaries, width,
                                    height, tileDim);
    int shipCounter = 0;
    bool found = false;
    bool clicked = false;
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

    for (itAllied = gameWorld.getAlliedFleet().begin(); itAllied != gameWorld.getAlliedFleet().end(); ++itAllied) { //creazione lista contenete tutte le navi di gioco, propedeutica al controllo delle collisoni
        iteratorPositions itPos;
        itPos.it = itAllied;
        fullNavyCollision.push_back(itPos);
    }
    for (itEnemy = gameWorld.getEnemyFleet().begin(); itEnemy != gameWorld.getEnemyFleet().end(); ++itEnemy) {
        iteratorPositions itPos;
        itPos.it = itEnemy;
        fullNavyCollision.push_back(itPos);
    }



    std::thread thread_collision(f, std::ref(fullNavyCollision), std::ref(gameWorld), tileDim, std::ref(window));
    std::thread thread_tiles_effect(tilesCheckAndDeath, std::ref(window), std::ref(gameWorld),
                                    std::ref(fullNavyCollision), tileDim);
    std::thread thread_checkHit(checkHit, std::ref(fullNavyCollision), std::ref(window));
    thread_collision.detach();
    thread_tiles_effect.detach();
    thread_checkHit.detach();
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
                switch (event.key.code) {
                    case sf::Mouse::Left: {

                        //FIXME le hitbox della selezione sono calcolate in base ai vertici della sprite e non ruota

                        sf::Vector2<double> coords(event.mouseButton.x, event.mouseButton.y);
                        auto translated_pos = window.mapPixelToCoords(static_cast <sf::Vector2i> (coords));     /*Gestione della selezione navale e comando di spostamento*/

                        found = false;
                        for (auto it = gameWorld.getAlliedFleet().begin();
                             it != gameWorld.getAlliedFleet().end() && !found; ++it, shipCounter++) {

                            if (it->get()->getSprite().getGlobalBounds().contains(translated_pos) &&
                                !it->get()->isDeath()) {
                                itSecondClick->get()->setSelected(false);
                                it->get()->setSelected(true);
                                found = true;
                                clicked = false;
                                itSecondClick = it;
                            }
                        }
                        if (!found && !clicked) {
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
                    }
                        break;

                    case sf::Mouse::Right:

                        break;
                }
            } else if (event.type == sf::Event::MouseWheelMoved) {

            } else if (event.type == sf::Event::MouseMoved) {

            }

        }

        window.clear();
        for (int i = 0; i < (gameWorld.getMapHeight() / 30); i++) { //disegna mappa
            for (int j = 0; j < (gameWorld.getMapWidth() / 30); j++) {
                window.draw(gameWorld.getTiles()[i][j]->getSprite());

            }

        }

        for (auto &it: gameWorld.getEnemyFleet()) { //imposta il colore alle navi selezionate per lo spostamento e gestisci il colore per la selezione
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


        update(lst, clock.restart().asSeconds(), fullNavyCollision, gameWorld, tileDim, window);

        //calcola e mostra fps con l'aggiunta dei font
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
    return 0;
}