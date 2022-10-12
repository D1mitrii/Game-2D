//
// Created by Dmitriy on 10/11/2022.
//

#include "Buff.h"


void Buff::execute(Player &player) {
    RNGenerator generator;
    std::uniform_int_distribution<int> distr{1,3};
    player.set_max_stat(player.get_max_stat() + generator.get_random_value<int>(distr));
}
