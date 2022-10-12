#ifndef OOP_COINEVENT_H
#define OOP_COINEVENT_H

#include "PlayerEvents.h"
#include "src/Utils/RNG/RNGenerator.h"

class CoinEvent : public PlayerEvents {
public:
    CoinEvent() = default;
    void execute(Player& player) final;
    ~CoinEvent() override = default;
};


#endif //OOP_COINEVENT_H
