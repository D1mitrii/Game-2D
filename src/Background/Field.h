#ifndef OOP_FIELD_H
#define OOP_FIELD_H

#include <vector>
#include "Cell.h"
class Field {
private:
    int height;
    int width;
    std::vector<std::vector<Cell>> field;
public:
    explicit Field(int a = 10, int b = 10);
    void swap(Field& other);
    Field& operator=(const Field& other);
};


#endif
