#include "Game.h"

void Game::start() {
    Field new_field(3,3);
    new_field.generate_field();
    FieldView view;
    view.write_field(new_field);
}
