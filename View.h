//
// Created by pala on 02/07/21.
//

#ifndef SEALION_VIEW_H
#define SEALION_VIEW_H

#include "Bonus.h"


class View {

private:
    WarShip *model;
    Bonus *controller;
public:
    View(WarShip *m, Bonus *c) : model(m), controller(c) {};

    WarShip *getModel() const;

    Bonus *getController() const;

    void update();

    void bonusButtonPress();
};


#endif //SEALION_VIEW_H
