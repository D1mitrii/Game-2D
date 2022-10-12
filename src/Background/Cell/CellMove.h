//
// Created by Dmitriy on 10/11/2022.
//

#ifndef OOP_CELLMOVE_H
#define OOP_CELLMOVE_H

#include "ICell.h"
#include "src/Events/FieldEvents/FieldRegen.h"
#include "src/Events/FieldEvents/FieldChangePos.h"
#include "src/Utils/RNG/RNGenerator.h"

class CellMove : public ICell {
public:
    CellMove();
    Event* get_event() override;
    ~CellMove() override;
};


#endif //OOP_CELLMOVE_H
