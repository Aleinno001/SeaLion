//
// Created by pala on 02/07/21.
//

#ifndef SEALION_CANNONFACTORY_H
#define SEALION_CANNONFACTORY_H


#include "ArsenalFactory.h"
#include "LightCannon.h"
#include "MediumCannon.h"
#include "HeavlyCannon.h"

class CannonFactory : public ArsenalFactory {
public:
    //TODO implementare i metodi
    std::unique_ptr<Arsenal> createLight() const;

    std::unique_ptr<Arsenal> createMedium() const;

    std::unique_ptr<Arsenal> createHeavly() const;
};


#endif //SEALION_CANNONFACTORY_H
