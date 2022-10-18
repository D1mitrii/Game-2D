//
// Created by Dmitriy on 10/18/2022.
//

#ifndef OOP_FIELDGENERATOR_H
#define OOP_FIELDGENERATOR_H

class Field;
class CellFactory;
#include "src/Background/CellFactory/CellFactory.h"

class FieldGenerator {
private:
    CellFactory factory;
    std::map<std::string, std::function<Cell()> > cells;
    std::vector<std::vector<Cell>> fl;
    void set_cell(int x, int y);
public:
    explicit FieldGenerator(CellFactory& fact);
    void field_generate(Field& field);
};

#endif //OOP_FIELDGENERATOR_H
