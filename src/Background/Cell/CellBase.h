//
// Created by Dmitriy on 10/11/2022.
//

#ifndef OOP_CELLBASE_H
#define OOP_CELLBASE_H


#include "ICell.h"

class CellBase : public ICell{
public:
    CellBase() = default;
    Event* get_event() override {
        return nullptr;
    }
    ~CellBase() override = default;
};

#endif //OOP_CELLBASE_H
