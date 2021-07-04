//
// Created by pala on 7/4/21.
//

#ifndef SEALION_GAMETILE_H
#define SEALION_GAMETILE_H

#include <SFML/Graphics.hpp>

class GameTile {
private:
    bool isPassable;
    bool isExit;
    sf::Vector2f pos;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    GameTile(std::string textureName, float x, float y, bool collision, bool exit);

    bool setUpSprite(std::string);
};


#endif //SEALION_GAMETILE_H
