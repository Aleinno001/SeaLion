//
// Created by davide on 11/09/21.
//

#ifndef SEALION_BUTTON_H
#define SEALION_BUTTON_H

#include <SFML/Graphics.hpp>

class Button {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f pos;
    std::string name;
    int width;
    int length;
public:
    Button(const sf::Vector2f &pos, const std::string& name, const int &width, const int &length);

    bool setUpSprite(std::string textureName);

    bool checkClick (sf::Vector2f clickPos);
};


#endif //SEALION_BUTTON_H
