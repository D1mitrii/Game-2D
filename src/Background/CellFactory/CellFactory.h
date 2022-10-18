//
// Created by Dmitriy on 10/17/2022.
//

#ifndef OOP_CELLFACTORY_H
#define OOP_CELLFACTORY_H

class EventGenerator;

#include "src/Background/Cell.h"
#include "src/Events/EventGenerator/EventGenerator.h"

class CellFactory {
private:
    EventGenerator* ev_gen;
public:
    explicit CellFactory(EventGenerator* gen) : ev_gen(gen) {};
    void set_generator(EventGenerator* gen);
    Cell wall_cell();
    Cell base_cell();
    Cell event_cell();
    ~CellFactory();
};


#endif //OOP_CELLFACTORY_H
