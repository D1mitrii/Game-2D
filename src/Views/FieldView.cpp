//
// Created by Dmitriy on 9/17/2022.
//

#include "FieldView.h"

void FieldView::write_field() const {
    write_horizontal_border();

    for (int i = 0; i != field->get_height(); ++i) {
        std::cout << '|';
        for (int j = 0; j != field->get_width(); ++j) {
            if(i == field->get_position().second && j == field->get_position().first){
                std::cout << "P";
            }
            else{
                std::cout << CellView(field->get_field().at(i).at(j)).get_view();
            }
            std::cout << "  ";
        }
        std::cout << "|\n";
    }
    write_horizontal_border();
}

void FieldView::write_horizontal_border() const {
    for(int i = 0; i != field->get_width() + 1; i++){
        std::cout << "---";
    }
    std::cout << '\n';
}

FieldView::FieldView(Field *map) : field(map) {
    field->attach(this);
}

void FieldView::update() {
    write_field();
}

