//
// Created by Dmitriy on 10/11/2022.
//

#include "CellTrap.h"

CellTrap::CellTrap() {
    RNGenerator generator;
    std::uniform_int_distribution<int> dist{1, 2};
    switch (generator.get_random_value<int>(dist)) {
        case 1:{
            event = new PoisonTrap;
            break;
        }
        case 2:{
            event = new FrozenTrap;
            break;
        }
        default:
            break;
    }
}

Event *CellTrap::get_event() {
    return event;
}

CellTrap::~CellTrap() {
    delete event;
}
