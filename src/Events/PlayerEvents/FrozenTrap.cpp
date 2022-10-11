//
// Created by Dmitriy on 10/2/2022.
//

#include "FrozenTrap.h"

void FrozenTrap::execute(Player &player) {
    player.set_power(player.get_power()-1);
}
