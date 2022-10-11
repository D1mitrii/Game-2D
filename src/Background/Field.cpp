#include "Field.h"

Field::Field(int a, int b) : width(a), height(b), player_position({0,0}) {
    for (int i = 0; i != height; i++)
    {
        this->field.emplace_back();
        for (int j = 0; j != width; j++)
        {
            this->field.at(i).emplace_back();
        }
    }
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
            Cell new_cell(other.field.at(i).at(j));
            this->field.at(i).push_back(new_cell);
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
    field.at(player_position.second).at(player_position.first).set_type(Cell::PLAYER);
    RNGenerator generator;
    for(int i = 0; i != this->height; i++){
        int pos = i == 0 ? 1 : 0;
        for (int j = pos; j != this->width; j++) {
            field.at(i).at(j).set_type(Cell::STANDARD);
            std::uniform_int_distribution<int> distr{1, 7};
            switch (generator.get_random_value<int>(distr)) {
                case 1:
                    field.at(i).at(j).set_type(Cell::WALL);
                    break;
                case 2: {
                    field.at(i).at(j).set_type(Cell::Coin);
                    Event *event_new = new RegenField;
                    field.at(i).at(j).set_event(event_new);
                    break;
                }
                default:
                    break;
            }
        }
    }
    notify();
}

void Field::change_player_position(Player& player, Player::Directions direction) {
    field.at(player_position.second).at(player_position.first).set_type(Cell::STANDARD);
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

    field.at(player_position.second).at(player_position.first).set_type(Cell::PLAYER);
    notify();
    field.at(player_position.second).at(player_position.first).update(player, *this);
}

int Field::get_height() const {
    return this->height;
};

int Field::get_width() const {
    return this->width;
};

std::vector<std::vector<Cell>> Field::get_field() const {
    return this->field;
}

void Field::check_position(std::pair<int, int> pair) {
    if(this->field.at(pair.second).at(pair.first).get_celltype() == Cell::WALL){
        return;
    }
    this->player_position = pair;
}





