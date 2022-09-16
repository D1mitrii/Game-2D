//
// Created by Dmitriy on 9/16/2022.
//

#include "Field.h"
#include "Cell.h"
Field::Field(int a, int b) : width(a), height(b) {
    for (int i = 0; i < this->field.size(); i++)
    {
        for (int j = 0; j < this->field[i].size(); j++)
        {
            Cell new_cell;
            this->field[i][j] = new_cell;
        }
    }
};

void Field::swap(Field &other) {
    std::swap(height, other.height);
    std::swap(width, other.width);
    std::swap(field, other.field);
}

Field &Field::operator=(const Field &other) {
    if(this == &other){
        return *this;
    }

};


