//
// Created by Dmitriy on 10/24/2022.
//

#include "Message.h"

Message::Message(Levels lvl, const std::string& msg) {
    level = lvl;
    text = msg;
    time_t time = std::time(nullptr);
    std::string temp = std::asctime(localtime(&time));
    temp.pop_back();
    msg_time = temp;
}

std::string Message::get_time() const {
    return msg_time;
}

Levels Message::get_level() const {
    return level;
}

std::string Message::get_text() const {
    return text;
}

void Message::set_level(Levels lvl) {
    level = lvl;
}

std::string Message::get_prefix() const {
    return prefixs.at(this->level);
}

std::ostream &operator<<(std::ostream& os, const Message &obj) {
    os << obj.get_prefix();
    os << " ";
    os << obj.get_time();
    os << " ";
    os << obj.get_text();
    os << std::endl;
    return os;
}
