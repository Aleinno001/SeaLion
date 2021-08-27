//
// Created by pala on 8/27/21.
//

#ifndef SEALION_WARPLANES_H
#define SEALION_WARPLANES_H


class WarPlanes {
public:
    virtual ~WarPlanes()=default;
    virtual void update()=0;
};


#endif //SEALION_WARPLANES_H
