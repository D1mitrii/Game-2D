#include "Game.h"

void Game::start() {
    Player::Directions command;
    while (true){
        command = mediator.move();
        if(command == Player::Directions::EXIT){
            return;
        }
        reaction(command);
    }
};

Game::Game() : mediator(){
    this->player = Player();
    this->player_view = PlayerView(&player);

    std::pair<int,int> field_size = mediator.field_size();
    this->field = Field(field_size.first, field_size.second);
    this->field_view = FieldView(&field);
    this->field.generate_field();
}

void Game::reaction(Player::Directions move) {
    event_handler(this->field.change_player_position(move));
}

void Game::event_handler(Event* ptr_event) {
    if(ptr_event != nullptr){
        if(auto temp = dynamic_cast<PlayerEvents*>(ptr_event)){
            temp->execute(player);
        }
        field.set_base_cell();
    }
}

void Game::end() {

};
