#include "PlayerEvents.h"

#ifndef OOP_FROZENTRAP_H
#define OOP_FROZENTRAP_H


class FrozenTrap : public PlayerEvents {
public:
    explicit FrozenTrap(Player* pl);
    void execute() final;
    ~FrozenTrap() override = default;
};


#endif //OOP_FROZENTRAP_H
