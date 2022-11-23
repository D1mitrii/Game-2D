//
// Created by Dmitriy on 11/22/2022.
//

#ifndef OOP_WINEVENT_H
#define OOP_WINEVENT_H


#include "GameEvents.h"
#include "src/Game.h"

class WinEvent : public GameEvents {
public:
    explicit WinEvent(Game* gm);
    void execute() override;
};


#endif //OOP_WINEVENT_H
