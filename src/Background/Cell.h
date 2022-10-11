#ifndef OOP_CELL_H
#define OOP_CELL_H

class Field;

#include "src/Events/PlayerEvents/PoisonTrap.h"
#include "src/Events/PlayerEvents/FrozenTrap.h"
#include "src/Events/PlayerEvents/CoinEvent.h"
#include "src/Events/FieldEvents/RegenField.h"

#include "src/Entities/Player.h"
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
    CellType get_celltype() const;
    void set_type(CellType type1);
    void set_event(Event* other);
    void update(Player& player, Field& field);
private:
    CellType type;
    Event* event;
};


#endif //OOP_CELL_H
