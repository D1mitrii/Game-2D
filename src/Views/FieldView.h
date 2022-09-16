//
// Created by Dmitriy on 9/17/2022.
//

#ifndef OOP_FIELDVIEW_H
#define OOP_FIELDVIEW_H


#include "src/Background/Field.h"

class FieldView {
private:
    Field field;
public:
    explicit FieldView(Field& field);
    ~FieldView() = default;
    void print();
};


#endif //OOP_FIELDVIEW_H
