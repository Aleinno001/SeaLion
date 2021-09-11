//
// Created by davide on 11/09/21.
//

#include "Button.h"
#include "CurrentDir.h"

Button::Button(const std::string &name, const int &width, const int &length) : name(name), width(width), length(length) {
    setUpSprite(name);
    clickable = true;
}

bool Button::setUpSprite(std::string textureName) {
    std::string currentDir = CurrentDir::GetCurrentWorkingDir();
    std::string unitTestingPath = "UnitTesting";
    std::size_t found = currentDir.find(unitTestingPath);
    if (found != std::string::npos) {
        currentDir.erase(found);
        currentDir.pop_back();
    }
    std::string textPath;
    textPath = currentDir + "/../Res/Buttons/" + textureName + ".png";
    if (!texture.loadFromFile(textPath)) {
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
    Button::pos = pos;
}

const sf::Vector2f &Button::getPos() const {
    return pos;
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

void Button::setClickable(bool clickable) {
    Button::clickable = clickable;
}

bool Button::isClickable() const {
    return clickable;
}
