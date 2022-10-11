//
// Created by Dmitriy on 9/19/2022.
//

#ifndef OOP_MEDIATOR_H
#define OOP_MEDIATOR_H

#include "CommandReader.h"

class Mediator {
private:
    CommandReader reader;
public:
    Mediator(): reader(CommandReader()){};
    std::pair<int, int> field_size();
    Player::Directions move();
};


#endif //OOP_MEDIATOR_H
