//
// Created by Dmitriy on 10/11/2022.
//

#include "FieldNoWalls.h"


FieldNoWalls::FieldNoWalls(Field *fl) {
    field = fl;
}

void FieldNoWalls::execute() {
    field->remove_walls();
}
