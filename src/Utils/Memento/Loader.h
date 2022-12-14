//
// Created by Dmitriy on 12/11/2022.
//

#ifndef OOP_LOADER_H
#define OOP_LOADER_H

class Memento;
#include "Memento.h"

class Loader {
private:
    int error_code;
    std::fstream file;
public:
    explicit Loader(const std::string& filename);
    Memento* load();
    int invalid() const;
    ~Loader();
};


#endif //OOP_LOADER_H
