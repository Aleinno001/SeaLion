//
// Created by pala on 9/17/21.
//
#include "ConcreteWarPlane.h"
#include "ToolBox.h"
void ConcreteWarPlane::attack() {
    return;//FIXME Implementa
}
void ConcreteWarPlane::update() {
    sprite.setPosition(sprite.getPosition() + subject_.getMovement());
    sprite.setRotation(subject_.getSprite().getRotation());
    sf::Transform rotation;
    rotation.rotate(sprite.getRotation(), subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(sprite.getPosition());
    sprite.setPosition(newPosition);
}
bool ConcreteWarPlane::searchTarget() {
    return 0;//FIXME Implementa
}
float ConcreteWarPlane::rotate() {
    return 0;//FIXME Implementa
}
bool ConcreteWarPlane::canEngage() const {
    return 0;//FIXME Implementa
}
void ConcreteWarPlane::move() {
    return;//FIXME Implementa
}
void ConcreteWarPlane::removeMeFromTheList() {
    subject_.detachPlanes(std::shared_ptr<WarPlane>(this));
}

