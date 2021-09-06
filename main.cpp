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

auto f = [](std::list<iteratorPositions> fullNavyCollision, GameWorld &gameWorld, int tileDim,
            sf::RenderWindow &window) { //Scorre la lista di iteratori che puntano ad ogni nave di gioco e ogni sprite di ogni nave verrà controllata con ogni sprite di nave tranne se stessa per verificare l'avvenuta collisione
    while (window.isOpen()) {
        for (auto iter = fullNavyCollision.begin(); iter != fullNavyCollision.end(); ++iter) {

            for (auto &iterSecond: fullNavyCollision) {

                if (iter->it->get() != iterSecond.it->get()) {
                    if (Collision::PixelPerfectTest(iter->it->get()->getSprite(), iterSecond.it->get()->getSprite())) {
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
                             std::list<iteratorPositions> &fullNavyCollision, int tileDim) {
    while (window.isOpen()) {

        for (auto &itNaval: fullNavyCollision) {

            if (itNaval.it->get()->getHp() > 0) {

                for (int row = 0; row < (gameWorld.getMapHeight() / tileDim); row++)

                    for (int column = 0; column < (gameWorld.getMapWidth() / tileDim); column++) {

                        if (gameWorld.tiles[row][column]->getTileType() == TileType::Wave &&
                            Collision::PixelPerfectTest(itNaval.it->get()->getSprite(),
                                                        gameWorld.tiles[row][column]->getSprite())) {

                            itNaval.it->get()->setCurrentSpeed(itNaval.it->get()->getMaxSpeed() * 0.80);
                            itNaval.it->get()->setConcealed(false);


                        } else if (gameWorld.tiles[row][column]->getTileType() == TileType::Whirlpool &&
                                   Collision::PixelPerfectTest(itNaval.it->get()->getSprite(),
                                                               gameWorld.tiles[row][column]->getSprite())) {

                            itNaval.it->get()->setDamage(itNaval.it->get()->getHp() * 0.00001);
                            itNaval.it->get()->setConcealed(false);

                        } else if (gameWorld.tiles[row][column]->getTileType() == TileType::Fog &&
                                   Collision::PixelPerfectTest(itNaval.it->get()->getSprite(),
                                                               gameWorld.tiles[row][column]->getSprite())) {

                            itNaval.it->get()->setConcealed(true);

                        }
                    }
            } else {
                itNaval.it->get()->setCollision(false);
                itNaval.it->get()->setDeath(true);
                for (auto &itCannons: itNaval.it->get()->getArsenalList()) {
                    itCannons->getAmmoType()->setArrived(true);
                }
            }

        }


    }

};

auto checkHit = [](std::list<iteratorPositions> &fullNavy, sf::Window &window, Explosion &explosion) {
    while (window.isOpen()) {
        for (auto &iteratorNavy: fullNavy) {
            for (auto &iteratorTarget: fullNavy) {
                if (iteratorNavy.it != iteratorTarget.it) {

                    for (auto &iteratorCannons: iteratorNavy.it->get()->getArsenalList()) {
                        if (iteratorCannons->getTextureName() != "AntiAircraft" &&
                            iteratorCannons->getTextureName() != "TorpedoTube" &&
                            !iteratorCannons->getAmmoType()->isArrived()) {
                            if (Collision::PixelPerfectTest(iteratorCannons->getAmmoType()->getSprite(),
                                                            iteratorTarget.it->get()->getSprite())) {
                                double directDamage = 0;
                                Dice critical(3, iteratorCannons->getAmmoType()->getSprite().getPosition().y);
                                if (iteratorCannons->getTextureName() == "HeavlyCannon") {

                                    if (((critical.roll(1) - 1) *
                                         ((800 * iteratorCannons->getAmmoType()->getPenetrationMult()) *
                                          ((iteratorCannons->getAmmoType()->getCurrentSpeed()) /
                                           (iteratorCannons->getAmmoType()->getSpeed() *
                                            iteratorCannons->getAmmoType()->getSpeedMult())))) >
                                        iteratorTarget.it->get()->getArmour()) {
                                        directDamage =
                                                (critical.roll(1) - 1) * iteratorCannons->getAmmoType()->getDmgMult() *
                                                iteratorCannons->getFirepower();
                                    }

                                } else if (iteratorCannons->getTextureName() == "MediumCannon") {
                                    if (((critical.roll(1) - 1) *
                                         ((400 * iteratorCannons->getAmmoType()->getPenetrationMult()) *
                                          ((iteratorCannons->getAmmoType()->getCurrentSpeed()) /
                                           (iteratorCannons->getAmmoType()->getSpeed() *
                                            iteratorCannons->getAmmoType()->getSpeedMult())))) >
                                        iteratorTarget.it->get()->getArmour()) {
                                        directDamage =
                                                (critical.roll(1) - 1) * iteratorCannons->getAmmoType()->getDmgMult() *
                                                iteratorCannons->getFirepower();
                                    }

                                } else {
                                    if (((critical.roll(1) - 1) *
                                         ((200 * iteratorCannons->getAmmoType()->getPenetrationMult()) *
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


std::vector<Fleet> alliedDummyFleet() {
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


/*
void collisonControl(std::list<iteratorPositions> &fullNavyCollision,GameWorld &gameWorld)//Scorre la lista di iteratori che puntano ad ogni nave di gioco e ogni sprite di ogni nave verrà controllata con ogni sprite di nave tranne se stessa per verificare l'avvenuta collisione
{
    for(auto iter = fullNavyCollision.begin();iter!=fullNavyCollision.end();++iter){

        for(auto iterSecond = fullNavyCollision.begin();iterSecond!=fullNavyCollision.end();++iterSecond){

            if(iter->it->get() != iterSecond->it->get()){
               if(Collision::PixelPerfectTest(iter->it->get()->getSprite(),iterSecond->it->get()->getSprite())){
                    iter->it->get()->setCollision(false);
                    iterSecond->it->get()->setCollision(false);
               }
            }else{
            }

        }
    }
}

*/






void update(std::list<iteratorPositions> &lst, double dt, std::list<iteratorPositions> &fullNavyCollision,
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

    sf::Color deathColor(140, 140, 140, 120);
    sf::Color selectedColor(196, 255, 168, 255);
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
    GameWorld gameWorld = GameWorld(a, b, c, d, e, fleet, FactionType::Uk, FactionType::Italy, 8, boundaries, width,
                                    height, tileDim);
    int shipCounter = 0;
    bool found = false;
    auto itSecondClick = gameWorld.getAlliedFleet().begin();
    auto itAllied = gameWorld.getAlliedFleet().begin();
    auto itEnemy = gameWorld.getEnemyFleet().begin();
    auto itTiles = gameWorld.getTiles().begin();
    sf::Vector2f pos;
    pos.x = 1;
    pos.y = 1;
    Explosion explosion(pos);
    std::list<iteratorPositions> lst;
    std::list<iteratorPositions> fullNavyCollision;

    for (itAllied = gameWorld.getAlliedFleet().begin(); itAllied != gameWorld.getAlliedFleet().end(); ++itAllied) {
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
    std::thread thread_checkHit(checkHit, std::ref(fullNavyCollision), std::ref(window), std::ref(explosion));
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

                        sf::Vector2<double> coords(event.mouseButton.x, event.mouseButton.y);
                        auto translated_pos = window.mapPixelToCoords(static_cast <sf::Vector2i> (coords));
                        if (found == false) {

                            itSecondClick = gameWorld.getAlliedFleet().begin();

                            //FIXME cambiare nave selezionata
                            for (auto it = gameWorld.getAlliedFleet().begin();
                                 it != gameWorld.getAlliedFleet().end() && found == false; ++it, shipCounter++) {

                                if (it->get()->getSprite().getGlobalBounds().contains(translated_pos)) {

                                    it->get()->setSelected(true);
                                    found = true;

                                }

                            }
                            if (found == false) {
                                shipCounter = 0;
                            }
                        } else {
                            int miniCounter = 0;
                            bool foundIter = false;
                            while (miniCounter < shipCounter - 1) {
                                ++itSecondClick;
                                miniCounter++;
                            }



                            for (auto iter = lst.begin(); iter != lst.end() && foundIter == false; ++iter) {
                                if (iter->it == itSecondClick) {
                                    foundIter = true;
                                    lst.erase(iter);
                                }

                            }


                            iteratorPositions itPos;
                            itPos.it = itSecondClick;
                            itPos.pos = coords;
                            lst.push_back(itPos);
                            shipCounter = 0;
                            found = false;
                            itPos.it->get()->setSelected(false);
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
        for (int i = 0; i < (gameWorld.getMapHeight() / 30); i++) {
            for (int j = 0; j < (gameWorld.getMapWidth() / 30); j++) {
                window.draw(gameWorld.getTiles()[i][j]->getSprite());

            }

        }

        for (auto &it: gameWorld.getEnemyFleet()) {
            if (it.get()->isDeath()) {
                it.get()->getSprite().setColor(deathColor);
            } else if(it.get()->isSelected()) {
                it.get()->getSprite().setColor(selectedColor);
            } else {
                it.get()->getSprite().setColor(removeColor);
            }
            window.draw(it->getSprite());


            for (auto const &itArsenal: it->getArsenalList())
                if (itArsenal->getTextureName() != "AntiAircraft" && itArsenal->getTextureName() != "TorpedoTube") {
                    if (it.get()->isDeath()) {
                        itArsenal.get()->getSprite().setColor(deathColor);
                    } else if(it.get()->isSelected()) {
                        itArsenal.get()->getSprite().setColor(selectedColor);
                    } else {
                        itArsenal.get()->getSprite().setColor(removeColor);
                    }
                    window.draw(itArsenal->getSprite());
                    if (!itArsenal->getAmmoType()->isArrived()) {
                        window.draw(itArsenal->getAmmoType()->getSprite());
                    }
                }

            for(auto const &itBars : it->getBars())
                window.draw(itBars->getSprite());

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

        for (auto &it: gameWorld.getAlliedFleet()) {
            if (it.get()->isDeath()) {
                it.get()->getSprite().setColor(deathColor);
            } else if(it.get()->isSelected()) {
                it.get()->getSprite().setColor(selectedColor);
            } else {
                it.get()->getSprite().setColor(removeColor);
            }
            window.draw(it->getSprite());

            for (auto const &itArsenal: it->getArsenalList())
                if (itArsenal->getTextureName() != "AntiAircraft" && itArsenal->getTextureName() != "TorpedoTube") {
                    if (it.get()->isDeath()) {
                        itArsenal.get()->getSprite().setColor(deathColor);
                    } else if(it.get()->isSelected()) {
                        itArsenal.get()->getSprite().setColor(selectedColor);
                    } else {
                        itArsenal.get()->getSprite().setColor(removeColor);
                    }
                    window.draw(itArsenal->getSprite());
                    if (!itArsenal->getAmmoType()->isArrived()) {
                        window.draw(itArsenal->getAmmoType()->getSprite());
                    } else {/*
                        if (abs(itArsenal->getAmmoType()->getSprite().getPosition().x -
                                itArsenal->getAmmoType()->getTargetPoint().x) < 5 &&
                            abs(itArsenal->getAmmoType()->getSprite().getPosition().y -
                                itArsenal->getAmmoType()->getTargetPoint().y) < 5){
                            explosion.setFrame(0, itArsenal->getAmmoType()->getTargetPoint());
                            window.draw(explosion.getSprite());
                        }*/
                    }
                }
            for(auto const &itBars : it->getBars())
                window.draw(itBars->getSprite());

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