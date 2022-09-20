//
// Created by Dmitriy on 9/18/2022.
//

#ifndef OOP_COMMANDREADER_H
#define OOP_COMMANDREADER_H

#include "src/Entities/Player.h"
#include "iostream"

class CommandReader {
public:
    CommandReader() = default;
    ~CommandReader() = default;
    int read_number() const;
    Player::Directions get_step() const;
};


#endif //OOP_COMMANDREADER_H
