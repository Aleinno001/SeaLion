//
// Created by davide on 18/07/21.
//

#ifndef SEALION_BULLET_H
#define SEALION_BULLET_H

#include <string>
#include <stdexcept>
#include "SFML/Graphics.hpp"
#include "CurrentDir.h"
#include "math.h"


class Bullet {
public:
    Bullet(const std::string &bulletName, int width, int length);
    void reachTarget ();

private:
    bool arrived {true};
    sf::Vector2f targetPoint;
    sf::Vector2f startPoint;
    float currentSpeed{0};
    float speed {200};
    float damage{};
    float penetration{};
    float speedMult {1};
    float deceleration{1};
    sf::Sprite sprite;
    sf::Texture texture;
    std::string bulletName;
    int width;
    int length;

    bool setUpSprite(std::string textureName);

    void resetOrigin();

public:
    void setTargetPoint(const sf::Vector2f &targetPoint);

    void setStartPoint(const sf::Vector2f &startPoint);

    const sf::Sprite &getSprite() const;

    const sf::Vector2f &getTargetPoint() const;

    bool isArrived() const;

    void setArrived(bool isArrived);
};



#endif //SEALION_BULLET_H
