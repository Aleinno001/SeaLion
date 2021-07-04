//
// Created by davide on 04/07/21.
//

#ifndef SEALION_OBSERVER_H
#define SEALION_OBSERVER_H


class Observer {
public:
    virtual ~Observer() {};

    virtual void update() = 0;
};


#endif //SEALION_OBSERVER_H
