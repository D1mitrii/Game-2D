//
// Created by Dmitriy on 10/11/2022.
//

#ifndef OOP_FIELDREGEN_H
#define OOP_FIELDREGEN_H

#include "FieldEvents.h"
#include "src/Background/Field.h"

class FieldRegen : public FieldEvents {
public:
    FieldRegen() = default;
    void execute(Field& field) final;
    ~FieldRegen() override = default;
};


#endif //OOP_FIELDREGEN_H
