//
// Created by Dmitriy on 12/11/2022.
//

#ifndef OOP_MEMENTO_H
#define OOP_MEMENTO_H

class Cell;
#include "src/Background/Cell.h"
#include <vector>
#include "Saver.h"

class Memento {
private:
    std::vector<std::vector<Cell>> field_map;
    std::pair<int, int> player_position;
    std::vector<int> player_stats;
    int width;
    int height;
    int hashcode;
public:
    Memento(int hash, int w, int h, std::vector<std::vector<Cell>> cells, std::pair<int,int> pos,std::vector<int> stats);
    std::vector<std::vector<Cell>> get_map() const;
    std::pair<int, int> get_position() const;
    std::vector<int> get_stats() const;
    int get_height() const;
    int get_width() const;
    int get_hashcode() const;
};


#endif //OOP_MEMENTO_H
