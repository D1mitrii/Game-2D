//
// Created by Dmitriy on 11/22/2022.
//

#include "WinEvent.h"

WinEvent::WinEvent(Game *gm) {
    game = gm;
}

void WinEvent::execute() {
    game->set_status(Game::WIN);
}
