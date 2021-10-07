//
// Created by davide on 11/09/21.
//

#include "Button.h"

#include <utility>

Button::Button(std::string n, const int &w, const int &l, sf::Vector2f pos) {
    name = std::move(n);
    width=w;
    length=l;
    position=pos;
    setUpSprite(name);
    sprite.setOrigin(width / 2, length / 2);
    sprite.setPosition(pos.x-width,pos.y-length);
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
sf::Sprite &Button::getSprite()  {
    return sprite;
}
void Button::setClicked(bool clickable) {
    Button::clicked = clickable;
}
bool Button::isClicked() const {
    return clicked;
}
void Button::drawEquipment(sf::RenderWindow &w) {
    w.draw(sprite);
}
