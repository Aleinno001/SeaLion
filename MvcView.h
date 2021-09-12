//
// Created by davide on 11/09/21.
//

#ifndef SEALION_MVCVIEW_H
#define SEALION_MVCVIEW_H


#include "MvcObserver.h"
#include "AircraftCarrier.h"
#include "MvcController.h"
#include "Button.h"

class MvcView: public MvcObserver{
private:
    WarShip &model;
    MvcController &controller;
    Button &button;
    sf::Window &window;

public:
    MvcView(WarShip &aircraftCarrier, MvcController &controller, Button &button, sf::Window &window);

    void airplaneClick();

    void updateMvcObserver() override;

    virtual ~MvcView();

    WarShip &getAircraftCarrier() const;

    Button &getButton() const;
};


#endif //SEALION_MVCVIEW_H
