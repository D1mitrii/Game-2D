#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include "src/Utils/Obs/ISubject.h"
#include <vector>
#include <algorithm>
#include <cstdio>

class Player : public ISubject {
private:
    int hearts;
    int power;
    int max_stat;
    int coins;
    std::vector<IObserver*> observers;
public:
    enum Directions{
        UP = 1,
        DOWN = 2,
        LEFT = 3,
        RIGHT = 4,
        EXIT = 5,
        NOTHING = 6
    };
    explicit Player(int hearts = 3, int power = 1);
    ~Player() = default;
    int get_hearts() const;
    int get_coins() const;
    int get_power() const;
    int get_max_stat() const;
    void set_hearts(int heart);
    void set_power(int dmg);
    void set_coins(int coin);
    void set_max_stat(int max);
};


#endif //OOP_PLAYER_H
