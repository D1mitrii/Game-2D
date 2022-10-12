#ifndef OOP_HEALEVENT_H
#define OOP_HEALEVENT_H

#include "PlayerEvents.h"

class HealEvent : public PlayerEvents{
public:
    HealEvent() = default;
    void execute(Player& player) final;
    ~HealEvent() override = default;
};


#endif //OOP_HEALEVENT_H
