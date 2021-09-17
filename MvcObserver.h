//
// Created by pala on 9/11/21.
//

#ifndef SEALION_MVCOBSERVER_H
#define SEALION_MVCOBSERVER_H


class MvcObserver {
public:
    virtual ~MvcObserver()=default;
    virtual void updateMvcObserver() = 0;
};


#endif //SEALION_MVCOBSERVER_H
