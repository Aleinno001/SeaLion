//
// Created by davide on 11/09/21.
//

#include "MvcView.h"

MvcView::MvcView(WarShip &aircraftCarrier, MvcController &controller, sf::Window &window) : model(
        aircraftCarrier), controller(controller), window(window) {
    airplaneButtonClickable = false;
    if (AircraftCarrier *pAircraftCarrier = dynamic_cast<AircraftCarrier *>(&model)) {
        pAircraftCarrier->addMvcObserver(std::shared_ptr<MvcObserver>(this));
    }
}

void MvcView::airplaneClick(std::_List_iterator<std::unique_ptr<WarShip>> target,double dt) {
    controller.startUpEngine(target,dt);
}

void MvcView::updateMvcObserver() {
    airplaneButtonClickable = false;
}

/*
MvcView::~MvcView() {

    if (AircraftCarrier *pAircraftCarrier = dynamic_cast<AircraftCarrier *>(&model)) {
        pAircraftCarrier->removeMvcObserver(std::shared_ptr<MvcView>(this));
    }

}
*/
WarShip &MvcView::getAircraftCarrier() const {
    return model;
}


bool MvcView::isAirplaneButtonClickable() const {
    return airplaneButtonClickable;
}

MvcView *MvcView::getInstance() {
    return this;
}

bool MvcView::checkAirplaneButtonClick(sf::Vector2f clickPos, Button &b) {
    bool result = false;
    if (b.getSprite().getGlobalBounds().contains(clickPos)) {
        result = true;
    }
    return result;
}
