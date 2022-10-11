//
// Created by Dmitriy on 9/17/2022.
//

#include "CellView.h"
char CellView::get_view() const {
    return this->cell_view;
};

CellView::CellView(const Cell & cell) {
    switch (cell.get_celltype()) {
        case Cell::CellType::STANDARD:
            this->cell_view = ' ';
            break;
        case Cell::CellType::WALL:
            this->cell_view = '#';
            break;
        case Cell::PLAYER:
            this->cell_view = 'P';
            break;
        case Cell::Coin:
            this->cell_view = 'C';
            break;
    }
};
