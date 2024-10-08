#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include "src/Utils/Obs/ISubject.h"
#include "src/Logs/Messages/MessageFactory.h"
#include <vector>
#include <algorithm>
#include <cstdio>

class Player : public ISubject {
private:
    int hearts;
    int power;
    int max_stat;
    int coins;
public:
    enum Moves{
        UP,
        DOWN,
        LEFT,
        RIGHT,
        EXIT,
        MENU,
        NOTHING
    };
    explicit Player(int hearts = 3, int power = 3);
    ~Player() = default;
    int get_hearts() const;
    int get_coins() const;
    int get_power() const;
    int get_max_stat() const;
    void set_hearts(int heart);
    void set_power(int dmg);
    void set_coins(int coin);
    void set_max_stat(int max);
    std::vector<int> get_stats() const;
};


#endif //OOP_PLAYER_H
