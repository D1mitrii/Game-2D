//
// Created by Dmitriy on 10/12/2022.
//

#ifndef OOP_MEDIATOROBJECT_H
#define OOP_MEDIATOROBJECT_H

class IMediator;

#include "IMediator.h"

class MediatorObject {
public:
    MediatorObject(IMediator *med = nullptr);
    void set_mediator(IMediator* med);
    virtual ~MediatorObject() = default;
protected:
    IMediator* mediator;
};


#endif //OOP_MEDIATOROBJECT_H
