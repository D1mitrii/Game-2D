//
// Created by Dmitriy on 11/22/2022.
//

#ifndef OOP_R_WIN_CELL_H
#define OOP_R_WIN_CELL_H

#include "src/Background/Field.h"
#include "src/Events/PlayerEvents/TreasureEvent.h"
#include "Util_Funcs.h"

template<int x, int y>
class R_Win_Cell {
public:
    void operator() (Field* field){
        if (check_pos(x, field->get_width()-1))
            return;
        if (check_pos(y, field->get_height()-1))
            return;
        if (std::make_pair(x, y) == field->get_position())
            return;
        field->get_cell(x, y).set_wall(false);
        field->get_cell(x, y).set_event(new TreasureEvent(field->get_player()));
        field->set_count(field->get_count_free()-1);
    }
};


#endif //OOP_R_WIN_CELL_H
