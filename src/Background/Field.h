#ifndef OOP_FIELD_H
#define OOP_FIELD_H

class CellFactory;

#include <vector>
#include "utility"
#include "src/Entities/Player.h"
#include "src/Utils/Obs/ISubject.h"
#include "CellFactory/CellFactory.h"
#include <functional>
#include <map>

class Field : public ISubject{
private:
    int height;
    int width;
    CellFactory* factory;
    std::map<std::string, std::function<Cell()> > cells;
    std::pair<int, int> player_position;
    std::vector<std::vector<Cell>> field;
    void check_position(std::pair<int, int> pair);
    std::vector<IObserver*> observers;
    void deconstruct();
    void set_cell(int y);
public:
    explicit Field(int a = 10, int b = 10);
    Field(const Field& other);
    Field(Field&& other);
    void swap(Field& other);
    Field& operator=(const Field& other);
    Field& operator=(Field&& other);
    void set_factory(EventGenerator* ev_gen);
    void generate_field();
    void change_player_position(Player::Directions direction);
    int get_height() const;
    int get_width() const;
    Cell& get_cell(int x, int y);
    std::pair<int, int> get_position() const;
    ~Field();
};


#endif
