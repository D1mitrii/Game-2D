#include "Field.h"

Field::Field(int a, int b) : width(a), height(b), player_position({0,0}) {
    this->field.resize(height);
    for (int i = 0; i != height; i++)
    {
        this->field.at(i).resize(width);
        for (int j = 0; j != width; j++)
        {
            this->field.at(i).at(j) = Cell();
        }
    }
};

void Field::swap(Field &other) {
    std::swap(height, other.height);
    std::swap(width, other.width);
    std::swap(field, other.field);
    std::swap(player_position, other.player_position);
}

Field &Field::operator=(Field &&other) {
    if(this != &other){
        this->swap(other);
    }
    return *this;
}

Field::Field(const Field &other) : width(other.width), height(other.height), player_position(other.player_position) {
    field.resize(height);
    for (int i = 0; i != height; i++)
    {
        this->field.at(i).resize(width);
        for (int j = 0; j != width; j++)
        {
            this->field.at(i).at(j) = other.field.at(i).at(j);
        }
    }
}

Field::Field(Field &&other) {
    this->swap(other);
}

Field &Field::operator=(const Field &other) {
    if (this != &other)
        Field(other).swap(*this);

    return *this;
}

void Field::generate_field() {
    field.at(0).at(0).Set_Type(Cell::CellType::PLAYER);
    for(int i = 0; i != this->height; i++){
        int pos = i == 0 ? 1 : 0;
        for (int j = pos; j < this->width; ++j) {
            field.at(i).at(j).Set_Type(Cell::CellType::STANDARD);
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist(1,100);
            switch (dist(rng) % 5) {
                case 1:
                    field.at(i).at(j).Set_Type(Cell::CellType::WALL);
                    break;
                case 2:
                    field.at(i).at(j).Set_Type(Cell::CellType::Coin);
                    break;
                default:
                    break;
            }
        }
    }
};




