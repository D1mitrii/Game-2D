//
// Created by Dmitriy on 10/11/2022.
//

#include "CellCoin.h"

CellCoin::CellCoin() {
    event = new CoinEvent;
}

Event *CellCoin::get_event() {
    return event;
}

CellCoin::~CellCoin() {
    delete event;
}
