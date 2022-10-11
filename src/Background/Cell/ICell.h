//
// Created by Dmitriy on 10/11/2022.
//

#ifndef OOP_ICELL_H
#define OOP_ICELL_H


#include "src/Events/Event.h"

class ICell {
public:
    ICell() = default;
    virtual Event* get_event() = 0;
    virtual ~ICell() = default;
};


#endif //OOP_ICELL_H
