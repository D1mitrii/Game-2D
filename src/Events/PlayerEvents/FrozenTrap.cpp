//
// Created by Dmitriy on 10/2/2022.
//

#include "FrozenTrap.h"

FrozenTrap::FrozenTrap(Player *pl, int dec) {
    player = pl;
    decrease = dec;
}

void FrozenTrap::execute() {
    player->set_power(player->get_power()-decrease);
}