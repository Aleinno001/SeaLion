//
// Created by davide on 02/07/21.
//

#ifndef SEALION_CANNONFACTORY_H
#define SEALION_CANNONFACTORY_H

#include "ArsenalFactory.h"

class CannonFactory : public ArsenalFactory {
public:
    //TODO implementare i metodi
    std::unique_ptr<ConcreteArsenal> createLight(int posX, int posY,ConcreteWarShip &subject) const override;
    std::unique_ptr<ConcreteArsenal> createMedium(int posX, int posY,ConcreteWarShip &subject) const override;
    std::unique_ptr<ConcreteArsenal> createHeavly(int posX, int posY,ConcreteWarShip &subject) const override;
};


#endif //SEALION_CANNONFACTORY_H
