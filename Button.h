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
    std::string name;
    int width;
    int length;
    bool clicked;
public:
    Button(const std::string &name, const int &width, const int &length, sf::Vector2f pos);

    bool setUpSprite(std::string textureName);

    bool checkClick (sf::Vector2f clickPos);

    void setPos(const sf::Vector2f &pos);

    int getWidth() const;

    int getLength() const;

    void setWidth(int width);

    void setLength(int length);

    sf::Sprite &getSprite();

    void setClicked(bool clickable);

    bool isClicked() const;
};


#endif //SEALION_BUTTON_H
