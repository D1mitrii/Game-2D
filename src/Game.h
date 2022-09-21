#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "src/Entities/Player.h"
#include "src/Views/FieldView.h"
#include "src/Utils/Mediator.h"

class Game {
private:
    Field field;
    FieldView view;
    Mediator mediator;
    void reaction(Player::Directions move);
public:
    Game();
    void start();
};


#endif //OOP_GAME_H
