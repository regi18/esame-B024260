//
// Created by Simone Carletti on 26/06/2021.
//

#ifndef CARLETTI_ESAME_B024260_OBSERVER_H
#define CARLETTI_ESAME_B024260_OBSERVER_H


class Observer {
public:
    virtual ~Observer() = default;

    virtual void update() = 0;
};


#endif //CARLETTI_ESAME_B024260_OBSERVER_H
