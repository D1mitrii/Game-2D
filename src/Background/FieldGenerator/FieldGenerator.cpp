//
// Created by Dmitriy on 10/18/2022.
//

#include "FieldGenerator.h"

FieldGenerator::FieldGenerator(CellFactory& fact) {
    this->factory = fact;
    cells["BASE"] = std::function<Cell()>([this]() { return factory.base_cell();});
    cells["WALL"] = std::function<Cell()>([this]() { return factory.wall_cell();});
    cells["EVENT"] = std::function<Cell()> ([this]() { return factory.event_cell();});
}

void FieldGenerator::field_generate(Field &field) {
    for (int i = 0; i != field.get_height(); ++i) {
        fl.emplace_back();
        for (int j = 0; j != field.get_width(); ++j) {
            if(std::pair<int,int>{i, j} == field.get_position())
                fl.at(i).push_back(cells["BASE"]());
            else
                set_cell(j, i);
        }
    }
    field.set_field(fl);
}

void FieldGenerator::set_cell(int x, int y) {
    RNGenerator gen;
    std::uniform_int_distribution<int> dist {0, 10};
    int num = gen.get_random_value<int>(dist);
    if(num < 5){
        fl.at(y).push_back(cells["BASE"]());
        return;
    } else if(num < 7){
        fl.at(y).push_back(cells["WALL"]());
        return;
    } else{
        fl.at(y).push_back(cells["EVENT"]());
        return;
    }
}
