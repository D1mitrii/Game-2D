#include "Game.h"

void Game::start() {
    status = INPROGRESS;
    Player::Directions command;
    while (status != END){
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
    status = START;
}

void Game::reaction(Player::Directions move) {
    event_handler(this->field.change_player_position(move));
}

void Game::event_handler(Event* ptr_event) {
    if(ptr_event == nullptr) {
        return;
    }
    if(auto temp = dynamic_cast<PlayerEvents*>(ptr_event)){
        temp->execute(player);
    }
    if(auto temp = dynamic_cast<FieldEvents*>(ptr_event)){
        temp->execute(field);
    }
    field.set_base_cell();
    is_end();
}

void Game::is_end() {
    if(player.get_hearts() <= 0){
        status = END;
    }
    if(player.get_power() <= 0){
        status = END;
    }
};
