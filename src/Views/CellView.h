//
// Created by Dmitriy on 9/17/2022.
//

#ifndef OOP_CELLVIEW_H
#define OOP_CELLVIEW_H

#include "src/Background/Cell.h"

class CellView {
private:
    char cell_view;
public:
    explicit CellView(const Cell& cell);
    ~CellView() = default;
    char get_view() const;
};


#endif //OOP_CELLVIEW_H
