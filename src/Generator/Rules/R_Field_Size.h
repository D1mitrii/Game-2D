//
// Created by Dmitriy on 11/23/2022.
//

#ifndef OOP_R_FIELD_SIZE_H
#define OOP_R_FIELD_SIZE_H

#include "src/Background/Field.h"
#include "src/Background/Cell.h"
#include "Util_Funcs.h"
template<int width=10, int height=10>
class R_Field_Size {
public:
    void operator() (Field* field){
        if(check_pos(width, 25))
            return;
        if(check_pos(height, 25))
            return;

        std::vector<std::vector<Cell>> cells;
        for (int i = 0; i < height; ++i) {
            cells.emplace_back();
            for (int j = 0; j < width; ++j) {
                cells.at(i).emplace_back();
            }
        }
        field->set_field(cells);
    }
};


#endif //OOP_R_FIELD_SIZE_H
