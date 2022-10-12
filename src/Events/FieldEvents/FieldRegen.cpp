//
// Created by Dmitriy on 10/11/2022.
//

#include "FieldRegen.h"

void FieldRegen::execute(Field &field) {
    field.deconstruct();
    field.generate_field();
}
