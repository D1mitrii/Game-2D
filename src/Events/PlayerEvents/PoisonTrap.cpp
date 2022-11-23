//
// Created by Dmitriy on 10/2/2022.
//

#include "PoisonTrap.h"

PoisonTrap::PoisonTrap(Player *pl, int damage) {
    player = pl;
    dmg = damage;
}

void PoisonTrap::execute() {
    player->set_hearts(player->get_hearts() - dmg);
}
