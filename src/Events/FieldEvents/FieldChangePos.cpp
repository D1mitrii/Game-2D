//
// Created by Dmitriy on 10/10/2022.
//

#include "FieldChangePos.h"

void FieldChangePos::execute(Field &field) {
    RNGenerator generator;
    std::uniform_int_distribution<int> distr {1, 4};
    switch (generator.get_random_value<int>(distr)) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }
}
