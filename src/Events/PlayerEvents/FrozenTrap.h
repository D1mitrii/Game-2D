//
// Created by Dmitriy on 10/2/2022.
//

#include "PlayerEvents.h"

#ifndef OOP_FROZENTRAP_H
#define OOP_FROZENTRAP_H


class FrozenTrap : public PlayerEvents {
public:
    void execute(Player& player) final;
};


#endif //OOP_FROZENTRAP_H
