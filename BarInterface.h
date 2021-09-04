//
// Created by pala on 9/4/21.
//

#ifndef SEALION_BARINTERFACE_H
#define SEALION_BARINTERFACE_H


class BarInterface {
public:
    virtual ~BarInterface()= default;;
    virtual void update()=0;


};


#endif //SEALION_BARINTERFACE_H
