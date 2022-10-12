#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "src/Entities/Player.h"
#include "src/Views/FieldView.h"
#include "src/Utils/Mediator.h"
#include "src/Entities/Player.h"
#include "src/Views/PlayerView.h"

class Game {
public:
    enum STATUS{
        START,
        INPROGRESS,
        END
    };
    Game();
    void start();
private:
    Field field;
    Mediator mediator;
    Player player;
    FieldView field_view;
    PlayerView player_view;
    void reaction(Player::Directions move);
    void event_handler(Event* ptr_event);
    void is_end();
    STATUS status;
};


#endif //OOP_GAME_H
