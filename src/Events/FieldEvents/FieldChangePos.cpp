//
// Created by Dmitriy on 10/10/2022.
//

#include "FieldChangePos.h"


FieldChangePos::FieldChangePos(Field *fl) {
    field = fl;
}

void FieldChangePos::execute() {
    RNGenerator generator;
    std::uniform_int_distribution<int> distr {1, 4};
    Player::Directions dir;
    switch (generator.get_random_value<int>(distr)) {
        case 1:
            dir = Player::UP;
            break;
        case 2:
            dir = Player::RIGHT;
            break;
        case 3:
            dir = Player::LEFT;
            break;
        case 4:
            dir = Player::DOWN;
            break;
    }
    field->change_player_position(dir);
}
