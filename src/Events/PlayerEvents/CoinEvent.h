//
// Created by Dmitriy on 10/10/2022.
//

#ifndef OOP_COINEVENT_H
#define OOP_COINEVENT_H

#include "PlayerEvents.h"
#include "src/Utils/RNG/RNGenerator.h"

class CoinEvent : public PlayerEvents {
public:
    void execute(Player& player) final;
};


#endif //OOP_COINEVENT_H
