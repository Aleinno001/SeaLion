#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameWorld.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SeaLion");
    GameWorld gameWorld = GameWorld();
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

        for (int i = 0; i < gameWorld.gridLength; i++) {
            for (int j = 0; j < gameWorld.gridLength; j++) {
                window.draw(gameWorld.tiles[i][j]->sprite);
            }
        }

        window.display();
    }
    return 0;
}
