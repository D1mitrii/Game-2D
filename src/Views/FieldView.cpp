//
// Created by Dmitriy on 9/17/2022.
//

#include "FieldView.h"
#include "conio.h"

void FieldView::write_field(const Field& field) const {
    write_horizontal_border(field.get_width());
    for (int i = 0; i != field.get_height() ; ++i) {
        std::cout << '|';
        for (int j = 0; j != field.get_width() ; ++j) {
            CellView current_cell = CellView(field.get_field().at(i).at(j));
            std::cout << current_cell.get_view() << "  ";
        }
        std::cout << "|\n";
    }
    write_horizontal_border(field.get_width());
}

void FieldView::write_horizontal_border(int width) const {
    for(int i = 0; i != width + 1; i++){
        std::cout << "---";
    }
    std::cout << '\n';
}