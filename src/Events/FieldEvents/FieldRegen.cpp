//
// Created by Dmitriy on 10/11/2022.
//

#include "FieldRegen.h"


FieldRegen::FieldRegen(Field *fl) {
    field = fl;
}

void FieldRegen::execute() {
    field->generate_field();
}
