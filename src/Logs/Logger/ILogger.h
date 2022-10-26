#ifndef OOP_ILOGGER_H
#define OOP_ILOGGER_H

class Message;

class ILogger {
public:
    virtual void print(const Message& msg) = 0;
    virtual ~ILogger() {};
};


#endif //OOP_ILOGGER_H
