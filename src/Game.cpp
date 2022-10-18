#include "Game.h"

void Game::start() {
    status = START;
    mediator->notify(this, IMediator::GAME_STATUS);
    status = INPROGRESS;
    field_generate();
    loop();
}

Game::Game(){
    this->player = new Player();
    this->player_view = new PlayerView(player);
}

void Game::reaction() {
    if(cur_step == Player::EXIT){
        status = END;
        return;
    }
    field->change_player_position(cur_step);
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

void Game::field_generate() {
    EventGenerator gen(player, field);
    CellFactory factory(gen);
    FieldGenerator fieldGenerator(factory);
    fieldGenerator.field_generate(*field);
}

void Game::initialize_field() {
    this->field = new Field();
    field_view = new FieldView(field);
}

void Game::initialize_field(std::pair<int, int> size) {
    this->field = new Field(size.first, size.second);
    field_view = new FieldView(field);
}

void Game::set_step(Player::Directions cur) {
    cur_step = cur;
}

void Game::loop() {
    while (status == INPROGRESS){
        mediator->notify(this, IMediator::STEP);
        reaction();
    }
}

Game::~Game() {
    delete field_view;
    delete player_view;
    delete player;
    delete field;
}
