//
// Created by davide on 11/09/21.
//

#ifndef SEALION_BUTTON_H
#define SEALION_BUTTON_H

#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "ToolBox.h"
#include <iostream>
class Button {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    std::string name;
    int width;
    int length;
    bool clicked;
    sf::Vector2f position;
public:
    Button(std::string n, const int &w, const int &l, sf::Vector2f pos);
    bool setUpSprite(std::string textureName);
    sf::Sprite &getSprite();
    void setClicked(bool clickable);
    bool isClicked() const;
    void drawEquipment(sf::RenderWindow &w);
    ~Button()=default;
};


#endif //SEALION_BUTTON_H
