//
// Created by Dmitriy on 11/21/2022.
//

#ifndef OOP_FIELDGEN_H
#define OOP_FIELDGEN_H

#include "src/Background/Field.h"
template <class ... Rules>
class FieldGen {
public:
    Field* execute(Player* player){
        auto* field = new Field;
        field->set_player(player);
        (Rules()(field), ...);
        field->delete_player();
        return field;
    };
};


#endif //OOP_FIELDGEN_H
