//
// Created by Dmitriy on 9/17/2022.
//

#ifndef OOP_CELLVIEW_H
#define OOP_CELLVIEW_H

#include "src/Background/Cell.h"

class CellView {
private:
    char cell_char;
public:
    CellView() = default;
    ~CellView() = default;
    CellView(const Cell& cell);
    char get_render(Cell &cell);
};


#endif //OOP_CELLVIEW_H
