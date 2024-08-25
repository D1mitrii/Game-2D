//
// Created by Dmitriy on 12/11/2022.
//

#ifndef OOP_SAVER_H
#define OOP_SAVER_H

class Memento;
#include <string>
#include <fstream>
#include "Memento.h"
#include "src/Views/FieldView.h"

class Saver {
private:
    int error_code;
    std::fstream file;
public:
    explicit Saver(const std::string& filename);
    void save(Memento* snapshot);
    int invalid() const;
    ~Saver();
};


#endif //OOP_SAVER_H
