//
// Created by Dmitriy on 10/2/2022.
//

#include "FrozenTrap.h"

FrozenTrap::FrozenTrap(Player *pl) {
    player = pl;
}

void FrozenTrap::execute() {
    player->set_power(player->get_power()-1);
}