#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include "GameWorld.h"

enum class windowMode {
    Windowed,
    Fullscreen
};

int main() {
    std::vector<Fleet> fleet;
    Fleet submarineFleet;
    submarineFleet.name = ModelType::I400;
    submarineFleet.num = 1;
    submarineFleet.type = ShipType::Submarine;
    fleet.emplace_back(submarineFleet);
    sf::Vector2i boundaries(1920, 1080);
    int a, b, c, d, e;
    int width, height, tileDim;
    windowMode videoMode = windowMode::Windowed;
    a = 10;
    b = 10;
    c = 10;
    d = 10;
    e = 10;

    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 2;
    settings.minorVersion = 1;

    sf::RenderWindow window;
    auto desktop = sf::VideoMode::getDesktopMode();
    width = desktop.width;
    height = desktop.height;
    tileDim = 30;  //FIXME adattabile a tutte le risoluzioni
    window.create(sf::VideoMode(width, height), "SeaLion", sf::Style::Close, settings);
    window.setPosition(sf::Vector2i(0, 0));

    GameWorld gameWorld = GameWorld(a, b, c, d, e, fleet, FactionType::Japan, FactionType::Italy, 8, boundaries, width,
                                    height, tileDim);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11 &&
                       videoMode == windowMode::Fullscreen) {
                window.create(sf::VideoMode(width, height), "OpenGL", sf::Style::Close, settings);
                videoMode = windowMode::Windowed;
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11 &&
                       videoMode == windowMode::Windowed) {
                window.create(sf::VideoMode(width, height), "OpenGL", sf::Style::Fullscreen, settings);
                videoMode = windowMode::Fullscreen;
            }
            window.setPosition(sf::Vector2i(0, 0));
        }

        window.clear();
        for (int i = 0; i < (gameWorld.getMapHeight() / 30); i++) {
            for (int j = 0; j < (gameWorld.getMapWidth() / 30); j++) {
                window.draw(gameWorld.getTiles()[i][j]->getSprite());

            }

        }

        for (auto it = gameWorld.getEnemyFleet().begin(); it != gameWorld.getEnemyFleet().end(); ++it) {
            window.draw(it->get()->getSprite());

            /*for(auto itArsenal = it->get()->getArsenalList().begin(); itArsenal!= it->get()->getArsenalList().end(); ++itArsenal){
                window.draw(itArsenal->get().);
            }*/

        }

        for (auto it = gameWorld.getAlliedFleet().begin(); it != gameWorld.getAlliedFleet().end(); ++it) {


        }

        window.display();
    }
    return 0;
}
