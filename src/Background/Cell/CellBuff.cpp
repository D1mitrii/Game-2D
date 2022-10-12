//
// Created by Dmitriy on 10/11/2022.
//

#include "CellBuff.h"

CellBuff::CellBuff() {
    RNGenerator generator;
    std::uniform_int_distribution<int> distr{1,2};
    if(generator.get_random_value<int>(distr) == 1){
        event = new HealEvent;
    } else
        event = new Buff;
}

Event* CellBuff::get_event() {
    return event;
}

CellBuff::~CellBuff() {
    delete event;
}
