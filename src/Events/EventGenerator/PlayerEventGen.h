#ifndef OOP_PLAYEREVENTGEN_H
#define OOP_PLAYEREVENTGEN_H


#include "src/Events/PlayerEvents/PoisonTrap.h"
#include "src/Events/PlayerEvents/FrozenTrap.h"
#include "src/Events/PlayerEvents/Buff.h"
#include "src/Events/PlayerEvents/CoinEvent.h"
#include "src/Events/PlayerEvents/HealEvent.h"
#include "src/Events/FieldEvents/FieldNoWalls.h"
#include "src/Events/FieldEvents/FieldChangePos.h"
#include "IEventGen.h"

class PlayerEventGen : public IEventGen {
public:
    explicit PlayerEventGen(Field *pField) {field = pField;};
    Event* generate() final;
    ~PlayerEventGen() override = default;
};



#endif