#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "src/Entities/Player.h"
#include "src/Views/FieldView.h"
#include "src/Utils/Mediator.h"
#include "src/Entities/Player.h"
#include "src/Views/PlayerView.h"

class Game {
private:
    Field field;
    Mediator mediator;
    Player player;
    FieldView field_view;
    PlayerView player_view;
    void reaction(Player::Directions move);
    void event_handler(Event* ptr_event);
    void end();
public:
    Game();
    void start();
};


#endif //OOP_GAME_H
