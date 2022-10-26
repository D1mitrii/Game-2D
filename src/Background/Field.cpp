#include "Field.h"

Field::Field(int a, int b) : width(a), height(b), player_position({0,0}) {
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

void Field::set_field(std::vector<std::vector<Cell>>& fl) {
    deconstruct();
    field = fl;
    notify();
}

void Field::change_player_position(Player::Directions direction) {

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
    if(field.at(player_position.second).at(player_position.first).get_event() != nullptr){
        MessageFactory::get_instance().create_message(GameObjects, "Event started!");
        field.at(player_position.second).at(player_position.first).get_event()->execute();
        field.at(player_position.second).at(player_position.first).set_event(nullptr);
    }
}


void Field::remove_walls() {
    for (int i = 0; i != height; ++i) {
        for (int j = 0; j != width; ++j) {
            field.at(i).at(j).set_wall(false);
        }
    }
    this->notify();
    MessageFactory::get_instance().create_message(GameObjects, "Walls have been removed from the playing field.");
}

int Field::get_height() const {
    return this->height;
};

int Field::get_width() const {
    return this->width;
}

Cell& Field::get_cell(int x, int y){
    return field.at(y).at(x);
}

void Field::check_position(std::pair<int, int> pair) {
    if(field.at(pair.second).at(pair.first).is_wall()){
        MessageFactory::get_instance().create_message(Errors, "The player tried to step on the wall.");
        return;
    }
    this->player_position = pair;
}

void Field::deconstruct() {
    if(field.empty()){
        return;
    }
    for (int i = 0; i != height; ++i) {
        for (int j = 0; j != width; ++j) {
            field.at(i).at(j).set_event(nullptr);
        }
        field.at(i).clear();
    }
    field.clear();
}

Field::~Field() {
    deconstruct();
}

std::pair<int, int> Field::get_position() const {
    return player_position;
}




