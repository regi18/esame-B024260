//
// Created by Simone Carletti on 26/06/2021.
//

#ifndef CARLETTI_ESAME_B024260_SUBJECT_H
#define CARLETTI_ESAME_B024260_SUBJECT_H

#include <list>
#include "Observer.h"


class Subject {
public:
    virtual void subscribe(Observer* observer) {
        this->observers.push_back(observer);
    }

    virtual void unsubscribe(Observer* observer) {
        this->observers.remove(observer);
    }

    virtual void notifyAll() {
        for (const auto& o : observers) {
            o->update();
        }
    }

    virtual ~Subject() = default;

private:
    std::list<Observer*> observers;
};


#endif //CARLETTI_ESAME_B024260_SUBJECT_H
