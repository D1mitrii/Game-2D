#ifndef OOP_COINEVENT_H
#define OOP_COINEVENT_H

#include "PlayerEvents.h"
#include "src/Utils/RNG/RNGenerator.h"

class CoinEvent : public PlayerEvents {
private:
    int coins;
public:
    CoinEvent(Player* pl, int coin);
    void execute();
    ~CoinEvent() override = default;
};


#endif //OOP_COINEVENT_H
