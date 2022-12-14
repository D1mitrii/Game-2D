//
// Created by Dmitriy on 12/11/2022.
//

#include "Memento.h"

Memento::Memento(int hash, int w, int h, std::vector<std::vector<Cell>> cells, std::pair<int,int> pos,std::vector<int> stats) {
    field_map = std::move(cells);
    pos = std::move(pos);
    player_stats = std::move(stats);
    this->hashcode = hash;
    width = w;
    height = h;
}

std::vector<std::vector<Cell>> Memento::get_map() const {
    return field_map;
}

std::pair<int, int> Memento::get_position() const {
    return player_position;
}

std::vector<int> Memento::get_stats() const {
    return player_stats;
}

int Memento::get_hashcode() const {
    return hashcode;
}

int Memento::get_height() const {
    return height;
}

int Memento::get_width() const {
    return width;
}
