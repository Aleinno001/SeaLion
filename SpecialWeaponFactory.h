//
// Created by alessandro on 02/07/21.
//

#ifndef SEALION_SPECIALWEAPONFACTORY_H
#define SEALION_SPECIALWEAPONFACTORY_H

class SpecialWeaponFactory {
public:
    virtual std::unique_ptr <Arsenal> createSpecialWeapon(std::string type) const = 0;
};

#endif //SEALION_SPECIALWEAPONFACTORY_H
