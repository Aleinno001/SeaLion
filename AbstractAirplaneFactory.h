//
// Created by alessandro on 04/07/21.
//

#ifndef SEALION_ABSTRACTAIRPLANEFACTORY_H
#define SEALION_ABSTRACTAIRPLANEFACTORY_H

class AbstractAirplaneFactory {
public:
    virtual std::unique_ptr <Vehicle> createFighter() = 0;

    virtual std::unique_ptr <Vehicle> createBomber() = 0;

    virtual std::unique_ptr <Vehicle> createTorpedoBomber() = 0;
};

#endif //SEALION_ABSTRACTAIRPLANEFACTORY_H
