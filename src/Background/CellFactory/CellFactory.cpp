#include "CellFactory.h"


CellFactory::CellFactory(EventGenerator &gen) {
    this->ev_gen = gen;
}

Cell CellFactory::wall_cell() {
    return Cell(true, nullptr);
}

Cell CellFactory::base_cell() {
    return Cell(false, nullptr);
}

Cell CellFactory::event_cell() {
    return Cell(false, ev_gen.generate());
}
