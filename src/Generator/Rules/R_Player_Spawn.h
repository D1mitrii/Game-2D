//
// Created by Dmitriy on 11/21/2022.
//

#ifndef OOP_R_PLAYER_SPAWN_H
#define OOP_R_PLAYER_SPAWN_H

#include "src/Background/Field.h"

template<int x, int y>
class R_Player_Spawn{
public:
    void operator()(Field* field){
        auto pair = std::make_pair<int, int>(x, y);
        field->set_player_pos(pair);
    };
};

#endif //OOP_R_PLAYER_SPAWN_H
