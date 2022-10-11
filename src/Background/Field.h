#ifndef OOP_FIELD_H
#define OOP_FIELD_H

class Cell;

#include <vector>
#include "/Cell/CellBase.h"
#include "/Cell/CellCoin.h"
#include "/Cell/CellTrap.h"
#include "/Cell/CellWall.h"
#include "utility"
#include "src/Utils/RNG/RNGenerator.h"
#include "src/Entities/Player.h"
#include "src/Utils/Obs/ISubject.h"

class Field : public ISubject{
private:
    int height;
    int width;
    std::pair<int, int> player_position;
    std::vector<std::vector<Cell>> field;
    void check_position(std::pair<int, int> pair);
    std::vector<IObserver*> observers;
public:
    explicit Field(int a = 10, int b = 10);
    Field(const Field& other);
    Field(Field&& other);
    void swap(Field& other);
    Field& operator=(const Field& other);
    Field& operator=(Field&& other);
    void generate_field();
    void deconstruct();
    void change_player_position(Player& player, Player::Directions direction);
    int get_height() const;
    int get_width() const;
    std::vector<std::vector<Cell>> get_field() const;
    ~Field();
};


#endif
