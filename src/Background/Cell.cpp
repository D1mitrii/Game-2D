#include "Cell.h"


Cell::Cell() : type(CellType::STANDARD), event(nullptr) {
};

Cell::CellType Cell::get_celltype() const {
    return this->type;
}

void Cell::set_type(Cell::CellType type1) {
    this->type = type1;
};

void Cell::set_event(Event* other) {
    delete this->event;
    this->event = other;
};

void Cell::update(Player& player, Field& field) {
    if(event != nullptr || type == PLAYER){
        if(auto temp = dynamic_cast<FieldEvents*>(this->event)){
            temp->execute(field);
        }
    }
}

