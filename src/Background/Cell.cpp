//
// Created by Dmitriy on 9/16/2022.
//

#include "Cell.h"
#include "src/Events/Event.h"

Cell::Cell() {
    this->type = CellType::STANDARD;
    Event new_event;
    this->event = &new_event;
}

Cell::CellType Cell::GetCellType() {
    return this->type;
};
