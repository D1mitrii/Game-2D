//
// Created by Dmitriy on 11/22/2022.
//

#ifndef OOP_GAMEEVENTS_H
#define OOP_GAMEEVENTS_H

class Game;
#include "src/Events/Event.h"

class GameEvents : public Event{
protected:
    Game* game;
public:
    virtual void execute() = 0;
    virtual ~GameEvents() = default;
};


#endif //OOP_GAMEEVENTS_H
