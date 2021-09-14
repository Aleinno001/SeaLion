//
// Created by pala on 9/11/21.
//

#include "MvcController.h"

void MvcController::startUpEngine(std::_List_iterator<std::unique_ptr<WarShip>> target,double dt) {

    if (AircraftCarrier *model = dynamic_cast<AircraftCarrier *>(model)) {
        model->searchAndHuntDownEnemyTargets(target,dt);
    }


}
