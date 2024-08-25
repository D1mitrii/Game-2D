//
// Created by Dmitriy on 11/22/2022.
//

#ifndef OOP_IEVENTGEN_H
#define OOP_IEVENTGEN_H

class Event;
class Field;
#include "src/Utils/RNG/RNGenerator.h"

class IEventGen {
protected:
    RNGenerator generator;
    Field* field;
public:
    IEventGen() : generator(), field(nullptr) {};
    virtual Event* generate() = 0;
    virtual ~IEventGen() = default;
};


#endif //OOP_IEVENTGEN_H
