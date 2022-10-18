//
// Created by Dmitriy on 10/17/2022.
//

#include "CellFactory.h"


void CellFactory::set_generator(EventGenerator* gen) {
    ev_gen = gen;
}

Cell CellFactory::wall_cell() {
    return Cell(true, nullptr);
}

Cell CellFactory::base_cell() {
    return Cell(false, nullptr);
}

Cell CellFactory::event_cell() {
    return Cell(false, ev_gen->generate());
}

CellFactory::~CellFactory() {
    delete ev_gen;
}
