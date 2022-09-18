#include "Player.h"

Player* Player::instance(int hearts, int power) {
    if(Player::player == nullptr){
        Player::player = new Player(hearts, power);
    }
    return Player::player;
}

Player::Player(int hearts, int power) : hearts(hearts), power(power){
    this->coins = 0;
}

int Player::get_hearts() const {
    return this->hearts;
}

Player* Player::player= nullptr;