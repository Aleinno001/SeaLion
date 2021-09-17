//
// Created by pala on 9/17/21.
//
#ifndef SEALION_CONCRETEWARPLANE_H
#define SEALION_CONCRETEWARPLANE_H
#include "WarPlane.h"
class ConcreteWarPlane : public WarPlane{
public:
    const std::string &getNationality() const override;
    void attack() override;
    ~ConcreteWarPlane() override = default;
    void update() override;
protected:
    bool searchTarget() override;
    float rotate() override;
    bool canEngage() const override;
    void move() override;
};
#endif //SEALION_CONCRETEWARPLANE_H
