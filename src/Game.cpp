#include "Game.h"

void Game::start() {
    view.write_field(this->field);
    Player::Directions command;
    while (true){
        command = mediator.move();
        if(command == Player::Directions::EXIT){
            return;
        }
        reaction(command);
    }
};

Game::Game() : view(FieldView()), mediator(Mediator()){
    std::pair<int,int> field_size = mediator.field_size();
    this->field = Field(field_size.first, field_size.second);
    this->field.generate_field();
}

void Game::reaction(Player::Directions move) {
    this->field.change_player_position(move);
    this->view.write_field(field);
};
