//
// Created by pala on 9/11/21.
//

#include "MvcController.h"

void MvcController::startUpEngine(std::_List_iterator<std::unique_ptr<WarShip>> enemyListStart,
                                  std::_List_iterator<std::unique_ptr<WarShip>> enemyListEnd,double dt) {

    model.searchAndHuntDownEnemyTargets(enemyListStart,enemyListEnd,dt);

}
