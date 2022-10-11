//
// Created by Dmitriy on 10/10/2022.
//

#ifndef OOP_FIELDEVENTS_H
#define OOP_FIELDEVENTS_H


#include "src/Background/Field.h"
#include "src/Utils/RNG/RNGenerator.h"


class FieldEvents : public Event{
public:
    void execute() override {};
    virtual void execute(Field& field) = 0;
    virtual ~FieldEvents() = default;
};


#endif //OOP_FIELDEVENTS_H
