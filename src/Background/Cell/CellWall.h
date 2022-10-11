//
// Created by Dmitriy on 10/11/2022.
//

#ifndef OOP_CELLWALL_H
#define OOP_CELLWALL_H


#include "ICell.h"

class CellWall : public ICell{
public:
    CellWall() = default;
    Event* get_event() override {
        return nullptr;
    }
    ~CellWall() override = default;
};


#endif //OOP_CELLWALL_H
