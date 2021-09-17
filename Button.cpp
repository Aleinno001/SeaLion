//
// Created by davide on 11/09/21.
//

#include "Button.h"

Button::Button(const std::string &name, const int &width, const int &length, sf::Vector2f pos) : name(name),
                                                                                                 width(width),
                                                                                                 length(length) {
    setUpSprite(name);
    sprite.setOrigin(width / 2, length / 2);
    sprite.setPosition(pos);
    clicked = false;
}

bool Button::setUpSprite(std::string textureName) {
    std::string currentDir = ToolBox::GetCurrentWorkingDir();
    std::string unitTestingPath = "UnitTesting";
    std::size_t found = currentDir.find(unitTestingPath);
    if (found != std::string::npos) {
        currentDir.erase(found);
        currentDir.pop_back();
    }
    std::string textPath;
    textPath = currentDir + "/../Res/Buttons/" + textureName + ".png";
    if (!Collision::CreateTextureAndBitmask(texture, textPath)) {
        throw std::runtime_error("Path to tile filename invalid!!");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, length));
    return true;
}

bool Button::checkClick(sf::Vector2f clickPos) {
    bool result = false;
    if(sprite.getGlobalBounds().contains(clickPos)){
        result = true;
    }
    return result;
}

void Button::setPos(const sf::Vector2f &pos) {
    sprite.setPosition(pos);
}

int Button::getWidth() const {
    return width;
}

int Button::getLength() const {
    return length;
}

void Button::setWidth(int width) {
    Button::width = width;
}

void Button::setLength(int length) {
    Button::length = length;
}

sf::Sprite &Button::getSprite()  {
    return sprite;
}

void Button::setClicked(bool clickable) {
    Button::clicked = clickable;
}

bool Button::isClicked() const {
    return clicked;
}
