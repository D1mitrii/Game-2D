#include "Cell.h"
#include "src/Events/Event.h"

Cell::Cell() : type(CellType::STANDARD), event(nullptr) {
};

Cell::CellType Cell::get_celltype() const {
    return this->type;
}

void Cell::set_type(Cell::CellType type1) {
    this->type = type1;
};

void Cell::set_event(Event* other) {
    if(this->event == nullptr || this->event == other)
        return;
    this->event = other;
};

void Cell::update(Player& player) {
    if(event != nullptr || type == PLAYER){
        event->Execute();
    }
};