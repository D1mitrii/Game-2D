//
// Created by Dmitriy on 10/17/2022.
//

#include "Cell.h"


void Cell::swap(Cell &other) {
    std::swap(wall, other.wall);
    std::swap(event, other.event);
}

Cell::Cell(const Cell& other) {
    this->wall = other.wall;
    this->event = other.event;
}


Cell::Cell(Cell&& other) {
    this->swap(other);
}


Cell &Cell::operator=(const Cell& other) {
    if(this != &other){
        Cell(other).swap(*this);
    }
    return *this;
}

void Cell::set_event(Event *ev) {
    delete event;
    event = ev;
}

void Cell::set_wall(bool value) {
    wall = value;
}

bool Cell::is_wall() const {
    return wall;
}

Event *Cell::get_event() {
    return event;
}
