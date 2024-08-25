//
// Created by Dmitriy on 10/2/2022.
//
#ifndef OOP_PLAYEREVENTS_H
#define OOP_PLAYEREVENTS_H

#include "src/Events/Event.h"
#include "src/Entities/Player.h"

class PlayerEvents : public Event {
protected:
    Player* player;
public:
    void execute() override = 0;
    virtual ~PlayerEvents() = default;
};


#endif //OOP_PLAYEREVENTS_H
