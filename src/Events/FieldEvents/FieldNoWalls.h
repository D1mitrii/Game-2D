//
// Created by Dmitriy on 10/11/2022.
//

#ifndef OOP_FIELDNOWALLS_H
#define OOP_FIELDNOWALLS_H

#include "FieldEvents.h"
#include "src/Background/Field.h"

class FieldNoWalls : public FieldEvents {
public:
    FieldNoWalls(Field* fl);
    void execute() final;
    ~FieldNoWalls() override = default;
};


#endif //OOP_FIELDNOWALLS_H
