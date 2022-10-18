//
// Created by Dmitriy on 9/17/2022.
//

#ifndef OOP_CELLVIEW_H
#define OOP_CELLVIEW_H

#include "src/Background/Cell.h"
#include "src/Events/PlayerEvents/CoinEvent.h"
#include "src/Events/PlayerEvents/HealEvent.h"
#include "src/Events/PlayerEvents/Buff.h"
#include "src/Events/PlayerEvents/PoisonTrap.h"
#include "src/Events/PlayerEvents/FrozenTrap.h"
#include "src/Events/FieldEvents/FieldRegen.h"
#include "src/Events/FieldEvents/FieldChangePos.h"

class CellView {
private:
    char cell_view;
public:
    explicit CellView(Cell& cell);
    ~CellView() = default;
    char get_view() const;
};


#endif //OOP_CELLVIEW_H
