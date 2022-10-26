#ifndef OOP_LOGPOOL_H
#define OOP_LOGPOOL_H

class Message;
class MessageFactory;

#include "src/Logs/Logger/ConsoleLog.h"
#include "src/Logs/Messages/Message.h"
#include <vector>
#include <algorithm>
#include "src/Logs/Levels.h"
#include "src/Utils/Obs/IObserver.h"
#include "src/Logs/Messages/MessageFactory.h"

class LogPool : public IObserver {
private:
    std::vector<ILogger*> loggers;
    std::vector<Levels> levels;
    MessageFactory* factory;
    bool is_logging(Levels);
public:
    explicit LogPool(MessageFactory*);
    void add_log_level(Levels);
    void set_log_levels(std::vector<Levels>);
    void update() final;
    template<typename T>
    void add_logger(){
        if(std::is_base_of<ILogger, T>::value)
            loggers.push_back(new T);
    }

    template<typename T>
    void add_logger(std::string filename){
        if(std::is_base_of<ILogger, T>::value)
            loggers.push_back(new T(filename));
    }

    void print_log(Message& msg);

    ~LogPool(){
        std::for_each(loggers.begin(), loggers.end(), [](ILogger* obj){delete obj;});
    }
};



#endif
