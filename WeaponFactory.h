//
// Created by alessandro on 02/07/21.
//

#ifndef SEALION_WEAPONFACTORY_H
#define SEALION_WEAPONFACTORY_H

#include <memory>
#include "Arsenal.h"
#include "SpecialWeaponFactory.h"

class WeaponFactory : public SpecialWeaponFactory {
public:
    std::unique_ptr<Arsenal> createSpecialWeapon(std::string type) const override;

};


#endif //SEALION_WEAPONFACTORY_H
