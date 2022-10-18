//
// Created by Dmitriy on 10/17/2022.
//

#ifndef OOP_CELLFACTORY_H
#define OOP_CELLFACTORY_H

class EventGenerator;

#include "src/Events/EventGenerator/EventGenerator.h"

class CellFactory {
private:
    EventGenerator ev_gen;
public:
    CellFactory() = default;
    explicit CellFactory(EventGenerator& gen);
    Cell wall_cell();
    Cell base_cell();
    Cell event_cell();
};


#endif //OOP_CELLFACTORY_H
