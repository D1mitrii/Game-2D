//
// Created by Dmitriy on 11/22/2022.
//

#include "FieldEventGen.h"

Event *FieldEventGen::generate() {
    std::uniform_int_distribution<int> distr_percent{0, 100};

    int num = generator.get_random_value<int>(distr_percent);

    if(num < 15){
        return new FieldNoWalls(field);
    }
    else{
        return new FieldChangePos(field);
    }
}
