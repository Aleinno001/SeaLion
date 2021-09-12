//
// Created by pala on 9/11/21.
//

#include "MvcController.h"

void MvcController::startUpEngine() {

    if (AircraftCarrier *model = dynamic_cast<AircraftCarrier *>(model)) {
        model->searchAndHuntDownEnemyTargets();
    }

}
