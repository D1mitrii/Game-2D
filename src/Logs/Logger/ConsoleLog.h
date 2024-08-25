#ifndef OOP_CONSOLELOG_H
#define OOP_CONSOLELOG_H

#include <iostream>
#include "ILogger.h"
#include "src/Logs/Messages/Message.h"

class ConsoleLog final : public ILogger{
public:
    ConsoleLog() = default;
    void print(const Message& msg) override;
    ~ConsoleLog() override = default;
};


#endif //OOP_CONSOLELOG_H
