//
// Created by Dmitriy on 9/16/2022.
//


#include "Cell.h"
#include "src/Events/Event.h"

Cell::Cell() {
    this->type = CellType::STANDARD;
    Event new_event;
    this->event = &new_event;
};

Cell::Cell(const Cell &other) : type(other.type){
};

Cell::Cell(Cell &&other) {
    this->swap(other);
};

void Cell::swap(Cell& other) {
    std::swap(this->type, other.type);
    std::swap(this->event, other.event);
};

Cell &Cell::operator=(const Cell& other) {
    if(this != &other){
        Cell(other).swap(*this);
    }
    return  *this;
};

Cell &Cell::operator=(Cell&& other){
    if(this != &other){
        this->swap(other);
    }
    return  *this;
};

Cell::CellType Cell::get_celltype() const {
    return this->type;
}

void Cell::set_type(Cell::CellType type) {
    this->type = type;
};