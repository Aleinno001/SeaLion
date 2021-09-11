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
    bool clickable;
public:
    Button(const std::string& name, const int &width, const int &length);

    bool setUpSprite(std::string textureName);

    bool checkClick (sf::Vector2f clickPos);

    void setPos(const sf::Vector2f &pos);

    const sf::Vector2f &getPos() const;

    int getWidth() const;

    int getLength() const;

    void setWidth(int width);

    void setLength(int length);

    sf::Sprite &getSprite();

    void setClickable(bool clickable);

    bool isClickable() const;
};


#endif //SEALION_BUTTON_H
