//
// Created by davide on 11/09/21.
//

#include "MvcView.h"

MvcView::MvcView(AircraftCarrier &aircraftCarrier, MvcController &controller, Button &button, sf::Window &window) : aircraftCarrier(
        aircraftCarrier), controller(controller), button(button), window(window) {
    sf::Vector2f pos;
    pos.x = window.getSize().x/2;
    pos.y = window.getSize().y - button.getLength()/2;
    button.setPos(pos);
}

void MvcView::airplaneClick() {
    controller.startUpEngine();
}

void MvcView::updateMvcObserver() {
    button.getSprite().setColor(sf::Color(30, 30, 30));
    button.setClickable(false);
}

MvcView::~MvcView() {

    aircraftCarrier.removeMvcObserver(std::shared_ptr<MvcView> (this));

}
