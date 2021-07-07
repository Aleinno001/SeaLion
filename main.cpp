#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameWorld.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SeaLion");
    std::vector<Fleet> fleet;
    Fleet submarineFleet;
    submarineFleet.name = ModelType::I400;
    submarineFleet.num = 1;
    submarineFleet.type = ShipType::Submarine;
    fleet.emplace_back(submarineFleet);
    sf::Vector2i boundaries(1920, 1080);
    int a, b, c, d, e;
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    e = 5;
    GameWorld gameWorld = GameWorld(a, b, c, d, e, fleet, FactionType::Japan, FactionType::Italy, 8, boundaries);
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        for (int i = 0; i < 36 - 1; i++) {
            for (int j = 0; j < 64 - 1; j++) {
                window.draw(gameWorld.tiles[i][j]->sprite);
            }
        }
        window.display();
    }
    return 0;
}
