//
// Created by Dmitriy on 10/17/2022.
//

#include "EventGenerator.h"

Event* EventGenerator::generate() {
    std::uniform_int_distribution<int> distr_percent{0, 100};
    std::uniform_int_distribution<int> coins{1, 4};
    std::uniform_int_distribution<int> buf{1, 2};
    int num = generator.get_random_value<int>(distr_percent);

    if(num < 20){
        return new PoisonTrap(pl);
    }
    else if(num < 40){
        return new FrozenTrap(pl);
    } else if(num < 70){
        return new CoinEvent(pl, generator.get_random_value<int>(coins));
    } else if(num < 85){
        return new FieldRegen(fl);
    }
    else if(num <= 100){
        return new HealEvent(pl);
    }
    return nullptr;
}
