#ifndef OOP_CELL_H
#define OOP_CELL_H


#include "src/Events/Event.h"
#include <algorithm>

class Cell {
public:
    enum CellType{
        STANDARD,
        PLAYER,
        WALL,
        Coin
    };
    Cell();
    Cell(const Cell& other);
    Cell(Cell &&other);
    CellType get_celltype();
    void swap(Cell& other);
    Cell& operator=(const Cell& other);
    Cell& operator=(Cell&& other);
    void set_type(CellType type);
private:
    CellType type;
    Event* event;
};


#endif //OOP_CELL_H
