//
// Created by Dmitriy on 11/22/2022.
//

#ifndef OOP_TREASUREEVENT_H
#define OOP_TREASUREEVENT_H


#include "PlayerEvents.h"

class TreasureEvent : public PlayerEvents {
public:
    explicit TreasureEvent(Player* pl);
    void execute() override;
    ~TreasureEvent() override = default;
};


#endif //OOP_TREASUREEVENT_H
