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
public:
    Game();
    void start();
    void reaction(Player::Directions move);
};


#endif //OOP_GAME_H
