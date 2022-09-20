//
// Created by Dmitriy on 9/19/2022.
//

#include "Mediator.h"

std::pair<int, int> Mediator::field_size() {
    std::cout << "Введите ширину поля:\n";
    int width = reader.read_number();
    if(width < 1 || width > 25){
        std::cout << "Некорректное значение ширины!\nЗначиение будет установленно в значение 10.\n";
        width = 10;
    }
    std::cout << "Введите высоту поля:\n";
    int height = reader.read_number();
    if(height < 1 || height > 25){
        std::cout << "Некорректное значение высоты!\nЗначиение будет установленно в значение 10.\n";
        height = 10;
    }
    return std::pair<int, int>({width, height});
}

Player::Directions Mediator::move() {
    std::cout << "Введите направление движения(w, a, s, d):";
    return reader.get_step();
}
