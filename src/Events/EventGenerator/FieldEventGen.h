//
// Created by Dmitriy on 11/22/2022.
//

#ifndef OOP_FIELDEVENTGEN_H
#define OOP_FIELDEVENTGEN_H


#include "IEventGen.h"
#include "src/Background/Field.h"
#include "src/Events/FieldEvents/FieldChangePos.h"
#include "src/Events/FieldEvents/FieldNoWalls.h"

class FieldEventGen : public IEventGen {
public:
    explicit FieldEventGen(Field *pField) {field = pField;};
    Event* generate() final;
    ~FieldEventGen() override = default;
};


#endif //OOP_FIELDEVENTGEN_H
