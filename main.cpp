#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include "GameWorld.h"

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
    int videoMode = sf::Style::Fullscreen;
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    e = 5;
    width = 1920;
    height = 1080;
    tileDim = 30;
    sf::RenderWindow window(sf::VideoMode(width, height), "SeaLion", videoMode);
    GameWorld gameWorld = GameWorld(a, b, c, d, e, fleet, FactionType::Japan, FactionType::Italy, 8, boundaries, width,
                                    height, tileDim);
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
            if (e.key.code == sf::Keyboard::Escape && videoMode == sf::Style::Fullscreen) {
                videoMode = 0;
                window.create(sf::VideoMode(width, height), "SeaLion");
            }
        }

        window.clear();
        for (int i = 0; i < (gameWorld.getMapHeight() / 30); i++) {
            for (int j = 0; j < (gameWorld.getMapWidth() / 30); j++) {
                window.draw(gameWorld.tiles[i][j]->sprite);
            }
        }
        window.display();
    }
    return 0;
}
