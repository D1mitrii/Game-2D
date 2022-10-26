//
// Created by Dmitriy on 9/18/2022.
//

#include "IOCommander.h"
#include "src/Logs/Logger/FileLog.h"

int IOCommander::read_number() const {
    int number;
    std::cin >> number;
    if(number < 5 || number > 15){
        number = 10;
        MessageFactory::get_instance().create_message(Errors, "Incorrect side value!");
    }
    return number;
}

void IOCommander::read_levels(std::vector<Levels>& list) {
    std::cout << "Logging the level of the Game Object?\n";
    if(get_approve())
        list.push_back(GameObjects);

    std::cout << "Logging the level of the Game Status?\n";
    if(get_approve())
        list.push_back(Gamestatus);

    std::cout << "Logging the level of the Errors?\n";
    if(get_approve())
        list.push_back(Errors);
}

bool IOCommander::get_approve() const {
    char ch;
    std::cout << "[1 - yes]\n";
    std::cin >> ch;
    return ch == '1';
}

void IOCommander::map_standard() const {
    std::cout << "Do you want to enter a size of map yourself?\n";
    if(get_approve()){
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
    MessageFactory::get_instance().create_message(Gamestatus, "The game ended in defeat.");
}

void IOCommander::Victory() const {
    std::cout << R"(\\\\\!VICTORY!/////)" << '\n';
    std::cout << "\tWOW!" << '\n';
    MessageFactory::get_instance().create_message(Gamestatus, "The game ended in victory.");
}

void IOCommander::create_logger() {
    std::cout << "Do you need logs?\n";
    if(!get_approve())
        return;

    auto* log = new LogPool(&MessageFactory::get_instance());

    std::cout << "Console log?\n";
    if(get_approve())
        log->add_logger<ConsoleLog>();

    std::cout << "File log?\n";
    if(get_approve()){
        std::cout << "Enter filename:\n";
        std::string filename;
        std::cin >> filename;
        log->add_logger<FileLog>(filename);
    }

    std::vector<Levels> list_levels;
    read_levels(list_levels);
    log->set_log_levels(list_levels);
    mediator->set_log(log);
}

std::pair<int, int> IOCommander::read_size() {
    int width;
    int height;
    std::cout << "The size of the map must be in range from 5 to 15" << '\n';
    std::cout << "If you enter an incorrect output, the values set to 10" << '\n';
    std::cout << "Enter a size for the map." << '\n' << "Width:";
    width = read_number();
    std::cout << "Height:";
    height = read_number();
    return std::pair<int, int>{width, height};
}

Player::Directions IOCommander::get_step() const {
    return step;
}
