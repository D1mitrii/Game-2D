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
    } else if(num < 75){
        return new CoinEvent(pl, generator.get_random_value<int>(coins));
    } else if(num < 80){
        return new Buff(pl, generator.get_random_value<int>(buf));
    } else if(num < 89){
        return new FieldNoWalls(fl);
    } else if(num < 95){
        return new FieldChangePos(fl);
    }
    else{
        return new HealEvent(pl);
    }
}

EventGenerator &EventGenerator::operator=(const EventGenerator &other) {
    if(this != &other){
        EventGenerator(other).swap(*this);
    }
    return *this;
}

EventGenerator::EventGenerator(const EventGenerator &other) {
    this->generator = other.generator;
    this->pl = other.pl;
    this->fl = other.fl;
}

void EventGenerator::swap(EventGenerator& other) {
    std::swap(this->pl, other.pl);
    std::swap(this->fl, other.fl);
    std::swap(this->generator, other.generator);
}

EventGenerator::EventGenerator(Player *player, Field *field) : generator(), pl(player), fl(field){

}
