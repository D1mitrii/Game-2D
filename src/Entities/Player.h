#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


class Player {
private:
    int hearts;
    int coins;
    int power;

protected:
    static Player* player;
    explicit Player(int hearts = 3, int power = 1);

public:
    enum Directions{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    static Player* instance(int hearts = 3, int power = 1);
    Player(Player &other) = delete;
    void operator=(const Player &) = delete;
    ~Player() = default;
    int get_hearts() const;
};


#endif //OOP_PLAYER_H
