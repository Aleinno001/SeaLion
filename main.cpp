#include <iostream>
#include "SFML/Graphics.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    /*
    unsigned int windowHeight=400;
    unsigned int windowWidth=400;
    sf::RenderWindow window(sf::VideoMode(windowWidth,windowHeight),"SeaLion");
     */
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

        window.display();
    }
    return 0;
}
