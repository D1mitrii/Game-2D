#ifndef OOP_EVENTGENERATOR_H
#define OOP_EVENTGENERATOR_H


#include "src/Events/PlayerEvents/PoisonTrap.h"
#include "src/Events/PlayerEvents/FrozenTrap.h"
#include "src/Events/PlayerEvents/Buff.h"
#include "src/Events/PlayerEvents/CoinEvent.h"
#include "src/Events/PlayerEvents/HealEvent.h"
#include "src/Events/FieldEvents/FieldNoWalls.h"
#include "src/Events/FieldEvents/FieldChangePos.h"

class EventGenerator {
private:
    RNGenerator generator;
    Player* pl;
    Field* fl;
public:
    EventGenerator() = default;
    explicit EventGenerator(Player* player, Field* field);
    void swap(EventGenerator& other);
    EventGenerator(const EventGenerator& other);
    EventGenerator& operator=(const EventGenerator& other);
    Event* generate();
};


#endif