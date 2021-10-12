//
// Created by davide on 02/07/21.
//

#ifndef SEALION_CANNONFACTORY_H
#define SEALION_CANNONFACTORY_H

#include "ArsenalFactory.h"

class CannonFactory : public ArsenalFactory {
public:
    std::unique_ptr<ConcreteArsenal> createLight(int posX, int posY,WarShip &subject)override;
    std::unique_ptr<ConcreteArsenal> createMedium(int posX, int posY,WarShip &subject)override;
    std::unique_ptr<ConcreteArsenal> createHeavly(int posX, int posY,WarShip &subject)override;
    virtual ~CannonFactory() = default;
};


#endif //SEALION_CANNONFACTORY_H
