#include "Field.h"

Field::Field(int a, int b) : width(a), height(b), player_position({0,0}) {
    generate_field();
}

void Field::swap(Field &other) {
    std::swap(height, other.height);
    std::swap(width, other.width);
    std::swap(field, other.field);
    std::swap(player_position, other.player_position);
    std::swap(observers, other.observers);
}

Field &Field::operator=(Field &&other) {
    if(this != &other){
        this->swap(other);
    }
    return *this;
}

Field::Field(const Field &other) : width(other.width), height(other.height), player_position(other.player_position) {
    for (int i = 0; i != height; i++)
    {
        this->field.emplace_back();
        for (int j = 0; j != width; j++)
        {
            this->field.at(i).push_back(other.field.at(i).at(j));
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
    for(int i = 0; i != height; i++){
        field.emplace_back();
        for (int j = 0; j != width; j++) {
                field.at(i).push_back(generate_cell());
        }
    }
    delete field.at(player_position.second).at(player_position.first);
    field.at(player_position.second).at(player_position.first) = new CellBase;
    notify();
}

ICell* Field::generate_cell(){
    RNGenerator generator;
    std::uniform_int_distribution<int> distr{1, 13};
    switch (generator.get_random_value<int>(distr)) {
        case 1:
            return new CellWall;
        case 2:
            return new CellCoin;
        case 3:
            return new CellTrap;
        case 4:
            return new CellMove;
        case 5:
            return new CellBuff;
        default:
            return new CellBase;
    }
}

Event* Field::change_player_position(Player::Directions direction) {

    std::pair<int, int> temp = player_position;

    switch (direction) {
        case Player::UP:
            temp.second--;
            break;
        case Player::DOWN:
            temp.second++;
            break;
        case Player::LEFT:
            temp.first--;
            break;
        case Player::RIGHT:
            temp.first++;
            break;
    }
    temp.first = temp.first % width;
    temp.second = temp.second % height;
    if(temp.first < 0) temp.first += width;
    if(temp.second < 0) temp.second += height;

    check_position(temp);

    notify();
    return field.at(player_position.second).at(player_position.first)->get_event();
}

int Field::get_height() const {
    return this->height;
};

int Field::get_width() const {
    return this->width;
};

ICell* Field::get_cell(int x, int y) const {
    return this->field.at(y).at(x);
}

void Field::check_position(std::pair<int, int> pair) {
    if(dynamic_cast<CellWall*>(field.at(pair.second).at(pair.first)) != nullptr){
        return;
    }
    this->player_position = pair;
}

Field::~Field() {
    deconstruct();
}

std::pair<int, int> Field::get_position() const {
    return player_position;
}

void Field::set_base_cell() {
    delete field.at(player_position.second).at(player_position.first);
    field.at(player_position.second).at(player_position.first) = new CellBase;
}

void Field::deconstruct() {
    if(field.empty())
        return;
    for (int i = 0; i != height; ++i) {
        for (int j = 0; j != width; ++j)
            delete field.at(i).at(j);
    }
    field.clear();
}




