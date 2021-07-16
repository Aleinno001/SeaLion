//
// Created by pala on 02/07/21.
//

#ifndef SEALION_ARSENALFACTORY_H
#define SEALION_ARSENALFACTORY_H

#include <memory>
#include "Arsenal.h"

class ArsenalFactory {
public:
    virtual std::unique_ptr<Arsenal> createLight() const = 0;

    virtual std::unique_ptr<Arsenal> createMedium() const = 0;

    virtual std::unique_ptr<Arsenal> createHeavly() const = 0;
};


#endif //SEALION_ARSENALFACTORY_H
