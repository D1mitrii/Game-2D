//
// Created by Dmitriy on 10/10/2022.
//

#ifndef OOP_REGENFIELD_H
#define OOP_REGENFIELD_H

#include "FieldEvents.h"

class RegenField : public FieldEvents{
public:
    void execute(Field& field) final;
};


#endif //OOP_REGENFIELD_H
