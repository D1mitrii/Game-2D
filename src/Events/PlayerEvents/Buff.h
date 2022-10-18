//
// Created by Dmitriy on 10/11/2022.
//

#ifndef OOP_BUFF_H
#define OOP_BUFF_H


#include "PlayerEvents.h"
#include "src/Utils/RNG/RNGenerator.h"

class Buff : public PlayerEvents {
private:
    int power_up;
public:
    explicit Buff(Player* pl, int value);
    void execute() final;
    ~Buff() override = default;
};


#endif //OOP_BUFF_H
