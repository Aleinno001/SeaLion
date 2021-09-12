//
// Created by davide on 11/09/21.
//

#include "MvcView.h"

MvcView::MvcView(WarShip &aircraftCarrier, MvcController &controller, Button &button, sf::Window &window) : model(
        aircraftCarrier), controller(controller), button(button), window(window) {
    sf::Vector2f pos;
    pos.x = window.getSize().x / 2;
    pos.y = window.getSize().y - button.getLength() / 2;
    button.setPos(pos);
    if (AircraftCarrier *model = dynamic_cast<AircraftCarrier *>(model)) {
        model->addMvcObserver(std::shared_ptr<MvcObserver>(this));
    }
}

void MvcView::airplaneClick() {
    controller.startUpEngine();
}

void MvcView::updateMvcObserver() {
    button.getSprite().setColor(sf::Color(30, 30, 30));
    button.setClickable(false);
}

MvcView::~MvcView() {

    if (AircraftCarrier *model = dynamic_cast<AircraftCarrier *>(model)) {
        model->removeMvcObserver(std::shared_ptr<MvcView>(this));
    }

}

WarShip &MvcView::getAircraftCarrier() const {
    return model;
}

Button &MvcView::getButton() const {
    return button;
}
