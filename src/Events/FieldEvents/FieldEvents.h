//
// Created by Dmitriy on 10/10/2022.
//

#ifndef OOP_FIELDEVENTS_H
#define OOP_FIELDEVENTS_H

class Field;

#include "src/Utils/RNG/RNGenerator.h"
#include "src/Events/Event.h"

class FieldEvents : public Event{
public:
    void execute() override {};
    virtual void execute(Field& field) = 0;
    virtual ~FieldEvents() = default;
};


#endif //OOP_FIELDEVENTS_H
