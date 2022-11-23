//
// Created by Dmitriy on 10/12/2022.
//

#ifndef OOP_IMEDIATOR_H
#define OOP_IMEDIATOR_H

class MediatorObject;
class LogPool;
#include "MediatorObject.h"

class IMediator {
public:
    enum MEVENTS{
        GAME_STATUS,
        LEVEL,
        FIELD,
        STEP
    };
    IMediator() = default;
    virtual void notify(MediatorObject *who, MEVENTS event) = 0;
    virtual void set_log(LogPool*) = 0;
    virtual ~IMediator() = default;
};


#endif //OOP_IMEDIATOR_H
