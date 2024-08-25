#ifndef OOP_MESSAGEFACTORY_H
#define OOP_MESSAGEFACTORY_H

class MessageFactoryDestroyer;

#include "Message.h"
#include "MessageFactoryDestroyer.h"
#include "src/Logs/Levels.h"
#include "src/Utils/Obs/ISubject.h"

class MessageFactory : public ISubject {
private:
    static MessageFactory* p_factory;
    static MessageFactoryDestroyer destroyer;
    Message* msg;
    MessageFactory() = default;
    ~MessageFactory();
    friend class MessageFactoryDestroyer;
public:
    MessageFactory(const MessageFactory&) = delete;
    MessageFactory& operator=(MessageFactory&) = delete;
    static MessageFactory& get_instance();
    void create_message(Levels, const std::string&);
    Message& get_message();
};

#endif
