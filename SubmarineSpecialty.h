//
// Created by alessandro on 19/09/21.
//

#ifndef SEALION_SUBMARINESPECIALTY_H
#define SEALION_SUBMARINESPECIALTY_H

#include <list>
#include "MvcSubject.h"

class SubmarineSpecialty : public MvcSubject{
protected:
    std::list<std::shared_ptr<MvcObserver>> listMvcObservers;
public:
    virtual const std::list<std::shared_ptr<MvcObserver>> &getListMvcObservers() const {return listMvcObservers;}
    ~SubmarineSpecialty() override =0;
    virtual void torpedoAttack()=0;
};

#endif //SEALION_SUBMARINESPECIALTY_H
