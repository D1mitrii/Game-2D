//
// Created by Dmitriy on 9/17/2022.
//

#ifndef OOP_CELLVIEW_H
#define OOP_CELLVIEW_H

#include "src/Background/Cell/CellBase.h"
#include "src/Background/Cell/CellCoin.h"
#include "src/Background/Cell/CellTrap.h"
#include "src/Background/Cell/CellWall.h"
#include "src/Background/Cell/CellMove.h"
#include "src/Background/Cell/CellBuff.h"

class CellView {
private:
    char cell_view;
public:
    explicit CellView(ICell* cell);
    ~CellView() = default;
    char get_view() const;
};


#endif //OOP_CELLVIEW_H
