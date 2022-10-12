//
// Created by Dmitriy on 10/10/2022.
//

#include "CoinEvent.h"

void CoinEvent::execute(Player &player) {
    RNGenerator generator;
    std::uniform_real_distribution<double> distr{0.5, 2.0};
    int coins_count = 2.0 * generator.get_random_value<double>(distr) + player.get_coins();
    player.set_coins( coins_count);
}
