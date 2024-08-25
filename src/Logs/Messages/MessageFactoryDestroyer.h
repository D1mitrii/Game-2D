//
// Created by Dmitriy on 10/26/2022.
//

#ifndef OOP_MESSAGEFACTORYDESTROYER_H
#define OOP_MESSAGEFACTORYDESTROYER_H

class MessageFactory;
#include "MessageFactory.h"

class MessageFactoryDestroyer {
private:
    MessageFactory* p_factory;
public:
    void initialize(MessageFactory* pointer);
    ~MessageFactoryDestroyer();
};


#endif //OOP_MESSAGEFACTORYDESTROYER_H
