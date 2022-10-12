//
// Created by Dmitriy on 9/18/2022.
//

#include "IOCommander.h"

int IOCommander::read_number() const {
    int number;
    std::cin >> number;
    if(number < 5 || number > 15)
        number = 10;
    return number;
}

void IOCommander::map_standard() const {
    std::cout << "Do you want to enter a size of map yourself? [1 - yes]\n";
    char ch;
    std::cin >> ch;
    if(ch == '1'){
        mediator->notify((MediatorObject *) this, IMediator::MEVENTS::CONFIRM);
    }
    else
        mediator->notify((MediatorObject *) this, IMediator::MEVENTS::CANCEL);
}

void IOCommander::input_step(){
    std::cout << "The direction of the player's movement (w, a, s, d). To exit, write e:";
    char ch;
    std::cin >> ch;
    switch (ch) {
        case 'w':
            step = Player::UP;
            break;
        case 's':
            step = Player::DOWN;
            break;
        case 'a':
            step = Player::LEFT;
            break;
        case 'd':
            step = Player::RIGHT;
            break;
        case 'e':
            step = Player::EXIT;
            break;
        default:
            step = Player::NOTHING;
            break;
    }
    mediator->notify(this, IMediator::STEP);
}

void IOCommander::Defeat() const {
    std::cout << R"(\\\\\!DEFEAT!/////)" << '\n';
    std::cout << "\tBRUH!" << '\n';
}

void IOCommander::Victory() const {
    std::cout << R"(\\\\\!VICTORY!/////)" << '\n';
    std::cout << "\tWOW!" << '\n';
}

std::pair<int, int> IOCommander::read_size() {
    int width;
    int height;
    std::cout << "The size of the map must be in range from 5 to 15" << '\n';
    std::cout << "If you enter an incorrect output, the values set to 10" << '\n';
    std::cout << "Enter a size for the map." << '\n' << "Width: ";
    width = read_number();
    std::cout << '\n' << "Height: ";
    height = read_number();
    std::cout << '\n';
    return std::pair<int, int>{width, height};
}

Player::Directions IOCommander::get_step() const {
    return step;
}
