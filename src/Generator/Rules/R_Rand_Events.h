//
// Created by Dmitriy on 11/21/2022.
//

#ifndef OOP_R_RAND_EVENTS_H
#define OOP_R_RAND_EVENTS_H

#include "src/Background/Field.h"
#include "src/Events/EventGenerator/IEventGen.h"
#include "src/Utils/RNG/RNGenerator.h"
#include "Util_Funcs.h"

template<class Gen_Event, int count = 0>
class R_Rand_Events {
public:
    void operator() (Field* field){
        if(count < 0)
            return;
        RNGenerator generator;

        Gen_Event gen(field);

        std::uniform_int_distribution<int> dist_height {0, field->get_height() - 1};
        std::uniform_int_distribution<int> dist_width {0, field->get_width() - 1};

        int counter = 0;
        int real_count = new_count(count, field->get_count_free());

        while (counter < real_count){
            int x = generator.get_random_value<int>(dist_width);
            int y = generator.get_random_value<int>(dist_height);

            if(field->get_cell(x, y).is_wall())
                continue;
            if(field->get_cell(x, y).get_event() != nullptr)
                continue;
            if(std::make_pair(x, y) == field->get_position())
                continue;

            field->get_cell(x, y).set_event(gen.generate());
            field->set_count(field->get_count_free()-1);
            counter++;
        }
    }
};

#endif //OOP_R_RAND_EVENTS_H
