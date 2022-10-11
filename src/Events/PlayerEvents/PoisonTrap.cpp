//
// Created by Dmitriy on 10/2/2022.
//

#include "PoisonTrap.h"

void PoisonTrap::execute(Player &player) {
    player.set_hearts(player.get_hearts() - 1);

}
