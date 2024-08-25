//
// Created by Dmitriy on 11/22/2022.
//

#include "TreasureEvent.h"

TreasureEvent::TreasureEvent(Player *pl) {
    player = pl;
}

void TreasureEvent::execute() {
    player->set_coins(100);
}
