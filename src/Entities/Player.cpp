#include "Player.h"

Player::Player(int hearts, int power) : hearts(hearts), power(power), coins(0){
}

int Player::get_hearts() const {
    return this->hearts;
}

int Player::get_coins() const {
    return this->coins;
}

int Player::get_power() const {
    return this->power;
}

void Player::set_hearts(int heart) {
    this->hearts = heart;
}

void Player::set_power(int dmg) {
    this->power = dmg;
}

void Player::set_coins(int coin) {
    this->coins = coin;
}
