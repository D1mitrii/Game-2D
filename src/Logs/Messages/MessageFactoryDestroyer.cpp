//
// Created by Dmitriy on 10/26/2022.
//

#include "MessageFactoryDestroyer.h"

void MessageFactoryDestroyer::initialize(MessageFactory *pointer) {
    p_factory = pointer;
}

MessageFactoryDestroyer::~MessageFactoryDestroyer() {
    delete p_factory;
}
