#ifndef OOP_CELL_H
#define OOP_CELL_H


#include "src/Events/Event.h"

class Cell {
public:
    Cell();
    enum CellType{
        STANDARD,
        WALL
    };
    CellType GetCellType();
private:
    CellType type;
    Event* event;
};


#endif //OOP_CELL_H
