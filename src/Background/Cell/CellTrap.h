//
// Created by Dmitriy on 10/11/2022.
//

#ifndef OOP_CELLTRAP_H
#define OOP_CELLTRAP_H


#include "ICell.h"
#include "src/Utils/RNG/RNGenerator.h"
#include "src/Events/PlayerEvents/PoisonTrap.h"
#include "src/Events/PlayerEvents/FrozenTrap.h"

class CellTrap : public ICell{
public:
    CellTrap();
    Event* get_event() override;
    ~CellTrap() override;
};


#endif //OOP_CELLTRAP_H
