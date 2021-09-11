//
// Created by pala on 9/11/21.
//

#ifndef SEALION_MVCSUBJECT_H
#define SEALION_MVCSUBJECT_H


#include <memory>
#include "MvcObserver.h"

class MvcSubject {
public:
    virtual ~MvcSubject() = default;
    virtual void notifyMvcObserver() = 0;
    virtual void addMvcObserver(std::shared_ptr<MvcObserver> o) = 0;
    virtual void removeMvcObserver(std::shared_ptr<MvcObserver> o) = 0;

};


#endif //SEALION_MVCSUBJECT_H
