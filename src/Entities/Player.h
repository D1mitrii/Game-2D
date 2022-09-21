#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


class Player {
private:
    int hearts;
    int coins;
    int power;

public:
    enum Directions{
        UP,
        DOWN,
        LEFT,
        RIGHT,
        EXIT,
        NOTHING
    };
    explicit Player(int hearts = 3, int power = 1);
    Player(Player &other) = delete;
    void operator=(const Player &) = delete;
    ~Player() = default;
    int get_hearts() const;
    int get_coins() const;
    int get_power() const;
    void set_hearts(int heart);
    void set_power(int dmg);
    void set_coins(int coin);
};


#endif //OOP_PLAYER_H
