#include "PlayerEvents.h"

#ifndef OOP_FROZENTRAP_H
#define OOP_FROZENTRAP_H


class FrozenTrap : public PlayerEvents {
public:
    void execute(Player& player) final;
    ~FrozenTrap() override = default;
};


#endif //OOP_FROZENTRAP_H
