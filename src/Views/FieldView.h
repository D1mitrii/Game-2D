//
// Created by Dmitriy on 9/17/2022.
//

#ifndef OOP_FIELDVIEW_H
#define OOP_FIELDVIEW_H


#include "src/Background/Field.h"
#include "src/Views/CellView.h"
#include "iostream"

class FieldView {
private:
    void write_horizontal_border(int width) const;
public:
    explicit FieldView() = default;
    ~FieldView() = default;
    void write_field(const Field& field) const;
};


#endif //OOP_FIELDVIEW_H
