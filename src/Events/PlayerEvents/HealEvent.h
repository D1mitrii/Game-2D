#ifndef OOP_HEALEVENT_H
#define OOP_HEALEVENT_H

#include "PlayerEvents.h"

class HealEvent : public PlayerEvents{
public:
    explicit HealEvent(Player* pl);
    void execute() final;
    ~HealEvent() override = default;
};


#endif //OOP_HEALEVENT_H
