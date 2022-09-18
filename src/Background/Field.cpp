#include "Field.h"

Field::Field(int a, int b) : width(a), height(b), player_position({0,0}) {
    for (int i = 0; i != height; i++)
    {
        this->field.emplace_back();
        this->field.at(i).resize(width);
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
    if (this != &other)
        Field(other).swap(*this);

    return *this;
}

void Field::generate_field() {
    field.at(0).at(0).set_type(Cell::PLAYER);
    for(int i = 0; i != this->height; i++){
        int pos = i == 0 ? 1 : 0;
        for (int j = pos; j < this->width; ++j) {
            field.at(i).at(j).set_type(Cell::STANDARD);
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist(1,100);
            switch (dist(rng) % 5) {
                case 1:
                    field.at(i).at(j).set_type(Cell::WALL);
                    break;
                case 2:
                    field.at(i).at(j).set_type(Cell::Coin);
                    break;
                default:
                    break;
            }
        }
    }
}

void Field::change_player_position(Player::Directions direction) {
    field.at(player_position.second).at(player_position.first).set_type(Cell::STANDARD);
    std::pair<int, int> temp_pair = this->player_position;

    switch (direction) {
        case Player::UP:
            temp_pair.second--;
            break;
        case Player::DOWN:
            temp_pair.second++;
            break;
        case Player::LEFT:
            temp_pair.first--;
            break;
        case Player::RIGHT:
            temp_pair.first++;
            break;
    }

    check_position(temp_pair);

    player_position.first = player_position.first % width;
    player_position.second = player_position.second % height;

    if(player_position.first < 0) player_position.first += width;
    if(player_position.second < 0) player_position.second += height;

    field.at(player_position.second).at(player_position.first).set_type(Cell::PLAYER);
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
    if(this->field.at(pair.second).at(pair.second).get_celltype() == Cell::WALL){
        return;
    }
    this->player_position = pair;
};




