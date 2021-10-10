//
// Created by davide on 02/07/21.
//

#ifndef SEALION_WEAPONFACTORY_H
#define SEALION_WEAPONFACTORY_H

#include <memory>
#include "Arsenal.h"
#include "SpecialWeaponFactory.h"
#include "ConcreteArsenal.h"


class WeaponFactory : public SpecialWeaponFactory {
public:
    std::unique_ptr<Arsenal> createSpecialWeapon(WeaponType type,WarShip &subject) const override;
    virtual ~WeaponFactory() = default;
};


#endif //SEALION_WEAPONFACTORY_H
