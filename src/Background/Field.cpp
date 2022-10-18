#include "Field.h"

Field::Field(int a, int b) : width(a), height(b), player_position({0,0}), factory(nullptr) {
}

void Field::swap(Field &other) {
    std::swap(height, other.height);
    std::swap(width, other.width);
    std::swap(field, other.field);
    std::swap(player_position, other.player_position);
    std::swap(observers, other.observers);
    std::swap(factory, other.factory);
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


void Field::set_cell(int y) {
    RNGenerator gen;
    std::uniform_int_distribution<int> dist {0, 10};
    int num = gen.get_random_value<int>(dist);
    if(num < 5){
        field.at(y).push_back(cells["BASE"]());
        return;
    } else if(num < 7){
        field.at(y).push_back(cells["WALL"]());
        return;
    } else{
        field.at(y).push_back(cells["EVENT"]());
        return;
    }
}

void Field::set_factory(EventGenerator* ev_gen) {
    delete factory;
    factory = new CellFactory(ev_gen);
    cells["BASE"] = std::function<Cell()>([this]() { return factory->base_cell();});
    cells["WALL"] = std::function<Cell()>([this]() { return factory->wall_cell();});
    cells["EVENT"] = std::function<Cell()> ([this]() { return factory->event_cell();});
}

void Field::generate_field() {
    deconstruct();
    for(int i = 0; i != height; i++){
        field.emplace_back();
        for (int j = 0; j != width; j++) {
            set_cell(i);
        }
    }
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
        field.at(player_position.second).at(player_position.first).get_event()->execute();
        field.at(player_position.second).at(player_position.first).set_event(nullptr);
    }
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
    delete factory;
}

std::pair<int, int> Field::get_position() const {
    return player_position;
}




