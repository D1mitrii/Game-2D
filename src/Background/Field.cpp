#include "Field.h"

Field::Field(int a, int b) : width(a), height(b), player_position({0,0}) {
    generate_field();
};

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
    if (this != &other){
        this->height = other.height;
        this->width = other.width;
        this->player_position = other.player_position;
        this->observers = other.observers;
        for(int i = 0; i != height; i++){
            this->field.emplace_back();
            for(int j = 0; j != width; j++){
                this->field.at(i).push_back(other.field.at(i).at(j));
            }
        }
    }
    return *this;
}

void Field::generate_field() {
    //deconstruct();
    RNGenerator generator;
    for(int i = 0; i != this->height; i++){
        field.emplace_back();
        for (int j = 0; j != this->width; j++) {
            field.at(i).push_back(new CellBase);
            std::uniform_int_distribution<int> distr{1, 7};
            switch (generator.get_random_value<int>(distr)) {
                case 1:{
                    field.at(i).erase(field.at(i).begin() + j);
                    field.at(i).push_back(new CellWall);
                    break;
                }
                case 2: {
                    field.at(i).erase(field.at(i).begin() + j);
                    field.at(i).push_back(new CellCoin);
                    break;
                }
                case 3: {
                    field.at(i).erase(field.at(i).begin() + j);
                    field.at(i).push_back(new CellTrap);
                    break;
                }
                default:
                    break;
            }
        }
    }
    notify();
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

std::vector<std::vector<ICell*>> Field::get_field() const {
    return this->field;
}

void Field::check_position(std::pair<int, int> pair) {
    if(dynamic_cast<CellWall*>(field.at(pair.second).at(pair.first)) != nullptr){
        return;
    }
    this->player_position = pair;
}


Field::~Field() {
    //deconstruct();
}

std::pair<int, int> Field::get_position() const {
    return player_position;
}

void Field::set_base_cell() {
    delete field.at(player_position.second).at(player_position.first);
    field.at(player_position.second).at(player_position.first) = new CellBase;
}





