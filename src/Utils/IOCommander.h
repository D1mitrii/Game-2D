//
// Created by Dmitriy on 9/18/2022.
//

#ifndef OOP_IOCOMMANDER_H
#define OOP_IOCOMMANDER_H

class MediatorObject;

#include "src/Entities/Player.h"
#include "src/Utils/Med/MediatorObject.h"
#include "src/Utils/Med/IMediator.h"
#include "src/Logs/LogPool/LogPool.h"
#include "iostream"

class IOCommander : public MediatorObject{
private:
    std::vector<Levels> read_levels();
    int level_num;
public:
    IOCommander() = default;
    void create_logger();
    void read_level_num();
    int get_level() const;
    bool get_approve() const;
    void Defeat() const;
    void Victory() const;
};


#endif //OOP_IOCOMMANDER_H
