//
// Created by Dmitriy on 11/22/2022.
//

#ifndef OOP_UTIL_FUNCS_H
#define OOP_UTIL_FUNCS_H

#include "src/Background/Cell.h"

bool check_pos(int point, int length);
void placer(Cell& cell, bool with_force);
int new_count(int cur_count, int free_cells);
#endif //OOP_UTIL_FUNCS_H
