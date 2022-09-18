#ifndef OOP_FIELD_H
#define OOP_FIELD_H

#include <vector>
#include "src/Entities/Player.h"
#include "Cell.h"
#include "utility"
#include "random"

class Field {
private:
    int height;
    int width;
    std::pair<int, int> player_position;
    std::vector<std::vector<Cell>> field;
public:
    explicit Field(int a = 10, int b = 10);
    Field(const Field& other);
    Field(Field&& other);
    void swap(Field& other);
    Field& operator=(const Field& other);
    Field& operator=(Field&& other);
    void generate_field();
    void change_player_position(Player::Directions direction);
};


#endif
