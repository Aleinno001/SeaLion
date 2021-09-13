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
    AircraftCarrier &aircraftCarrier;
    MvcController &controller;
    Button &button;
    sf::Window &window;

public:
    MvcView(AircraftCarrier &aircraftCarrier, MvcController &controller, Button &button, sf::Window &window);

    void airplaneClick(std::_List_iterator<std::unique_ptr<WarShip>> enemyListStart,
                       std::_List_iterator<std::unique_ptr<WarShip>> enemyListEnd,double dt);

    void updateMvcObserver() override;

    virtual ~MvcView();
};


#endif //SEALION_MVCVIEW_H
