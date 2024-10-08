//
// Created by Dmitriy on 9/17/2022.
//

#include "CellView.h"

CellView::CellView(Cell& cell) {
    if(cell.is_wall()){
        cell_view = '#';
        return;
    }
    if(dynamic_cast<CoinEvent*>(cell.get_event()) != nullptr){
        cell_view = 'C';
    }else if(dynamic_cast<Buff*>(cell.get_event()) != nullptr){
        cell_view = 'B';
    }else if(dynamic_cast<PoisonTrap*>(cell.get_event()) != nullptr){
        cell_view = 'P';
    } else if (dynamic_cast<FrozenTrap*>(cell.get_event()) != nullptr){
        cell_view = 'F';
    }else if(dynamic_cast<HealEvent*>(cell.get_event()) != nullptr) {
        cell_view = 'H';
    }else if(dynamic_cast<FieldNoWalls*>(cell.get_event()) != nullptr) {
        cell_view = 'N';
    }else if(dynamic_cast<FieldChangePos*>(cell.get_event()) != nullptr) {
        cell_view = '*';
    }
    else{
        cell_view = ' ';
    }
}

char CellView::get_view() const {
    return this->cell_view;
}
