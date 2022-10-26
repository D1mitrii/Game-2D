//
// Created by Dmitriy on 10/24/2022.
//

#ifndef OOP_MESSAGE_H
#define OOP_MESSAGE_H

class LogPool;
#include "src/Logs/Levels.h"
#include "src/Logs/LogPool/LogPool.h"
#include <map>
#include "string"
#include "ctime"

class Message {
private:
    std::map<Levels, std::string> prefixs {
            {Levels::GameObjects, "[GameOBJECT]"},
            {Levels::Gamestatus,  "[STATUS]"},
            {Levels::Errors,      "[ERROR]"}
    };
    std::string text;
    Levels level;
    std::string msg_time;
public:
    Message(Levels lvl, const std::string& msg);
    std::string get_prefix() const;
    Levels get_level() const;
    std::string get_text() const;
    std::string get_time() const;
    void set_level(Levels lvl);
    friend std::ostream& operator<<(std::ostream&, const Message& obj);
    ~Message() = default;
};


#endif //OOP_MESSAGE_H
