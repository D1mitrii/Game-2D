#ifndef OOP_EVENTGENERATOR_H
#define OOP_EVENTGENERATOR_H

class Field;
#include "src/Events/PlayerEvents/PoisonTrap.h"
#include "src/Events/PlayerEvents/FrozenTrap.h"
#include "src/Events/PlayerEvents/Buff.h"
#include "src/Events/PlayerEvents/CoinEvent.h"
#include "src/Events/PlayerEvents/HealEvent.h"
#include "src/Events/FieldEvents/FieldRegen.h"

class EventGenerator {
private:
    RNGenerator generator;
    Player* pl;
    Field* fl;
public:
    EventGenerator(Player* player, Field* field) : generator(), pl(player), fl(field) {};
    Event* generate();
};


#endif