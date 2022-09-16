//
// Created by Dmitriy on 9/17/2022.
//

#include "CellView.h"
char CellView::get_render(Cell &cell) {
    switch (cell.GetCellType()) {
        case Cell::CellType::STANDARD:
            return ' ';
        case Cell::CellType::WALL:
            return '#';
    }
}

CellView::CellView(const Cell & cell) {
    this->cell_char = get_render(const_cast<Cell &>(cell));
}
