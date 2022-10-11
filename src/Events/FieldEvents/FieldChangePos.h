//
// Created by Dmitriy on 10/10/2022.
//

#ifndef OOP_FIELDCHANGEPOS_H
#define OOP_FIELDCHANGEPOS_H

#include "src/Background/Field.h"

#include "src/Events/FieldEvents/FieldEvents.h"

class FieldChangePos : public FieldEvents{
public:
    void execute(Field& field) final;
};


#endif //OOP_FIELDCHANGEPOS_H
