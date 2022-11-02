//
// Created by Dmitriy on 11/1/2022.
//

#ifndef OOP_CONSOLECONTROLER_H
#define OOP_CONSOLECONTROLER_H

#include "IControler.h"
#include <iostream>

class ConsoleControler final : public IControler {
public:
    ConsoleControler() = default;
    char get_command() final;
    ~ConsoleControler() final = default;
};


#endif //OOP_CONSOLECONTROLER_H
