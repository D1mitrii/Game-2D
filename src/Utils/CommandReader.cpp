//
// Created by Dmitriy on 9/18/2022.
//

#include "CommandReader.h"

int CommandReader::read_number() const {
    int number;
    std::cin >> number;
    return number;
}

Player::Directions CommandReader::get_step() const {
    char ch;
    std::cin >> ch;
    switch (ch) {
        case 'w':
            return Player::UP;
        case 's':
            return Player::DOWN;
        case 'a':
            return Player::LEFT;
        case 'd':
            return Player::RIGHT;
        case 'e':
            return Player::EXIT;
        default:
            return Player::NOTHING;
    }
}
