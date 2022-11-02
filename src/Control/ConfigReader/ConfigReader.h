#ifndef OOP_CONFIGREADER_H
#define OOP_CONFIGREADER_H

#include "src/Control/Configs/FileConfig.h"

class ConfigReader  {
private:
    /*
    std::map<char, Player::Moves> default_controls{
            {'w', Player::Moves::UP},
            {'s', Player::Moves::DOWN},
            {'d', Player::Moves::RIGHT},
            {'a', Player::Moves::LEFT},
            {'e', Player::Moves::EXIT},
            {'m', Player::Moves::MENU}
    };
     */
    std::map<char, Player::Moves> controls;
public:
    ConfigReader() = default;
    std::map<char, Player::Moves>& read_cfg();
    ~ConfigReader() = default;
};


#endif //OOP_CONFIGREADER_H
