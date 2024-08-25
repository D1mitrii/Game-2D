//
// Created by Dmitriy on 10/9/2022.
//

#ifndef OOP_ISUBJECT_H
#define OOP_ISUBJECT_H

#include "IObserver.h"
#include <vector>
#include <algorithm>

class ISubject {
protected:
    std::vector<IObserver*> observers;
public:
    void attach(IObserver *observer);
    void detach(IObserver *observer);
    void notify();
    ~ISubject() = default;
};


#endif //OOP_ISUBJECT_H
