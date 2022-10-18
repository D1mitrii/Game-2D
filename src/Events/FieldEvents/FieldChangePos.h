//
// Created by Dmitriy on 10/10/2022.
//

#ifndef OOP_FIELDCHANGEPOS_H
#define OOP_FIELDCHANGEPOS_H

#include "FieldEvents.h"
#include "src/Entities/Player.h"
#include "src/Background/Field.h"

class FieldChangePos : public FieldEvents{
public:
    explicit FieldChangePos(Field* fl);
    void execute() final;
    ~FieldChangePos() override = default;
};


#endif //OOP_FIELDCHANGEPOS_H
