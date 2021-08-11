//
// Created by davide on 02/07/21.
//

#ifndef SEALION_SPECIALWEAPONFACTORY_H
#define SEALION_SPECIALWEAPONFACTORY_H

enum class WeaponType {
    torpedo, antiAir
};

class SpecialWeaponFactory {
public:
    virtual std::unique_ptr<Arsenal> createSpecialWeapon(WeaponType type,WarShip &subject) const = 0;
};

#endif //SEALION_SPECIALWEAPONFACTORY_H
