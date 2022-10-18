//
// Created by Dmitriy on 10/10/2022.
//

#ifndef OOP_FIELDEVENTS_H
#define OOP_FIELDEVENTS_H

class Field;

#include "src/Events/Event.h"

class FieldEvents : public Event{
protected:
    Field* field;
public:
    virtual void execute() = 0;
    virtual ~FieldEvents() = default;
};


#endif //OOP_FIELDEVENTS_H
