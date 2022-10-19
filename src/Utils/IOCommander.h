//
// Created by Dmitriy on 9/18/2022.
//

#ifndef OOP_IOCOMMANDER_H
#define OOP_IOCOMMANDER_H

class MediatorObject;

#include "src/Entities/Player.h"
#include "src/Utils/Med/MediatorObject.h"
#include "src/Utils/Med/IMediator.h"
#include "iostream"

class IOCommander : public MediatorObject{
private:
    Player::Directions step;
public:
    IOCommander() = default;
    void map_standard() const;
    int read_number() const;
    std::pair<int, int> read_size();
    void input_step();
    Player::Directions get_step() const;
    void Defeat() const;
    void Victory() const;
};


#endif //OOP_IOCOMMANDER_H
