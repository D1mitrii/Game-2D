//
// Created by Dmitriy on 10/2/2022.
//

#include "PlayerEvents.h"

#ifndef OOP_POISONTRAP_H
#define OOP_POISONTRAP_H


class PoisonTrap : public PlayerEvents {
public:
    void execute(Player& player) final;
};

#endif //OOP_POISONTRAP_H
