//
// Created by Dmitriy on 10/11/2022.
//

#ifndef OOP_CELLBUFF_H
#define OOP_CELLBUFF_H


#include "ICell.h"
#include "src/Events/PlayerEvents/HealEvent.h"
#include "src/Events/PlayerEvents/Buff.h"
#include "src/Utils/RNG/RNGenerator.h"

class CellBuff : public ICell {
public:
    CellBuff();
    Event * get_event() override;
    ~CellBuff() override;
};


#endif //OOP_CELLBUFF_H
