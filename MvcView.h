//
// Created by davide on 11/09/21.
//

#ifndef SEALION_MVCVIEW_H
#define SEALION_MVCVIEW_H


#include "MvcObserver.h"
#include "AircraftCarrier.h"
#include "MvcController.h"
#include "Button.h"

class MvcView : public MvcObserver {
private:
    WarShip &model;
    MvcController &controller;
    sf::Window &window;
    sf::Texture tx;
    bool airplaneButtonClickable;

public:
    MvcView(WarShip &aircraftCarrier, MvcController &controller, sf::Window &window);

    void airplaneClick();

    void updateMvcObserver() override;

    //virtual ~MvcView();

    virtual ~MvcView() = default;

    WarShip &getAircraftCarrier() const;

    bool isAirplaneButtonClickable() const;

    MvcView *getInstance();

    bool checkAirplaneButtonClick(sf::Vector2f clickPos, Button &b);
};


#endif //SEALION_MVCVIEW_H
