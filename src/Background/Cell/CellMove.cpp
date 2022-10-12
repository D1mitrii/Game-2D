#include "CellMove.h"

CellMove::CellMove() {
    RNGenerator generator;
    std::uniform_int_distribution<int> distr{1,2};
    if(generator.get_random_value<int>(distr) == 1){
        event = new FieldRegen;
    }
    else
        event = new FieldChangePos;
}

Event *CellMove::get_event() {
    return event;
}

CellMove::~CellMove() {
    delete event;
}


