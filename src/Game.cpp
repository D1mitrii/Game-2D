#include "Game.h"

void Game::start() {
    status = START;
    mediator->notify(this, IMediator::GAME_STATUS);
    status = INPROGRESS;
    loop();
}

Game::Game(){
    this->player = new Player();
    this->player_view = new PlayerView(player);
}

void Game::reaction() {
    event_handler(this->field->change_player_position(cur_step));
}

void Game::event_handler(Event* ptr_event) {
    if(ptr_event == nullptr) {
        return;
    }
    if(auto temp = dynamic_cast<PlayerEvents*>(ptr_event)){
        temp->execute(*player);
    }
    if(auto temp = dynamic_cast<FieldEvents*>(ptr_event)){
        temp->execute(*field);
    }
    field->set_base_cell();
    is_end();
}

void Game::is_end() {
    if(player->get_coins() > 20){
        status = WIN;
    }
    if(player->get_hearts() <= 0){
        status = DEFEAT;
    }
    if(player->get_power() <= 0){
        status = DEFEAT;
    }
    mediator->notify(this, IMediator::GAME_STATUS);
}

Game::STATUS Game::get_status() const {
    return status;
}

void Game::set_status(STATUS stat) {
    status = stat;
}

void Game::initialize_field() {
    this->field = new Field();
    field_view = new FieldView(field);
}

void Game::initialize_field(std::pair<int, int> size) {
    this->field = new Field(size.first, size.second);
    field_view = new FieldView(field);
    std::printf("!%p!", &this->field_view);
}

void Game::set_step(Player::Directions cur) {
    cur_step = cur;
}

void Game::loop() {
    field->generate_field();
    while (status == INPROGRESS){
        mediator->notify(this, IMediator::STEP);
        reaction();
    }
}

Game::~Game() {
    delete player;
    delete field;
    delete field_view;
    delete player_view;
}
