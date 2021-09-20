//
// Created by davide on 02/07/21.
//

#ifndef SEALION_ARSENALFACTORY_H
#define SEALION_ARSENALFACTORY_H

#include <memory>
#include "Arsenal.h"
#include "ConcreteWarShip.h"
#include "ConcreteArsenal.h"

class ArsenalFactory {
public:
    virtual std::unique_ptr<ConcreteArsenal> createLight(int posX, int posY,WarShip &subject) const = 0;
    virtual std::unique_ptr<ConcreteArsenal> createMedium(int posX, int posY,WarShip &subject) const = 0;
    virtual std::unique_ptr<ConcreteArsenal> createHeavly(int posX, int posY,WarShip &subject) const = 0;
};

#endif //SEALION_ARSENALFACTORY_H
