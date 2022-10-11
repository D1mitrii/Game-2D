//
// Created by Dmitriy on 9/17/2022.
//

#include "CellView.h"

CellView::CellView(ICell* cell) {
    if(dynamic_cast<CellWall*>(cell) != nullptr){
        cell_view = '#';
    } else if(dynamic_cast<CellBase*>(cell) != nullptr){
        cell_view = ' ';
    } else if (dynamic_cast<CellCoin*>(cell) != nullptr){
        cell_view = 'C';
    }
    else if (dynamic_cast<CellTrap*>(cell) != nullptr){
        cell_view = 'T';
    }
}

char CellView::get_view() const {
    return this->cell_view;
};
