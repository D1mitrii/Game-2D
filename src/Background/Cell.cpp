//
// Created by Dmitriy on 9/16/2022.
//


#include "Cell.h"
#include "src/Events/Event.h"

Cell::Cell() : type(CellType::STANDARD), event(nullptr) {
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

void Cell::set_type(Cell::CellType type1) {
    this->type = type1;
};

void Cell::set_event(Event &other) {
    this->event = &other;
};

void Cell::update() {
    if(event != nullptr){
        event->Execute();
    }
};