//
// Created by pala on 9/11/21.
//

#include "MvcController.h"

void MvcController::startUpEngine(std::_List_iterator<std::unique_ptr<WarShip>> &target,double dt) {


        model.searchAndHuntDownEnemyTargets(target,dt);



}

AircraftCarrier &MvcController::getModel() const {
    return model;
}
