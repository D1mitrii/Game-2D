#ifndef OOP_FIELD_H
#define OOP_FIELD_H

class Cell;

#include "Cell.h"
#include "src/Entities/Player.h"
#include "src/Utils/Obs/ISubject.h"
#include <functional>
#include <map>
#include <vector>
#include <utility>
#include "src/Logs/LogPool/LogPool.h"

class Field : public ISubject{
private:
    int height;
    int width;
    std::pair<int, int> player_position;
    std::vector<std::vector<Cell>> field;
    void check_position(std::pair<int, int> pair);
    std::vector<IObserver*> observers;
    void deconstruct();
public:
    explicit Field(int a = 10, int b = 10);
    Field(const Field& other);
    Field(Field&& other);
    void swap(Field& other);
    Field& operator=(const Field& other);
    Field& operator=(Field&& other);
    void set_field(std::vector<std::vector<Cell>>& fl);
    void change_player_position(Player::Moves direction);
    int get_height() const;
    int get_width() const;
    Cell& get_cell(int x, int y);
    std::pair<int, int> get_position() const;
    void remove_walls();
    ~Field();
};


#endif
